/**
 * This header file  defines the constructors and methods for user defined Vector  class
 * @author: Bivash Pandey
 */

#pragma once
#include <Eigen/Geometry>

//Data types
typedef Eigen::Matrix<float, 3, 1> Vec3;

class Vector{
public:
    // Constructor
    Vector(){};
    
    // Methods for normalization, dot/cross product, and norm
    Vec3 normalize(Vec3 v);
    float dot(Vec3 v1, Vec3 v2);
    Vec3 cross(Vec3 v1, Vec3 v2);
    float norm(Vec3 v);
};

