# Contains Duplicate (217) - Easy

```
Arrays & Hashing
```

[**Question:**](https://leetcode.com/problems/contains-duplicate) Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Approaches:**

- can use a hashset to store the elements and check for duplicate elements
- can compare the number of elements in the list and its unordered set version

**C++ Code:**

```cpp
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> a;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (a.find(nums[i]) != a.end())
                return true;
            else
                a.insert(nums[i]);
        }
        return false;
    }
};
```

**Python Code:**

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        s = set()
        for x in nums:
            if x in s:
                return True
            else:
                s.add(x)
        return False
```

**Time complexity:** `O(n)`

**Space complexity:** `O(n)`

**Remarks:**

- In python set() is unordered set
- Function to add an element into a set() in python: add()
