struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *slow = head, *fast=head, *prev=NULL;
        while(fast && fast->next){
            prev =  slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverse(slow);
        #if 0
        head = merge(head, slow);
        #else
        // merge two lists
        ListNode *curr = head;
        while (curr->next) {
            ListNode *tmp = curr->next;
            curr->next = slow;
            slow = slow->next;
            curr->next->next = tmp;
            curr = tmp;
        }
        curr->next = slow;
        #endif
        return;
        
    }
    ListNode* reverse(ListNode* head){
        ListNode *prev = NULL, *cur = head;
        while(head != NULL){
            head = head->next;
            cur->next = prev;
            prev = cur;
            cur = head;
        }
        return prev;
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode *ret = head1, *tmp;
        while(head1!=NULL && head2!=NULL){
            tmp = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = head2->next;
            head2 = tmp;            
        }
        if(head1) head1->next = tmp;
        return ret;
    }
};
int main(int argc, char** argv){
    Solution solution;
      
}
