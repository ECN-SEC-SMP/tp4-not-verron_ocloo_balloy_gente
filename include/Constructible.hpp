#pragma once

class Constructible
{
public:
    Constructible() = default;
    ~Constructible() = default;
    virtual float surfaceConstructible() const = 0;
};