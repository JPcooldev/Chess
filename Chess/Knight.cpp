//
//  Knight.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Knight.hpp"

Knight::Knight(Color color) : Piece(KNIGHT, color)
{}

bool Knight::isValidMove(const Chessboard &board, const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    return true;
}
