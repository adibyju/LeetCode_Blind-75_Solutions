# Valid Anagram (242) - Easy

```
Arrays & Hashing
```

[**Question:**](https://leetcode.com/problems/valid-anagram) Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

**Approaches:**

- `O(nlogn)` - compare the 2 sorted strings
- `O(n)` - make an integer array of 26 zeroes, increment by one for the letters in the first word and
  decrement for the second one, check if all the elements in the array are zero

**C++ Code:**

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int a[26]={};
        for(int i=0; i<26; ++i) cout<<a[i]<<"\n";
        for(int i=0; i<s.size(); ++i){
            ++a[s[i]-'a'];
            --a[t[i]-'a'];
        }
        for(int i=0; i<26; ++i) if(a[i]!=0) return false;
        return true;
    }
};
```

**Python Code:**

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        a=[0]*26
        if len(s)!=len(t):
            return False
        for x in range(0, len(s)):
            a[ord(s[x])-ord('a')]+=1
            a[ord(t[x])-ord('a')]-=1
        for x in range(0,26):
            if a[x]!=0:
                return False
        return True
```

**Time complexity:** `O(n)`

**Space complexity:** `O(1)`

**Remarks:**

- In C++, an integer array can be intialized to NULL or 0 in the following ways:
  - int a[26]={};
  - int a[26]={0};
- In Python a list of zeroes can be created by: a = [0]∗26
- In Python, the ord() function returns the number representing the unicode code of a specified
  character
