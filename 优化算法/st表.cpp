#include<bits/stdc++.h>
using namespace std;
int f[100006][66],n,a[100007],q;//f[i][j]表示区间[i,i+pow(2,j)-1]的最大值
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)f[i][0]=a[i];
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<17;j++){
            if(i+(1<<j)-1<n)f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int s=__lg(r-l+1);
        printf("%d\n",max(f[l][s],f[r-(1<<s)+1][s]));
    }
    return 0;
}