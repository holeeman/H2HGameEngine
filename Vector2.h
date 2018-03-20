//
//  Header.h
//  vector2.h
//
//  Created by Heran Gao on 3/20/18.
//  Copyright © 2018 Heran.Gao. All rights reserved.
//

#ifndef VECTOR_2_H
#define VECTOR_2_H
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
    Vec2(const Vec2& other) {
        _x = other.getX();
        _y = other.getY();
    }
    Vec2() {
        
    }
    float dotProduct(const Vec2& other)const {
        return _x * other.getX() + _y * other.getY();
    }
    float crossProduct(const Vec2& other) const {
        return _x*other.getY()-_y*other.getX();
    }
    float getAngleDegree(const Vec2&other) const{
        return acos(dotProduct(other) / ((length() * other.length()))) / M_PI * 180;
    }
    float getgetAngleRadians(const Vec2 &other) const{
        return acos(dotProduct(other) / ((length() * other.length())));
    }
    
    float length()const{
        return sqrt((_x * _x) + (_y * _y));
    }
    
    void scale(float scaleX, float scaleY) {
        _x *= scaleX;
        _y *= scaleY;
    }
    void scale(float scale) {
        _x *= scale;
        _y *= scale;
    }
    
    void rotate(Vec2 point, float degree) {
        float dist = sqrt((point.getX() - _x) * (point.getX() - _x) + (point.getY() - _y) * (point.getY() - _y));
        float angle = degree / 180 * M_PI;
        _x = dist * cos(angle);
        _y = dist * sin(angle);
    }
    
    float getX() const {
        return _x;
    }
    
    float getY() const {
        return _y;
    }
    
    Vec2 getUnitVec()const{
        float l = length();
        return Vec2(_x/l, _y/l);
    }
    
    void set(float newX, float newY) {
        _x = newX;
        _y = newY;
    }
    
    Vec2 normalize() {
        float l = length();
        return Vec2(_x/l, _y/l);
    }
    
    Vec2 getPerpen() const {
        return Vec2(-_y, _x);
    }
    
    Vec2 getMidPoint(Vec2 other) const{
        return Vec2((other.getX() + _x)/2, (other.getY() + _y)/2);
    }
    
    float getScaleProjection(const Vec2& other) const{
        return length()*cos(getgetAngleRadians(other));
    }
    Vec2 getVectorEqualToThis() {
        return Vec2(_x,_y);
    }
    
    Vec2 getVectorProjection(const Vec2& other) {
        Vec2 vec = other.getUnitVec();
        vec.scale(getScaleProjection(other));
        return vec;
    }
    
    bool equal(const Vec2& other ) {
        return other.getX() == _x && other.getY() == _y;
    }
    
    inline bool operator == (const Vec2& other) {
        return equal(other);
    }
    inline bool operator != (const Vec2& other) {
        return !equal(other);
    }
    
    //"^" is the symbol for dot product
    inline float operator ^ (const  Vec2& other) {
        return dotProduct(other);
    }
    
    inline float operator * (const Vec2& other) {
        return crossProduct(other);
    }
    
    inline Vec2 operator * (float ratio) {
        Vec2 v = getVectorEqualToThis();
        v.scale(ratio);
        return v;
    }
    
    inline Vec2& operator *= (float ratio) {
        scale(ratio);
        return *this;
    }
    
    inline Vec2 operator / (float ratio) {
        Vec2 v = getVectorEqualToThis();
        v.scale(1.0/ratio);
        return v;
    }
    
    inline Vec2& operator /= (float ratio) {
        scale(1.0/ratio);
        return *this;
    }
    
    inline Vec2 operator + (const Vec2& other) {
        return Vec2(_x+other.getX(),_y+other.getY());
    }
    
    inline Vec2& operator += (const Vec2& other) {
        _x+=other.getX();
        _y+=other.getY();
        return *this;
    }
    
    inline Vec2 operator - (const Vec2& other) {
        return Vec2(_x-other.getX(),_y-other.getY());
    }
    
    inline Vec2& operator -= (const Vec2& other) {
        _x-=other.getX();
        _y-=other.getY();
        return *this;
    }
    
private:
    float _x, _y;
};

#endif /* VECTOR_2_H */
