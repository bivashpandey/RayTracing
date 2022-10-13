/**
 *
 * This header file  defines the constructors and methods for Sphere class
 * @author: Bivash Pandey
 *
 */

#pragma once
#include <Eigen/Geometry>
#include "Ray.hpp"
#include "Material.hpp"
#include "Vector.hpp"

// data types
typedef Eigen::Matrix<float, 3, 1> Vec3;
typedef Eigen::Matrix<float, 2, 1> Vec2;

class Sphere {
    
private:
    // Instance variables
    Vec3 center;
    float radius;
    Material material;
    
public:
    // Constructors
    Sphere() {};
    Sphere(Vec3 c, float r, Material m);
    
    // Methods
    float intersects(Ray ray);
    Material getMaterial();
    cv::Vec3b getMaterialColour();
    Vec3 getNormalAt(Vec3 point);
};
