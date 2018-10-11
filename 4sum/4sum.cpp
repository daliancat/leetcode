#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size() < 4) return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i< nums.size()-3; i = inc(nums,i)){
            for(int j = i+1; j<nums.size()-2; j = inc(nums,j)){
                int l = j+1, h = nums.size()-1;
                while(l < h){
                    int sum = nums[i] + nums[j] + nums[l] + nums[h];
                    if(sum == target){
                        vector<int> path;
                        path.push_back(nums[i]);
                        path.push_back(nums[j]);
                        path.push_back(nums[l]);
                        path.push_back(nums[h]);
                        ret.push_back(path);
                        l = inc(nums,l);
                        h = dec(nums,h);
                    }else if(sum >target){
                        h = dec(nums,h);
                    }else{ //sum < target
                        l = inc(nums,l);
                    }
                }
            }
        }
        return ret;
    }
    int inc(vector<int>& nums, int index){
        while(index +1 < nums.size() && nums[index+1] == nums[index++]);
        return index;
    }
    int dec(vector<int>& nums, int index){
        while(index > 0 && nums[index-1] == nums[index--]);
        return index;
    }
};
int main(int argc, char** argv){
    int seed[]={1,0,-1,0,-2,2};
    vector<int> arr(seed, seed+sizeof(seed)/sizeof(seed[0]));
    Solution solution;
    solution.fourSum(arr,0);
    return 0;
}
