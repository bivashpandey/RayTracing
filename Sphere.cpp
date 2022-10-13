/**
 * This files implements the constructors and methods defined in the Sphere header file
 * @author: Bivash Pandey
 */

#include "Sphere.hpp"

// Object of the type Vector to access methods of Vector class
Vector vect;

/**
 * This constructor initializes the center, radius, and the material properties of Sphere
 *
 * @param center The centre of sphere
 * @param radius The radius of sphere
 * @param material The material properties of sphere
 */
Sphere::Sphere(Vec3 center, float radius, Material material) {
        this->center = center;
        this->radius = radius;
        this->material = material;
}

/**
 * This method returns the Material properties of a Sphere
 *
 * @return The material properties
 */
Material Sphere::getMaterial(){
    return material;
}

/**
 * This method returns the Colour of a Sphere
 *
 * @return The Colour of a Sphere
 */
cv::Vec3b Sphere::getMaterialColour(){
    return material.getColour();
}

/**
 * This method returns the normal at a point on the sphere
 * Normal always points away from the center of the sphere
 *
 * @param point The point on the sphere
 * @return The normal at a point
 */
Vec3 Sphere::getNormalAt(Vec3 point) {
  return vect.normalize(point - center);
}

/**
 * This method returns the distance from the origin to intersection point of Ray/Sphere
 *
 * @param ray The ray vector
 * @return distance from the origin to intersection point (value of t)
 */
float Sphere::intersects(Ray ray){
    Vec3 r = ray.getDirection();
    Vec3 co = ray.getOrigin() - center;
    
    float a = r.dot(r);
    float b = 2.0 * co.dot(r);
    float c = co.dot(co) - radius * radius;
    float discriminant = b*b - 4*a*c;
    
    // if discriminant is less than 0, ray doesn't intersect Sphere
    if(discriminant < 0){
        return -1.0;
    }
    else{
        return (-b - sqrt(discriminant))/(2*a);
    }
}
