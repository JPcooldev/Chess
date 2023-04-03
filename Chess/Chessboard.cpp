//
//  Chessboard.cpp
//  Chess
//
//  Created by Jakub Prokop on 28.03.2023.
//
//   0  1  2  3  4  5  6  7
//0  BR BN BB BQ BK BB BN BR  P - PAWN
//1  BP BP BP BP BP BP BP BP  R - ROOK
//2  -- -- -- -- -- -- -- --  N - KNIGHT
//3  -- -- -- -- -- -- -- --  B - BISHOP
//4  -- -- -- -- -- -- -- --  Q - QUEEN
//5  -- -- -- -- -- -- -- --  K - KING
//6  WP WP WP WP WP WP WP WP
//7  WR WN WB WQ WK WB WN WR
//

#include "Chessboard.hpp"
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"

#include <utility>
#include <iostream>

Chessboard::Chessboard()
{
    createBoard();
    createPieces();
}

void Chessboard::createPieces() {
    createPawns();
    createRooks();
    createKnights();
    createBishops();
    createQueens();
    createKings();
}

void Chessboard::createPawns() {
    placeOnBoard(std::make_pair(6, 0), std::make_unique<Pawn>(WHITE));
    placeOnBoard(std::make_pair(6, 1), std::make_unique<Pawn>(WHITE));
    placeOnBoard(std::make_pair(6, 2), std::make_unique<Pawn>(WHITE));
    placeOnBoard(std::make_pair(6, 3), std::make_unique<Pawn>(WHITE));
    placeOnBoard(std::make_pair(6, 4), std::make_unique<Pawn>(WHITE));
    placeOnBoard(std::make_pair(6, 5), std::make_unique<Pawn>(WHITE));
    placeOnBoard(std::make_pair(6, 6), std::make_unique<Pawn>(WHITE));
    placeOnBoard(std::make_pair(6, 7), std::make_unique<Pawn>(WHITE));
    
    placeOnBoard(std::make_pair(1, 0), std::make_unique<Pawn>(BLACK));
    placeOnBoard(std::make_pair(1, 1), std::make_unique<Pawn>(BLACK));
    placeOnBoard(std::make_pair(1, 2), std::make_unique<Pawn>(BLACK));
    placeOnBoard(std::make_pair(1, 3), std::make_unique<Pawn>(BLACK));
    placeOnBoard(std::make_pair(1, 4), std::make_unique<Pawn>(BLACK));
    placeOnBoard(std::make_pair(1, 5), std::make_unique<Pawn>(BLACK));
    placeOnBoard(std::make_pair(1, 6), std::make_unique<Pawn>(BLACK));
    placeOnBoard(std::make_pair(1, 7), std::make_unique<Pawn>(BLACK));
}

void Chessboard::createRooks() {
    placeOnBoard(std::make_pair(7, 0), std::make_unique<Rook>(WHITE));
    placeOnBoard(std::make_pair(7, 7), std::make_unique<Rook>(WHITE));
    
    placeOnBoard(std::make_pair(0, 0), std::make_unique<Rook>(BLACK));
    placeOnBoard(std::make_pair(0, 7), std::make_unique<Rook>(BLACK));
}

void Chessboard::createKnights() {
    placeOnBoard(std::make_pair(7, 1), std::make_unique<Knight>(WHITE));
    placeOnBoard(std::make_pair(7, 6), std::make_unique<Knight>(WHITE));
    
    placeOnBoard(std::make_pair(0, 1), std::make_unique<Knight>(BLACK));
    placeOnBoard(std::make_pair(0, 6), std::make_unique<Knight>(BLACK));
}

void Chessboard::createBishops() {
    placeOnBoard(std::make_pair(7, 2), std::make_unique<Bishop>(WHITE));
    placeOnBoard(std::make_pair(7, 5), std::make_unique<Bishop>(WHITE));
    
    placeOnBoard(std::make_pair(0, 2), std::make_unique<Bishop>(BLACK));
    placeOnBoard(std::make_pair(0, 5), std::make_unique<Bishop>(BLACK));
}

void Chessboard::createQueens() {
    placeOnBoard(std::make_pair(7, 7), std::make_unique<Queen>(WHITE));
    
    placeOnBoard(std::make_pair(0, 7), std::make_unique<Queen>(BLACK));
}

void Chessboard::createKings() {
    placeOnBoard(std::make_pair(7, 7), std::make_unique<King>(WHITE));
    
    placeOnBoard(std::make_pair(0, 7), std::make_unique<King>(BLACK));
}

