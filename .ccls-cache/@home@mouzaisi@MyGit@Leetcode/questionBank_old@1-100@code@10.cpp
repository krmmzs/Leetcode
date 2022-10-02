class Solution
{
public:
    bool isMatch(string s, string p) 
    {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n ; i ++)
            for (int j = 1; j <= m; j ++)
            {
                if (j + 1 <= m && p[j + 1] == '*') continue; // If followed by * then the state is not calculated
                if (p[j] != '*' && i)
                {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else if (p[j] == '*')
                {
                    f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
                }
            }

        return f[n][m];
    }
};
