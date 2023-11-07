#pragma once
#include "def.h"

class Board {
private:
	u64 whitePawns;
	u64 whiteKnights;
	u64 whiteBishops;
	u64 whiteRooks;
	u64 whiteQueens;
	u64 whiteKing;
	u64 blackPawns;
	u64 blackKnights;
    u64 blackBishops;
	u64 blackRooks;
	u64 blackQueens;
	u64 blackKing;
	std::string FEN = "";
	//TODO
public:
	Board() {
		FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
		//TODO
	}
};