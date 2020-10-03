#include "pawn.h"

#include "../board.h"

std::vector<Coordinate> Pawn::get_candidate_moves() const {
  std::vector<Coordinate> candidate_moves;

  int dir = color_ == Color::WHITE ? 1 : -1;

  // Pawns may always move one square forward
  std::vector<int> forward_moves(1, 1);
  if (move_history_.empty()) {
    // If this is the first move that this pawn has made, then it may optionally
    // move two squares forward
    forward_moves.push_back(2);
  }
  for (int rank_offset : forward_moves) {
    Coordinate dest(coordinate_.get_rank() + rank_offset * dir,
                    coordinate_.get_file());
    // When moving forward, pawns may be blocked by pieces of either color (and
    // may not capture)
    if (board_->piece_at(dest) == nullptr) {
      candidate_moves.push_back(dest);
    }
  }

  // Pawns may move diagonally one square to capture an enemy piece
  for (int file_offset : {-1, 1}) {
    Coordinate dest(coordinate_.get_rank() + dir,
                    coordinate_.get_file() + file_offset);
    Piece *dest_piece = board_->piece_at(dest);
    if (dest_piece != nullptr && dest_piece->get_color() != color_) {
      candidate_moves.push_back(dest);
    }
  }

  // TODO: Implement en passant

  return candidate_moves;
}
