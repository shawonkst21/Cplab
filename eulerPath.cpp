//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 void dfs(vector<int>adj[],int node,vector<bool>&visited)
 {
     visited[node]=true;
     for(auto i:adj[node])
     {
         if(!visited[i])
         {
             dfs(adj,node,visited);
         }
     }
 }
    bool isConnected(int v,vector<int>adj[])
    {
        int nonZero=-1;
        for(int i=0;i<v;i++)
        {
            if(adj[i].size()!=0)
            {
                nonZero=i;
                break;
            }
        }
        vector<bool>visited(v,false);
        dfs(adj,nonZero,visited);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false && adj[i].size()>0)
            {
                return false;
            }
        }
        return true;
       
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    if(isConnected(V,adj)==false)
	    {
	        return 0;
	    }
	    int odd=0;
	    for(int i=0;i<V;i++)
	    {
	        if(adj[i].size()%2==1)
	        {
	            odd++;
	        }
	    }
	    if(odd>2)
	    {
	        return 0;
	    }
	    else if (odd==2){
	        return 1;
	    }
	    else{
	        return 2;
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
//print the path
//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // DFS to check connectivity
    void dfs(vector<int> adj[], int node, vector<bool>& visited) {
        visited[node] = true;
        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfs(adj, i, visited);
            }
        }
    }

    // Function to check if the graph is connected, ignoring zero-degree vertices
    bool isConnected(int V, vector<int> adj[]) {
        int nonZero = -1;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() != 0) {
                nonZero = i;
                break;
            }
        }
        if (nonZero == -1) return true; // No edges in the graph, it's connected by definition

        vector<bool> visited(V, false);
        dfs(adj, nonZero, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && adj[i].size() > 0) {
                return false;
            }
        }
        return true;
    }

    // Function to find if a graph has an Euler Circuit or Path
    int isEulerCircuit(int V, vector<int> adj[]) {
        if (!isConnected(V, adj)) {
            return 0;
        }

        int odd = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 == 1) {
                odd++;
            }
        }
        if (odd > 2) {
            return 0;
        } else if (odd == 2) {
            return 1; // Euler Path
        } else {
            return 2; // Euler Circuit
        }
    }

    // Function to find and print the Euler Path or Circuit using Hierholzer's Algorithm
    void printEulerPath(int V, vector<int> adj[]) {
        vector<int> degree(V, 0);
        int oddDegree = 0, startNode = 0;

        // Count odd degree vertices and find a starting node
        for (int i = 0; i < V; i++) {
            degree[i] = adj[i].size();
            if (degree[i] % 2 == 1) {
                oddDegree++;
                startNode = i;
            }
        }

        // If no odd-degree vertices, start from any non-zero-degree vertex
        if (oddDegree == 0) {
            for (int i = 0; i < V; i++) {
                if (degree[i] > 0) {
                    startNode = i;
                    break;
                }
            }
        }

        // Stack-based Hierholzer's Algorithm
        stack<int> currentPath;
        vector<int> circuit;
        currentPath.push(startNode);

        while (!currentPath.empty()) {
            int current = currentPath.top();
            if (degree[current] > 0) {
                int next = adj[current].back();
                adj[current].pop_back();
                adj[next].erase(find(adj[next].begin(), adj[next].end(), current)); // Remove edge in both directions
                degree[current]--;
                degree[next]--;
                currentPath.push(next);
            } else {
                circuit.push_back(current);
                currentPath.pop();
            }
        }

        // Print the Euler path/circuit
        reverse(circuit.begin(), circuit.end());
        cout << "Euler Path/Circuit: ";
        for (int node : circuit) {
            cout << node << " ";
        }
        cout << endl;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        int ans = obj.isEulerCircuit(V, adj);
        if (ans == 0) {
            cout << "No Euler Path or Circuit\n";
        } else {
            cout << (ans == 1 ? "Euler Path\n" : "Euler Circuit\n");
            obj.printEulerPath(V, adj);
        }
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
