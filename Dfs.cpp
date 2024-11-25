#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define pb push_back  
const int N=1e3+10;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
//int dx2[]={0,0,-1,1,1,1,-1,-1};
//int dy2[]={-1,1,0,0,1,-1,1,-1};
#define vi vector<int>
#define vp vector<pair<int,int>>
#define  mii map<int,int>
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
 //unordered_map<int,vector<int>>m;


void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)


int bfs(int node,vector<vector<int>>&g)
{
    vector<bool>vis(g.size()+10,false);
    queue<pair<int,int>>q;
    q.push({node,0});
    vis[node]=true;
    while(!q.empty()){
        int par=q.front().first;
        int depth=q.front().second;
        q.pop();
        for(auto i:g[par])
        {
            if(!vis[i])
            {
                q.push({i,depth+1});
                vis[i]=true;
            }
            else if(i==node)
            {
                return depth+1;
            }
        }
    }
    return -1;
}
int32_t main()
{
     faster();
     int n;
     cin>>n;
     vector<vector<int>>g(n+1);
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin>>x;
            if(x)
            {
                g[i].pb(j);
            }
        }
     }
     for(int i=1;i<=n;i++)
     {
        int ans=bfs(i,g);
        if(ans!=-1)
        {
            cout<<ans<<endl;
        }
        else{
            cout<<"NO WAY"<<endl;
        }
     }
             
}