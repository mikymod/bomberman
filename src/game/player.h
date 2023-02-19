#pragma once

#include "vector2.h"

using namespace math;

namespace game
{
    class Player
    {
        Player(const Vector2 &pos, const unsigned int speed, const unsigned int numLifes, const unsigned int numBombs);

    private:
        Vector2 position;
        unsigned int speed;
        unsigned int number_of_lifes;
        unsigned int number_of_bombs;
        unsigned int score;
    };
} // namespace game
