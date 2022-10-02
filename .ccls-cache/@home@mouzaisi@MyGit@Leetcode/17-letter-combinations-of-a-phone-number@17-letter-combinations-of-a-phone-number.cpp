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

    void dfs(const string& digit, int u, string path)
    {
        if (digit.size() == u) res.push_back(path);
        else
        {
            for (auto& c : strs[digit[u] - '0'])
                dfs(digit, u + 1, path + c);
        }
        
    }
};