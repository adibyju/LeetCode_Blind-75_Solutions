# Two Sum (1) - Easy

```
Arrays & Hashing
```

[**Question:**](https://leetcode.com/problems/two-sum) Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Approaches:**

- `O(n²)` - double loop iteration
- `O(n)` - keep a map of elements and index, check if the (target-current) element is found in the map

**C++ Code:**

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i=0; i<nums.size(); ++i){
            if(m.find(target-nums[i])!=m.end()) return {m[target-nums[i]],i};
            else m[nums[i]] = i;
        }
        return {0,0};
    }
};
```

**Python Code:**

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for x in range(0, len(nums)):
            if target-nums[x] in d:
                return {d[target-nums[x]], x}
            else:
                d[nums[x]] = x
        return
```

**Time complexity:** `O(n)`

**Space complexity:** `O(n)`

**Remarks:**

- A map can be created in python by using {}
- In python, we don’t have to return anything at the end because we know there exists a solution all the time
