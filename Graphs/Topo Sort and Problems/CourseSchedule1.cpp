//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    vector <int> adj[V];
	    for(auto it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    int in_degree[V] = {0};
	    for(int i=0 ; i<V ; i++){
	        for(int x:adj[i]){
	            in_degree[x]++;
	        }
	    }
	    queue <int> q;
	    for(int i=0 ; i<V ; i++){
	        if(in_degree[i] == 0){
	            q.push(i);
	        }
	    }
	    int count = 0;
	    while(!q.empty()){
	        int u = q.front();
	        q.pop();
	        count++;
	        for(int v:adj[u]){
	            if(--in_degree[v] == 0){
	                q.push(v);
	            }
	        }
	    }
	    return (count == V);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
