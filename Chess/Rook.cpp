//
//  Rook.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Rook.hpp"

Rook::Rook(Color color) : Piece(ROOK, color)
{}

bool Rook::isValidMove()
{
    return 1;
}
