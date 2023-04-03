//
//  Bishop.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Bishop.hpp"

Bishop::Bishop(Color color) : Piece(BISHOP, color)
{}

bool Bishop::isValidMove()
{
    return 1;
}
