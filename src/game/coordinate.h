#ifndef __COORDINATE_H__
#define __COORDINATE_H__

class Coordinate {
public:
  Coordinate(int rank, int file) : rank_(rank), file_(file) {}

  int get_rank() const { return rank_; }
  int get_file() const { return file_; }

private:
  int rank_;
  int file_;
};

#endif
