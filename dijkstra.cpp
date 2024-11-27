#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
const int INF = 1e18;

void faster() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int32_t main() {
    faster();
    int n, m;
    cin >> n >> m;

    // Graph representation: adjacency list with {neighbor, weight}
    vector<vector<pair<int, int>>> g(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }

    // Priority queue for Dijkstra: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INF); // Distance array initialized to "infinity"
    dis[1] = 0;                 // Distance to the source (city 1) is 0
    pq.push({0, 1});            // Start with source node

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dis[node]) continue; // Ignore outdated distances

        for (auto &i : g[node]) {
            int neighbor = i.first;
            int weight = i.second;

            if (dis[node] + weight < dis[neighbor]) {
                dis[neighbor] = dis[node] + weight;
                pq.push({dis[neighbor], neighbor});
            }
        }
    }

    // Output the shortest distances from city 1 to all cities
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;

    return 0;
}
