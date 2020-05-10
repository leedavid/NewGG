#include "chess.h"


////
//// Includes
////

#include <cassert>
#include <cmath>
#include <cstring>
//#if !(defined(__hpux) || defined(__ppc__) || defined(__ppc64__) || defined(__arm__))
//#  include <xmmintrin.h>
//#endif

#include "movegen.h"
#include "tt.h"





#ifndef USE_32KEY_HASH


// The main transposition table
TranspositionTable TT;


/// TranspositionTable::resize() sets the size of the transposition table,
/// measured in megabytes. Transposition table consists of a power of 2 number
/// of clusters and each cluster consists of TTClusterSize number of TTEntry.

void TranspositionTable::resize(size_t mbSize) {

	size_t newClusterCount = size_t(1) << msb((mbSize * 1024 * 1024) / sizeof(TTCluster));

	if (newClusterCount == clusterCount)
		return;

	clusterCount = newClusterCount;

	free(mem);
	mem = calloc(clusterCount * sizeof(TTCluster)+CACHE_LINE_SIZE - 1, 1);

	if (!mem)
	{
		std::cerr << "Failed to allocate " << mbSize
			<< "MB for transposition table." << std::endl;
		exit(EXIT_FAILURE);
	}

	table = (TTCluster*)((uintptr_t(mem) + CACHE_LINE_SIZE - 1) & ~(CACHE_LINE_SIZE - 1));
}


/// TranspositionTable::clear() overwrites the entire transposition table
/// with zeroes. It is called whenever the table is resized, or when the
/// user asks the program to clear the table (from the UCI interface).

void TranspositionTable::clear() {

	std::memset(table, 0, clusterCount * sizeof(TTCluster));
}


/// TranspositionTable::probe() looks up the current position in the
/// transposition table. Returns a pointer to the TTEntry or NULL if
/// position is not found.

const TTEntry* TranspositionTable::probe(const Key key) const {

	TTEntry* tte = first_entry(key);
	uint16 key16 = key >> 48;

	for (unsigned i = 0; i < TTClusterSize; ++i, ++tte)
		if (tte->key16 == key16)
		{
		   tte->genBound8 = uint8(generation | tte->bound()); // Refresh
			return tte;
		}

	return NULL;
}


/// TranspositionTable::store() writes a new entry containing position key and
/// valuable information of current position. The lowest order bits of position
/// key are used to decide on which cluster the position will be placed.
/// When a new entry is written and there are no empty entries available in cluster,
/// it replaces the least valuable of entries. A TTEntry t1 is considered to be
/// more valuable than a TTEntry t2 if t1 is from the current search and t2 is from
/// a previous search, or if the depth of t1 is bigger than the depth of t2.

void TranspositionTable::store(const Key key, Value v, Bound b, Depth d, Move m, Value statV) {

	int absv = abs(v);
	if (absv == VALUE_BAN_CAP || absv == VALUE_BAN_CHECK){
		return;
	}

	TTEntry *tte, *replace;
	uint16 key16 = key >> 48; // Use the high 16 bits as key inside the cluster

	tte = replace = first_entry(key);

	for (unsigned i = 0; i < TTClusterSize; ++i, ++tte)
	{
		if (!tte->key16 || tte->key16 == key16) // Empty or overwrite old
		{
			if (!m)
				m = tte->move(); // Preserve any existing ttMove

			replace = tte;
			break;
		}

		// Implement replace strategy
		if (((tte->genBound8 & 0xFC) == generation || tte->bound() == BOUND_EXACT)
			- ((replace->genBound8 & 0xFC) == generation)
			- (tte->depth8 < replace->depth8) < 0)
			replace = tte;
	}

	replace->save(key16, v, b, d, m, generation, statV);
}

#else

// The main transposition table
TranspositionTable TT;


/// TranspositionTable::set_size() sets the size of the transposition table,
/// measured in megabytes. Transposition table consists of a power of 2 number
/// of clusters and each cluster consists of ClusterSize number of TTEntry.

void TranspositionTable::resize(uint64 mbSize) {

	size_t newClusterCount = size_t(1) << msb((mbSize * 1024 * 1024) / sizeof(Cluster));

	if (newClusterCount == clusterCount)
		return;

	clusterCount = newClusterCount;

	free(mem);
	mem = calloc(clusterCount * sizeof(Cluster) + CacheLineSize - 1, 1);

	if (!mem)
	{
		std::cerr << "Failed to allocate " << mbSize
			<< "MB for transposition table." << std::endl;
		exit(EXIT_FAILURE);
	}

	table = (Cluster*)((uintptr_t(mem) + CacheLineSize - 1) & ~(CacheLineSize - 1));
}


/// TranspositionTable::clear() overwrites the entire transposition table
/// with zeroes. It is called whenever the table is resized, or when the
/// user asks the program to clear the table (from the UCI interface).

void TranspositionTable::clear() {

	std::memset(table, 0, clusterCount * sizeof(Cluster));
}


/// TranspositionTable::probe() looks up the current position in the
/// transposition table. Returns a pointer to the TTEntry or NULL if
/// position is not found. TTEntry* probe(const Key key, bool& found) const;

TTEntry* TranspositionTable::probe(const Key key, bool& found) const {

	TTEntry* tte = first_entry(key);
	uint32 key32 = key >> 32;

	for (int i = 1; i < ClusterSize; ++i)
		if (!tte[i].key32 || tte[i].key32 == key32)
		{
			if (tte[i].generation8 != generation8 && tte[i].key32)
				tte[i].generation8 = generation8; // Refresh
			    
			return found = (bool)tte[i].key32, &tte[i];
		}

	// Find an entry to be replaced according to the replacement strategy
	TTEntry* replace = tte;
	for (int i = 1; i < ClusterSize; ++i)
		// Due to our packed storage format for generation and its cyclic
		// nature we add 259 (256 is the modulus plus 3 to keep the lowest
		// two bound bits from affecting the result) to calculate the entry
		// age correctly even after generation8 overflows into the next cycle.
		if (replace->depth16 - (generation8 - replace->generation8) * 2 * ONE_PLY
	>   tte[i].depth16 - (generation8 - tte[i].generation8) * 2 * ONE_PLY)
			replace = &tte[i];

	return found = false, replace;
}

	/// Returns an approximation of the hashtable occupation during a search. The
	/// hash is x permill full, as per UCI protocol.

	int TranspositionTable::hashfull() const
	{
		int cnt = 0;
		for (int i = 0; i < 1000 / ClusterSize; i++)
		{
			const TTEntry* tte = &table[i].entry[0];
			for (int j = 0; j < ClusterSize; j++)
				if (tte[j].generation8 == generation8)
					cnt++;
		}
		return cnt;
	}

#endif