#ifndef __BOARD_H__
#define __BOARD_H__

#include "coordinate.h"
#include "piece/piece.h"
#include <unordered_map>
#include <unordered_set>

class Board {
public:
  static const int WIDTH = 8;
  static const int HEIGHT = 8;

  friend class Piece;

  Board();
  Board(const Board &b) { copy(b); }
  Board &operator=(const Board &b);
  ~Board() { destroy(); }

  bool contains(const Coordinate &coordinate) const {
    return coordinate.get_rank() >= 0 && coordinate.get_file() >= 0 &&
           coordinate.get_rank() < HEIGHT && coordinate.get_file() < WIDTH;
  }

  Piece *piece_at(const Coordinate &coordinate);
  const Piece *piece_at(const Coordinate &coordinate) const;

private:
  Piece ***board;
  std::unordered_map<Piece::Color, std::unordered_set<Piece *>> pieces_;

  void copy(const Board &b);
  void destroy();

  std::pair<bool, Piece *> in_check() const;
  std::pair<bool, Piece *> checkmated() const;
};

#endif
