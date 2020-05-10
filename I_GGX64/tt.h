 
















#if !defined(TT_H_INCLUDED)
#define TT_H_INCLUDED

#include <iostream>

#include "move.h"
#include "types.h"

#ifndef USE_32KEY_HASH
/// The TTEntry is the 10 bytes transposition table entry, defined as below:
///
/// key        16 bit
/// move       16 bit
/// value      16 bit
/// eval value 16 bit
/// generation  6 bit
/// bound type  2 bit
/// depth       8 bit

struct TTEntry {

	Move  move()  const      { return (Move)move16; }
	Value value() const      { return (Value)value16; }
	Value eval_value() const { return (Value)evalValue; }
	Depth depth() const      { return (Depth)depth8; }
	Bound bound() const      { return (Bound)(genBound8 & 0x3); }

private:
	friend class TranspositionTable;

	void save(uint16 k, Value v, Bound b, Depth d, Move m, uint8 g, Value ev) {

		key16 = (uint16)k;
		move16 = (uint16)m;
		value16 = (sint16)v;
		evalValue = (sint16)ev;
		genBound8 = (uint8)(g | b);
		depth8 = (sint8)d;
	}

	uint16 key16;
	uint16 move16;
	sint16  value16;
	sint16  evalValue;
	uint8  genBound8;
	sint8   depth8;
};

/// TTCluster is a 32 bytes cluster of TT entries consisting of:
///
/// 3 x TTEntry (3 x 10 bytes)
/// padding     (2 bytes)

const unsigned TTClusterSize = 3;

struct TTCluster {
	TTEntry entry[TTClusterSize];
	char padding[2];
};

/// A TranspositionTable consists of a power of 2 number of clusters and each
/// cluster consists of ClusterSize number of TTEntry. Each non-empty entry
/// contains information of exactly one position. Size of a cluster shall not be
/// bigger than a cache line size. In case it is less, it should be padded to
/// guarantee always aligned accesses.

class TranspositionTable {

public:
	~TranspositionTable() { free(mem); }
	void new_search() { generation += 4; } // Lower 2 bits are used by Bound

	const TTEntry* probe(const Key key) const;
	TTEntry* first_entry(const Key key) const;
	void resize(size_t mbSize);
	void clear();
	//void store(const Key key, Value v, Bound type, Depth d, Move m, Value statV);

private:
	size_t clusterCount;
	TTCluster* table;
	void* mem;
	uint8 generation; // Size must be not bigger than TTEntry::genBound8
};

extern TranspositionTable TT;


/// TranspositionTable::first_entry() returns a pointer to the first entry of
/// a cluster given a position. The lowest order bits of the key are used to
/// get the index of the cluster inside the table.

inline TTEntry* TranspositionTable::first_entry(const Key key) const {

	return &table[(size_t)key & (clusterCount - 1)].entry[0];
}

#else

/// The TTEntry is the 128 bit transposition table entry, defined as below:
///
/// key: 32 bit
/// move: 16 bit
/// bound type: 8 bit
/// generation: 8 bit
/// value: 16 bit
/// depth: 16 bit
/// static value: 16 bit
/// static margin: 16 bit

struct TTEntry {

	uint32 key() const                { return key32; }
	Move move() const                 { return (Move)move16; }
	Bound bound() const               { return (Bound)bound8; }
	Value value() const               { return (Value)value16; }
	Depth depth() const               { return (Depth)depth16; }
	Value eval() const          { return (Value)evalValue; }

	void save(Key k, Value v, Bound b, Depth d, Move m, Value ev, uint8 g) {

//#ifndef STORE_ALWAYS_CHECK 
		//if (abs(ev) == VALUE_BAN_CHECK) {
		//	return;  // 不保存连将分到HASH表中
		//}
//#endif // !STORE_ALWAYS_CHECK 
		//if (abs(ev) == VALUE_BAN_CAP) {   // 常捉不保存了
		//	return;
		//}

		//if (abs(ev) == VALUE_DRAW) {
		//	d = Depth(d + 40);
		//}

		// if (ev != Value(15)) return;
		// fen 3k5/1R7/3ara3/9/6n2/6B2/9/4C4/4AK3/c5B2 w - - 0 1 moves b8a8 a0b0 a8a9 d9d8 a9b9 b0a0 b9b8 d8d9

		// Preserve any existing move for the same position
		if (m || (k >> 32) != key32)
			move16 = (uint16_t)m;

		// Don't overwrite more valuable entries
		if ((k >> 32) != key32
			|| d > depth16 - 4    // was 2 
			//|| g != generation8 // Any matching keys are already refreshed by probe() */
			|| b == BOUND_EXACT)
		{
			key32 = (uint32)(k >> 32);
			value16 = (sint16)v;
			evalValue = (sint16)ev;
			generation8 = (uint8)g;
			bound8 = (uint8)b;
			depth16 = (sint16)d;
		}
	}

private:
	friend class TranspositionTable;

	uint32 key32;                          // 4
	uint16 move16;	                       // 2
	sint16 value16, depth16, evalValue;    // 6
	uint8  bound8, generation8;            // 2
};


/// A TranspositionTable consists of a power of 2 number of clusters and each
/// cluster consists of ClusterSize number of TTEntry. Each non-empty entry
/// contains information of exactly one position. Size of a cluster shall not be
/// bigger than a cache line size. In case it is less, it should be padded to
/// guarantee always aligned accesses.

class TranspositionTable {

	static const int CacheLineSize = 64;
	static const int ClusterSize = 4;

	struct Cluster {
		TTEntry entry[ClusterSize];
		//char padding[16]; // Align to a divisor of the cache line size
	};

	static_assert(CacheLineSize % sizeof(Cluster) == 0, "Cluster size incorrect");

public:
	~TranspositionTable() { free(mem); }
	void new_search() { ++generation8; }
	uint8 generation() const { return generation8; }
	TTEntry* probe(const Key key, bool& found) const;
	int hashfull() const;
	void resize(size_t mbSize);
	void clear();

	// The lowest order bits of the key are used to get the index of the cluster
	TTEntry* first_entry(const Key key) const {
		return &table[(size_t)key & (clusterCount - 1)].entry[0];
	}

private:
	size_t clusterCount;
	Cluster* table;
	void* mem;
	uint8 generation8; // Size must be not bigger than TTEntry::generation8
};

extern TranspositionTable TT;

#endif

#endif // !defined(TT_H_INCLUDED)
