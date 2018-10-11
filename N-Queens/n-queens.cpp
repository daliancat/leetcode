#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ret;
		vector<string> path;
		dfs(n, 0, ret, path);
		return ret;	
	}
 	void dfs(int n, int level, vector<vector<string>>& ret,vector<string>& path){
        if(level == n){
        	ret.push_back(path);
		}
		string str(n,'.');
     	for(int i =0; i<n; i++){
			if(isValid(path, n, level, i)){
				str[i]='Q';				
				path.push_back(str);
                dfs(n, level+1,ret, path);
 				str[i] = '.';
  				path.pop_back();
			}
		}
	}
	bool isValid(vector<string>& path, int n, int row, int col){
		for(int i = 0;i<row; i++){ //check columns
			if(path[i][col]=='Q') return false;
		}	

		/*for(int i = 0;i<col; i++){ //check columns
			if(path[row][i]=='Q') return false;
		}*/
		int i = row -1, j= col-1;
        while(i>=0&&j>=0){
			if(path[i][j]=='Q') return false;
			i--;
			j++;	
		}
	
		i = row -1, j= col-1;
        while(i>=0&&j<n){
			if(path[i][j]=='Q') return false;
			i--;
			j++;	
		}
		return true;
	}
};
int main(int argc, char** argv){
	Solution solution;
	solution.solveNQueens(4);
    return 0;
}
