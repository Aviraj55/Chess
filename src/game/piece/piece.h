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
  virtual ~Piece() {}

  Color get_color() const { return color_; }
  Coordinate get_coordinate() const { return coordinate_; }
  virtual Type get_type() const = 0;

  const std::vector<Coordinate> &get_move_history() const {
    return move_history_;
  }

  virtual std::vector<Coordinate> get_candidate_moves() const = 0;
  std::vector<Coordinate> get_moves() const;

  void move(const Coordinate &dest);

protected:
  Board *board_;
  Color color_;
  Coordinate coordinate_;

  std::vector<Coordinate> move_history_;

  std::vector<Coordinate> get_straight_moves() const;
  std::vector<Coordinate> get_diagonal_moves() const;
};

#endif
