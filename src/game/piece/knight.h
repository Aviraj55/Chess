#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "piece.h"

class Knight : public Piece {
public:
  Knight(Board *board, Color color, Coordinate coordinate)
      : Piece(board, color, coordinate) {}

  Type get_type() const override { return Type::KNIGHT; }

  std::vector<Coordinate> get_candidate_moves() const override;
};

#endif
