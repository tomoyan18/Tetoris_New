#pragma once
#include <SDL2/SDL.h>
#include <vector>

enum TetrominoType { I, O, T, S, Z, J, L};

class Tetromino{
    
    public:
        Tetromino();
        void rotate(); 
        void move(int dx, int dy);
        void draw(SDL_Renderer* renderer);
        void setPosition(int x, int y);
        void setType(TetrominoType type);
        TetrominoType getType() const;
        const std::vector<std::vector<int>>& getShape() const;
        int getX() const;
        int getY() const;
        
    private:
        int x, y;
        TetrominoType type;
        std::vector<std::vector<int>> shape;
        void initShape();
};