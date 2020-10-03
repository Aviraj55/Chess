#ifndef __PAWN_H__
#define __PAWN_H__

#include "piece.h"

class Pawn : public Piece {
public:
  Pawn(Board *board, Color color, Coordinate coordinate)
      : Piece(board, color, coordinate) {}

  Type get_type() const override { return Type::PAWN; }

  std::vector<Coordinate> get_candidate_moves() const override;
};

#endif
