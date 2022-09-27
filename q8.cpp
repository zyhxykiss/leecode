class Solution {
public:
    int myAtoi(string s) {
        string numstr = "";
        bool sing = true, flag = false;
        for (char c: s)
        {
            if (c == ' ' && !flag){
                continue;
            }
            if (c == '-' && !flag){
                sing = false;
                flag = true;
                continue;
            }
            if (c == '+' && !flag){
                sing = true;
                flag = true;
                continue;
            }
            if (c >= '0' && c <='9'){
                numstr += c;
                flag = true;
            }
            else{
                break;
            }
        }
        if (numstr == ""){
            return 0;
        }
        long long num;
        stringstream ss;
        ss << numstr;
        ss >> num;
        if (sing) return int(num) == num?int(num):2147483647;
        return int(-(num)) == -(num)?int(-num):2147483648;
    }
};

int main(){
    string s = "21474836460";
    Solution stoi;
    int x;
    x = stoi.myAtoi(s);
    cout << "result: " << x << endl;
}
