#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == nullptr || head->next == nullptr || left == right) {
        return head; // No need to reverse
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* curr = head;

    // Move pre to the node before the left-th node
    for (int i = 1; i < left; i++) {
        pre = curr;
        curr = curr->next;
    }

    ListNode* pre_left = pre;
    ListNode* left_node = curr;
    ListNode* next_node = nullptr;

    // Reverse the sublist between left and right
    for (int i = left; i <= right; i++) {
        next_node = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next_node;
    }

    // Connect the sublist with the rest of the list
    pre_left->next = pre;
    left_node->next = curr;

    head = dummy->next; // Update head if left is the first node
    delete dummy; // Release the memory allocated for dummy

    return head;
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
    // Create a sample linked list: 1 -> 2 -> 3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Reverse the list
    head = reverseBetween(head, 1, 2);

    cout << "Reversed list: ";
    printList(head);

}