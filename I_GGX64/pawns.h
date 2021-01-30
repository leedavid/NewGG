#ifndef PAWNS_H_INCLUDED
#define PAWNS_H_INCLUDED

#include "misc.h"
#include "chess.h"
#include "position.h"

// fen 3ak1b2/4a4/4c4/2R1p3p/5Np2/1n7/3N4P/1C2B4/4K4/1r7 w - - 0 1
#define LACK_SHI_ATT_POINT     4
#define LACK_XIANG_ATT_POINT   4
#define ALL_SHIXIANG_ATT_POINT 6

// 兵，仕相的特殊形状引起的评分

#define PEV_Rshi_MenGong         (1<<0)  // 炮闷宫的情况
#define PEV_Bshi_MenGong         (1<<1)
								
#define PEV_C_is_Rche_ATT		 (1<<2)  // 是不是有红车进攻，要另外加分
#define PEV_C_is_Bche_ATT		 (1<<3)  // 是不是有黑车进攻，要另外加分
								
#define R_HAVE_CONNECT_PAWN      (1<<4)  // 红方有连兵不是底线
#define B_HAVE_CONNECT_PAWN      (1<<5)  // 黑方有连兵

#define KING_CANNOT_STRING       (1<<6)  // 双方的将不会有牵制作用,二者只隔一个子，且在一个FILE上
#define R_KING_CANNOT_ATT        (1<<7)  // 红将不可能加入进攻，也就是说，红将上面没有自己的仕相兵
#define B_KING_CANNOT_ATT        (1<<8)  // 黑将不可能加入进攻，也就是说，黑将上面没有自己的仕相兵


//const int PawnTableSize = 16384*2;

//template<class Entry, int Size>
//struct HashTable {
//	Entry* operator[](Key key) { return &table[(uint32_t)key & (Size - 1)]; }

//private:
//	std::vector<Entry> table = std::vector<Entry>(Size);
//};

namespace Pawns {

/// Pawns::Entry contains various information about a pawn structure. Currently,
/// it only includes a middle game and end game pawn structure evaluation, and a
/// bitboard of passed pawns. We may want to add further information in the future.
/// A lookup to the pawn hash table (performed by calling the probe function)
/// returns a pointer to an Entry object.

struct Entry {

	Score pawns_value() const { return value; } 
	sint8 getPawnCan(Color c) const { return _pcan[c]; }
	sint8 getAttpoint(Color c) const { return _attPoint[c]; }
	uint16 getExtraPawnInfo() const { return _PawnInfo; }
	Bitboard pawnshiXiang_attacks(Color c) const { return _pawnShiXiangAttacks[c]; }
	Bitboard attack_pawn() const { return _attackKingBoard; }
	
	Key key;
	Bitboard _pawnShiXiangAttacks[2];     // 这个可放在一起
	Bitboard _attackKingBoard;            // 处于进攻位置的兵， 红黑可写在一起
	sint8   _pcan[2];                     // 除了相，兵可河的能力。
	sint8   _attPoint[2];                 // 转换成 KingSafety;
	uint16  _PawnInfo;                    // 要测试兵的其它信息。
	Score value;
};


typedef HashTable<Entry, 32768> Table;

// void init();
Entry* probe(Position& pos, Table& entries);

} // namespace Pawns

#endif // #ifndef PAWNS_H_INCLUDED