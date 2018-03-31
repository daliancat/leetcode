#include <vector>
#include <string>
using namespace std;
class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict){
        int len = s.length();
        vector<bool> f(len+1,false);
        f[0] = true;
        for(int i=1;i<len+1;i++){
            for(int j = 0;j<i;j++){
                string sub = s.substr(j,i-j);
                if(matched(sub,wordDict) == true && f[j] == true){
                    f[i] = true;
                    break;
                 }
             }
        } 
        return f[len];
    }
    bool matched(string & str, vector<string>& wordDict){
        bool ret=false;
        for(int i =0;i<wordDict.size();i++){
            if(wordDict[i].compare(str) == 0){
                ret = true;
                break;
             }
         }
         return ret;
    }
};

int main(int argc, char** argv){
    Solution solution;
    vector<string> wordDict;
    wordDict.push_back("leet");
    wordDict.push_back("code");
    solution.wordBreak("leetcode",wordDict);
    return 0;
}
