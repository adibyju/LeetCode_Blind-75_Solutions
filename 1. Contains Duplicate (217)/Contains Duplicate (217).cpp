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