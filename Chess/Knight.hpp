//
//  Knight.hpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

class Knight : public Piece {
    
public:
    Knight(Color color);
    ~Knight() override = default;
    
    bool isValidMove() override;
};

#endif /* Knight_hpp */
