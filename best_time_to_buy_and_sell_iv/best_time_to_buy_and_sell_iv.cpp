#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len<2) return 0;
        
        if(k>=len/2){
            vector<int> profit_0(len,0), profit_1(len,0);
            profit_1[0] = -prices[0];
            for(int i=1;i<len;i++){
                profit_0[i] = max(profit_0[i-1], profit_1[i-1] + prices[i]);
                profit_1[i] = max(profit_1[i-1], profit_0[i-1] - prices[i]);
            }
            return profit_0[len-1];
        }
        vector<vector<int>> profit_0(len, vector<int>(k+1,0)), profit_1(len,vector<int>(k+1,0));
        for(int j =1;j<k+1;j++){
            profit_1[0][j] = -prices[0];
        }
        for(int i = 1;i<len;i++){            
            for(int j = 1;j<k+1;j++){
                
                profit_0[i][j] = max(profit_0[i-1][j], profit_1[i-1][j] + prices[i]);
                profit_1[i][j] = max(profit_1[i-1][j], profit_0[i-1][j-1] - prices[i]);
            }
        }
        return profit_0[len-1][k];
    }
};
int main(int argc, char** argv){
    Solution solution;
    int input_arr[]={3,2,6,5,0,3};
    vector<int> input(input_arr,input_arr+sizeof(input_arr)/sizeof(int));
    solution.maxProfit(2,input);
    return 0;	

}
