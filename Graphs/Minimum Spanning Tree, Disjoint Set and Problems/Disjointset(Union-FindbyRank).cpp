//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    int find(int x, int parent[]){
        if(x == parent[x]){
            return x;
        }
        parent[x] = find(parent[x], parent);
        return parent[x];
    }
    //Function to merge two nodes a and b.
    void union_( int a, int b, int parent[], int rank[]) 
    {
        int a_rep = find(a,parent);
        int b_rep = find(b,parent);
        if(a_rep == b_rep){
            return ;
        }
        else if(rank[a_rep] < rank[b_rep]){
            parent[a_rep] = b_rep;
        }
        else if(rank[a_rep] > rank[b_rep]){
            parent[b_rep] = a_rep;
        }
        else{
            parent[a_rep] = b_rep;
            rank[b_rep]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int parent[], int rank[])
    {
        int x_rep = find(x,parent);
        int y_rep = find(y,parent);
        if(x_rep == y_rep) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    //taking number of testcases
    int t;
    cin>>t;
    while(t--) {
        
        //taking number of elements
        int n;
        cin>>n;
        
        
        int par[n+1];
        int rank1[n+1];

        //initializing the parent and
        //the rank array
        for(int i=1; i<=n; i++) {
            par[i] = i;
            rank1[i] = 1;
    }
    
    //taking number of queries
    Solution obj;
    int q;
    cin>>q;
    while(q--) {    
        int a,b;
        char c;
        cin>>c>>a>>b;
        
        //if query type is 'U'
        //then calling union_ method
        if(c=='U')
        {
            obj.union_(a,b, par, rank1);
        }
        else//else calling isConnected() method
        cout<<obj.isConnected(a,b, par, rank1)<<endl;
    }
    }
    return 0;
}

// } Driver Code Ends
