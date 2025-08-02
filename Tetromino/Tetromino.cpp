#include "Tetromino.h"

void Tetromino::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_Rect block = { x * 32, y * 32, 32 - 1, 32 - 1};
    SDL_RenderFillRect(renderer, &block);
}