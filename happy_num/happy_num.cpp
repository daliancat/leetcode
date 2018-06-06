#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> map;
        int t = 0;
        while(true){
            t += (n%10 * n%10);
            n /=10;
            if(n == 0){
                if(t == 1){
                    return true;
                }
                if(map[t] > 1) return false;
                else map[t]++;
                n = t;
                t = 0;
            }
        } 
    }

};
int main(int argc, char** argv){
    Solution solution;
    solution.isHappy(19);
    return 0;
}
