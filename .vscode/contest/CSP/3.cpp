#include<bits/stdc++.h>
using namespace std;
struct word{
	vector<string>s;
	int cnt;
}w[10006];
void solve(){
	int n,m,cnt=0;
	int alpha[26];
	memset(alpha,0,sizeof(alpha));
	cin>>n>>m;
	int mark=n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.length();j++){
			string ss="";
			ss+=s[j];
			w[i].s.push_back(ss);
			alpha[s[j]-'a']=1;
		}
		cin>>w[i].cnt;
	}
	for(int i=0;i<26;i++)if(alpha[i]){
		cout<<(char)('a'+i)<<endl;
		cnt++;
		if(cnt==m)return;
	}
	while(cnt<m&&mark){
		mark=n;
		map<string,int>a;
		for(int i=0;i<n;i++){
			for(int j=0;j<w[i].s.size()-1;j++){
				string ss="";
				ss+=w[i].s[j];
				ss+=w[i].s[j+1];
				a[ss]+=w[i].cnt;
			}
		}
		int maxx=0;
		string ma="";
		map<string,int>::iterator it=a.begin();
		for(;it!=a.end();it++){
			if(it->second>maxx){
				maxx=it->second;
				ma=it->first;	
			}
			else if(it->second==maxx){
				if(it->first.length()<ma.length()||it->first<ma){
					maxx=it->second;
					ma=it->first;
				}
			}
		}
		cout<<ma<<endl;
		cnt++;
		for(int i=0;i<n;i++){
			for(int j=0;j<w[i].s.size()-1;j++){
				string ss="";
				ss+=w[i].s[j];
				ss+=w[i].s[j+1];
				if(ss==ma){
					w[i].s[j]+=w[i].s[j+1];
					w[i].s.erase(w[i].s.begin()+j+1);
				}
			}
		}
		for(int i=0;i<n;i++)if(w[i].s.size()==1)mark--;
	}
}
int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}