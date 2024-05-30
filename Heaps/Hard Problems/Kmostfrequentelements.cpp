class Solution {
public:
    struct doublet{
        int val;
        int freq;
        doublet(int v, int f){
            val = v;
            freq = f;
        }
    };
    struct MyCmp{
        bool operator() (doublet &d1, doublet &d2){
            return d1.freq < d2.freq;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans;
        priority_queue <doublet, vector<doublet>,MyCmp> pq;
        unordered_map <int,int> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]]++;
        }
        for(auto x:m){
            doublet d(x.first, x.second);
            pq.push(d);
        }
        for(int i=0 ; i<k ; i++){
            ans.push_back(pq.top().val);
            pq.pop();
        }
        return ans;
    }
};
