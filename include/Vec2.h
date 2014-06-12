#ifndef VEC2_H
#define VEC2_H

struct Vec2 {
public:
    char x;
    char y;
    Vec2(char x, char y) {
        this->x = x;
        this->y = y;
    }
    Vec2() {
        this->x = 0;
        this->y = 0;
    }
};

#endif
