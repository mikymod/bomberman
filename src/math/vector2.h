#pragma once

#include <math.h>

namespace math
{
    struct Vector2
    {
        float x, y;

        explicit Vector2() : x(0), y(0) {}
        explicit Vector2(float x, float y) : x(x), y(y) {}
        explicit Vector2(float a) : x(a), y(a) {}

        Vector2(const Vector2 &b)
        {
            x = b.x;
            y = b.y;
        }

        Vector2 operator+(const Vector2 &b)
        {
            Vector2 v;
            v.x = this->x + b.x;
            v.y = this->y + b.y;
            return v;
        }

        Vector2 operator+=(const Vector2 &b)
        {
            return *this + b;
        }

        Vector2 operator-(const Vector2 &b)
        {
            Vector2 v;
            v.x = this->x - b.x;
            v.y = this->y - b.y;
            return v;
        }

        Vector2 operator-=(const Vector2 &b)
        {
            return *this - b;
        }

        Vector2 operator*(const float k)
        {
            return Vector2(this->x * k, this->y * k);
        }

        Vector2 operator*=(const float k)
        {
            return *this * k;
        }

        bool operator==(const Vector2 &b)
        {
            return this->x == b.x && this->y == b.y;
        }

        float Dot(const Vector2 &b)
        {
            return this->x * b.x + this->y * b.y;
        }

        float SquaredLength()
        {
            return Dot(*this);
        }

        float Length()
        {
            return sqrt(SquaredLength());
        }

        Vector2 Normalize()
        {
            const float inverse_length = 1.0f / Length();
            return Vector2(this->x * inverse_length, this->y * inverse_length);
        }

        float SquaredDistance(Vector2 b)
        {
            // FIXME: b must be passed by value because operator-
            return (b - *this).SquaredLength();
        }

        float Distance(Vector2 b)
        {
            // FIXME: b must be passed by value because operator-
            return (b - *this).Length();
        }

        float Angle(const Vector2 &b)
        {
            const float len = Length();
            return acos(Dot(b) / (len * len));
        }
    };
} // namespace math