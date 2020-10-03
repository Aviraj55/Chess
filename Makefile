SRC = src
BIN = bin

GTKMM_ARGS = `pkg-config gtkmm-3.0 --cflags --libs`
C_FLAGS = -Wall -Wextra -g
ARGS = $(C_FLAGS) $(GTKMM_ARGS)

# COMPILATION/LINKING
main: piece pawn board
	g++ $(ARGS) $(SRC)/main.cpp $(BIN)/piece.o $(BIN)/pawn.o $(BIN)/board.o -o chess.out

piece:
	g++ $(ARGS) -c $(SRC)/game/piece/piece.cpp -o $(BIN)/piece.o

pawn:
	g++ $(ARGS) -c $(SRC)/game/piece/pawn.cpp -o $(BIN)/pawn.o

board:
	g++ $(ARGS) -c $(SRC)/game/board.cpp -o $(BIN)/board.o

# TASKS
clean:
	rm -f $(BIN)/*.o

build: clean main
