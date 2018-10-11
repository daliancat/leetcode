#include<string>
using namespace std;
class Solution {
public:
    #if 1
    string countAndSay(int n){
        string ret = "1";
        int i =1; 
        while(i<n){
            string tmp="";
            for(int j = 0; j<ret.size(); j++){
                int num = 1;
                while(j+1 < ret.size() && ret[j+1] == ret[j]){
                    num++;
                    j++;
                }
                tmp += to_string(num) + to_string(ret[j]-'0');
            }
            ret = tmp;
            i++;
        }
        return ret;
    }
    #else
    string countAndSay(int n) {
        if(n<=0) return "";
        string res = "1";
        while(--n){
            string cur = "";
            for(int i = 0; i< res.size(); i++){
                int cnt = 1;
                while(i+1 < res.size() && res[i] == res[i+1]){
                    cnt++;
                    i++;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
    #endif
};
int main(int argc, char** argv){
    Solution solution;
    solution.countAndSay(2);
    return 0;
}
