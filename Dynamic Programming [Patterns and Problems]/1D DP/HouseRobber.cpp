class Solution {
    private:
    int helper(vector<int>& arr){
        int n = arr.size();
        int curr = 0;
	    int prev1 = arr[0];
	    int prev2 = 0;
	    for(int i=1 ; i<n ; i++){
	        int pick = prev2 + arr[i];
	        int notPick = prev1 + 0;
	        curr = max(pick,notPick);
	        prev2 = prev1;
	        prev1 = curr;
	    }
	    return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector <int> temp1, temp2;
        for(int i=0 ; i<nums.size() ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};
