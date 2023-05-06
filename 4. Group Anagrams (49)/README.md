# Group Anagrams (49) - Medium

```
Arrays & Hashing
```

[**Question:**](https://leetcode.com/problems/group-anagrams) Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

**Approaches:**

- Use the count of letters as key of a hashmap to group together anagrams
- Assign prime numbers to each of the 26 letters. Each anagram can be now equated to a unique number, which can act as the key of the hashmap.
- Can also sort the string to keep it as the key in the hashmap


**C++ Code:**

```cpp
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
```

**Python Code:**

```python
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        grps = {}

        for string in strs:
            count = [0]*26
            
            for letter in string:
                count[ord(letter)-ord('a')]+=1
            
            key = '.'.join([str(n) for n in count])

            if key in grps:
                grps[key].append(string)
            else:
                grps[key] = [string]

        return grps.values()
```

**Time complexity:** `O(n.m)`, where n is the number of strings, and m is the length of a string. `O(n.m.log(m))` if sorted string method is used.

**Space complexity:** `O(n.m)`

**Remarks:**

- In Python, we can use .values() method on hashmap to return the values of the hashmap in a list.
- In Python .join() method can be used to join contents of a string list into a string using specfied delimiter.
