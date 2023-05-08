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
    Chessboard m_chessboard;
    
public:
    Game() = default;
    ~Game() = default;
    
    void run();
private:
    //std::vector<std::pair<int, int>> help(const std::pair<int, int> &square);
    void castle();
    
    void print();
    bool isInCheck(Color color) const;
    bool isInCheckMate(Color color);
    bool isInStalemate(Color color);
    Color whoTurn(int moveCount);
    bool isRightTurn(const std::pair<int, int> &coord, Color turn);
    
    //bool isCheckSimulation(std::pair<int, int> &kingLocation, )
    
    std::string whoTurnDisplay(Color color);
    
    void splitStringBySpace(const std::string &input, std::vector<std::string> &tmp);
    std::pair<int, int> textToCoordinates(const std::string &textCoord);
};

#endif /* Game_hpp */
