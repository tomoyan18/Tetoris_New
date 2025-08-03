#include "Tetromino.h"
#include <cstdlib>

//①各テトロミノ形状の定義(4✖️4マトリクス)
std::vector<std::vector<std::vector<int>>> tetrominoShape ={

    //I
    {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },

    //O
    {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0,},
        {0, 0, 0, 0}
    },

    //T
    {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },

    //S
    {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },

    //Z
    {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },

    //J
    {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    },

    //L
    {
        {0, 0, 1, 0},
        {1, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

Tetromino::Tetromino(){
    //ランダムに初期化
    setType(static_cast<TetrominoType>(rand() % 7)); 
    //初期位置
    setPosition(3, 0);
}

void Tetromino::setType(TetrominoType t){
    type = t;
    shape = tetrominoShape[t];
}

TetrominoType Tetromino::getType() const {
    return type;
}

void Tetromino::setPosition(int x_, int y_){
    x = x_;
    y = y_;
}

int Tetromino::getX() const { return x; }
int Tetromino::getY() const { return y; }

void Tetromino::move(int dx, int dy){
    x += dx;
    y += dy;
}

const std::vector<std::vector<int>>& Tetromino::getShape() const{
    return shape;
}

void Tetromino::rotate(){
    std::vector<std::vector<int>> rotated(4, std::vector<int>(4));
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            rotated[i][j] = shape[3 - j][i];
        }
    }
    shape = rotated;
}

void Tetromino::draw(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(shape[j][i]){
                SDL_Rect rect = { (x + i) * 32, (y + j) * 32, 31, 31};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}