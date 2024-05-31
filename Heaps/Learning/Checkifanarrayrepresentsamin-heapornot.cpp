//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        
        for(int i=0 ; i<n ; i++){
            int left = 2*i+1;
            int right = 2*i+2;
            int parent = i;
            if(left < n && arr[parent] < arr[left]){
                return false;
            }
            if(right < n && arr[parent] < arr[right]){
                return false;
            }
            if(left >= n || right >= n){
                break;
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
