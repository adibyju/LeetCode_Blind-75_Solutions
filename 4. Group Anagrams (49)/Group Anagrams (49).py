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