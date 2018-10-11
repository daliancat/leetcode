#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    #if 1
    bool isMatch(string s, string p){
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 1; i<=n; i++){
            if(p[i-1] == '*') dp[0][i] = dp[0][i-1];
        }
        for(int i = 1; i<=m ; i++){
            for(int j = 1; j<=n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    for(int k =0; k<=i; k++){
                        if(dp[k][j-1] == true){
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[m][n];
    }
    #else
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 1; i<=n; i++){
            if(p[i-1] == '*') dp[0][i] = dp[0][i-1];
        }
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1]||dp[i-1][j];
                }else{
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
    #endif
};
int main(int argc, char** argv){
    Solution solution;
    solution.isMatch("adceb","*a*b");
    return 0;
}
