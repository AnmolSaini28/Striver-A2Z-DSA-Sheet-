//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int total = 0;
	    for(int i=0 ; i<n ; i++) total += arr[i];
	    int k = total;
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
        int ans = 1e9;
        for(int i=0 ; i<=k/2 ; i++){
            if(dp[n-1][i] == true){
                ans = min(ans, abs((total-i)-i));
            }
        }
        return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
