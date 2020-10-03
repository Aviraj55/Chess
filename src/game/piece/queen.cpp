#include "knight.h"

#include "../board.h"

std::vector<Coordinate> Knight::get_candidate_moves() const {
  std::vector<Coordinate> candidate_moves;
  std::vector<Coordinate> straight_moves(get_straight_moves());
  std::vector<Coordinate> diagonal_moves(get_diagonal_moves());

  candidate_moves.insert(candidate_moves.end(), straight_moves.begin(),
                         straight_moves.end());
  candidate_moves.insert(candidate_moves.end(), diagonal_moves.begin(),
                         diagonal_moves.end());

  return candidate_moves;
}
