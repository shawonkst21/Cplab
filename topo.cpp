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
priority_queue<int,vector<int>,greater<int>>q;
void faster()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
}
#define testCase \
    int t;       \
    cin >> t;    \
    while (t--)
int32_t main()
{
     faster();
     int n,m;
     cin>>n>>m;
     vector<int>indegree(n+1);
     vector<vector<int>>g(n+1);
     while(m--)
     {
          int a,b;
          cin>>a>>b;
          indegree[b]++;
          g[a].pb(b);
     }  
    // queue<int>q;
     for(int i=1;i<=n;i++)
     {
          if(indegree[i]==0)
          {
               q.push(i);
          }
     } 
     vector<int>ans;
     while(!q.empty())
     {
          int x=q.top();
          q.pop();
          ans.push_back(x);
          for(auto i:g[x])
          {
               indegree[i]--;
               if(indegree[i]==0)
               {
                    q.push(i);
                   // cout<<i<<endl;
               }
          }
     }
     if(ans.size()==n)
     {
          //reverse(ans.begin(),ans.end());
          for(auto i:ans)
          {
               cout<<i<<" ";
          }
     }  
     else{
          cout<<"Sandro fails."<<endl;
     }
}