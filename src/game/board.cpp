#include "board.h"

#include "piece/piece.h"

Board::Board() {
  board = new Piece **[HEIGHT];
  for (int rank = 0; rank < HEIGHT; ++rank) {
    board[rank] = new Piece *[WIDTH];
    for (int file = 0; file < WIDTH; ++file) {
      board[rank][file] = nullptr;
    }
  }

  // Populate the board with pieces
  for (int file = 0; file < WIDTH; ++file) {
    // Insert white pawn
    board[1][file] = new Pawn(board, Piece::Color::WHITE, Coordinate(1, file));
    // Insert black pawn
    board[HEIGHT - 2][file] = new Pawn(board, Piece::Color::BLACK, Coordinate(HEIGHT - 2, file));
  }

  // Insert rooks
  board[0][0] = new Rook(board, Piece::Color::WHITE, Coordinate(0, 0));
  board[0][WIDTH - 1] = new Rook(board, Piece::Color::WHITE, Coordinate(0, WIDTH - 1));
  baord[HEIGHT - 1][0] = new Rook(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 0));
  board[HEIGHT - 1][WIDTH - 1] = new Rook(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, WIDTH - 1));

  // Insert knights
  board[0][1] = new Knight(board, Piece::Color::WHITE, Coordinate(0, 1));
  board[0][WIDTH - 2] = new Knight(board, Piece::Color::WHITE, Coordinate(0, WIDTH - 2));
  baord[HEIGHT - 1][1] = new Knight(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 1));
  board[HEIGHT - 1][WIDTH - 2] = new Knight(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, WIDTH - 2));

  // Insert bishops
  board[0][2] = new Bishop(board, Piece::Color::WHITE, Coordinate(0, 2));
  board[0][WIDTH - 3] = new Bishop(board, Piece::Color::WHITE, Coordinate(0, WIDTH - 3));
  baord[HEIGHT - 1][2] = new Bishop(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 2));
  board[HEIGHT - 1][WIDTH - 3] = new Bishop(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, WIDTH - 3));

  // Insert queens
  board[0][3] = new Queen(board, Piece::Color::WHITE, Coordinate(0, 3));
  baord[HEIGHT - 1][3] = new Queen(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 3));
  
  // Insert kings
  board[0][4] = new King(board, Piece::Color::WHITE, Coordinate(0, 4));
  baord[HEIGHT - 1][4] = new King(board, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 4));
}

Piece *Board::piece_at(const Coordinate &coordinate) {
  if (!contains(coordinate)) {
    return nullptr;
  }
  return board[coordinate.get_rank()][coordinate.get_file()];
}

const Piece *Board::piece_at(const Coordinate &coordinate) const {
  if (!contains(coordinate)) {
    return nullptr;
  }
  return board[coordinate.get_rank()][coordinate.get_file()];
}
