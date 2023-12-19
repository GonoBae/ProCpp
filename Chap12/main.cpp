#include "GameBoard.h"
#include "ChessPiece.h"

int main()
{
    GameBoard chessBoard { 8, 8 };
    auto pawn { std::make_unique<ChessPiece>() };
    chessBoard.at(0, 0) = std::move(pawn);
    chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
    chessBoard.at(0, 1) = nullptr;
    return 0;
}