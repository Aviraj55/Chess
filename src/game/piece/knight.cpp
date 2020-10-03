#include "knight.h"

#include "../board.h"

std::vector<Coordinate> Knight::get_candidate_moves() const {
  std::vector<Coordinate> candidate_moves;

  // Possible relative moves for a knight (counterclockwise)
  int rank_offsets[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int file_offsets[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  for (int rank_offset : rank_offsets) {
    for (int file_offset : file_offsets) {
      candidate_moves.push_back(
          Coordinate(coordinate_.get_rank() + rank_offset,
                     coordinate_.get_file() + file_offset));
    }
  }

  return candidate_moves;
}
