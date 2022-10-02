class Solution
{
public:
    vector<string> res;
    string strs[10] =
    {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits)
    {
        if (!digits.size()) return res;
        dfs(digits, 0, "");
        return res;
    }

    void dfs(const string& digits, int u, string path)
    {
        if (u == digits.size()) res.push_back(path);
        else
        {
            for (auto& c : strs[digits[u] - '0'])
            {
                dfs(digits, u + 1, path + c);
            }
        }
    }
};
