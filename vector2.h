//
//  vector2.hpp
//  
//
//  Created by LeeHosung on 3/15/18.
//

#ifndef vector2_hpp
#define vector2_hpp

#include <cmath>
#include <algorithm>
#include <iostream>

class Vec2
{
public:
    Vec2(float x, float y) {
        _x = x;
        _y = y;
    }
    
    float dotProduct(Vec2 other) {
        return _x * other.getX() + _y * other.getY();
    }
    
    float angle(Vec2 other) {
        return acos(dotProduct(other) / ((length() * other.length()))) / M_PI * 180;
    }
    
    float length() {
        return sqrt((_x * _x) + (_y * _y));
    }
    
    void scale(float scaleX, float scaleY) {
        _x *= scaleX;
        _y *= scaleY;
    }
    
    void rotate(Vec2 point, float degree) {
        float dist = sqrt((point.getX() - _x) * (point.getX() - _x) + (point.getY() - _y) * (point.getY() - _y));
        float angle = degree / 180 * M_PI;
        _x = dist * cos(angle);
        _y = dist * sin(angle);
    }
    
    float getX() {
        return _x;
    }
    
    float getY() {
        return _y;
    }
    
    Vec2 getUnitVec() {
        float l = length();
        return Vec2(_x/l, _y/l);
    }
    
    void set(float newX, float newY) {
        _x = newX;
        _y = newY;
    }
    
    float normalize() {
        return 0.0;
    }
    
    Vec2 getPerpen() {
        float l = length();
        return Vec2(l * cos(M_PI/2), l * sin(M_PI/2));
    }

private:
    float _x, _y;
};

#endif /* vector2_hpp */
