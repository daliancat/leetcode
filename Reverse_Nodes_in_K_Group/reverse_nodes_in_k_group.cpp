#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
      ListNode* reverseKGroup(ListNode* head, int k){
        if(head == nullptr || head->next == nullptr || k == 1) return head;
        ListNode dummy(0), *p = &dummy, *first = head, *last = head;
        p->next = head;
        while(last && k-1 >0){
            k--;
            last = last->next;
        }
        if(last!=nullptr){
            last = last->next;
            ListNode *prev = nullptr, *next, *cur=head;
            while(cur!=last){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            first->next = reverseKGroup(last, k);
            p->next = prev;
        }
        return dummy.next;
    }
};
ListNode* createList(vector<int>& nums){
    ListNode dummy(0), *p = &dummy;
    for(int i =0; i<nums.size(); i++){
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return dummy.next;
}
int main(int argc, char** argv){
    Solution solution;
    int arr[]={1,2,3,4,5};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));
    ListNode *root = createList(vec);
    solution.reverseKGroup(root,2);
    return 0;
}
