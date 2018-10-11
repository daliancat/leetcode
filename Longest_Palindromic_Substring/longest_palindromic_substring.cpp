#include<string>
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    #if 1
    string longestPalindrome(string s){
        string ret;
        if(s.empty()) return ret;
        int distance = INT_MIN, start = 0;
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(int i = 0;i<len; i++){
            dp[i][i] = true;
            for(int j = 0; j<=i; j++){
                dp[j][i] = (s[i] == s[j]) && (i-j<=2 || dp[j+1][i-1] ==true);
                if(dp[j][i] == true && i-j+1 > distance){
                    distance = i-j +1;
                    start = j;
                }
            }
        }
        return s.substr(start, distance);
    }
    #else
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        vector<vector<bool>> f(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i< s.size(); i++){
            f[i][i] = 1;
            for(int j =0; j<= i; j++){
                f[j][i] = (s[i] == s[j] && (i-j<3 || f[j+1][i-1]));
                if(f[j][i] && maxLen < i-j+1){
                    maxLen = i-j+1;
                    start = j;
                }
            }
        }
        return s.substr(start, maxLen);
    }
    #endif
};
int main(int argc, char** argv){
    Solution solution;
    solution.longestPalindrome("ac");
    return 0;
}
