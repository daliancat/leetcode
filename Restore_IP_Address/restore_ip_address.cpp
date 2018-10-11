#include<vector>
#include<string>
using namespace std;
class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        vector<int> path;
        dfs(s, 0, ret, path);
        return ret;
    }
    void dfs(string& s, int start, vector<string>& ret, vector<int>& path){
        int tmp = 0;
        if(start == s.size() && path.size() == 4){
            string str = to_string(path[0]);
            for(int i = 1; i<4; i++){
                str += "." + to_string(path[i]);
            }
            ret.push_back(str);
            return;
        }
        if(s.size() - start < 4- path.size() || s.size() -start > 3*(4-path.size())){
            return;
        }
        for(int i = start; i< s.size(); i++){
            tmp = tmp*10 + s[i] - '0';
            if(i>start && tmp == 0) continue;
            if(tmp <= 255){
                path.push_back(tmp);
                dfs(s, i+1, ret, path);
                path.pop_back();
            }    
        }
    }
};
int main(int argc, char** argv){
	Solution solution;
	solution.restoreIpAddresses("010010");
    return 0;
}
