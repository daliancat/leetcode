#include<vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        if(nums.empty()) return ret;
        int ret1=nums[0],ret2,count1=1, count2=0;
        for(int i=1;i<nums.size();i++){
            if(ret1==nums[i]) count1++;
            else if(ret2 == nums[i]) count2++;
            else{
                if(count1 == 0){
                    ret1 = nums[i];
                    count1 =1;
                }else if(count2 == 0){
                    ret2 = nums[i];
                    count2 = 1;
                }else{
                    count1--;
                    count2--;
                }
            }
        }
        if(count1 > nums.size()/3) ret.push_back(ret1);
        if(count2 > nums.size()/3) ret.push_back(ret2);
        return ret;
    }
};
int main(int argc, char** argv){
    int para[]={2,2,1,3}; 
    vector<int> paraVec(para,para+sizeof(para)/sizeof(para[0]));
    Solution solution;
    solution.majorityElement(paraVec);
    return 0;
}
