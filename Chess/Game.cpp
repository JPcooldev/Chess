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
        
        // determines if player is in checkmate
        if (isInCheckMate(turn))
        {
            std::cout << whoTurnDisplay(turn) << " is in checkmate. Game over.\n";
            break;
        }
        
        //determines if player is in stalemate
        if (isInStalemate(turn)) {
            std::cout << whoTurnDisplay(turn) << " is in stalemate. It is a draw.\n";
            break;
        }
        
        
        print();
        
        // INPUT SECTION
        // user puts input (e.g "a4 a5" or "a4 command")
        std::cout << whoTurnDisplay(turn) << "'s turn\n";
        std::cout << "Enter move: ";
        std::string input {};
        std::getline(std::cin, input);
        
        // checks for non-move commands
        if (input == "exit")
        {
            std::cout << "Game over\n";
            break;
        }
        else if (input == "revert")
        {
            m_chessboard.revertLastMove();
            moveCounter++;
            turn = whoTurn(moveCounter);
            continue;
        }
        else if (input == "captures")
        {
            m_chessboard.printCaptures();
            continue;
        }
        
        std::vector<std::string> coordinatesStr {};
        splitStringBySpace(input, coordinatesStr);
        
        std::pair<int, int> coordsFrom {textToCoordinates(coordinatesStr.at(0))};
        std::pair<int, int> coordsTo {textToCoordinates(coordinatesStr.at(1))};
        
        // CHECK INPUT
        // check if player chose occupied square (square with piece) and if so, if he chose his piece
        if ( ! isRightTurn(coordsFrom, turn) )
        {
            std::cout << "Invalid move\n";
            continue;
        }
        
        // checks is move is valid, oherwise player will move again
        if ( m_chessboard.movePiece(coordsFrom, coordsTo) )
        {
            if ( isInCheck(turn))
            {
                std::cout << "Invalid move: This leaves " << whoTurnDisplay(turn) << " in check\n";
                m_chessboard.revertLastMove();
                continue;
            }
            else
            {
                moveCounter++;
                turn = whoTurn(moveCounter);
            }
        }
        else
        {
            std::cout << "Invalid move\n";
            continue;
        }
    }
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

// determones if player get himself into check by his move
bool Game::isInCheck(Color defendingColor) const
{
    Color attackingColor {};
    if (defendingColor == WHITE)
        attackingColor = BLACK;
    else
        attackingColor = WHITE;
    
    std::pair<int, int> kingLoc = m_chessboard.getKingsLocation(defendingColor);
    std::vector<std::pair<int, int>> attackLocations = m_chessboard.getPiecesLocations(attackingColor);
    
    // check if attacking's piece can attack player's king
    for (auto &attackPiece : attackLocations)
    {
        if (m_chessboard.isValidMove(attackPiece, kingLoc))
            return true;
    }
    return false;
}

// is in check and has no legal moves
bool Game::isInCheckMate(Color defendingColor)
{
    if (isInCheck(defendingColor))
    {
        //auto& board = m_chessboard.getBoard();
        
        // get all defending's pieces and try all their possible moves, if one can stop king from being in check => no checkmate
        for (const auto &pieceLoc : m_chessboard.getPiecesLocations(defendingColor))
        {
            // trying all moves for defending's pieces
            for (int row = 0; row < boardSize; row++)
            {
                for (int square = 0; square < boardSize; square++)
                {
                    std::pair<int, int> locationToMove = std::make_pair(row, square);
                    if ( m_chessboard.movePiece(pieceLoc, locationToMove) )
                    {
                        // player is no longer in check, so there exists possible move
                        if ( ! isInCheck(defendingColor))
                        {
                            m_chessboard.revertLastMove();
                            return false;
                        }
                        // move did not help with defending check so it must be reverted
                        m_chessboard.revertLastMove();
                    }
                }
            }
        }
        // no move is possible to defend checkmate => end
        return true;
    }
    else
        return false;
}

// is not in check and there are no legal moves
bool Game::isInStalemate(Color defendingColor)
{
    if ( isInCheck(defendingColor) )
        return false;
    else
    {
        //auto& board = m_chessboard.getBoard();
        
        // get all defending's pieces and try all their possible moves, if one can stop king from being in check => no checkmate
        for (const auto &pieceLoc : m_chessboard.getPiecesLocations(defendingColor))
        {
            // trying all moves for defending's pieces
            for (int row = 0; row < boardSize; row++)
            {
                for (int square = 0; square < boardSize; square++)
                {
                    std::pair<int, int> locationToMove = std::make_pair(row, square);
                    if ( m_chessboard.movePiece(pieceLoc, locationToMove) )
                    {
                        // player find a move which does not put him in check => no stalemate
                        if ( ! isInCheck(defendingColor))
                        {
                            m_chessboard.revertLastMove();
                            return false;
                        }
                        // move put player into check, it must be reverted
                        m_chessboard.revertLastMove();
                    }
                }
            }
        }
    }
    // all possible moves put player into check => stalemate
    return true;
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
    int x = '8' - textCoord[1];
    return {x, y};
}

void Game::print()
{
    m_chessboard.printBoard();
}

//checks if player wants to move with his piece
bool Game::isRightTurn(const std::pair<int, int> &coord, Color turn)
{
    if (m_chessboard.isOccupied(coord))
        return m_chessboard.getPiece(coord)->getColor() == turn;
    else
        return false;
}

std::string Game::whoTurnDisplay(Color color)
{
    return (color == WHITE ? "WHITE" : "BLACK");
}

std::vector<std::pair<int, int>> Game::getHelp(const std::pair<int, int> &square)
{
    return m_chessboard.getPossibleMoves(square);
}



