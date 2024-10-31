#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000007
bool isprime[MAXN]; // isprime[i]表示i是不是素数
int prime[MAXN]; // 现在已经筛出的素数列表
int n; // 上限，即筛出<=n的素数
int cnt; // 已经筛出的素数个数

void euler()
{
    memset(isprime, true, sizeof(isprime)); // 先全部标记为素数
    isprime[1] = false; // 1不是素数
    for (int i = 2; i <= n; ++i) // i从2循环到n（外层循环）
    {
        if (isprime[i]) prime[++cnt] = i;
        // 如果i没有被前面的数筛掉，则i是素数
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)
            // 筛掉i的素数倍，即i的prime[j]倍
            // j循环枚举现在已经筛出的素数（内层循环）
        {
            isprime[i * prime[j]] = false;
            // 倍数标记为合数，也就是i用prime[j]把i * prime[j]筛掉了
            if (i % prime[j] == 0) break;
            // 最神奇的一句话，如果i整除prime[j]，退出循环
            // 这样可以保证线性的时间复杂度
        }
    }
}
int main() {
    n = 100000000;
    euler();
    for (int i = 0; i < cnt; i++)cout << prime[i] <<endl;
    return 0;
}