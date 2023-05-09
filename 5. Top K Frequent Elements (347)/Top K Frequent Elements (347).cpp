class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        vector<vector<int>> a(len);
        unordered_map<int, int> m;
        vector<int> res;

        for(auto x: nums){
            ++m[x];
        }

        for(auto& [key, value]: m){
            a[value-1].push_back(key);
        }

        for(int i=a.size()-1; i>=0; --i){
            if(k && a[i].size()!=0){
                for(auto x: a[i]){
                    res.push_back(x);
                }
                k=k-a[i].size();
            }
        }
        return res;    
    }
};