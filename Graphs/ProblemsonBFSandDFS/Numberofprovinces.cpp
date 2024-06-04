//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void bfs(vector<vector<int>> adj, bool visited[], int s, int V) {
        visited[s] = true;
        queue <int> q;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=0 ; i<V ; i++){
                if(adj[u-1][i] == 1 && visited[i+1] == false){
                    q.push(i+1);
                    visited[i+1] = true;
                }
            }
        } 
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int count = 0;
        bool visited[V+1];
        for(int i=0 ; i<=V ; i++){
            visited[i] = false;
        }
        for(int i=0 ; i<V ; i++) {
            if(visited[i+1] == false) {
                count++;
                bfs(adj ,visited, i+1, V);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
