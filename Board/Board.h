#pragma once
#include <SDL2/SDL.h>
#include "../Tetromino/Tetromino.h"

class Board{
    public:
        static const int WIDTH = 10;
        static const int HEIGHT = 20;
        static const int BLOCK_SIZE = 32;

        Board();
        void draw(SDL_Renderer* renderer);
        //ミノとの衝突
        bool isCollision(const Tetromino& tetromino);
        //ミノを盤面に固定
        void fixTetromino(const Tetromino& tetromino);
        //ラインが揃っていたら消去
        void clearLines(int& score);
        //ゲームオーバー判定
        bool isGameOver();

    private:
        //盤面(20行✖️10列)
        std::vector<std::vector<int>> grid;

};