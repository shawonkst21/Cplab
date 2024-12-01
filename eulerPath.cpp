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