// init.c

#include "defs.h"
#include "stdlib.h"

// 0000 000000000000000 000000000000000 000000000000000 111111111111111
// 0000 000000000000000 000000000000000 111111111111111 000000000000000
// 0000 000000000000000 111111111111111 000000000000000 000000000000000
// 0000 111111111111111 000000000000000 000000000000000 000000000000000
// 1111 000000000000000 000000000000000 000000000000000 000000000000000

#define RAND_64 (\
    (U64)rand() | \
    (U64)rand() << 15 | \
    (U64)rand() << 30 | \
    (U64)rand() << 45 | \
    ((U64)rand() & 0xf) << 60\
)

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

U64 SetMask[64];
U64 ClearMask[64];

U64 PieceKeys[13][120];
U64 SideKey;
U64 CastleKeys[16];

void InitHashKeys() {
    int index00 = 0;
    int index01 = 0;
    for(index00 = 0; index00 < 13; ++index00) {
        for(index01 = 0; index01 < 120; ++index01) {
            PieceKeys[index00][index01] = RAND_64;
        }
    }

    SideKey = RAND_64;
    for(index00 = 0; index00 < 16; ++index00) {
        CastleKeys[index00] = RAND_64;
    }
}


void InitBitMasks() {
    int index = 0;

    for (index= 0; index < 64; index++) {
        SetMask[index] = 0ULL;
        ClearMask[index] = 0ULL;
    }
    for (index= 0; index < 64; index++) {
        SetMask[index] |= (1ULL << index);
        ClearMask[index] = ~SetMask[index];
    }

}

void InitSq120To64() {

	int index = 0;
	int file = FILE_A;
	int rank = RANK_1;
	int sq = A1;
	int sq64 = 0;
	for(index = 0; index < BRD_SQ_NUM; ++index) {
		Sq120ToSq64[index] = 65;
	}

    for(index = 0; index < 64; ++index) {
		Sq64ToSq120[index] = 120;
	}

    for(rank = RANK_1; rank <= RANK_8; ++rank) {
		for(file = FILE_A; file <= FILE_H; ++file) {
			sq = FR2SQ(file,rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit() {
    InitSq120To64();
    InitBitMasks();
    InitHashKeys();
}