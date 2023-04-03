//
//  Game.cpp
//  Chess
//
//  Created by Jakub Prokop on 29.03.2023.
//

#include "Game.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>

void Game::run()
{
    int moveCounter = 1;
    Color turn = whoTurn(moveCounter);
    
    std::cout << "Welcome in CHESS GAME\n";
    
    while (true)
    {
        //determines if player is in checkmate
        if (isInCheckMate(turn))
        {
            std::cout << turn << " is in checkmate. Game over.\n";
            break;
        }
        
        //determines if player is in stalemate
        if (isInStalemate(turn)) {
            std::cout << turn << " is in stalemate. It is a draw.\n";
            break;
        }
        
        print();
        
        //user puts input (e.g "a4 a5" or "a4 command")
        std::cout << turn << "'s turn\n";
        std::cout << "Enter move: ";
        std::string input {};
        std::getline(std::cin, input);
        
        //checks for non-move commands
        if (input == "exit")
        {
            std::cout << "Game over\n";
            break;
        }
        
        std::vector<std::string> coordinatesStr {};
        splitStringBySpace(input, coordinatesStr);
        
        std::pair<int, int> coordsFrom {textToCoordinates(coordinatesStr.at(0))};
        
        //checks if player chose his piece
        if (isRightTurn(coordsFrom)) {
            std::cout << "Invalid move. It is " << turn << "'s turn\n";
            continue;
        }
        
        
        
    }
}

void Game::move() {
    ;
}

void Game::castle() {
    ;
}

bool Game::isInCheck(Color color) const
{
    return 1;
}

bool Game::isInCheckMate(Color color) const
{
    return 1;
}

bool Game::isInStalemate(Color color) const
{
    return 1;
}

//returns who's turn it is
Color Game::whoTurn(int moveCount)
{
    if (moveCount % 2 == 1)
        return WHITE;
    else
        return BLACK;
}

//converts user input (e.g. "a2 a3", "a2 possibilities" or "exit" ...) to separate strings
void Game::splitStringBySpace(const std::string& input, std::vector<std::string>& tmp)
{
    std::istringstream iss(input);
    std::string buf {};
    
    while (iss >> buf)
        tmp.emplace_back(buf);
}
 
//converts text coordinates into board indexes
std::pair<int, int> Game::textToCoordinates(const std::string &textCoord)
{
    int x = textCoord[0] - 'a';
    int y = textCoord[1] - '0';
    return {x, y};
}

void Game::print()
{
    chessboard.printBoard();
}

//checks if player wants to move with his piece
bool Game::isRightTurn(const std::pair<int, int> &coord) {
    if (chessboard.isOccupied(coord))
        return 1;
    else
        return false;
}






