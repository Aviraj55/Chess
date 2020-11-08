#include "king.h"

#include "../board.h"

std::vector<Coordinate> King::get_candidate_moves() const {
  std::vector<Coordinate> candidate_moves;

  // Possible relative moves for a king
  for (int rank_offset = -1; rank_offset <= 1; ++rank_offset) {
    for (int file_offset = -1; file_offset <= 1; ++file_offset) {
      if (rank_offset == 0 && file_offset == 0) {
        continue;
      }
      candidate_moves.push_back(
          Coordinate(coordinate_.get_rank() + rank_offset,
                     coordinate_.get_file() + file_offset));
    }
  }

  // Add castling moves
  if (move_history_.empty()) {
    for (int rook_file : {0, Board::WIDTH - 1}) {
      Piece *rook =
          board_->piece_at(Coordinate(coordinate_.get_rank(), rook_file));
      if (rook != nullptr && rook->get_type() == Piece::Type::ROOK &&
          rook->get_move_history().empty()) {
        int dir = rook_file < coordinate_.get_file() ? 1 : -1;
        bool blocked = false;
        for (int file = coordinate_.get_file() + dir;
             file != rook_file && !blocked; file += dir) {
          if (board_->piece_at(Coordinate(coordinate_.get_rank(), file)) !=
              nullptr) {
            blocked = true;
          }
        }
        if (blocked) {
          continue;
        }

        bool through_check = board_->in_check().second == this;
        for (int file_offset = 1; file_offset <= 2 && !through_check;
             ++file_offset) {
          Board candidate_board(*board_);
          candidate_board.piece_at(get_coordinate())
              ->move(Coordinate(coordinate_.get_rank(),
                                coordinate_.get_file() + dir * file_offset));
          Piece *king_in_check = candidate_board.in_check().second;
          if (king_in_check != nullptr &&
              king_in_check->get_color() == color_) {
            through_check = true;
          }
        }
        if (through_check) {
          continue;
        }

        candidate_moves.push_back(Coordinate(
            coordinate_.get_rank(), coordinate_.get_file() + (2 * dir)));
      }
    }
  }

  return candidate_moves;
}
