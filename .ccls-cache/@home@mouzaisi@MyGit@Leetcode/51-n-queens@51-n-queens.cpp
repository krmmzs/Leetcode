class Solution
{
    public:
        int n;
        vector<bool> col, dg, udg;
        vector<vector<string>> res;
        vector<string> path;

        vector<vector<string>> solveNQueens(int _n)
        {
            n = _n;
            col = vector<bool>(n);
            dg = udg = vector<bool>(n * 2); // need 2 * n - 1
            path = vector<string>(n, string(n, '.'));

            dfs(0);
            return res;
        }

        void dfs(int u) // u represent col
        {
            if (u == n)
            {
                res.push_back(path);
                return;
            }

            for (int i = 0; i < n; i ++) // i represent row
            {
                if (!col[i] && !dg[u - i + n] && !udg[u + i])
                {
                    col[i] = dg[u - i + n] = udg[u + i] = true;
                    path[u][i] = 'Q';
                    dfs(u + 1);
                    path[u][i] = '.';
                    col[i] = dg[u - i + n] = udg[u + i] = false;
                }
            }
        }
};
