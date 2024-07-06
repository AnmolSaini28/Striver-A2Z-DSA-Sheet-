//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs1(vector<vector<int>>& adj, stack<int> &st, int s, vector <int> &vis){
	    vis[s] = 1;
	    for(auto it : adj[s]){
	        if(!vis[it]){
	            dfs1(adj,st,it,vis);
	        }
	    }
	    st.push(s);
	}
	
	void dfs2(vector<int> adjT[], int s, vector <int> &vis){
	    vis[s] = 1;
	    for(auto it : adjT[s]){
	        if(!vis[it]){
	            dfs2(adjT,it,vis);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector <int> vis(V,0);
        stack <int> st;
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                dfs1(adj,st,i,vis);
            }
        }
        
        vector <int> adjT[V];
        for(int i=0 ; i<V ; i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int count = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                count++;
                dfs2(adjT,node,vis);
            }
        }
        
        return count;
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
    }

    return 0;
}


// } Driver Code Endsv
