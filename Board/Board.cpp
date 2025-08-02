#include "Board.h"

void Board::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
    for(int i = 0; i < WIDTH; ++i){
        for(int j = 0; j < HEIGHT; ++j){
            SDL_Rect rect = { i * BLOCK_SIZE, j * BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1 };
            SDL_RenderDrawRect(renderer, &rect);
        }
    }
}