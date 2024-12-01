//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,vector<vector<int>>& adj,vector<bool>&visited,stack<int>&st)
	{
	    visited[node]=true;
	    for(auto i:adj[node])
	    {
	        if(!visited[i])
	        {
	            dfs(i,adj,visited,st);
	        }
	    }
	    st.push(node);
	}
	void dfsrev(int node,vector<vector<int>>& adjrev,vector<bool>&visited)
	{
	    visited[node]=true;
	    for(auto i:adjrev[node])
	    {
	        if(!visited[i])
	        {
	            dfsrev(i,adjrev,visited);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int v, vector<vector<int>>& adj)
    {
        stack<int>st;
        vector<bool>visited(v+1,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,st);
            }
        }
        vector<vector<int>>adjrev(v);
        for(int i=0;i<v;i++)
        {
            for(auto j:adj[i])
            {
                adjrev[j].push_back(i);
            }
        }
        int countscc=0;
        visited=vector<bool>(v+1,false);
        
        while(!st.empty())
        {
           int node=st.top();
           st.pop();
           
               if(!visited[node])
               {
                   dfsrev(node,adjrev,visited);
                   countscc++;
               }
          
        }
        return countscc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends