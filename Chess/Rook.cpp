//
//  Rook.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Rook.hpp"

Rook::Rook(Color color) : Piece(ROOK, color)
{}

bool Rook::isValidMove(const Chessboard &board, const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    return true;
}
