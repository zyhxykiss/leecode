#include <iostream>
using namespace std;
#include <sstream>
#include <string>

class Solution {
public:
    int reverse(int x) {
        string s_x;
        s_x  = to_string(x);
        int len = s_x.length();
        cout << "len" << len << endl;
        if (x < 0){
            cout << "less than 0" << endl;
            string reverse_x = reverse_str(s_x.substr(1, len-1), len-1);
            cout << reverse_x << endl;
            return -(eq(reverse_x, len-1, false));
        }
        else if (x > 0){
            cout << "more than 0" << endl;
            string reverse_x = reverse_str(s_x, len);
            cout << reverse_x << endl;
            return eq(reverse_x, len, true);
        }
        else{
            cout << "equal 0" << endl;
            return 0;
        }
            
    }

private:
    string reverse_str(string str, int len){
        char stemp;
        for (int i = 0; i < len/2; i ++)
        {
            stemp = str[i];
            str[i] = str[len - 1 - i];
            str[len - 1 - i] = stemp;
        }
        return str;
    }

    int eq(string & str, int len, bool sing){
        int res;
        stringstream ssres;
        string smax;
        if (sing){
            long long max = 2147483647;
            cout << max << endl;
            smax = to_string(max);
        }
        else{
            long long max = 2147483648;
            smax = to_string(max);
        }
        cout << smax << endl;
        int smax_len = smax.length();
        if (smax_len > len)
        {
            ssres << str;
            ssres >> res;
            return res;
        }
        else if (smax_len < len)
        {
            return 0;
        }
        else{
            int flag = smax.compare(str);
            if (flag >= 0)
            {
                ssres << str;
                ssres >> res;
                return res;
            }
            return 0; 
        }
    }  
};

int main(){
    int x = 1563847412;
    cout << "x  " << x << endl;
    Solution reverse;
    int y = reverse.reverse(x);
    cout << y << endl;
}
