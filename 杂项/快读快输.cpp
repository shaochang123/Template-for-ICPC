int in()//读入整数
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k*f;
}
void out(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x<10)putchar(x+'0');
    else out(x/10),putchar(x%10+'0');
}
string read(){//读入字符串
    char c=getchar();
    string s="";
    while(c>='a'&&c<='z'){//可根据实际情况修改
        s+=c;
        c=getchar();
    }
    return s;
}
void out(string s){
    for(int i=0;i<s.length();i++)putchar(s[i]);
    putchar('\n');
}
int main(){
    ios::sync_with_stdio(false);//取消兼容stdio
    cin.tie(0);
    cout.tie(0);//解除cin与cout的绑定，加快执行效率。
}
