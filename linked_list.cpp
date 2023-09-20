#include <iostream>
using namespace std;

class linked_list{
    private:
        struct node{
            int data;
            struct node *next;
        };
        struct node *head = NULL;
        struct node *current = NULL;
    public:
        linked_list(){};
        void insert_at_front(int);
        void insert_at_back(int);
        void print();
        void search(int);

};
void linked_list::insert_at_front(int element){
    struct node *newNode = new node;
    //or: struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->next = head;
    newNode->data = element;
    head = newNode;
}
void linked_list::insert_at_back(int element){
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = element;

   newNode->next = NULL;

   if(head==NULL){
      head = newNode;
      return;
   }

   current = head;

   while(current->next != NULL)
   {
	   current = current->next;
   }

   current->next = newNode;
}
void linked_list::print(){

   struct node *newNode = head;

   while(newNode != NULL){
      cout<<"data= "<<newNode->data;
      newNode = newNode->next;
   }

   cout<<endl;
}

void linked_list::search(int element){
   int pos = 0;

   if(this->head==NULL)
   {
      cout<<"Linked List is empty";
      return;
   }

   this->current = this->head;
   while(this->current != NULL)
   {
    if(this->current->data == element){
        cout<<"the element: "<<element<<"is found at index: "<<pos;
        return;
    }
    this->current = this->current->next;
    pos++;
   }

   cout<<"Can't find The element: "<<element;
}

int main(){
    linked_list l1;
    l1.insert_at_front(1);
    l1.insert_at_back(2);
    l1.insert_at_back(3);
    l1.print();
    l1.search(3);

}