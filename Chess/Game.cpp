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
    
    std::cout << "Welcome to CHESS GAME\n\n";
    
    while (true)
    {
        /*TO TEST FUNCTIONALITY
         
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
         
        */
        
        print();
        
        //user puts input (e.g "a4 a5" or "a4 command")
        std::cout << turnToString(turn) << "'s turn\n";
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
        std::pair<int, int> coordsTo {textToCoordinates(coordinatesStr.at(1))};
        
        //checks if coordinates are on the board
        if ( ! (chessboard.isOnBoard(coordsFrom)) || ! (chessboard.isOnBoard(coordsTo)) )
        {
            std::cout << "Off the board. Invalid move\n";
            continue;
        }
        
        //checks if player chose no-empty square and if so, if he chose his piece
        if ( ! isRightTurn(coordsFrom, turn) )
        {
            std::cout << "Invalid move\n";
            continue;
        }
        
        /*
        //checks if player wants help
        if (coordinatesStr.at(1) == "help")
        {
            help(coordsFrom);
        }
        */
        
        //TO TEST FUNCTIONALITY
        
        move(coordsFrom, coordsTo);
        
        moveCounter++;
        turn = whoTurn(moveCounter);
    }
}

bool Game::move(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo)
{
    return chessboard.movePiece(squareFrom, squareTo);
}

/*
std::vector<std::pair<int, int>> Game::help(const std::pair<int, int> &square)
{
    return chessboard.showPossibleMoves(square);
}
 */

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
    int y = textCoord[0] - 'a';
    int x = textCoord[1] - '1';
    return {x, y};
}

void Game::print()
{
    chessboard.printBoard();
}

//checks if player wants to move with his piece
bool Game::isRightTurn(const std::pair<int, int> &coord, Color turn)
{
    if (chessboard.isOccupied(coord))
        return chessboard.getPiece(coord)->getColor() == turn;
    else
        return false;
}

std::string Game::turnToString(Color color)
{
    return (color == WHITE ? "WHITE" : "BLACK");
}






