//
//  Bishop.hpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#ifndef Bishop_hpp
#define Bishop_hpp

#include "Piece.hpp"

class Bishop : public Piece {
    
public:
    Bishop(Color color);
    ~Bishop() override = default;
    
    bool isValidMove() override;
};

#endif /* Bishop_hpp */
