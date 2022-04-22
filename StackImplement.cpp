#include <iostream>
using namespace std;

struct node{
	int data;
	node *ptr;
};
class Stack{
	private:
	node *next;
    node *top;
public:
Stack(){
	next=top=NULL;
}
void display( ){
    next=top;
    if (next==NULL)
    {
        cout<<"Stack is empty\n";
    }
    else
    {
        while(next!=NULL){
		    cout<<"| "<<next->data<<" |"<<endl;
		    next=next->ptr;
	    }    
    }
}	
void push(int x){
    if (top==NULL)	
	{
		next= new node;
		next->data = x;
		next->ptr = NULL;
		top=next;
	}
	else
	{
		next=new node;
		next->data =x;
		next->ptr=top;
		top=next;		
	}
} 
void pop(){
	if (isEmpty())	
	{
		cout<<"Stack is empty\n";
	}
	else
	{
        node *temp;
		temp=top;
        top=top->ptr;
        delete (temp);
        cout<<"Element popped successfully.\n";		
	}
} 
void peek(){
	if (top==NULL)	
	{
		cout<<"Stack is empty\n";
	}
	else
	{
        cout<<"The top element is:\n";
        cout<<top->data<<endl;		
	}
} 
bool isEmpty(){
    if (top==NULL)
    {
        return true;
    }
    else{
        return false;
    }
}
};
int main(){
    Stack obj;
    int data,op;
    while (op!=7)
    {
        cout<<"=====================================================\n";
        cout<<"Stack using single linked list\n";
        cout<<"=====================================================\n";
        cout<<"1. Push()\n2. Pop()\n3. Display()\n4. Peak\n5. isEmpty()\n6. Clear Screen\n7. Exit\n";
        cin>>op;
        switch (op)
        {
        case 1:
            cout<<"Enter Number to enter into stack:\n";
            cin>>data;
            obj.push(data);
            break;
        
        case 2:
            obj.pop();
            break;
        
        case 3:
            cout<<"Stack:\n";
            obj.display();
            break;
        
        case 4:
            obj.peek();
            break;
        
        case 5:
            if (obj.isEmpty())
            {
                cout<<"Stack is empty\n";
            }
            else{
                cout<<"Stack is not empty\n";
            }
            break;
        
        case 6:
            system("CLS");
            break;
        
        default:
            cout<<"Operation not recognized. Kindly choose correct option [1-5].\n";
            break;
        }
    }
    return 0;
}
