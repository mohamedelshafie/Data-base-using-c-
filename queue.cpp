#include <iostream>
using namespace std;

class queue{
    private:
        struct node{
            int data;
            struct node *next;
        };
        struct node *front = NULL;
        struct node *rear = NULL;
        struct node *current = NULL;
    public:
        void Enqueue(int);
        void Dequeue();
        int Peek();
};
void queue::Enqueue(int data){

	struct node *newNode = (struct node*) malloc(sizeof(struct node));

	newNode->data = data;
	newNode->next = NULL;

	if(front==NULL){
		front = newNode;
		rear = newNode;
		return;
	}
	rear->next = newNode;
	rear = newNode;
}

void queue::Dequeue(){
   struct node *remove_node = front;
   if(front == NULL){
	   return;
   }
   front = front->next;
   free(remove_node);
}

int queue::Peek(void)
{
	return front->data;
}