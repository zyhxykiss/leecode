class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max_i = 0, end = 1;
        vector<vector<int>> dp(len, vector(len, 0));
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
            if ((i < len - 1) && (s[i] == s[i+1]))
            {
                    dp[i][i+1] = 1;
                    max_i = i;
                    end = 2;   
            }
        }
        for (int L = 3; L <= len; L ++)
        {
            for (int i = 0; i + L - 1 < len; i ++)
            {
                int j = i + L -1;
                if ((dp[i + 1][j - 1] == 1) && (s[i] == s[j]))
                {
                    dp[i][j] = 1;
                    max_i = i;
                    end = L;
                }
            }
        }
        return s.substr(max_i, end);
    }
};
