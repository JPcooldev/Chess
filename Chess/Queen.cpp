//
//  Queen.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Queen.hpp"

Queen::Queen(Color color) : Piece(QUEEN, color)
{}

bool Queen::isValidMove()
{
    return 1;
}
