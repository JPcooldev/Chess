//
//  Knight.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Knight.hpp"

Knight::Knight(Color color) : Piece(KNIGHT, color)
{}

bool Knight::isValidMove()
{
    return 1;
}
