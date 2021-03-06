#include<iostream>
using namespace std; 
class node 
{
	public:
		int data;          // data = entered value 
		node* next;        // next = pointer 
		// CONSTRUCTOR 	IS CREATED 
	node (int d)
	{
		data = d;            // The input data 
		next = NULL;         // The adress value 
	}
}; 
// Inserting at the head 
void insertAtHead(node* &head , int data)
{
	node *n = new node(data);
	n -> next = head;
	head = n;
}
// Counting the length of the linked list 
int length(node *head)
{
	int count = 0;
	
	while(head != NULL)
	{
		head = head -> next;
		count +=1;
	}
	return count;
}
//Inserting the node at the Tail 
void insertatTail(node* &head, int data)
{
	if(head == NULL)
	{
		head = new node(data);
        return;
	}
	node *tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	node* n = new node(data);
    tail->next = n;
	return;
	
}
//Inserting the node at the middle 
void insertIntheMiddle(node* &head , int data , int p)
{
	if(head == NULL || p == 0)
	{
		insertAtHead(head,data);
		
	}
	else if(p > length(head))
	{
		insertatTail(head,data);
	}
	else
	{
		//Insert in the middle 
		//Take p-1 jumps 
		int jump = 1;
		node*temp = head;
		while(jump<=p-1)
		{ 
			temp = temp -> next;
			jump +=1; 
		}
		node*n = new node(data);
		n->next = temp->next;
		temp->next = n;
	}
	return;
}

//Deleting using the middle 


void print(node* head)
{
    node *temp = head;
    while(temp!= NULL)
    {
         cout<<temp->data<<"->"; //temp->data is used to access the data in the linked list 
         temp= temp -> next;  // Next is used to move to next variable 
     }
}     
int main()
{
    node *head = NULL; 
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertatTail(head,5);
    insertIntheMiddle(head,2,2);
    print(head);
    return 0;
 }