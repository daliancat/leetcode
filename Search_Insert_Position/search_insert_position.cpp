#include<vector>
using namespace std;
class Solution {
public:
   int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int m = l+(r-l)/2;
            if(nums[m] < target){
                l = m +1;
            }else{
                r = m;
            }
        }
        if(nums[l] >= target) return l;
        else return l+1;
    }
};
int main(int argc, char** argv){
    int seed1[] = {1,3,5,6};
    vector<int> arr(seed1, seed1+sizeof(seed1)/sizeof(seed1[0]));
    Solution solution;
    int ret = solution.searchInsert(arr,0);
    return 0;
}
