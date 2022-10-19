#include <iostream>

using namespace std;

int fun(int x = 0, int y = 1, int z=0) {
    return (x + y + z);
}

double fun(double x = 0.0, double y = 1.0) {
    return (x + y);
}


int main() {
    cout << fun(10, 1, 0);
    cout << fun(20.4, 30.4);
    return 0;
}