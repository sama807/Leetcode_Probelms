#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    
    ListNode* curr = head->next;
    ListNode* pre = head;
    ListNode* p = head;
    if (head == nullptr || head->next == nullptr) {
            return head; // If the list is empty or has only one node, it's already reversed
        }
    while(curr!= nullptr){
        ListNode* temp = curr->next; // Store the next node
        curr->next = pre;
        pre = curr;
        curr = temp;            
    }
    head->next = nullptr;

    
    return pre;
}
// Function to print the elements of the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
    // Create a sample linked list: 1 -> 2 -> 3->4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Reverse the list
    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

}