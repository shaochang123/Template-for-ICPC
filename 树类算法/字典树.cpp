#include<bits/stdc++.h>
using namespace std;
int T,q,n,t[3000005][65],cnt[3000005],idx;
char s[3000005];
int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
} 
void insert(char str[]){
    int p=0,len=strlen(str);
    for(int i=0;i<len;i++){
        int c=getnum(str[i]);
        if(!t[p][c])
            t[p][c]=++idx;
        p=t[p][c];
        cnt[p]++;
    }
}
int find(char str[]){//找以str为前缀的字符串有多少个
    int p=0,len=strlen(str);
    for(int i=0;i<len;i++){
        int c=getnum(str[i]);
        if(!t[p][c])
            return 0;
        p=t[p][c];
    }
    return cnt[p];
}
int main(){
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<=idx;i++)
            for(int j=0;j<=122;j++)
                t[i][j]=0;
        for(int i=0;i<=idx;i++)
            cnt[i]=0;
        idx=0;
        scanf("%d%d",&n,&q);//模式串个数和询问次数
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            insert(s);
        }
        for(int i=1;i<=q;i++){
            scanf("%s",s);
            printf("%d\n",find(s));
        }
    }
    return 0;
}