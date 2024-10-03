#include <iostream>
#include <cmath>


#ifndef LINE_H
#define LINE_H


// Point structure
//----------------------------------------------------------------------------------------
struct Point {
    int x;
    int y;

    // Default constructor
    //----------------------------------------------------------------------------------------
    Point() : x(0), y(0) {}

    // Parameterized constructor
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}
};

// Menu enumerator
//----------------------------------------------------------------------------------------
enum Menu {
    TwoPointMethod,
    PointSlopeMethod,
    Exit
};

// Line class
//----------------------------------------------------------------------------------------
class Line {
private:
    Point pointOne;
    Point pointTwo;
    float slope;

public:
    // Default constructor
    Line();

    // Constructor with two points
    Line(Point p1, Point p2);

    // Constructor with a point and a slope
    Line(Point p1, float m);

    // Check if the line is empty
    bool isEmpty() const;

    // Calculate the y-intercept
    float calculateYIntercept() const;

    // Calculate the distance between the two points
    float calculateDistance() const;

    // Calculate the angle between the two points
    float calculateAngle() const;

    // Getters
    Point getPointOne() const;
    Point getPointTwo() const;
    float getSlope() const;

    // Helper methods
    int calculateSlope();
    void calculatePointTwo();
};

// Function prototypes for `Line_Program.cpp`
//----------------------------------------------------------------------------------------
Point getPoint();
float getSlope();
void displayMenu();
Menu getUserChoice();

#endif // LINE_H
