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
vector<int>createlps(string patt)
{
     vector<int>lps(patt.size());
     int ldx=0;
     for(int i=1;i<patt.size();)
     {
          if(patt[ldx]==patt[i])
          {
               lps[i]=ldx+1;
               ldx++;
               i++;
          }
          else{
               if(ldx!=0)
               {
                    ldx=lps[ldx-1];
               }
               else{
                    lps[i]=ldx;
                    i++;
               }
          }
     }
     return lps;
}
void kmp(string text,string pattern)
{
     vector<int>lps=createlps(pattern);
     int i=0,j=0;
     vector<int>ans;
     while(i<text.size())
     {
          if(text[i]==pattern[j]){
               i++;
               j++;
          }
          else{
               if(j!=0)
               {
                    j=lps[j-1];
               }
               else{
                    i++;
               }
          }
          if(j==pattern.size())
          {
               ans.push_back(i-pattern.size()+1);
               j=lps[j-1];
          }
     }
     if(ans.size()==0)
     {
          cout<<"Not Found"<<endl;
     }
     else{
          cout<<ans.size()<<endl;
          for(auto i:ans)
          {
               cout<<i<<' ';
          }cout<<endl;
     }
}
int32_t main()
{
     faster();
     testCase
     {
          string text,pattern;
          cin>>text>>pattern;
          kmp(text,pattern);
     }
             
}