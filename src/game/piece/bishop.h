#ifndef __BISHOP_H__
#define __BISHOP_H__

#include "piece.h"

class Bishop : public Piece {
public:
  Bishop(Board *board, Color color, Coordinate coordinate)
      : Piece(board, color, coordinate) {}

  Type get_type() const override { return Type::BISHOP; }

  std::vector<Coordinate> get_candidate_moves() const override {
    return get_diagonal_moves();
  }
};

#endif
