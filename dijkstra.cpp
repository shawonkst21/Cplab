#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
#define pb push_back
const int N = 1e5 + 10;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
// int dx2[]={0,0,-1,1,1,1,-1,-1};
// int dy2[]={-1,1,0,0,1,-1,1,-1};
#define vi vector<int>
#define vp vector<pair<int, int>>
#define mii map<int, int>
// priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;

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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INT_MAX);
    pq.push({0, 1}); // {distance, node}
    dis[1] = 0;
    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
       // if (d > dis[node]) // Skip if the current distance is not optimal
         //   continue;
        for (auto &i : g[node])
        {
            if (dis[node] + i.second < dis[i.first])
            {
                dis[i.first] = dis[node] + i.second;
                pq.push({dis[i.first], i.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == INT_MAX)
            cout << -1 << ' '; // Print -1 for unreachable nodes
        else
            cout << dis[i] << ' ';
    }

    return 0;
}
