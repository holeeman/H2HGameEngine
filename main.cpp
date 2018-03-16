#include <iostream>
#include "vector2.h"
int main()
{
    Vec2 vect(5, 5);
    Vec2 vect2(10, 0);
    
    // length
    std::cout<<vect.length()<<"\n";
    
    // angle
    std::cout<<vect.angle(vect2)<<"\n";
    
    // unit vector
    std::cout<<"{"<<vect.getUnitVec().getX()<<","<<vect.getUnitVec().getY()<<"}\n";
    
    // scale
    vect.scale(2, 2);
    std::cout<<"{"<<vect.getX()<<","<<vect.getY()<<"}\n";
    
    // get perpendicular vector
    std::cout<<"{"<<vect.getPerpen().getX()<<","<<vect.getPerpen().getY()<<"}\n";
    std::cout<<vect.angle(vect.getPerpen())<<"\n";
    
    return 0;
}
