#ifndef __BOARD_H__
#define __BOARD_H__

#include "coordinate.h"

class Piece;

class Board {
public:
  static const int WIDTH = 8;
  static const int HEIGHT = 8;

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

  void copy(const Board &b);
  void destroy();
};

#endif
