CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
LDFLAGS = `sdl2-config --libs` -lSDL2
INCLUDES = -IGame -ITetromino -IBoard

SRC = main.cpp Game/Game.cpp Tetromino/Tetromino.cpp Board/Board.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = tetris

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
