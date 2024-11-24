#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define pb push_back  
const int N=1e5+10;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
//int dx2[]={0,0,-1,1,1,1,-1,-1};
//int dy2[]={-1,1,0,0,1,-1,1,-1};
#define vi vector<int>
#define vp vector<pair<int,int>>
#define  mii map<int,int>
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;

void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
int mx,mxnode;
void dfs(vector<vector<pair<int,int>>>&g,int node,int d,vector<bool>&visited)
{
     visited[node]=true;
     if(d>mx)
     {
          mx=d;
          mxnode=node;
     }
     for(auto i:g[node])
     {
          if(!visited[i.first])
          {
               dfs(g,i.first,d+i.second,visited);
          }
     }
}
int32_t main()
{
     faster();
     int test=0;
     testCase
     {
          test++;
          int n;
          cin>>n;
          int e=n-1;
          vector<vector<pair<int,int>>>g(n);
          vector<bool>visited(n,false);
          while(e--)
          {
               int u,v,w;
               cin>>u>>v>>w;
               g[u].pb({v,w});
               g[v].pb({u,w});
          }

            dfs(g,0,0,visited);
            //cout<<mx<<endl;
            mx=-1;
         // memset(visited,false,sizeof(visited));
            for(int i=0;i<n;i++)
            {
               visited[i]=false;
            }
          dfs(g,mxnode,0,visited);
          cout<<"Case "<<test<<": "<<mx<<endl;
          mx=-1;
          for(int i=0;i<n;i++)
          {
               g[i].clear();
          }
           for(int i=0;i<n;i++)
            {
               visited[i]=false;
            }

   }
             
}