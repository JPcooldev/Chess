//
//  Pawn.hpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

class Pawn : public Piece {
    
public:
    Pawn(Color color);
    ~Pawn() override = default;
    
    bool isValidMove() override;
};

#endif /* Pawn_hpp */
