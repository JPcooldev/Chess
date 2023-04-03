//
//  Game.hpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#ifndef Game_hpp
#define Game_hpp

#include "Chessboard.hpp"

class Game {
    Chessboard chessboard;
    
public:
    Game() = default;
    ~Game() = default;
    
    void run();
    void move();
    void showPosiibleMoves();
    void castle();
    
    void print();
private:
    bool isInCheck(Color color) const;
    bool isInCheckMate(Color color) const;
    bool isInStalemate(Color color) const;
    Color whoTurn(int moveCount);
    bool isRightTurn(const std::pair<int, int> &coord);
    
    
    void splitStringBySpace(const std::string &input, std::vector<std::string> &tmp);
    std::pair<int, int> textToCoordinates(const std::string &textCoord);
};

#endif /* Game_hpp */
