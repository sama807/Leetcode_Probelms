#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int nodeCount(ListNode* head) {
    int count = 0;
    ListNode* curr = head;

    while (curr != nullptr) {
            count++;
            curr = curr->next;
    }

    return count;
}

ListNode* deleteMiddle(ListNode* head) {

    int nodesCount = nodeCount(head);
    //nodes count start from zero 0th index is the first node ....
    int n = nodesCount/2 ;
    if (nodesCount <= 1) {
        delete head;
        return nullptr;
    }
    if(nodesCount == 2){

        delete head->next;
        head->next = nullptr;
        return head;
    }
    ListNode* pre = head;
    ListNode* p = head;
    for(int i=0; i<n; i++){
        pre = p;
        p = p->next;
    }   
    pre->next = p->next;
    delete p;  
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
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);
    
    head = deleteMiddle(head);
    cout<<"List after deleteion: ";
    printList(head);

    
}