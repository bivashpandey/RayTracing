/**
 *
 * This files implements the constructors and methods defined in the Ray header file
 * @author: Bivash Pandey
 */

#include "Ray.hpp"

// defining an object of a type Vector
Vector v;

/**
 * This constructor initializes the origin and the normalized direction
 *
 * @param origin The origin of the ray
 * @param direction The direction of the ray
 */
Ray::Ray(Vec3 origin, Vec3 direction){
    this->origin = origin;
    this->direction = v.normalize(direction);
}

/**
 * This method returns the origin of the Ray
 *
 * @return The origin where Ray starts/originates
 */
Vec3 Ray::getOrigin(){
    return origin;
}

/**
 * This method returns the normalized direction as Vec3
 *
 * @return The normalized direction of the Ray
 */
Vec3 Ray::getDirection(){
    return direction;
}

/**
 * This method returns the point at 't' distance from the origin. For the ray, we take positive 't' value
 *
 * @param t a value in floating point
 * @return The point in the Ray at a distance 't' from the origin
 */
Vec3 Ray::getPointAt(float t){
    // Parametric Equation of a line: r(t) = p + t * d; (t > 0)
    return origin + t * direction;
}
