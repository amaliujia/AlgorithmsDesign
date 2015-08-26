/*
 * parition list to two sublist - even num and odd num 
 */

#include <iostream>
#include <string>
using namespace std;

struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(NULL) {}
};

void list_push(ListNode **head, int data){
  ListNode *node = (ListNode *)malloc(sizeof(ListNode));
  node->val = data;
  node->next = *head;
  *head = node;
}

void list_print(string str, ListNode *head){
  cout << "list " << str << ": ";
  while(head != NULL){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void partition_list(ListNode *head){
  if(head == NULL){
    return;
  }

  ListNode *evenHead = NULL, *oddHead = NULL;
  ListNode *eveCur = NULL, *oddCur = NULL;

  while(head){
    if(head->val % 2 == 0){
      if(evenHead == NULL){
        evenHead = head;
        eveCur = head;
      }else{
        eveCur->next = head;
        eveCur = eveCur->next;
      }

    }else{
      if(oddHead == NULL){
        oddHead = head;
        oddCur = head;
      }else{
        oddCur->next = head;
        oddCur = oddCur->next;
      }
    }

    head = head->next;
  }

  oddCur->next = NULL;
  eveCur->next = NULL;

  list_print("even", evenHead);
  list_print("odd", oddHead);
}

int main(){
  ListNode *head = NULL;
  list_push(&head, 2);
  list_push(&head, 4);
  list_push(&head, 5);
  list_push(&head, 6);
  list_push(&head, 3);
  list_push(&head, 7);
  list_push(&head, 8);

  partition_list(head);  
}
