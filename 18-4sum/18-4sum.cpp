class Solution
{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target)
        {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            for (int i = 0; i < nums.size(); i ++ )
            {
                if (i && nums[i] == nums[i - 1]) continue;
                for (int j = i + 1; j < nums.size(); j ++ )
                {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                    for (int k = j + 1, u = nums.size() - 1; k < u; k ++ )
                    {
                        if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                        while (u - 1 > k && nums[i] + nums[j]  >= target - nums[k] - nums[u - 1]) u -- ;
                        if (nums[i] + nums[j] == target - nums[k] - nums[u])
                        {
                            res.push_back({nums[i], nums[j], nums[k], nums[u]});
                        }
                    }
                }
            }

            return res;
        }
};
