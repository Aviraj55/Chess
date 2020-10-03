#include "knight.h"

#include "../board.h"

std::vector<Coordinate> Knight::get_candidate_moves() const {
  std::vector<Coordinate> candidate_moves;

  // Possible relative moves for a knight (counterclockwise)
  int rank_offsets[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int file_offsets[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  for (int idx = 0; idx < 8; ++idx) {
    candidate_moves.push_back(
        Coordinate(coordinate_.get_rank() + rank_offsets[idx],
                   coordinate_.get_file() + file_offsets[idx]));
  }

  return candidate_moves;
}
