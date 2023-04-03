//
//  Pawn.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Pawn.hpp"

Pawn::Pawn(Color color) : Piece(PAWN, color)
{}

bool Pawn::isValidMove()
{
    return 1;
}
