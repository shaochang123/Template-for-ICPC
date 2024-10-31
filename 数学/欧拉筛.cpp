#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000007
bool isprime[MAXN]; // isprime[i]��ʾi�ǲ�������
int prime[MAXN]; // �����Ѿ�ɸ���������б�
int n; // ���ޣ���ɸ��<=n������
int cnt; // �Ѿ�ɸ������������

void euler()
{
    memset(isprime, true, sizeof(isprime)); // ��ȫ�����Ϊ����
    isprime[1] = false; // 1��������
    for (int i = 2; i <= n; ++i) // i��2ѭ����n�����ѭ����
    {
        if (isprime[i]) prime[++cnt] = i;
        // ���iû�б�ǰ�����ɸ������i������
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)
            // ɸ��i������������i��prime[j]��
            // jѭ��ö�������Ѿ�ɸ�����������ڲ�ѭ����
        {
            isprime[i * prime[j]] = false;
            // �������Ϊ������Ҳ����i��prime[j]��i * prime[j]ɸ����
            if (i % prime[j] == 0) break;
            // �������һ�仰�����i����prime[j]���˳�ѭ��
            // �������Ա�֤���Ե�ʱ�临�Ӷ�
        }
    }
}
int main() {
    n = 100000000;
    euler();
    for (int i = 0; i < cnt; i++)cout << prime[i] <<endl;
    return 0;
}