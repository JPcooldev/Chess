#include "Piece.hpp"//
//  King.hpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#ifndef King_hpp
#define King_hpp


class King : public Piece {
    
public:
    King(Color color);
    ~King() override = default;
    
    bool isValidMove() override;
};
#endif /* King_hpp */
