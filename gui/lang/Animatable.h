#pragma once
class Animatable {
public:
    virtual void advance() = 0;
    virtual ~Animatable() {};
};

