//
//  Queen.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Queen.hpp"

Queen::Queen(Color color) : Piece(QUEEN, color)
{}

bool Queen::isValidMove(const Chessboard &board, const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    return true;
}
