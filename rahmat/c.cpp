#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct Point {
    int x;
    int y;

    // Overloading the equality operator
    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }
};

// Function to check if a point lies on a segment
// bool onSegment(Point p, Point q, Point r) {
//     if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
//         q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
//         return true;

//     return false;
// }

// Determine orientation of triplet (p, q, r)
int orientation(Point p, Point q, Point r) {
    ll val = (ll)(q.y - p.y) * (ll)(r.x - q.x) - (ll)(q.x - p.x) * (ll)(r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Check if line segments 'p1q1' and 'p2q2' intersect, excluding endpoints
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    
    if(p1 == p2 || q1 == q2 || p1 == q2 || q1 == p2) return false;
    
    // General case
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // Check if segments properly intersect internally
    if (o1 != o2 && o3 != o4)
        return true;

    // Check for collinearity and overlapping cases
    // if (o1 == 0 && onSegment(p1, p2, q1)) return false;  // p2 lies on p1q1
    // if (o2 == 0 && onSegment(p1, q2, q1)) return false;  // q2 lies on p1q1
    // if (o3 == 0 && onSegment(p2, p1, q2)) return false;  // p1 lies on p2q2
    // if (o4 == 0 && onSegment(p2, q1, q2)) return false;  // q1 lies on p2q2

    return false; // Segments don't intersect
}

void Main() {
    int n;
    cin >> n;
    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<pair<Point, Point>> segments;

    // Create all segments
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            segments.push_back({points[i], points[j]});
        }
    }

    int nonCrossingCount = 0;
    // for (auto& segment : segments) {
    //     bool isNonCrossing = true;
    //     for (auto& otherSegment : segments) {
    //         if (segment == otherSegment) continue;
    //         if (doIntersect(segment.first, segment.second, otherSegment.first, otherSegment.second)) {
    //             isNonCrossing = false;
    //             break;
    //         }
    //     }
    // }

    const int segmentSize = segments.size();
    vector<bool> crossed(segmentSize, 0);
    for (int i = 0; i < segmentSize; ++i) {
        if(crossed[i]) continue;
        bool isNonCrossing = true;
        for (int j = 0; j < segmentSize; ++j) {
            if(i == j) continue;
            if (doIntersect(segments[i].first, segments[i].second, segments[j].first, segments[j].second)) {
                crossed[i] = crossed[j] = 1;
                isNonCrossing = false;
                break;
            }
        }
        if (isNonCrossing) nonCrossingCount++;
    }
    
    cout << nonCrossingCount << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Main();
    return 0;
}
