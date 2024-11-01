#include<iostream>
#include<vector>
using namespace std;

struct Point {
    double x, y;
};

double calculateArea(vector<Point>& polygon) {
    double area = 0;
    int j = polygon.size() - 1;
    for (int i = 0; i < polygon.size(); i++) {
        area += (polygon[j].x + polygon[i].x) * (polygon[j].y - polygon[i].y);
        j = i;
    }
    return abs(area*1.0/ 2);
}

int main() {
    int n;
    cin >> n;
    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }
    cout << calculateArea(polygon) << endl;
    return 0;
}
