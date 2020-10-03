#ifndef __ROOK_H__
#define __ROOK_H__

#include "piece.h"

class Rook : public Piece {
public:
  Rook(Board *board, Color color, Coordinate coordinate)
      : Piece(board, color, coordinate) {}

  Type get_type() const override { return Type::ROOK; }

  std::vector<Coordinate> get_candidate_moves() const override {
    return get_straight_moves();
  }
};

#endif
