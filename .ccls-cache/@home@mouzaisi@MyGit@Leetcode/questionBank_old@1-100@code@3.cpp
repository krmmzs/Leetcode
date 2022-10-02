class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> heap;
        int res = 0;
        for (size_t i = 0, j = 0; i < s.size(); i ++)
        {
            heap[s[i]] ++;
            while (heap[s[i]] > 1)
                heap[s[j ++]] --;
            res = max(res, (int)i - (int)j + 1);
        }

        return res;
    }
};
