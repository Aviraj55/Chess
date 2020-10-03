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

  return candidate_moves;
}
