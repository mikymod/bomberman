#include "vector2.h"

using namespace math;

namespace game
{
    class Bomb
    {
    public:
        Bomb() = delete;
        Bomb(const Vector2 position, const unsigned int range, const unsigned int cooldown);
        Bomb(const Bomb &other);
        Bomb &operator=(const Bomb &other);
        ~Bomb() = default;

    private:
        Vector2 position;
        unsigned int range;
        unsigned int cooldown;
    };

    Bomb::Bomb(const Vector2 position, const unsigned int range, const unsigned int cooldown)
        : position(position),
          range(range),
          cooldown(cooldown)
    {
    }

    Bomb::Bomb(const Bomb &other)
    {
        position = other.position;
        range = other.range;
        cooldown = other.cooldown;
    }

    Bomb &Bomb::operator=(const Bomb &other)
    {
        position = other.position;
        range = other.range;
        cooldown = other.cooldown;
    }
}