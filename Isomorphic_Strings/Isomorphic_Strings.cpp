#include<string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        int s1[256] ={-1}, t1[256]={-1};
        for(int i =0;i<len;i++){
            if(s1[s[i]] != t1[t[i]]) return false;
            s1[s[i]] = i;
            t1[t[i]] = i;
        }
        return true;
    }
};
int main(int argc, char** argv){
    Solution solution;
    solution.isIsomorphic("ab","aa");
    return 0;
}
