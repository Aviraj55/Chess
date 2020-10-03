#ifndef __PIECE_H__
#define __PIECE_H__

#include "../coordinate.h"
#include <vector>

class Board;

class Piece {
public:
  enum class Color { BLACK, WHITE };
  enum class Type { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

  Piece(Board *board, Color color, Coordinate coordinate)
      : board_(board), color_(color), coordinate_(coordinate) {}

  Color get_color() const { return color_; }
  Coordinate get_coordinate() const { return coordinate_; }
  virtual Type get_type() const = 0;

  virtual std::vector<Coordinate> get_candidate_moves() const = 0;
  std::vector<Coordinate> get_moves() const;

protected:
  Board *board_;
  Color color_;
  Coordinate coordinate_;

  std::vector<Coordinate> move_history_;

  std::vector<Coordinate> get_straight_moves() const;
  std::vector<Coordinate> get_diagonal_moves() const;
};

#endif
