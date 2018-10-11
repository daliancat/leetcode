#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
		vector<string> path;
		count = 0;
		dfs(n, 0, path);
		return count;
    }
	void dfs(int n, int level, vector<string>& path){
		if(level == n){
			count++;
		}
		string str(n, '.');
		for(int i = 0; i< n; i++){
			if(isValid(path, n, level, i)){
				str[i] = 'G';
				path.push_back(str);
				dfs(n, level+1, path);
				str[i] = '.';
				path.pop_back();
			}
		}
		return;
	}
	bool isValid(vector<string>& path, int n,int row, int col){
		for(int i = 0; i< row; i++){
			if(path[i][col] == 'G') return false;
		}
		int i = row-1, j = col-1;
		while(i>=0&&j>=0){
			if(path[i][j] == 'G') return false;
			i--;
			j--;
		}
		i = row-1, j = col+1;
		while(i>=0&&j<n){
			if(path[i][j] == 'G') return false;
			i--;
			j++;
		}
		return true;
	}
private:
	int count;
};
int main(int argc, char** argv){
	Solution solution;
	solution.totalNQueens(4);
    return 0;
}