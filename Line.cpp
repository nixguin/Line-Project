#include "Line.h"

// Default constructor
//--------------------------------------------------------------------------------------
Line::Line() : pointOne(Point()), pointTwo(Point()), slope(0.0f) {}

// Property Constructor
//---------------------------------------------------------------------------------------
Line::Line(Point p1, Point p2) : pointOne(p1), pointTwo(p2) {
    calculateSlope();
}
Line::Line(Point p1, float m) : pointOne(p1), slope(m) {
    calculatePointTwo();
}

//Accessor and mutator
//----------------------------------------------------------------------------------------

// Check if the line is empty
bool Line::isEmpty() const {
    return pointOne.x == 0 && pointOne.y == 0 && pointTwo.x == 0 && pointTwo.y == 0;
}

// Calculate the y-intercept
float Line::calculateYIntercept() const {return pointOne.y - (slope * pointOne.x);}

// Calculate the distance between the two points
float Line::calculateDistance() const {
    return sqrt(pow(pointTwo.x - pointOne.x, 2) + pow(pointTwo.y - pointOne.y, 2));}

// Calculate the angle between  two points
float Line::calculateAngle() const {
    return atan2(pointTwo.y - pointOne.y, pointTwo.x - pointOne.x);}

// Getters
//----------------------------------------------------------------------------------------
Point Line::getPointOne() const {return pointOne;}

Point Line::getPointTwo() const {return pointTwo;}

float Line::getSlope() const {return slope;}

// Helper method to calculate slope
int Line::calculateSlope() {
    if (pointTwo.x == pointOne.x) {
        std::cout << "This is going to be a vertical line";
        return 0;
    } else {
        return (pointTwo.y - pointOne.y) / (pointTwo.x - pointOne.x);
    }
}

/**
 * Helper method to calculate
 * pointTwo based on pointOne and slope
 */
void Line::calculatePointTwo() {
    // Assuming pointTwo lies on the x-axis (x2 = 1, arbitrary choice)
    pointTwo.x = 1;
    pointTwo.y = static_cast<int>(pointOne.y + slope * (pointTwo.x - pointOne.x));
}

// asking the user to get all of the inputs
Point getPoint() {
    int x, y;
    std::cout << "Enter x-coordinate: ";
    std::cin >> x;
    std::cout << "Enter y-coordinate: ";
    std::cin >> y;
    return Point(x, y);
}

float getSlope() {
    float slope;
    std::cout << "Enter slope: ";
    std::cin >> slope;
    return slope;
}

/**
 * Displaying the menu for the user to choose between two point,
 * point slope or just to exit
 */
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Two-point method\n";
    std::cout << "2. Point-slope method\n";
    std::cout << "3. Exit\n";
}

//Asking the user for a choice
Menu getUserChoice() {
    int choice;
    std::cout << "Enter choice (1-3): ";
    std::cin >> choice;
    // Validate input
    while (choice < 1 || choice > 3) {
        std::cout << "Invalid choice. Enter choice (1-3): ";
        std::cin >> choice;
    }
    return static_cast<Menu>(choice - 1);
}
