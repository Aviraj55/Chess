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
