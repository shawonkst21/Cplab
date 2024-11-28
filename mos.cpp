#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define pb push_back  
const int N=2e5+10;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
//int dx2[]={0,0,-1,1,1,1,-1,-1};
//int dy2[]={-1,1,0,0,1,-1,1,-1};
#define vi vector<int>
#define vp vector<pair<int,int>>
#define  mii map<int,int>
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
int a[N],frq[N],res[N];
map<int,int>m;
int sqrtn;
struct QUERY{
     int l,r,id;
};
vector<QUERY>query;
bool comp(QUERY a,QUERY b)
{
     if(a.l/sqrtn==b.l/sqrtn)
     {
          return a.r>b.r;
     }
     
      return a.l/sqrtn<b.l;
}
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
     int n,q;
     cin>>n>>q;
     int c=1;
     for(int i=0;i<n;i++)
     {
          cin>>a[i];
          if(m[a[i]]==0)
          {
               m[a[i]]=c;
               c++;
          }
          a[i]=m[a[i]];
     }
     sqrtn=sqrt(n);
     query.resize(q);
     for(int i=0;i<q;i++)
     {
          cin>>query[i].l>>query[i].r;
          query[i].id=i;
     }
     sort(query.begin(),query.end(),comp);
     int cur_r=-1,cur_l=0,cnt=0;
     int L,R;
     for(auto i:query)
     {
          L=i.l;
          R=i.r;
          L--;
          R--;
          while(cur_r<R)
          {
                cur_r++;

               frq[a[cur_r]]++;
               if(frq[a[cur_r]]==1)
               {
                    cnt++;
               }
          }
          while(cur_r>R)
          {
               frq[a[cur_r]]--;
               if(frq[a[cur_r]]==0)
               {
                    cnt--;
               }
               cur_r--;
          }
          while(cur_l<L)
          {
               frq[a[cur_l]]--;
               if(frq[a[cur_l]]==0)
               {
                    cnt--;
               }
               cur_l++;
          }
          while(cur_l>L)
          {
              cur_l--;
             frq[a[cur_l]]++;
             if(frq[a[cur_l]]==1)
             {
               cnt++;
             }
          }
          res[i.id]=cnt;
     }

     for(int i=0;i<q;i++)
     {
          cout<<res[i]<<endl;
     }

}