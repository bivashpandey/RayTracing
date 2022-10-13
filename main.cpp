/**
 * This  is the main program for the ray tracing assignment
 * @author: Bivash Pandey
 */

#include <Eigen/Geometry>
#include <iostream>

#include "Image.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Vector.hpp"
#include "Colour.hpp"
#include "Material.hpp"
#include "Light.hpp"
 
// Assign a new name to existing data-types
typedef Eigen::Matrix<float, 3, 1> Vec3;
typedef Eigen::Matrix<float, 2, 1> Vec2;

// Defining objects of the type Colour and Vector
Colour colourObj;
Vector vectorObj;

// width and height of an image
const int WIDTH = 600;
const int HEIGHT = 480;

// specular constant
const int SPECULAR_K = 100;

/**
 * This method returns the nearest distance as well as index of the object hit by a ray
 *
 * @param ray The ray
 * @param spheres The objects in the scene
 * @returns The distance and index of nearest object
 */
Vec2 findNearestObject(Ray ray, std::vector<Sphere> spheres){
    float minDistance = 0.0;
    int objectHit = -1;
    
    // loop through all the objects and check if Ray intersects the object
    for(int i = 0; i < spheres.size(); i++){
        float distance = spheres[i].intersects(ray);
        
        // update the minimum distance and object hit
        if(distance > 0 && (objectHit == -1 || distance < minDistance)){
            minDistance = distance;
            objectHit = i;
        }
    }
    // return the minimum distance and the object index as Vec2
    return Vec2(minDistance, objectHit);
}

/**
 * This method returns the color at hit position
 *
 * @param objHitNum The index of the object hit by a ray
 * @param hitPosition The hit position in Vec3
 * @param normal The normal at hit position
 * @param camera The Camera
 * @param spheres The collections of object in a scene
 * @param light A light source in a scene
 * @returns The color at hit position
 */
cv::Vec3b colorAt(int objHitNum, Vec3 hitPosition, Vec3 normal, Camera camera, std::vector<Sphere> spheres, Light light){
    
    // get the property of an object & store in material variable
    Material material = spheres[objHitNum].getMaterial();
    // variable to store the color of an object
    cv::Vec3b objColor = material.getColour();
    
    // Ambient (ambient value times black color): [K * I]
    cv::Vec3b colour = material.getAmbient() * colourObj.dimBlack();

    // Ray with a hitposition as origin and direction from hit position towards light
    Ray hitPosToLight = Ray(hitPosition, light.getLightPosition() - hitPosition);
    // Vector from hit position to camera
    Vec3 hitPosToCamera = camera.getCameraPosition() - hitPosition;
    
    // Diffuse/Lambertian shading: [I * k * max(0, n.l)]
    colour = colourObj.add(colour, objColor * material.getDiffuse() * fmax(0, vectorObj.dot(normal, hitPosToLight.getDirection())));

    // For Specular Shading using Blinn-Phong Model: [I * k * max(0, n.h)^p]
    Vec3 halfVector = vectorObj.normalize(hitPosToLight.getDirection() + hitPosToCamera);
    colour = colourObj.add(colour, light.getLightColour() * material.getSpecular() * pow(fmax(0, vectorObj.dot(normal, halfVector)), SPECULAR_K));

    return colour;
}

/**
 * This method returns true if the point is in shadow otherwise false
 *
 * @param intersectPoint The point of intersection of ray and a sphere
 * @param objectNum The index of an object in the spheres vector
 * @param spheres All the objects
 * @param light A light
 * @returns true or false
 */
bool isPointInShadow(Vec3 intersectPoint, int objectNum, std::vector<Sphere> spheres, Light light){
    bool inShadow = false;
    
    // position of the light
    Vec3 lightPosition = light.getLightPosition();
    
    // Generate a ray from intersection point to light
    Ray ray = Ray(intersectPoint, lightPosition - intersectPoint);
    
    // loop through each objects and check if a point intersects another object while shooting a Ray to the light
    for(int i = 0; i < spheres.size(); i++){
        if(i != objectNum){
            // this checks if a ray intersected object or not
            float distance = spheres[i].intersects(ray);
            if(distance > 0 ){
                return true;
            }
        }
    }
    return inShadow;
}

/**
 * This method traces the ray
 *
 * @param ray The ray sent by a camera
 * @param camera The Camera object
 * @param spheres The collections of object in a scene
 * @param light A light in a scene
 * @returns The color at a position after calculating all the reflections and stuffs
 */
