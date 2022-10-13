/**
 *
 * This header file  defines the constructors and functions for Material class
 * This class holds the properties of material like colour, ambient, diffuse, specular,
 * and reflection value
 * @author: Bivash Pandey
 *
 */

#pragma once
#include <Eigen/Geometry>
#include "Image.hpp"

//Data types
typedef Eigen::Matrix<float, 3, 1> Vec3;

class Material{

private:
    // Instance variables
    cv::Vec3b materialColour;
    float ambient;
    float diffuse;
    float specular;
    
public:
    // Constructors
    Material(){};
    Material(cv::Vec3b colr, float amb, float diff, float spec);
    
    // Methods
    float getAmbient();
    float getDiffuse();
    float getSpecular();
    cv::Vec3b getColour();
    void setColour(cv::Vec3b newColour);
};
