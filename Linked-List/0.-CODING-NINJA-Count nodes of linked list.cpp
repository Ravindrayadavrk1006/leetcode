/*
  1.see the defintion of linked list class
  2.how to travese the linked list
  3. never temper the head
*/



class Node
{
  public:
      int data;
      Node *next;
      Node()
      {
          this->data = 0;
          next = NULL;
      }
      Node(int data)
      {
          this->data = data;
          this->next = NULL;
      }
      Node(int data, Node* next)
      {
          this->data = data;
          this->next = next;
      }
};

int length(Node *head)
{
    Node* traverser = head;
    int count = 0;
    while(traverser){
        count++;
        traverser = traverser->next;
    }
    return count;
}
