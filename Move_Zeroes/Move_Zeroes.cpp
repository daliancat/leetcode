#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>::iterator it = nums.begin();
        while(it!=nums.end()){
            if(*it == 0){
                it = nums.erase(it);
                //it=prev(it);
                nums.push_back(0);
            }else{
                it++;
            }
        }
        return;
    }
};
int main(int argc, char** argv){
    int arr[]={0,1,0,3,12};
    vector<int> vec(arr,arr+sizeof(arr)/sizeof(arr[0]));
    Solution solution;
    solution.moveZeroes(vec);
    return 0;
} 
