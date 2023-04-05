//
//  Chessboard.hpp
//  Chess
//
//  Created by Jakub Prokop on 28.03.2023.
//

#ifndef Chessboard_hpp
#define Chessboard_hpp

#include "Piece.hpp"
#include "typedef.h"

#include <array>
#include <vector>
#include <memory>
#include <utility>

const unsigned int boardSize = 8;

class Piece;
class Pawn;

class Chessboard {
    //posibility to do this by std::map<std::pair<int, int>, pointer to an Piece object>
    std::array<std::array<std::unique_ptr<Piece>, boardSize>, boardSize> board; //{nullptr}; vyzkouset alternativa createBoard
    std::array<std::vector<std::unique_ptr<Piece>>, 2> captures; //first vector for WHITE captures, second for BLACK captures
    
private:
    //fills board with nullptr
    void createBoard();
    void createPieces();
    void createPawns();
    void createRooks();
    void createKnights();
    void createBishops();
    void createQueens();
    void createKings();
    //set-ups a piece at x,y location and creates an object using unique_ptr
    void placeOnBoard(const std::pair<int, int> &squareStart, std::unique_ptr<Piece> piece);
    //places a piece on given square(if capture takes place, captured piece is returned via unique_ptr, if piece moves to an empty square, it returns nullptr)
    std::unique_ptr<Piece> setPieceOnSquare(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo);
    
    std::string getTypeToPrint(const std::unique_ptr<Piece> &square) const;
public:
    Chessboard();
    ~Chessboard() = default;
    
    bool isForwardMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    bool isHorizontalMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    bool isVerticalMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    bool isDiagonalMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    bool isKnightMove(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    bool isOnBoard(const std::pair<int, int> &square) const;
    bool isSameColor(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    bool isDifferentColor(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    bool isOccupied(const std::pair<int, int> &square) const;
    bool isPathFree(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    int getMoveLength(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo) const;
    const std::unique_ptr<Piece>& getPiece(const std::pair<int, int> &square) const;
    
    bool movePiece(const std::pair<int, int> &squareFrom, const std::pair<int, int> &squareTo);
    
    //std::vector<std::pair<int, int>> showPossibleMoves(const std::pair<int, int> &square);
    
    void printBoard() const;
};

#endif /* Chessboard_hpp */
