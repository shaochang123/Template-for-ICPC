#include<iostream>
using namespace std;
#define maxn INT_MAX
long long fastPower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = result * base % maxn;
        }
        power >>= 1;
        base = (base * base) % maxn;
    }
    return result;
}
int main() {
    long long a, b;
    cin >> a >> b;
    cout << fastPower(a, b);
    return 0;
}