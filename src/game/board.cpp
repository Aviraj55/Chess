#include "board.h"

#include "piece/bishop.h"
#include "piece/king.h"
#include "piece/knight.h"
#include "piece/pawn.h"
#include "piece/piece.h"
#include "piece/queen.h"
#include "piece/rook.h"

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
    board[1][file] = new Pawn(this, Piece::Color::WHITE, Coordinate(1, file));
    // Insert black pawn
    board[HEIGHT - 2][file] =
        new Pawn(this, Piece::Color::BLACK, Coordinate(HEIGHT - 2, file));
  }

  // Insert rooks
  board[0][0] = new Rook(this, Piece::Color::WHITE, Coordinate(0, 0));
  board[0][WIDTH - 1] =
      new Rook(this, Piece::Color::WHITE, Coordinate(0, WIDTH - 1));
  board[HEIGHT - 1][0] =
      new Rook(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 0));
  board[HEIGHT - 1][WIDTH - 1] =
      new Rook(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, WIDTH - 1));

  // Insert knights
  board[0][1] = new Knight(this, Piece::Color::WHITE, Coordinate(0, 1));
  board[0][WIDTH - 2] =
      new Knight(this, Piece::Color::WHITE, Coordinate(0, WIDTH - 2));
  board[HEIGHT - 1][1] =
      new Knight(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 1));
  board[HEIGHT - 1][WIDTH - 2] =
      new Knight(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, WIDTH - 2));

  // Insert bishops
  board[0][2] = new Bishop(this, Piece::Color::WHITE, Coordinate(0, 2));
  board[0][WIDTH - 3] =
      new Bishop(this, Piece::Color::WHITE, Coordinate(0, WIDTH - 3));
  board[HEIGHT - 1][2] =
      new Bishop(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 2));
  board[HEIGHT - 1][WIDTH - 3] =
      new Bishop(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, WIDTH - 3));

  // Insert queens
  board[0][3] = new Queen(this, Piece::Color::WHITE, Coordinate(0, 3));
  board[HEIGHT - 1][3] =
      new Queen(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 3));

  // Insert kings
  board[0][4] = new King(this, Piece::Color::WHITE, Coordinate(0, 4));
  board[HEIGHT - 1][4] =
      new King(this, Piece::Color::BLACK, Coordinate(HEIGHT - 1, 4));
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
