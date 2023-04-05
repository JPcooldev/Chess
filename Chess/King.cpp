//
//  King.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "King.hpp"

King::King(Color color) : Piece(KING, color)
{}

bool King::isValidMove(const Chessboard &board, const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    return true;
}
