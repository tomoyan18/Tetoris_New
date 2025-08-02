#include "Game.h"
#include <iostream>

Game::Game() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tetoris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 640, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = true;
    current = Tetromino();
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run(){
    while (isRunning)
    {
        processInput();
        update();
        render();
        SDL_Delay(100); //簡易的な速度調整
    }   
}

void Game::processInput(){
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            isRunning = false;
        }
    }
}

void Game::update(){
    //落下処理など
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    board.draw(renderer);
    current.draw(renderer);
    SDL_RenderPresent(renderer);
}
