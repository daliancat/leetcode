#include <string>
#include <vector>
#include <algorithm> 
using namespace std; 
#if 1
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string ret;
        string dir;
        string::iterator i = path.begin(), j;
        while(i != path.end()){
            i++;
            j = find(i, path.end(),'/');
            dir = string(i,j);
            if(!dir.empty() && dir != "."){
                if(dir == ".."){
                    if(!dirs.empty()) dirs.pop_back();
                }else{
                    dirs.push_back(dir);
                }
                
            }
            i = j;
        }
        if(dirs.empty()){
            ret = "/";
        }else{    
            for(vector<string>::iterator i=dirs.begin();i!=dirs.end();i++){
                ret += "/"+*i;
            }
        }
        return ret;
    }
};
#else
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir,ret;;
        int i = 0;
        while(i<path.size()){
            int j = path.find("/", i);
            dir = path.substr(i, j-i);
            if(!dir.empty() && dir!="."){
                if(dir == ".."){
                    if(!dirs.empty()) dirs.pop_back();
                }else{
                    dirs.push_back(dir);
                }
            }
            i = j+1;
        }
        if(!dirs.empty()){
            for(vector<string>::iterator it = dirs.begin(); it!= dirs.end(); it++){
                ret += "/" + *it;
            }
        }else{
            ret = "/";
        }
        return ret;
    }
};
#endif
int main(int argc, char** argv){
    Solution solution;
    solution.simplifyPath("hmoe");
    return 0;
}
