 Check if a Point is Inside a Triangle
Algorithm
Input: Three triangle vertices A, B, C and a point P.

Compute total area of the triangle ABC using:
 
Compute three sub-triangle areas:
A_ABC = (1/2) * | xA (yB - yC) + xB (yC - yA) + xC (yA - yB) |

A1 = Area(PBC),
A2 = Area(APC),
A3 = Area(ABP).
If A1 + A2 + A3 == A_ABC, return "Point is inside".
Otherwise, return "Point is outside".

#include <iostream>
#include <cmath> 

using namespace std;

struct Point {
    double x, y;
};

double area(Point A, Point B, Point C) {
    return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

// Check if point P is inside triangle ABC
bool isInside(Point A, Point B, Point C, Point P) {
    double A1 = area(A, B, C);
    double A2 = area(P, B, C) + area(A, P, C) + area(A, B, P);

    return abs(A1 - A2) < 1e-9; 
}

int main() {
    Point A = {0, 0}, B = {5, 0}, C = {2, 5}, P = {2, 2};
    
    if (isInside(A, B, C, P))
        cout << "Point is inside the triangle\n";
    else
        cout << "Point is outside the triangle\n";
    
    return 0;
}
