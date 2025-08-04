#include "Board.h"
#include <iostream>

Board::Board(){
    //盤面の初期化(全て０)
    grid = std::vector<std::vector<int>>(HEIGHT, std::vector<int>(WIDTH, 0));
}

//ミノを描画
void Board::draw(SDL_Renderer* renderer){
    for(int y = 0; y < HEIGHT; ++y){
        for(int x = 0; x < WIDTH; ++x){
            if(grid[y][x] != 0){
                SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255);
                SDL_Rect rect = { x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }
}

//衝突判定(ミノと盤面・壁との接触)
bool Board::isCollision(const Tetromino& tetromino){
    const auto& shape = tetromino.getShape();
    int x = tetromino.getX();
    int y = tetromino.getY();

    for(int j = 0; j < 4; ++j){
        for(int i = 0; i < 4; ++i){
            if(shape[j][i]){
                int boardX = x + i;
                int boardY = y + j;

                //境界をチェック
                if(boardX < 0 || boardX >= WIDTH || boardY >= HEIGHT){
                    return true;
                }

                //盤面のブロックと衝突
                if(boardY >= 0 && grid[boardY][boardX] != 0){
                    return true;
                }
            }
        }
    }

    return false;
}

//ミノを盤面に固定
void Board::fixTetromino(const Tetromino& tetromino){
    const auto& shape = tetromino.getShape();
    int x = tetromino.getX();
    int y = tetromino.getY();

    for(int j = 0; j < 4; ++j){
        for(int i = 0; i < 4; ++i){
            if(shape[j][i]){
                int boardX = x + i;
                int boardY = y + j;
                if(boardY >= 0 && boardY < HEIGHT && boardX >= 0 && boardX < WIDTH){
                    grid[boardY][boardX] = 1;
                }
            }
        }
    }
}

//行が揃っていれば削除し、スコアを加算
void Board::clearLines(int& score){
    for(int y = HEIGHT - 1; y >= 0; --y){
        bool full = true;
        for(int x = 0; x < WIDTH; ++x){
            if(grid[y][x] == 0){
                full = false;
                break;
            }
        }

        if(full){
            //ライン削除：上に詰める
            for(int row = y; row > 0; --row){
                grid[row] = grid[row - 1];
            }
            grid[0] = std::vector<int>(WIDTH, 0);
            //スコア加算(１行１点)
            score += 10;
            //詰めた分を再確認する
            ++y;
        }

    }
}

//最上段にブロックがある場合はゲームオーバー
bool Board::isGameOver(){
    for(int x = 0; x < WIDTH; ++x){
        if(grid[0][x] != 0){
            return true;
        }
    }
    
    return false;

}