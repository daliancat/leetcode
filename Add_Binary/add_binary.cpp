#include <string>
using namespace std;
class Solution {
public:
    #if 1
    string addBinary(string a, string b) {
        int len1 = a.size()-1, len2 = b.size()-1;
        int c = 0;
        string ret;
        while(len1>=0 || len2>=0){
            int sum = ((len1>=0?a[len1]-'0':0) + (len2>=0?b[len2]-'0':0) + c)%2;
            c = (len1>=0?a[len1]-'0':0 + len2>=0?b[len2]-'0':0 + c)/2;
            ret.insert(ret.begin(), sum+'0');
            len1--;
            len2--;
        }
        if(c!=0){
            ret.insert(ret.begin(), c+'0');
        }
        return ret;
    }    
    #else
    string addBinary(string a, string b) {
        string ret;
        
        int sa = a.size() -1;
        int sb = b.size() -1;
        int carry = 0;
        int i =0;
        while(sa >=0 || sb >= 0){
            int value = (carry + (sa>=0? (a[sa] - '0'):0) + (sb>=0?(b[sb] - '0'):0) ) %2;
            carry = (carry + (sa>=0? (a[sa] - '0'):0) + (sb>=0?(b[sb] - '0'):0) )/2;
            if(sa>=0) sa--;
            if(sb>=0) sb--;
            ret.insert(ret.begin(), value + '0');
        }
        if(carry >0) 
            ret.insert(ret.begin(), carry + '0');
        //reverse(ret.begin(), ret.end());
        return ret;
    }
    #endif
};
int main(int argc, char** argv){
    Solution solution;
    string s1 ="1010", s2="1011";
    solution.addBinary(s1,s2);
    return 0;
}
