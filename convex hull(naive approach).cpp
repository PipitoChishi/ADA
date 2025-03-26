Convex Hull (Naive Approach)
Algorithm
Input: A set of n points in a 2D plane.

If n < 3, print "Convex hull not possible" and return.

For each pair of points (A, B):
Initialize left = 0 and right = 0.

For each other point C in the set:
Compute the cross product to check whether C is on the left or right side of AB.
If C is on the left, increment left.
If C is on the right, increment right.
If left == 0 or right == 0, add A and B to the convex hull.
Remove duplicate points from the convex hull.
Output the convex hull points.



#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

int direction(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Convex Hull (Naive Approach)
void convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull not possible\n";
        return;
    }

    vector<Point> hull;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int left = 0, right = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                int d = direction(points[i], points[j], points[k]);
                if (d > 0) left++;
                else if (d < 0) right++;
            }
            if (left == 0 || right == 0)
                hull.push_back(points[i]);
        }
    }

    cout << "Convex Hull Points:\n";
    for (auto p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";
}

int main() {
    vector<Point> points = {{0, 0}, {2, 2}, {1, 1}, {2, 0}, {3, 3}, {4, 4}, {0, 4}};
    convexHull(points);
    return 0;
}
