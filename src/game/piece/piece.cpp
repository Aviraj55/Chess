#include "piece.h"

#include "../board.h"

std::vector<Coordinate> Piece::get_moves() const {
  std::vector<Coordinate> candidate_moves = get_candidate_moves();

  std::vector<Coordinate> moves;
  for (const Coordinate &move : candidate_moves) {
    // A piece cannot move off of the board
    if (!board_->contains(move)) {
      continue;
    }

    // A piece cannot move to a square already occupied by a piece of the same
    // color
    Piece *dest_piece = board_->piece_at(move);
    if (dest_piece->color_ == color_) {
      continue;
    }

    // TODO: Prevent moves which put the king in check

    moves.push_back(move);
  }

  return moves;
}
