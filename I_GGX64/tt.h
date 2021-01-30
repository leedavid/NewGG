


#if !defined(TT_H_INCLUDED)
#define TT_H_INCLUDED

#include <iostream>

#include "move.h"
#include "types.h"

#ifndef USE_32KEY_HASH
#else











/// TTEntry struct is the 10 bytes transposition table entry, defined as below:
///
/// key        32 bit			BY LGL
/// depth       8 bit
/// generation  5 bit
/// pv node     1 bit
/// bound type  2 bit
/// move       16 bit
/// value      16 bit
/// eval value 16 bit

struct TTEntry {

	Move  move()  const { return (Move)move16; }
	Value value() const { return (Value)value16; }
	Value eval()  const { return (Value)eval16; }
	Depth depth() const { return (Depth)depth8 + DEPTH_OFFSET; }
	bool is_pv()  const { return (bool)(genBound8 & 0x4); }
	Bound bound() const { return (Bound)(genBound8 & 0x3); }
	void save(Key k, Value v, bool pv, Bound b, Depth d, Move m, Value ev);

private:
	friend class TranspositionTable;

	uint16_t key16;                        // 2   中象好象32位好些
	uint8_t  depth8;                       // 1
	uint8_t  genBound8;                    // 1
	uint16_t move16;                       // 2
	int16_t  value16;                      // 2
	int16_t  eval16;                       // 2
};


/// A TranspositionTable is an array of Cluster, of size clusterCount. Each
/// cluster consists of ClusterSize number of TTEntry. Each non-empty TTEntry
/// contains information on exactly one position. The size of a Cluster should
/// divide the size of a cache line for best performance, as the cacheline is
/// prefetched when possible.

class TranspositionTable {

	static constexpr int ClusterSize = 3;

	struct Cluster {
		TTEntry entry[ClusterSize];
		char padding[2]; // Pad to 32 bytes  
	};

	static_assert(sizeof(Cluster) == 32, "Unexpected Cluster size");

public:
	~TranspositionTable() { aligned_large_pages_free(table); }
	void new_search() { generation8 += 8; } // Lower 3 bits are used by PV flag and Bound
	TTEntry* probe(const Key key, bool& found) const;
	int hashfull() const;
	void resize(size_t mbSize);
	void clear();

	TTEntry* first_entry(const Key key) const {
		return &table[mul_hi64(key, clusterCount)].entry[0];
	}

private:
	friend struct TTEntry;

	size_t clusterCount;
	Cluster* table;
	uint8_t generation8; // Size must be not bigger than TTEntry::genBound8
};

extern TranspositionTable TT;

#endif

#endif // !defined(TT_H_INCLUDED)
