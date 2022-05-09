class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> mapp;
        for (size_t i = 0; i < nums.size(); i ++)
        {
            int x = target - nums[i];
            if (mapp.count(x))
                return {mapp[x], (int)i};
            else
                mapp[nums[i]] = i;
        }

        return {};
    }

};
