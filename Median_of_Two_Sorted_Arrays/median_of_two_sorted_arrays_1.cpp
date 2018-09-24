#include<vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
#if 1
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if((n1+n2)%2 == 1){
            return find_kth(nums1, 0, n1, nums2, 0, n2, (n1+n2)/2+1);
        }else{
            return (find_kth(nums1, 0, n1, nums2, 0, n2, (n1+n2)/2) + find_kth(nums1, 0, n1, nums2, 0, n2, (n1+n2)/2+1))*0.5;
        }
    }
    int find_kth(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k){
        if(r1 - l1 > r2 - l2) return find_kth(nums2, l2, r2, nums1, l1, r1, k);
        if(r1 == l1) return nums2[l2 + k -1];
        if(k==1) return min(nums1[l1], nums2[l2]);
        int l = l1, r = r1;
        while(l < r){
            int m1 = l + (r-l)/2;
            int m2 = k - m1;
            if(nums1[m1] < nums2[m2-1]){
                l = m1+1;
            }else{
                r = m1;
            }
        }
        int m1 = l, m2 = k-m1;
        
        int c = max(l1+m1-1>=0?nums1[l1+m1-1]:INT_MIN, l2+m2-1>=0?nums2[l2+m2-1]:INT_MIN);
        return c;
    }
#else
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2= nums2.size();
        if((n1+n2)%2 == 1){
            return dfs(nums1, 0, n1, nums2, 0, n2, (n1+n2+1)/2);
        }else{
            return (dfs(nums1, 0, n1, nums2, 0, n2, (n1+n2)/2) +
                    dfs(nums1, 0, n1, nums2, 0, n2, (n1+n2)/2+1)) *0.5;
        }
    }
    double dfs(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k){
        if(end1 - start1 > end2-start2) return dfs(nums2, start2, end2, nums1, start1, end1, k);
        if(end1 == start1) return nums2[start2+k-1];
        if(k == 1) return min(nums1[start1], nums2[start2]);
        int l = start1, r = end1;
        while(l < r){
            int m1 = l + (r -l)/2;
            int m2 = k - m1;
            if(nums1[m1] < nums2[m2-1]){
                l = m1 +1;
            }else{
                r = m1;
            }
        }
        int m1 = l, m2 = k - m1;
        int c = max(start1+m1-1 < 0? INT_MIN:nums1[start1+m1-1], start2+m2-1<0? INT_MIN:nums2[start2+m2-1]);
        return c;
    }
#endif
};
int main(int argc, char** argv){
    Solution solution;
    int seed1[]={1,1};
    int seed2[]={1,1};
    vector<int> arr1(seed1,seed1+sizeof(seed1)/sizeof(int));
    vector<int> arr2(seed2,seed2+sizeof(seed2)/sizeof(int));
    double ret = solution.findMedianSortedArrays(arr1,arr2);
    return 0;
}

