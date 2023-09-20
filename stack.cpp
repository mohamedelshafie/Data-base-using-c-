#include <iostream>
using namespace std;

class stack{
    private:
        struct node{
            int data;
            struct node *next;
        };
        struct node *top = NULL;
    public:
        void Push(int);
        void Pop();
        int Peek();
        void print();

};
void stack::Push(int data){
   struct node *newNode = (struct node*) malloc(sizeof(struct node));

   newNode->data = data;

   newNode->next = top;

   top = newNode;
}

void stack::Pop(){
   struct node *remove_node = top;

   if(top == NULL){
	   return;
   }

   top = top->next;

   free(remove_node);
}

int stack::Peek(){
	return top->data;
}

void stack::print(){

   struct node *newNode = top;

   while(newNode != NULL){
      cout<<"data= "<<newNode->data;
      newNode = newNode->next;
   }

   cout<<endl;
}

int main(){
    stack s1;
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);
    s1.Pop();
    s1.print();


}