cv::Vec3b rayTrace(Ray ray, Camera camera, std::vector<Sphere> spheres, Light light) {
    // default color as black
    cv::Vec3b color = colourObj.black();
    
    // store the distance of nearest object hit and the object index
    Vec2 distAndObjHit = findNearestObject(ray, spheres);
    float distanceHit = distAndObjHit(0);
    int objectHit = (int)distAndObjHit(1);
    
    // if no object is hit then return the background color as dimBlack
    if(objectHit == -1){
        return colourObj.dimBlack();
    }
    
    // position where the ray hits sphere
    Vec3 hitPosition = ray.getPointAt(distanceHit);
    
    // normal at the position where ray hits the sphere
    Vec3 hitNormal = spheres[objectHit].getNormalAt(hitPosition);
    
    // accumulate the color at hit position
    color = colourObj.add(color, colorAt(objectHit, hitPosition, hitNormal, camera, spheres, light));
    
    // If the point is in shadow then reduce the intensity of colour by half
    if(isPointInShadow(hitPosition, objectHit, spheres, light)){
        color = color * 0.5;
    }
    
    return color;
}


/**
 * Main function of the program
 */
int main(int argc, const char * argv[]) {
    // Create an blank image of given WIDTH and HEIGHT
    Image image = Image(WIDTH, HEIGHT);

    // aspect ratio
    float aspectRatio = float(WIDTH)/HEIGHT;
    
    // Coordinates of image rectangle
    Vec3 lowerLeftCorner = Vec3(-1, -1, -1);
    Vec3 upperRightCorner = Vec3(1, 1, -1);
    
    // width and height of image rectangle
    int width = upperRightCorner(0) - lowerLeftCorner(0);
    float height = upperRightCorner(1)/aspectRatio - lowerLeftCorner(1)/aspectRatio;
    
    // steps to move horizontally and vertically for next pixel
    float xStep = (float)width / image.cols;
    float yStep = (float)height / image.rows;

    // Object of the type Camera at (0, 0, 0)
    Camera camera = Camera(Vec3(0, 0, 0));
    
    // Properties of each sphere
    Material leftBallProperty = Material(colourObj.green(), 0.05, 0.5, 0.7);
    Material middleBallProperty = Material(colourObj.blue(), 0.05, 1.0, 0.1);
    Material rightBallProperty = Material(colourObj.red(),0.05, 1.0, 1.0);
    Material floorProperty = Material(colourObj.white(), 0.2, 1.0, 0.001);

    // Creating Sphere objects with its position, size and material properties
    Sphere leftBall = Sphere(Vec3(-0.5, -0.1, -1), 0.35, leftBallProperty);
    Sphere middleBall = Sphere(Vec3(0, -0.4, -1), 0.1, middleBallProperty);
    Sphere rightBall = Sphere(Vec3(0.5, -0.1, -1), 0.35, rightBallProperty);
    Sphere floor = Sphere(Vec3(0, -100.5, -1), 100.0, floorProperty);

    // store the Sphere objects into vector/array list
    std::vector<Sphere> spheres;
    spheres.push_back(leftBall);
    spheres.push_back(middleBall);
    spheres.push_back(rightBall);
    spheres.push_back(floor);

    // Creating a light source by defining its position and colour
    Light light = Light(Vec3(-10.0, 10.0, 10.0));
    
    //loop through each pixel of an image
    for(int row = 0; row < image.rows; row++){
        for(int col = 0; col < image.cols; col++){
            // Assign finalColr variable with black colour
            cv::Vec3b finalColour = colourObj.black();
                
            // Pixel position for each row and col
            Vec3 pixelPos = Vec3(lowerLeftCorner(0) + xStep * col, lowerLeftCorner(1) + yStep * row, -1);
            
            // Generate a ray from the fixed camera
            Ray ray = Ray(camera.getCameraPosition(), pixelPos - camera.getCameraPosition());
    
            // Get the final colour after ray tracing
            finalColour = colourObj.add(finalColour, rayTrace(ray, camera, spheres, light));
                
            // Assign the final color to an image (making upside down)
            image(HEIGHT - row - 1, col) = finalColour;
        }
    }
    // display the  image
    image.display();
    return EXIT_SUCCESS;
}

