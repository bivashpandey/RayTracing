/**
 *
 * This header file defines the constructors and methods for Ray class
 * @author: Bivash Pandey
 *
 */

#pragma once
#include <Eigen/Geometry>
#include "Vector.hpp"

//Data types
typedef Eigen::Matrix<float, 3, 1> Vec3;

// class
class Ray{

private:
    // Instance variables (attributes)
    Vec3 origin;
    Vec3 direction;
    
public:
    // Constructors
    Ray(){};
    Ray(Vec3 origin, Vec3 direction);
    
    // Methods
    Vec3 getOrigin();
    Vec3 getDirection();
    Vec3 getPointAt(float t);
};
