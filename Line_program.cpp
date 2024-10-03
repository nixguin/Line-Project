// Line_Program.cpp
// COP 2006 Summer 2024
// Tony Nguyen
// The use of line calculation asking the user for x1, y1, x2, y2 points
// and then calculating the slope, y-intercept, calculating the angle, distance of the angle,
// and basing off if they want a two-point method or a point-slope method.
//---------------------------------------------------------------------------------------------------------

#include "Line.h"
#include <iostream>

int main() {
    Line line;
    bool running = true;

    //going into a loop of runnign the program until user choose to exit
    while (running) {
        displayMenu();
        Menu choice = getUserChoice();

        switch (choice) {
            case TwoPointMethod: {
                std::cout << "Two-point method selected.\n";
                Point p1 = getPoint();
                Point p2 = getPoint();
                line = Line(p1, p2);
                std::cout << "Line created using two-point method.\n";
                break;
            }
            case PointSlopeMethod: {
                std::cout << "Point-slope method selected.\n";
                Point p = getPoint();
                float m = getSlope();
                line = Line(p, m);
                std::cout << "Line created using point-slope method.\n";
                break;
            }
            case Exit: {
                running = false;
                std::cout << "Exiting the program.\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }


        //outputting the user defined points and they're answers
        if (!line.isEmpty()) {
            std::cout << "\nLine Calculating:\n";
            std::cout << "Point 1: (" << line.getPointOne().x << ", "
            << line.getPointOne().y << ")\n";
            std::cout << "Point 2: (" << line.getPointTwo().x << ", "
            << line.getPointTwo().y << ")\n";
            std::cout << "Slope: " << line.getSlope() << "\n";
            std::cout << "Y-Intercept: " << line.calculateYIntercept()
            << "\n";
            std::cout << "Distance between points: " << line.calculateDistance()
            << "\n";
            std::cout << "Angle of the line: " << line.calculateAngle()
            << " radians\n";
        }
    }

    return 0;
}
