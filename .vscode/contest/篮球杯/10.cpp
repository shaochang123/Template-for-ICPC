#include<iostream>
#include<set>
using namespace std;
string s;
struct p{
    int dx,dy;
};
p a[100007];
void solve(int i,char st){
    if(i==s.length()){
        a[i]={0,0};
        return;
    }
    if(s[i]=='L'){
        if(st=='F')st='U';
        else if(st=='U')st='B';
        else if(st=='B')st='D';
        else st='F';
    }
    if(s[i]=='R'){
        if(st=='F')st='D';
        else if(st=='U')st='F';
        else if(st=='B')st='U';
        else st='B';
    }
    solve(i+1,st);
    if(st=='U'){
        p now=a[i+1];
        a[i]={now.dx,now.dy+1};
    }
    if(st=='D'){
        p now=a[i+1];
        a[i]={now.dx,now.dy-1};
       
    }
    if(st=='F'){
        p now=a[i+1];
        a[i]={now.dx+1,now.dy};
    }
    if(st=='B'){
        p now=a[i+1];
        a[i]={now.dx-1,now.dy}; 
    }
}
set<pair<int,int>>vis;
int n;
int main(){
    cin>>n>>s;
    solve(0,'F');
    int x=0,y=0;
    char st='F';
    for(int i=0;i<s.length();i++){
        if(s[i]=='F'){
            vis.insert({x-a[i].dy,y+a[i].dx});
            vis.insert({x+a[i].dy,y-a[i].dx});
          //  cout<<x-a[i].dy<<' '<<a[i].dx+y<<endl;
           // cout<<x+a[i].dy<<' '<<y-a[i].dx<<endl;
            if(st=='F')x++;
            else if(st=='B')x--;
            else if(st=='U')y++;
            else y--;
        }
        else if(s[i]=='L'){
            vis.insert({x+a[i].dy,y-a[i].dx});
            vis.insert({x-a[i].dx,y-a[i].dy});
          //  cout<<x+a[i].dy<<' '<<-a[i].dx+y<<endl;
           // cout<<x-a[i].dx<<' '<<y-a[i].dy<<endl;
            if(st=='F')st='U';
            else if(st=='U')st='B';
            else if(st=='B')st='D';
            else st='F';
            if(st=='F')x++;
            else if(st=='B')x--;
            else if(st=='U')y++;
            else y--;
        }
        else if(s[i]=='R'){
            vis.insert({x-a[i].dy,y+a[i].dx});
            vis.insert({x-a[i].dx,y-a[i].dy});
          //  cout<<x-a[i].dy<<' '<<a[i].dx+y<<endl;
          //  cout<<x-a[i].dx<<' '<<y-a[i].dy<<endl;
            if(st=='F')st='D';
            else if(st=='U')st='F';
            else if(st=='B')st='U';
            else st='B';
            if(st=='F')x++;
            else if(st=='B')x--;
            else if(st=='U')y++;
            else y--;
        }

    }
  //  for(int i=0;i<=s.length();i++)cout<<a[i].dx<<' '<<a[i].dy<<endl;
    cout<<vis.size()<<endl;
    return 0;
}