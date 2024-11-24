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
bool isvalid(int i,int j,int n,int m)
{
     return (i>=0 && i<n && j>=0 && j<m);
}
int32_t main()
{
     faster();
     int r,c;
     while(cin>>r>>c)
     {
      if(r==0 && c==0)
      {
          break;
      }
     bool g[r+1][c+1];
     vector<vector<int>>dis(r+1,vector<int>(c+1,-1));
     memset(g,false,sizeof(g));
     int br;
     cin>>br;
     while(br--)
     {
          int u,x;
          cin>>u>>x;
          while(x--)
          {
               int v;
               cin>>v;
               g[u][v]=true;
          }
     }
     int sx,sy,ex,ey;
     cin>>sx>>sy>>ex>>ey;
     queue<pair<int,int>>q;
     q.push({sx,sy});
     dis[sx][sy]=0;
     while(!q.empty())
     {
          int x=q.front().first;
          int y=q.front().second;
          q.pop();
          for(int i=0;i<4;i++)
          {
               int a=x+dx[i];
               int b=y+dy[i];
               if(isvalid(a,b,r,c) && !g[a][b])
               {
                    if(dis[a][b]==-1)
                    {
                         dis[a][b]=dis[x][y]+1;
                         q.push({a,b});
                    }
               }
          }
     }
cout<<dis[ex][ey]<<endl;
}
             
}