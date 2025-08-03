#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

//コンストラクタ
Game::Game(){
    SDL_Init(SDL_INIT_VIDEO);
    //SDL_ttfの初期化
    TTF_Init();

    window = SDL_CreateWindow("Tetoris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 640, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //スコア初期化とフォント読み込み
    score = 0;
    //フォントパスは環境に応じて変更
    font = TTF_OpenFont("./Assets/Fonts/Arial.ttf", 24);

    isRunning = true;
    srand(static_cast<unsigned>(time(0)));
    //最初のミノ生成
    spawnNewTetromino();
    lastDropTime = SDL_GetTicks();
    //ミノが500msごとに自動落下
    dropInterval = 500;
}

Game::~Game(){
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

//新しいランダムなミノを生成
void Game::spawnNewTetromino(){
    current.setType(static_cast<TetrominoType>(rand() % 7));
    current.setPosition(3, 0);
}

void Game::run(){
    while (isRunning)
    {
        processInput();
        update();
        render();
        SDL_Delay(16); //60fps程度
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
        else if(e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym) {
                case SDLK_LEFT:
                    current.move(-1, 0);
                    if (board.isCollision(current)) current.move(1, 0);
                    break;
                case SDLK_RIGHT:
                    current.move(1, 0);
                    if (board.isCollision(current)) current.move(-1, 0);
                    break;
                case SDLK_DOWN:
                    current.move(0, 1);
                    if (board.isCollision(current)) current.move(0, -1);
                    break;
                case SDLK_UP:
                    current.rotate();
                    if (board.isCollision(current)) {
                        // 回転が衝突したら戻す
                        current.rotate(); current.rotate(); current.rotate();
                    }
                    break;
            }
        }
    }
}

void Game::update(){
    Uint32 now = SDL_GetTicks();
    if(now - lastDropTime > dropInterval)
    {
        current.move(0, 1);
        if(board.isCollision(current)){
            current.move(0, -1);
            //固定
            board.fixTetromino(current);
            //ライン消去・スコア加算
            board.clearLines(score);
            //新ミノ
            spawnNewTetromino();
            //ゲームオーバー判定
            if(board.isCollision(current))
            {
                std::cout << "Game Over! Score: " << score << std::endl;
                isRunning = false;
            }
        }
        lastDropTime = now;
    }
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    board.draw(renderer);
    current.draw(renderer);

    //スコア表示
    SDL_Color white = {255, 255, 255};
    std::string scoreText = "Score: " + std::to_string(score);
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText.c_str(), white);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstRect = {10, 10, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);

    SDL_RenderPresent(renderer);
}