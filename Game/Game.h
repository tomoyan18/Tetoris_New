// Game.h
#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Board.h"
#include "Tetromino.h"
#include <deque>
#include <random>

// ★追加: ゲーム状態の定義（タイトル、プレイ中、ゲームオーバー）
enum class GameState {
    TITLE,
    PLAYING,
    GAMEOVER
};

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    bool isRunning;

    GameState state; // ★追加: 現在のゲーム状態

    Board board;
    Tetromino current;

    Uint32 lastDropTime;
    Uint32 dropInterval;

    int score;

    std::deque<TetrominoType> nextBag; // ★追加: 次のミノを管理する7バッグ方式
    std::mt19937 rng; // ★追加: 乱数生成器

    void processInput();
    void update();
    void render();

    void renderTitle(); // ★追加: タイトル画面描画
    void renderGameOver(); // ★追加: ゲームオーバー画面描画

    void spawnNewTetromino();
    void resetGame();
    void fillNextBag(); // ★追加: 7種のテトロミノをシャッフルしてバッグに追加
};