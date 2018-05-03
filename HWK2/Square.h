//
// Created by DING on 2018/1/30.
//

#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {

public:
    Square(std::string name, float length);
    ~Square(void);
    float GetArea(void);
    void Draw(void);

private:
    float length;
};


#endif //SHAPE_SQUARE_H
