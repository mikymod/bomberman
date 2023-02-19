#include "player.h"

namespace game
{
    Player::Player(const Vector2 &pos, const unsigned int speed, const unsigned int numLifes, const unsigned int numBombs)
        : position(pos),
          speed(speed),
          number_of_lifes(numLifes),
          number_of_bombs(numBombs)
    {
    }

} // namespace game