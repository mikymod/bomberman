#pragma once

namespace game
{
    class Cell
    {
        enum Type
        {
            GROUND,
            WALL,
            UNDESTROYABLE_WALL,
            TELEPORT
        };

        Cell() = delete;
        Cell(Type type);
        Cell(const Cell &other);
        Cell &operator=(const Cell &other);
        ~Cell() = default;

    private:
        Type type;
    };

    Cell::Cell(Type type)
        : type(type)
    {
    }

    Cell::Cell(const Cell &other)
    {
        type = other.type;
    }

    Cell &Cell::operator=(const Cell &other)
    {
        type = other.type;
    }
} // namespace game