/*
执行用时：20 ms, 在所有 C++ 提交中击败了16.55%的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了52.65%的用户
*/
class Solution1 {
public:
    bool isPalindrome(int x) {
        string str_x = to_string(x);
        string reverse_x = reverse(str_x);
        if (str_x.compare(reverse_x) == 0) return true;
        return false;
    }
private:
    string reverse(string s)
    {
        int len = s.length();
        for (int i = 0; i < len / 2; i++){
            char ctmp = s[i];
            s[i] = s[len - 1 - i];
            s[len - 1 - i] = ctmp;
        }
        return s;
    }
};

/*
执行用时：4 ms, 在所有 C++ 提交中击败了94.64%的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了55.32%的用户
*/
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long y = 0;
        int tmp = x;
        while(x != 0){
            y = y*10 + x%10;
            x = x /10;
        }
        return tmp == y;
    }
};

