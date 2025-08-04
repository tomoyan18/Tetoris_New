#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../Board/Board.h"
#include "../Tetromino/Tetromino.h"

enum class GameState{
    TITLE,
    PLAYING,
    GAMEOVER
};

class Game {
    public:
        Game();
        ~Game();
        //メインループ
        void run();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;

        //状態管理
        GameState state;

        //スコア用フォントと変数
        TTF_Font* font;
        int score;

        //ゲーム内構成
        Board board;
        Tetromino current;

        //自動落下の時間制御
        Uint32 lastDropTime;
        //落下間隔（ms）
        Uint32 dropInterval;

        //入力処理(←→↑↓)回転
        void processInput();
        //落下処理・固定・次ミノ生成
        void update();
        //描画(盤面・ミノ・スコア)
        void render();

        //ランダムな新しいミノ生成
        void spawnNewTetromino();

        //状態別描画/更新
        void renderTitle();
        void renderGameOver();
        //リトライ処理
        void resetGame();
};