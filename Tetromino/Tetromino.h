#pragma once
#include <SDL2/SDL.h>

class Tetromino{
    
    public:
        void draw(SDL_Renderer* renderer);
    
    private:
        int x = 3, y = 0;

};