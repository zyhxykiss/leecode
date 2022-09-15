class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sub_str_head=0;
        int str_ptr = 0;
        int max_sub_len = 1, current_max_sub_len = 0;
        if (s == "") return 0;
        while (str_ptr < s.length())
        {
            for (int i = sub_str_head; i < str_ptr; i++)
            {
                if (s[str_ptr] == s[i]){
                    if (current_max_sub_len > max_sub_len){
                        max_sub_len = current_max_sub_len;
                    }
                    sub_str_head = i+1;
                    //str_ptr = sub_str_head;
                    current_max_sub_len = str_ptr - sub_str_head;
                }
            }
            current_max_sub_len += 1;
            str_ptr += 1;
        }
        if (current_max_sub_len > max_sub_len){
            max_sub_len = current_max_sub_len;
        }
        return max_sub_len;
    }
};