//fills board with nullptr
void Chessboard::createBoard()
{
    for (auto& row : board)
        for (auto& a : row)
            a.reset(nullptr);
}

//moves ownership of a piece to the board (more precisily to the square(x,y) of a board
void Chessboard::placeOnBoard(const std::pair<int, int>& squareStart, std::unique_ptr<Piece> piece)
{
    board.at(squareStart.first).at(squareStart.second) = std::move(piece);
}

//checks if WHITE piece is moving upwards and if BLACK is moving downwards
bool Chessboard::isForwardMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    Color color = board.at(squareFrom.first).at(squareFrom.second)->getColor();
    if (color == WHITE && squareFrom.second > squareTo.second)
        return true;
    else if (color == BLACK && squareFrom.second < squareTo.second)
        return true;
    else
        return false;
}

//checks if row is unchanged, then it is horizontal move
bool Chessboard::isHorizontalMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    return squareFrom.first == squareTo.first;
}

//checks if column is unchanged, then it is vertical move
bool Chessboard::isVerticalMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    return squareFrom.second == squareTo.second;
}

//checks if the differences between moves in horizontal and vertical direction are the same, then it is diagonal move
bool Chessboard::isDiagonalMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    int verticalDifference = squareFrom.second - squareTo.second;
    int horizontalDifference = squareFrom.first - squareTo.first;
    return abs(verticalDifference) == abs(horizontalDifference);
}

//checks if the differences between moves in horizontal and vertical direction are in the L-shape, then it is knight move
bool Chessboard::isKnightMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const
{
    int verticalDifference = abs(squareFrom.second - squareTo.second);
    int horizontalDifference = abs(squareFrom.first - squareTo.first);
    return ((verticalDifference == 2 && horizontalDifference == 1) || (verticalDifference == 1 && horizontalDifference == 2));
}

//checks if row and column is in (0,7) interval
bool Chessboard::isOnBoard(const std::pair<int, int> &square) const
{
    int xloc = square.first;
    int yloc = square.second;
    return (xloc >= 0 && xloc < boardSize && yloc >= 0 && yloc < boardSize);
}

//checks if square is occupied then if colors match, otherwise square isn't the same color
bool Chessboard::isSameColor(const std::pair<int, int>& squareFrom, const std::pair<int, int>& squareTo) const
{
    if (isOccupied(squareTo))
        return (board.at(squareFrom.first).at(squareFrom.second)->getColor() == board.at(squareTo.first).at(squareTo.second)->getColor());
    else
        return false;
}

//checks if square is occupied then if colors are different, otherwise square is the same color
bool Chessboard::isDifferentColor(const std::pair<int, int>& squareFrom, const std::pair<int, int>& squareTo) const
{
    //return ! (isSameColor(squareFrom, squareTo));
    if (isOccupied(squareTo))
        return (board.at(squareFrom.first).at(squareFrom.second)->getColor() != board.at(squareTo.first).at(squareTo.second)->getColor());
    else
        return false;
}

//checks if a square has some value or nullptr (which means it is empty)
bool Chessboard::isOccupied(const std::pair<int, int>& square) const
{
    if (board.at(square.first).at(square.second) == nullptr)
        return false;
    else
        return true;
}

//returns a piece from board
const std::unique_ptr<Piece>& Chessboard::getPiece(const std::pair<int, int> &square) const
{
    return board.at(square.first).at(square.second);
}

//
bool Chessboard::movePiece(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo)
{
    return 1;
}

void setPieceOnSquare(const std::pair<int, int>& squareFrom, const std::pair<int, int>& squareTo)
{
    
}

//prints board
void Chessboard::printBoard() const
{
    for (const auto &row : board)
        for (const auto &square : row)
            std::cout << getTypeToPrint(square) << " ";
    std::cout << std::endl;
}

//prints specific string depending on what's on square
std::string Chessboard::getTypeToPrint(const std::unique_ptr<Piece> &square) const
{
    if (square == nullptr)
        return "--";
    else
    {
        Color color = square->getColor();
        
        switch (square->getType())
        {
            case PAWN:
                return (color == WHITE ? "WP" : "BP");
            case ROOK:
                return (color == WHITE ? "WR" : "BR");
            case KNIGHT:
                return (color == WHITE ? "WN" : "BN");
            case BISHOP:
                return (color == WHITE ? "WB" : "BB");
            case QUEEN:
                return (color == WHITE ? "WQ" : "BQ");
            case KING:
                return (color == WHITE ? "WK" : "BK");
            default:
                return "getTypeToPrint error";
        }
    }
    
}



