PROGRAM = chess

SRC = src
BIN = bin

GTKMMARGS = `pkg-config gtkmm-3.0 --cflags --libs`
CXXFLAGS = $(GTKMMARGS) -Wall -Wextra -g

# DEFAULT TARGET
build: $(PROGRAM)

# COMPILATION/LINKING
$(PROGRAM): pawn.o knight.o queen.o king.o piece.o board.o chessWindow.o
	$(CXX) $(SRC)/main.cpp $(BIN)/pawn.o $(BIN)/knight.o $(BIN)/queen.o $(BIN)/king.o $(BIN)/piece.o $(BIN)/board.o $(BIN)/chessWindow.o $(CXXFLAGS) -o $@

pawn.o: $(SRC)/game/piece/pawn.h $(SRC)/game/piece/pawn.cpp
	$(CXX) -c $(SRC)/game/piece/pawn.cpp $(CXXFLAGS) -o $(BIN)/pawn.o

knight.o: $(SRC)/game/piece/knight.h $(SRC)/game/piece/knight.cpp
	$(CXX) -c $(SRC)/game/piece/knight.cpp $(CXXFLAGS) -o $(BIN)/knight.o

queen.o: $(SRC)/game/piece/queen.h $(SRC)/game/piece/queen.cpp
	$(CXX) -c $(SRC)/game/piece/queen.cpp $(CXXFLAGS) -o $(BIN)/queen.o

king.o: $(SRC)/game/piece/king.h $(SRC)/game/piece/king.cpp
	$(CXX) -c $(SRC)/game/piece/king.cpp $(CXXFLAGS) -o $(BIN)/king.o

piece.o: $(SRC)/game/piece/piece.h $(SRC)/game/piece/piece.cpp
	$(CXX) -c $(SRC)/game/piece/piece.cpp $(CXXFLAGS) -o $(BIN)/piece.o

board.o: $(SRC)/game/board.h $(SRC)/game/board.cpp
	$(CXX) -c $(SRC)/game/board.cpp $(CXXFLAGS) -o $(BIN)/board.o

chessWindow.o: $(SRC)/gui/chessWindow.h $(SRC)/gui/chessWindow.cpp
	$(CXX) -c $(SRC)/gui/chessWindow.cpp $(CXXFLAGS) -o $(BIN)/chessWindow.o

# TASKS
clean:
	rm -f $(PROGRAM) $(BIN)/*.o
