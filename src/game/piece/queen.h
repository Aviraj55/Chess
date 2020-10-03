#ifndef __QUEEN_H__
#define __QUEEN_H__

#include "piece.h"

class Queen : public Piece {
public:
  Queen(Board *board, Color color, Coordinate coordinate)
      : Piece(board, color, coordinate) {}

  Type get_type() const override { return Type::QUEEN; }

  std::vector<Coordinate> get_candidate_moves() const override;
};

#endif
