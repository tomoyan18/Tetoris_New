#pragma once
#include <SDL2/SDL.h>

class Board{
    public:
        static const int WIDTH = 10;
        static const int HEIGHT = 20;
        static const int BLOCK_SIZE = 32;

        void draw(SDL_Renderer* renderer);

};