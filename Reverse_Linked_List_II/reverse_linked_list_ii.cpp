#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr||head->next==nullptr) return head;
        ListNode dummy(0), *p = &dummy, *prev=&dummy, *cur=head, *next;
        p->next = head;
        while(n > 0){
            if(m-1 > 0){
                p = p->next;
                prev = p;
                cur = p->next;
            }else{
                next = cur->next;
                
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            m--;
            n--;
        }
        ListNode *tmp = p->next;
        p->next = prev;
        tmp->next = cur;
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
    int arr[]={3,5};
    vector<int> vec(arr, arr+sizeof(arr)/sizeof(arr[0]));
    ListNode *root = createList(vec);
    solution.reverseBetween(root,1,1);
    return 0;
}
