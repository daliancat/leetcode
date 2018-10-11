class Solution {
public:
vector<vector<int> > combinationSum(vector<int> &nums, int target) {
  vector<vector<int>> ret;
  vector<int> path;
  dfs(nums,target,0,ret, path);
  return ret;
}
void dfs(vector<int> &nums, int gap, int start vector<vector<int>> ret,vector<int> path){
  if(gap == 0){
    ret.push_back(path);
    return;
  }
  if(gap<0) return;
  for(int i = start; i< nums.size(); i++ ){
      path.push_back(nums[i]);
      dfs(nums,gap-nums[i],i,ret, path);
      path.pop_back(); 
  }
  return;
}


