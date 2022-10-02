class Solution
{
public:
    int myAtoi(string s)
    {
        int k = 0;
        while (k < s.size() && s[k] == ' ') k ++;
        if (k == s.size()) return 0;

        int sign = 1;
        if (s[k] == '-') sign = -1, k ++;
        else if (s[k] == '+') k ++;

        int res = 0;
        while (k < s.size() && s[k] >= '0' && s[k] <= '9')
        {
            int x = s[k] - '0';
            if (sign == 1 && res > (INT_MAX - x) / 10) return INT_MAX;
            if (sign == -1 && -res < (INT_MIN + x) / 10) return INT_MIN;
            if (-res * 10 - x == INT_MIN) return INT_MIN;
            res = res * 10 + x;
            k ++;
            if (res > INT_MAX) break;
        }

        res *= sign;

        return res;
    }
};
