#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Exgcd(LL a, LL b, LL& x, LL& y)
{
    
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    LL d = Exgcd(b, a % b, x, y), t = x;
    x = y, y = t - a / b * x;
    return d;
}

int main() {
	LL a, b,x,y;
	cin >> a >> b;
	Exgcd(a, b, x, y);
    x = (x % b + b) % b;
    cout << x;
	return 0;
}