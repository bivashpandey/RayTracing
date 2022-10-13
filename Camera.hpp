/**
 *
 * This header file  defines the constructors and methods for Camera class
 * @author: Bivash Pandey
 */

#pragma once
#include <Eigen/Geometry>

//Data types
typedef Eigen::Matrix<float, 3, 1> Vec3;

class Camera{
    
private:
    // Instance variable
    Vec3 position;
    
public:
    // Constructor
    Camera(Vec3 position);
    
    // Method
    Vec3 getCameraPosition();
};
