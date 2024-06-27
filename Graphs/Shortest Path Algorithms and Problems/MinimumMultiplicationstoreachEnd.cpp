//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
        if(start == end) return 0;
        int mod = 100000;
        queue <pair <int,int>> q;
        q.push({start,0});
        vector <int> dist(100000,1e9);
        dist[start] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int steps = it.second;
            for(int i=0 ; i<n ; i++){
                int adjNode = (node*arr[i])%mod;
                if(dist[adjNode] > steps+1){
                    dist[adjNode] = steps+1;
                    if(adjNode == end){
                        return steps+1;
                    }
                    q.push({adjNode,steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
