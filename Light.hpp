/**
 *
 * This header file  defines the constructors and methods for Light class
 * @author: Bivash Pandey
 *
 */

#pragma once
#include <Eigen/Geometry>
#include "Image.hpp"

//Data types
typedef Eigen::Matrix<float, 3, 1> Vec3;

class Light{
    
private:
    // Instance variables
    Vec3 position;
    cv::Vec3b colour;
    
public:
    // Constructors
    Light(){};
    Light(Vec3 p);
    Light(Vec3 position, cv::Vec3b colour);
    
    // Methods
    Vec3 getLightPosition();
    cv::Vec3b getLightColour();
};
