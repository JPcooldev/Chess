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

#include <vector>
#include <utility>

class Chessboard;

class Piece {
    Color m_color;
    Type m_type;
    bool m_moved;
    
public:
    Piece(Type type, Color color);
    virtual ~Piece() = default;
    
    virtual bool isValidMove(const Chessboard &board, const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const = 0;
    //virtual std::vector<std::pair<int, int>> possibleMoves() = 0;
    
    Color getColor() const;
    Type getType() const;
    bool isMoved() const;
    void setMoved(bool moved);
};

#endif /* Piece_hpp */
