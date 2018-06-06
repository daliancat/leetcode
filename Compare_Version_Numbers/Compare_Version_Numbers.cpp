#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int major1_version, major2_version, minor1_version, minor2_version;
        string::iterator it1 =version1.begin(), i1;// find(version1.begin(), version1.end(),'.');
        string::iterator it2 =version2.begin(), i2;// find(version2.begin(), version2.end(),'.');      

        
        while(it1 != version1.end() || it2 != version2.end()){
            string version_str_1,version_str_2;
            int version_1=0,version_2=0;
            if(it1!=version1.end()){
                i1 = find(it1, version1.end(),'.');
                version_str_1 = string(it1,i1);
                version_1 = stoi(version_str_1);
            }

            if(it2!=version2.end()){
                i2 = find(it2, version2.end(),'.');
                version_str_2 = string(it2,i2);
                version_2 = stoi(version_str_2);
            }
            
            if(version_1 > version_2) return 1;
            if(version_1 < version_2) return -1;
            if(i1 != version1.end())it1 = i1+1;
            else it1=i1;
            if(i2 != version2.end())it2 = i2+1;
            else it2=i2;
            
        }
        return 0;

    }
};
int main(int argc,char** argv){
    Solution solution;
    solution.compareVersion("1","1.1");
} 
