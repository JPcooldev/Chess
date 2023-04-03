//
//  Piece.hpp
//  Chess
//
//  Created by Jakub Prokop on 28.03.2023.
//

#ifndef Piece_hpp
#define Piece_hpp

#include "Chessboard.hpp"
#include "typedef.h"

#include <memory>

class Piece {
    Color m_color;
    Type m_type;
    
public:
    Piece(Type type, Color color);
    virtual ~Piece() = default;
    
    virtual bool isValidMove() = 0;
    Color getColor() const;
    Type getType() const;
};

#endif /* Piece_hpp */
