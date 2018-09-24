#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0; 
        unordered_map<int, bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = false;
        }
        for(int i = 0; i<nums.size(); i++){
            if(map[nums[i]] == true) continue;
            
            int cur = 1;
            map[nums[i]] = true;
            int j=nums[i]-1;
            while(map.find(j) !=map.end() && map[nums[j]] == false ){
                cur++;
                map[j] = true;
                j--;
            }
            int k = nums[i]+1;
            while(map.find(k) != map.end() && map[nums[k]] == false){
                cur++;
                map[k] = true;
                k++;
            }
            longest = max(longest, cur);
        }
        return longest;
        
    }
};
int main(int argc, char** argv){
    int arr[] = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
    vector<int> vec(arr,arr+sizeof(arr)/sizeof(arr[0])); 
    Solution solution;
    int ret = solution.longestConsecutive(vec); 
    return 0;
}
