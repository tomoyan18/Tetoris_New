#pragma once
#include <SDL2/SDL.h>
#include "../Board/Board.h"
#include "../Tetromino/Tetromino.h"

class Game {
    public:
        Game();
        ~Game();
        void run();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;

        Board board;
        Tetromino current;

        void processInput();
        void update();
        void render();

};