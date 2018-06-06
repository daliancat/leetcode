class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        vector<int>::iterator first = nums.begin();
        vector<int>::iterator last = nums.end();
        vector<int>::iterator pivot = next(first);
        if(pivot == last){    
            return ;
        } 
        vector<int>::iterator change = first;
        while(change!=last && *change <= *pivot){
            ++change;
        }
        swap(*pivot, *change);
        reverse(first, pivot);
        reverse(nums.begin(),nums.end());
        return ;
    }
    #if 0
    bool nextPermutation(vector<int>::iterator first, vector<int>::iterator last){
        reverse_iterator<vector<int>::iterator> rfirst = reverse_iterator<vector<int>::iterator>(last);
        reverse_iterator<vector<int>::iterator> rlast = reverse_iterator<vector<int>::iterator>(first);
        reverse_iterator<vector<int>::iterator> pivot = next(rfirst);
        while(pivot != rlast && *pivot >= *prev(pivot)){
            ++pivot;
        } 
        if(pivot == rlast){
            reverse(rfirst, rlast);
            return false;
        }
        vector<int>::iterator change = rfirst;
        while(change!=rlast && *change <= *pivot){
            ++change;
        }
        swap(*pivot, *change);
        reverse(rfirst, rlast);
        return true;
    }
    #endif
};
