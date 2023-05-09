# Top K Frequent Elements (347) - Medium

```
Arrays & Hashing
```

[**Question:**](https://leetcode.com/problems/top-k-frequent-elements/description) Given an integer array nums and an integer k, return the k most frequent elements. You
may return the answer in any order.

**Approaches:**

- `O(n.log(n))` - Take frequencies of elements and sort according to frequency, then return the top k elements
- `O(n)` - Bucket sort: distribute the elements into an array where the elements index corresponds to its frequency. Iterate the array starting from the end to find the k most frequent elements.

**C++ Code:**

```cpp
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
```

**Python Code:**

```python
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        topK = [[] for i in range(len(nums))]
        res = []

        for n in nums:
            freq[n] = 1+freq.get(n,0)

        for n, count in freq.items():
            topK[count-1].append(n)

        for i in range(len(nums)-1, -1, -1):
            if not k:
                break
            k = k - len(topK[i])
            res = res + topK[i]

        return res
```

**Time complexity:** `O(n)`

**Space complexity:** `O(n)`

**Remarks:**

- Can also use priority queue (C++) to solve the problem.
- In Python .get() function returns a default value if the queried key is not found.
