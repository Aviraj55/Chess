PROGRAM = chess

SRC = src
BIN = bin

GTKMMARGS = `pkg-config gtkmm-3.0 --cflags --libs`
CXXFLAGS = $(GTKMMARGS) -Wall -Wextra -g

# DEFAULT TARGET
build: $(PROGRAM)

# COMPILATION/LINKING
$(PROGRAM): pawn.o piece.o board.o chessWindow.o
	$(CXX) $(CXXFLAGS) $(SRC)/main.cpp $(BIN)/pawn.o $(BIN)/piece.o $(BIN)/board.o $(BIN)/chessWindow.o -o $@

pawn.o: $(SRC)/game/piece/pawn.h $(SRC)/game/piece/pawn.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/game/piece/pawn.cpp -o $(BIN)/pawn.o

piece.o: $(SRC)/game/piece/piece.h $(SRC)/game/piece/piece.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/game/piece/piece.cpp -o $(BIN)/piece.o

board.o: $(SRC)/game/board.h $(SRC)/game/board.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/game/board.cpp -o $(BIN)/board.o

chessWindow.o: $(SRC)/gui/chessWindow.h $(SRC)/gui/chessWindow.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/gui/chessWindow.cpp -o $(BIN)/chessWindow.o

# TASKS
clean:
	rm -f $(PROGRAM) $(BIN)/*.o
