//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int n, int arr[], int k){
        vector <vector <bool>> dp(n, vector <bool>(k+1, false));
        for(int i=0 ; i<n ; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= k){
            dp[0][arr[0]] = true;
        }
        for(int ind=1 ; ind<n ; ind++){
            for(int target=1 ; target<=k ; target++){
                bool notTaken = dp[ind-1][target];
                bool Taken = false;
                if(arr[ind] <= target){
                    Taken = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = notTaken || Taken;
            }
        }
        return dp[n-1][k];
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i=0 ; i<N ; i++){
            sum += arr[i];
        }
        if(sum%2 != 0) return 0;
        int half = sum/2;
        return isSubsetSum(N,arr,half);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
