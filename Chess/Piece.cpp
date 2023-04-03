//
//  Piece.cpp
//  Chess
//
//  Created by Jakub Prokop on 28.03.2023.
//

#include "Piece.hpp"

Piece::Piece(Type type, Color color) : m_type(type), m_color(color)
{}

Color Piece::getColor() const { 
    return m_color;
}

Type Piece::getType() const {
    return m_type;
}
