#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<array>
#include<map>
#include<unordered_map>
#include<utility>
#include<set>
#include<stack>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
const int N=1e3+10;
const int mod=1e9+7;

int n;
int path[50];
int m;
map<int,int>mp;

bool dfs(int x,int cnt)
{
    if(x>n||cnt>=40||mp[x]==1)
    {
        return false;
    }
    if(x==n)
    {
        m=cnt;
        return true;
    }
    if(x!=1)
    {
        path[cnt]=1;
        if(dfs(2*x-1,cnt+1))
        {
            return true;
        }
        mp[2*x-1]=1;
    }
    path[cnt]=2;
    if(dfs(2*x+1,cnt+1))
    {
        return true;
    }
    mp[2*x+1]=1;
    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(!dfs(1,0))
        {
            cout<<-1<<'\n';
        }else
        {
            cout<<m<<'\n';
            for(int i=0;i<m;i++)
            {
                cout<<path[i]<<' ';
            }
            cout<<'\n';
        }
        mp.clear();
    }
    return 0;
}