#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))

int n,m;
string s1,s2,str[30];
map<string,int> ma;
int g[30][30];
int vis[30];

void init()
{
    mem(g);
    s1.clear();s2.clear();
    for(int i=0;i<30;i++)
        str[i].clear();
    ma.clear();
}

void floyd()
{
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    int kase=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        int t=0;
        init();
        for(int i=0;i<m;i++)
        {
            cin>>s1>>s2;
            int id1,id2;
            if(ma.count(s1)){
                id1=ma[s1];
            }
            else{
                id1=t;
                str[t]=s1;
                ma[s1]=t++;
            }
            if(ma.count(s2)){
                id2=ma[s2];
            }
            else{
                id2=t;
                str[t]=s2;
                ma[s2]=t++;
            }
            g[id1][id2]=1;
        }
        floyd();
        if(kase) printf("\n");
        kase++;
        printf("Calling circles for data set %d:\n",kase);
        mem(vis);
        for(int i=0;i<n;i++)
        if(!vis[i])
        {
            cout<<str[i];
            for(int j=i+1;j<n;j++){
                if(!vis[j]){
                    if(g[i][j]&&g[j][i]){
                        cout<<", "<<str[j];
                        vis[j]=1;
                    }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
