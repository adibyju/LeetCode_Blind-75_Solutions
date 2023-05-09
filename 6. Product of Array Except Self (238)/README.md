# Product of Array Except Self (238) - Medium

```
Arrays & Hashing
```

[**Question:**](https://leetcode.com/problems/product-of-array-except-self) Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. You must write an algorithm that runs in O(n) time and without using the division operation.

**Approaches:**

- Calculate prefix and postfix product arrays.
- Create output array and populate product by iterating the nums array from one side and then from the other side.

**C++ Code:**

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);
        int k = 1;

        for(int i=0; i<nums.size(); ++i){
            res[i] = k;
            k *= nums[i];
        }

        k = 1;

        for(int i=nums.size()-1; i>=0; --i){
            res[i] *= k;
            k *= nums[i];
        }

        return res;
    }
};
```

**Python Code:**

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1]*len(nums)
        k = 1

        for i in range(len(nums)):
            res[i] = k
            k = k*nums[i]

        k = 1

        for i in range(len(nums)-1, -1, -1):
            res[i] = res[i]*k
            k=k*nums[i]

        return res
```

**Time complexity:** `O(n)`

**Space complexity:** `O(1)`
