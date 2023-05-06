class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> a;
        vector<vector<string>> res;
        for(auto s: strs){
            string key = s;
            sort(key.begin(), key.end());
            a[key].push_back(s);
        }
                
        for(auto it = a.begin(); it!=a.end(); ++it){
            res.push_back(it->second);
        }
          
        return res;
    }
};