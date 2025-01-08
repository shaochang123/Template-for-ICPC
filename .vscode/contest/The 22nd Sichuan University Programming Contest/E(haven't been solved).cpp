#include<bits/stdc++.h>
using namespace std;
int m[6][4]={//f,b,l,r,u,d
    1,1,1,1,
    2,2,2,2,
    3,3,3,3,
    4,4,4,4,
    5,5,5,5,
    6,6,6,6,
};
void u(){
    int op[]={0,3,1,2},x=m[op[0]][0],y=m[op[0]][1];
    for(int i=0;i<3;i++){
        for(int j=0;j<=1;j++){
            m[op[i]][j]=m[op[i+1]][j];
        }
    }
    m[op[3]][0]=x;
    m[op[3]][1]=y;
    int z=m[4][3];
    for(int i=3;i>=1;i--){
        m[4][i]=m[4][i-1];
    }
    m[4][0]=z;
}
void d(){
    int op[]={0,3,1,2},x=m[op[0]][2],y=m[op[0]][3];
    for(int i=0;i<3;i++){
        for(int j=2;j<=3;j++){
            m[op[i]][j]=m[op[i+1]][j];
        }
    }
    m[op[3]][2]=x;
    m[op[3]][3]=y;
    int z=m[5][1];
    for(int i=3;i>=1;i--){
        m[5][i]=m[5][(i+1)%4];
    }
    m[5][0]=z;
}
void f(){//u,r,d,l
   int op[]={2,5,3,4},x=m[op[0]][2],y=m[op[0]][3];
    for(int i=0;i<3;i++){
        for(int j=2;j<=3;j++){
            m[op[i]][j]=m[op[i+1]][j];
        }
    }
    m[op[3]][2]=x;
    m[op[3]][3]=y;
    int z=m[0][3];
    for(int i=3;i>=1;i--){
        m[0][i]=m[0][i-1];
    }
    m[0][0]=z;
}
void b(){
    int op[]={2,5,3,4},x=m[op[0]][0],y=m[op[0]][1];
    for(int i=0;i<3;i++){
        for(int j=0;j<=1;j++){
            m[op[i]][j]=m[op[i+1]][j];
        }
    }
    m[op[3]][0]=x;
    m[op[3]][1]=y;
    int z=m[1][1];
    for(int i=3;i>=1;i--){
        m[1][i]=m[1][(i+1)%4];
    }
    m[1][0]=z;
}
void l(){
     int op[]={4,0,5,1},x=m[op[0]][0],y=m[op[0]][3];
    for(int i=0;i<3;i++){
        m[op[i]][0]=m[op[i+1]][0];
        m[op[i]][3]=m[op[i+1]][3];
    }
    m[op[3]][0]=x;
    m[op[3]][3]=y;
    int z=m[2][1];
    for(int i=3;i>=1;i--){
        m[2][i]=m[2][(i+1)%4];
    }
    m[2][0]=z;
}
void r(){
    int op[]={4,0,5,1},x=m[op[0]][1],y=m[op[0]][2];
    for(int i=0;i<3;i++){
        m[op[i]][1]=m[op[i+1]][1];
        m[op[i]][2]=m[op[i+1]][2];
    }
    m[op[3]][1]=x;
    m[op[3]][2]=y;
    int z=m[3][3];
    for(int i=3;i>=1;i--){
        m[3][i]=m[3][i-1];
    }
    m[3][0]=z;
}
void xz(char ch){
    if(ch=='L')l();
    if(ch=='R')r();
    if(ch=='U')u();
    if(ch=='D')d();
    if(ch=='F')f();
    if(ch=='B')b();
}
bool check(){
    for(int i=0;i<6;i++){
        if(m[i][0]=m[i][1]&&m[i][1]==m[i][2]&&m[i][2]==m[i][3])continue;
        else return false;
    }
    return true;
}
void solve(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        xz(s[i]);
        if(i+1<s.length()&&s[i+1]==39){
            xz(s[i]);
            xz(s[i]);
            i++;
        }
        else if(i+1<s.length()&&s[i+1]=='2'){
            xz(s[i]);
            i++;
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++)cout<<m[i][j]<<' ';
        cout<<endl;
    }
    if(check())cout<<"YES"<<endl;
    else{
        cout<<"NO"<<endl;
        
    }
    for(int i=0;i<6;i++){
            for(int j=0;j<4;j++)m[i][j]=i+1;
    }
}
int main(){
   int t;
   cin>>t;
   while(t--)solve();
    return 0;
}