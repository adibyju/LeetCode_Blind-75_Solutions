# Encode and Decode Strings (271) - Medium

```
Arrays & Hashing
```

[**Question:**](https://leetcode.com/problems/encode-and-decode-strings) Design an algorithm to encode a list of strings to a string. The encoded string is then sent
over the network and is decoded back to the original list of strings.

**Approaches:**

- The idea is to try to not read the strings while decoding.

**C++ Code:**

```cpp
class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        return result;
    }
};
```

**Python Code:**

```python
class Solution:
    def encode(self, strs):
        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    def decode(self, s):
        res, i = [], 0
        while i < len(s):
            j = i
            while s[j] != "#":
                j += 1
            length = int(s[i:j])
            res.append(s[j + 1 : j + 1 + length])
            i = j + 1 + length
        return res
```

**Time complexity:** `O(n)`

**Space complexity:** `O(1)`
