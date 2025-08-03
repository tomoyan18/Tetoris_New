CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf
INCLUDES = -IGame -ITetromino -IBoard

SRC = main.cpp Game/Game.cpp Tetromino/Tetromino.cpp Board/Board.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = tetris

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)