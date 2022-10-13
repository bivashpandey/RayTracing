/**
 *
 * This files implements the methods defined in the Vector header file
 * @author: Bivash Pandey
 *
 */

#include "Vector.hpp"

/**
 * This method returns the normalize vector of a given vector
 *
 * @param vector A Vector
 * @return The normalized vector
 */
Vec3 Vector::normalize(Vec3 vector){
    float magnitude = norm(vector);
    return Vec3(vector(0)/magnitude, vector(1)/magnitude, vector(2)/magnitude);
}

/**
 * This method returns the dot product of two vectors
 *
 * @param vector1 one vector
 * @param vector2 another vector
 * @return The dot product of two vectors
 */
float Vector::dot(Vec3 vector1, Vec3 vector2) {
    return vector1(0) * vector2(0) + vector1(1) * vector2(1) + vector1(2) * vector2(2);
}

/**
 * This method returns cross product of two vectors
 *
 * @param vector1 one vector
 * @param vector2 another vector
 * @return The vector perpendicular to both vector1 and vector2
 */
Vec3 Vector::cross(Vec3 vector1, Vec3 vector2) {
    return Vec3(vector1(1) * vector2(2) - vector1(2) * vector2(1),
                vector1(2) * vector2(0) - vector1(0) * vector2(2),
                vector1(0) * vector2(1) - vector1(1) * vector2(0));
}

/**
 * This method returns the norm of a vector
 *
 * @param vector A Vector
 * @return The norm of a vector
 */
float Vector::norm(Vec3 vector){
    return sqrt(dot(vector, vector));
}
