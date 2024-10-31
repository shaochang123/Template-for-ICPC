#include<bits/stdc++.h>
using namespace std;
string sec;
int main(){
    cin>>sec;
    int k = 0, i = 0, j = 1,n=sec.length();
    while (k < n && i < n && j < n) {
        if (sec[(i + k) % n] == sec[(j + k) % n]) {
            k++;
        } else {
            sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
    }
    }
    i = min(i, j);
    cout<<i<<endl;
    return 0;
}
