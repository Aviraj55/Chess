#include "piece.h"

#include "../board.h"

std::vector<Coordinate> Piece::get_moves() const {
  std::vector<Coordinate> candidate_moves = get_candidate_moves();

  std::vector<Coordinate> moves;
  for (const Coordinate &move : candidate_moves) {
    // A piece cannot move off of the board
    if (!board_->contains(move)) {
      continue;
    }

    // A piece cannot move to a square already occupied by a piece of the same
    // color
    Piece *dest_piece = board_->piece_at(move);
    if (dest_piece->color_ == color_) {
      continue;
    }

    // Prevent moves which put the king in check
    Board candidate_board(*board_);
    candidate_board.piece_at(get_coordinate())->move(move);
    if (candidate_board.in_check().second->color_ == color_) {
      continue;
    }

    moves.push_back(move);
  }

  return moves;
}

void Piece::move(const Coordinate &dest) {
  board_->board[coordinate_.get_rank()][coordinate_.get_file()] = nullptr;
  board_->pieces_[color_].erase(
      board_->board[dest.get_rank()][dest.get_file()]);
  delete board_->board[dest.get_rank()][dest.get_file()];
  board_->board[dest.get_rank()][dest.get_file()] = this;

  move_history_.push_back(dest);
}

std::vector<Coordinate> Piece::get_straight_moves() const {
  std::vector<Coordinate> straight_moves;
  std::vector<std::vector<int>> dirs{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  for (const std::vector<int> &dir : dirs) {
    Coordinate dest(coordinate_.get_rank() + dir[0],
                    coordinate_.get_file() + dir[1]);
    for (; board_->contains(dest) && board_->piece_at(dest) == nullptr;
         dest =
             Coordinate(dest.get_rank() + dir[0], dest.get_file() + dir[1])) {
      straight_moves.push_back(dest);
    }
  }

  return straight_moves;
}

std::vector<Coordinate> Piece::get_diagonal_moves() const {
  std::vector<Coordinate> diagonal_moves;
  std::vector<std::vector<int>> dirs{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
  for (const std::vector<int> &dir : dirs) {
    Coordinate dest(coordinate_.get_rank() + dir[0],
                    coordinate_.get_file() + dir[1]);
    for (; board_->contains(dest) && board_->piece_at(dest) == nullptr;
         dest =
             Coordinate(dest.get_rank() + dir[0], dest.get_file() + dir[1])) {
      diagonal_moves.push_back(dest);
    }
  }

  return diagonal_moves;
}
