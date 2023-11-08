#pragma once
#include "definitions.h"

class Board {
public:
	void setupBoard(std::string FEN);

private:
	u64 m_whitePawns;
	u64 m_whiteKnights;
	u64 m_whiteBishops;
	u64 m_whiteRooks;
	u64 m_whiteQueens;
	u64 m_whiteKing;
	u64 m_blackPawns;
	u64 m_blackKnights;
    u64 m_blackBishops;
	u64 m_blackRooks;
	u64 m_blackQueens;
	u64 m_blackKing;

	std::string m_FEN = "";
	//TODO
public:
	Board() {
		m_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
		setupBoard(m_FEN);
	}
};

void Board::setupBoard(std::string FEN) {
	m_whiteBishops = 1;
}