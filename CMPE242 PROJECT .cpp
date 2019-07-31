/**
**contributed by: Ahmed Mohamed - 21808164
** ahmed.e.haddad2.0@gmail.com
**CMPE 242 Project
**/
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//declare linked list(imlpement stack as LL)
struct Node {
	char data;
	struct Node * link;
};
struct Node * top;

void push(char data);
int isEmpty();
void pop();
void display();
char Top();

int paranthesisChecker(char []);
int matching (char, char);
string infixToPostfix(char []);
void postfixEvaluation(string);


int main(void){
	
	
	do{
	system("CLS");
	
	char eq[50]={'\0'};
	string pseq;
	int i=0;
	
	cout<<"Please enter the equation:";
	do{
		cin>>eq[i++];
	}while( cin.peek() != '\n' );
	
	
	if (paranthesisChecker(eq)){
		
		cout << "\nPress Enter to continue to conversion"; getch();
		system("CLS");
		cout << "Postfix Expression: ";
		pseq=infixToPostfix(eq);
		cout << "\nPress Enter to continue to Expression Evaluation"; getch();
		system("CLS");
		cout << "Postfix Expression Evaluation: ";
		postfixEvaluation(pseq);
	}
	
	cout << "\n\n(press Esc to exit ....)"<<endl;
	getch();
	system("PAUSE");
	}while(!GetAsyncKeyState(VK_ESCAPE));
	

    return 0;
}
/*
*Dynamic stack implementaion as LL
*/
//oush equivalent to LL insertFront operation
void push(char data){
	// create new node temp and allocate memory 
    struct Node* temp; 
    temp = (struct Node*)malloc(sizeof(struct Node)); 
  
    // check if stack (heap) is full. Then inserting an element would 
    // lead to stack overflow 
    if (!temp) { 
        cout<< "\nHeap Overflow"; 
        exit(1); 
    } 
   
    temp->data = data; 
    temp->link = top; 
    top = temp; 
}

int isEmpty() 
{ 
    return top == NULL; 
} 

// Utility function to return top element in a stack 
char Top() 
{ 
    // check for empty stack 
    if (!isEmpty()) 
        return top->data; 
    else
        exit(EXIT_FAILURE); 
} 

//Return top element from the Stack and move the top pointer to the second node of linked list or Stack.
void pop() 
{ 
    struct Node* temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
        cout<< "\nStack Underflow" ; 
        exit(1); 
    } 
    else { 
        // top assign into temp 
        temp = top; 
        // assign second node to top 
        top = top->link; 
        // destroy connection between first and second 
        temp->link = NULL; 
        // release memory of top node 
        free(temp); 
        
    } 
} 

//Print all element of Stack.
void display() 
{ 
    struct Node * temp; 
  
    // check for stack underflow 
    if (top == NULL) { 
       cout <<"\nStack Underflow"; 
        //exit(1); 
    } 
    else { 
        temp = top; 
        while (temp != NULL) { 
  
            // print node data 
            cout<< temp->data ; 
  
            // assign temp link to temp (go next)
            temp = temp->link; 
        } 
    } 
    cout<<"\n"<<endl;
} 

/*
*Paranthesis checker
*/
//matching character checker
int matching (char symb, char x)
{
    if ( (x=='(' && symb==')') || (x=='[' && symb==']') || (x=='{' && symb=='}') )
      return 1;
    else 
      return 0;
}
//
int paranthesisChecker(char eq[]){
	int valid=1,i=0;
	char /*eq[50],*/symb,x;
	
	while (eq[i]!='\0')
	{
          symb = eq[i];
          if (symb=='(' || symb=='[' || symb=='{')
             push(symb); 
          if (symb==')' || symb==']' || symb=='}')
          {
             if(isEmpty())
                 valid = 0;
             else
             {
                  x = Top();
                  pop();
                  if (matching(symb,x)==0)
                     valid = 0;
             } 
          }
          cout<<"stack after symb "<<symb<<" is as follows:"<<endl;   
          display();
          i++;
     }  
     
     if(!isEmpty())
         valid = 0;

     if(valid)
    	cout<<"\n\nString is valid\n\n";
     else
	    cout<<"\n\nString is not valid (invalid)\n\n";
	return valid;
}
/*
*infix to postfix conversion
*/
//function to return the precedence of operators
int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
//
string infixToPostfix(char eq[]) 
{ 
    
    push('N'); 
     
    string ns; 
    
	int i = 0; 
    while (eq[i] != '\0')
    { 
        // If the scanned character is an operand, add it to output string. 
        if((eq[i] >= 'a' && eq[i] <= 'z')||(eq[i] >= 'A' && eq[i] <= 'Z')||(eq[i] >= '0' && eq[i] <= '9')){
		 
        	ns+=eq[i]; 
        	i++;
        }
        // If the scanned character is an ‘(‘, push it to the stack. 
        else if(eq[i] == '(') {
		
          
        	push('('); 
        	i++;
        }
          
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        else if(eq[i] == ')') 
        { 
            while(Top() != 'N' && Top() != '(') 
            { 
                char c = Top(); 
                pop(); 
               ns += c; 
            } 
            if(Top() == '(') 
            { 
                char c = Top(); 
                pop(); 
            } 
            i++;
        } 
          
        //If an operator is scanned 
        else{ 
            while(Top() != 'N' && prec(eq[i]) <= prec(Top())) 
            { 
                char c = Top(); 
                pop(); 
                ns += c; 
            } 
            push(eq[i]); 
            i++;
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(Top() != 'N') 
    { 
        char c = Top(); 
        pop(); 
        ns += c; 
    } 
      
    cout << ns << endl; 
    return ns;
  
} 

/*
*postfix evaluation
*/
//
void postfixEvaluation(string eq){
	
    int i=0;  
    // Scan all characters one by one  
    while (eq[i] != '\n')  
    {  
        // If the scanned character is an operand (number here),  
        // push it to the stack.  
        if (isdigit(eq[i])){
            push(eq[i]);
            i++;
        }
			  
  
        // If the scanned character is an operator, pop two  
        // elements from stack apply the operator  
        else
        {  
            int val1 = Top();
			pop();  
            int val2 = Top();  
            pop();
            switch (eq[i])  
            {  
            case '+': push( val2 + val1); break;  
            case '-': push( val2 - val1); break;  
            case '*': push( val2 * val1); break;  
            case '/': push( val2/val1); break;  
            }  
        }  
    }  
    //return pop();
    display();
}
