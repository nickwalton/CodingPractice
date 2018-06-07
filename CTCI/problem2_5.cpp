#include <iostream>

using namespace std;


struct node {
  int val;
  node* next;
};

int sum_helper(node* node){
  if(!node->next){
    return node->val;
  }
  else{
    return node->val + sum_helper(node->next)*10;
  }
}

int recursive_sum(node* head1, node* head2){

  return sum_helper(head1) + sum_helper(head2);

}

int main(){
  
  node node1,node2,node3;
  node1.next = &node2;
  node2.next = &node3;
  node3.next = NULL;

  node1.val = 7;
  node2.val = 1;
  node3.val = 6;
  
  node node4,node5,node6;
  node4.next = &node5;
  node5.next = &node6;
  node6.next = NULL;

  node4.val = 5;
  node5.val = 9;
  node6.val = 2;

  cout << "Sum is " << recursive_sum(&node1, &node4);


  return 0;
}
