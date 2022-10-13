/**
 *
 * This header file  defines the constructors and methods for Colour class
 * @author: Bivash Pandey
 *
 */

#pragma once
#include <Eigen/Geometry>
#include "Image.hpp"

//Data types
typedef Eigen::Matrix<float, 3, 1> Vec3;
typedef Eigen::Matrix<float, 2, 1> Vec2;

class Colour{
public:
    // Constructor
    Colour(){};
    
    // Methods
    int clamp(int color);
    cv::Vec3b red();
    cv::Vec3b green();
    cv::Vec3b blue();
    cv::Vec3b white();
    cv::Vec3b black();
    cv::Vec3b dimBlack();
    cv::Vec3b ambient();
    cv::Vec3b diffuse();
    cv::Vec3b add(cv::Vec3b col1, cv::Vec3b col2);
    cv::Vec3b mul(cv::Vec3b col, float s);
};

