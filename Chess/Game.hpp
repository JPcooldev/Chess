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
//private:
    bool move(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo);
    //std::vector<std::pair<int, int>> help(const std::pair<int, int> &square);
    void castle();
    
    void print();
private:
    bool isInCheck(Color color) const;
    bool isInCheckMate(Color color) const;
    bool isInStalemate(Color color) const;
    Color whoTurn(int moveCount);
    bool isRightTurn(const std::pair<int, int> &coord, Color turn);
    
    std::string turnToString(Color color);
    
    void splitStringBySpace(const std::string &input, std::vector<std::string> &tmp);
    std::pair<int, int> textToCoordinates(const std::string &textCoord);
};

#endif /* Game_hpp */
