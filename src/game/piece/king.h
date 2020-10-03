#ifndef __KING_H__
#define __KING_H__

#include "piece.h"

class King : public Piece {
public:
  King(Board *board, Color color, Coordinate coordinate)
      : Piece(board, color, coordinate) {}

  Type get_type() const override { return Type::KING; }

  std::vector<Coordinate> get_candidate_moves() const override;
};

#endif
