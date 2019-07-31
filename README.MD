# Implementiaton Of Dynamic STACK structure as Linked List

## Intro:

This project is done as part of the DATA STRUCTURE & ORGANIZATION course for my undergraduate studies.


## Details Of Requirement:

** Term Project Details
*** ASSIGNMENT DEFINITION:
Write a complete C++ program to convert an infix equation to postfix, and to evaluate the postfix expression. Also, the program should check for the parenthesis first. Your program should have three separate functions: one for parenthesis checker, one for postfix conversion, and another one for postfix expression evaluation. The stacks should be dynamic stacks. Use linked list implementations to implement dynamic stacks. The algorithms of the problems are given below:
Algorithm for parenthesis checker:
Struct stack s
s=empty_stack // initialize the stack

valid =true
while( not read entire string)
{
	read the next symbol (symb) of the string
if(symb = = ‘(‘ || symb = = ‘[‘ || symb = = ‘{‘  )
	push(&s, symb)

if(symb = = ‘)‘ || symb = = ‘]‘ || symb = = ‘}‘  )
	if(empty_stack)
		valid = false
	else{
i = pop(&s)
if( i is not the matching opener of symb)
	valid = false
  		       }
}

if(!empty_stack)
	valid = false

if(valid)
	cout<<”String is valid”;
else
	cout<<”String is not valid (invalid)”;


Algorithm For Infix/Postfix Conversion: 

struct stack s
s=empty stack
while(not end of input)
{
	symb=next input character
if(symb is an operand)
	add symb to the postfix string
else{

	while(!is_empty(&s) && prcd(stackTop(&s), sybm))
	{
		topsymb= pop(&s)
		add topsymb to the postfix string
}

if(is_empty(&s) || symb!=’)’)
	push(&s, symb)
else
	topsymb=pop(&s)  //pop the open parenthesis and discard it
       
      }

}

while(!is_empty(&s)) //output any remaining operators
{
	topsymb=pop(&s)
	add topsymb to the postfix string
}
Process can be summarized by two simple rules:
1.	If the precedence of the input operator is higher then the precedence of the operator currently in the stack, then push the input operator onto the stack.
2.	If the precedence of the input operator is lower (or equal) then the precedence of the operator currently in the stack, then pop the operator from the stack and send it to the postfix string.
Note That: 
Preceding function:
 (if this function is return true then operator is popped, See Rule 2)
prcd(stackTop(&s), sybm)


prcd( ‘+’, ’+’);  true
prcd( ‘+’, ’-’);  true
prcd( ‘+’, ’*’);  false
prcd( ‘+’, ’/’);  false	
prcd( ‘-’, ’+’);  true
prcd( ‘-’, ’-’);  true
prcd( ‘-’, ’*’);  false
prcd( ‘-’, ’/’);  false
	
prcd( ‘*’, ’+’);  true
prcd( ‘*’, ’-’);  true
prcd( ‘*’, ’*’);  true
prcd( ‘*’, ’/’);  true
	
prcd( ‘/’, ’+’);  true
prcd( ‘/’, ’-’);  true
prcd( ‘/’, ’*’);  true
prcd( ‘/’, ’/’);  true



Algorithm of Evaluation of the Postfix Expressions:
….
Struct stack s;
s.top=-1 //Initialize stack
while(not end of input)
{
	symb = next input string
	if(symb is an operand)
		push(&s, symb)
	else {
		oprd2=pop(&s)
		oprd1=pop(&s)
		value = result of applying symb to oprd1 and oprd2
		push(&s, value)
}
}
result =pop(&s)
return ( result ) // return result
…..	return ( pop(&s) )


IMPORTANT NOTES:
•	Write user defined functions when necessary.
•	Use dynamic structures: Linked Lists for stack implementations.
•	Please upload your source code as .cpp file through the Moodle. 
•	The source codes will undergo similarity check process.

Write a complete C++ program to convert an infix equation to postfix, and to evaluate the postfix expression. Also, the program should check for the parenthesis first. Your program should have three separate functions: one for parenthesis checker, one for postfix conversion, and another one for postfix expression evaluation. The stacks should be dynamic stacks. Use linked list implementations to implement dynamic stacks. The algorithms of the problems are given below:
Algorithm for parenthesis checker:
Struct stack s
s=empty_stack // initialize the stack

valid =true
while( not read entire string)
{
	read the next symbol (symb) of the string
if(symb = = ‘(‘ || symb = = ‘[‘ || symb = = ‘{‘  )
	push(&s, symb)

if(symb = = ‘)‘ || symb = = ‘]‘ || symb = = ‘}‘  )
	if(empty_stack)
		valid = false
	else{
i = pop(&s)
if( i is not the matching opener of symb)
	valid = false
  		       }
}

if(!empty_stack)
	valid = false

if(valid)
	cout<<”String is valid”;
else
	cout<<”String is not valid (invalid)”;


Algorithm For Infix/Postfix Conversion: 

struct stack s
s=empty stack
while(not end of input)
{
	symb=next input character
if(symb is an operand)
	add symb to the postfix string
else{

	while(!is_empty(&s) && prcd(stackTop(&s), sybm))
	{
		topsymb= pop(&s)
		add topsymb to the postfix string
}

if(is_empty(&s) || symb!=’)’)
	push(&s, symb)
else
	topsymb=pop(&s)  //pop the open parenthesis and discard it
       
      }

}

while(!is_empty(&s)) //output any remaining operators
{
	topsymb=pop(&s)
	add topsymb to the postfix string
}
Process can be summarized by two simple rules:
1.	If the precedence of the input operator is higher then the precedence of the operator currently in the stack, then push the input operator onto the stack.
2.	If the precedence of the input operator is lower (or equal) then the precedence of the operator currently in the stack, then pop the operator from the stack and send it to the postfix string.
Note That: 
Preceding function:
 (if this function is return true then operator is popped, See Rule 2)
prcd(stackTop(&s), sybm)


prcd( ‘+’, ’+’);  true
prcd( ‘+’, ’-’);  true
prcd( ‘+’, ’*’);  false
prcd( ‘+’, ’/’);  false	
prcd( ‘-’, ’+’);  true
prcd( ‘-’, ’-’);  true
prcd( ‘-’, ’*’);  false
prcd( ‘-’, ’/’);  false
	
prcd( ‘*’, ’+’);  true
prcd( ‘*’, ’-’);  true
prcd( ‘*’, ’*’);  true
prcd( ‘*’, ’/’);  true
	
prcd( ‘/’, ’+’);  true
prcd( ‘/’, ’-’);  true
prcd( ‘/’, ’*’);  true
prcd( ‘/’, ’/’);  true



Algorithm of Evaluation of the Postfix Expressions:
….
Struct stack s;
s.top=-1 //Initialize stack
while(not end of input)
{
	symb = next input string
	if(symb is an operand)
		push(&s, symb)
	else {
		oprd2=pop(&s)
		oprd1=pop(&s)
		value = result of applying symb to oprd1 and oprd2
		push(&s, value)
}
}
result =pop(&s)
return ( result ) // return result
…..	return ( pop(&s) )


IMPORTANT NOTES:
•	Write user defined functions when necessary.
•	Use dynamic structures: Linked Lists for stack implementations.
•	Please upload your source code as .cpp file through the Moodle. 
•	The source codes will undergo similarity check process.

Write a complete C++ program to convert an infix equation to postfix, and to evaluate the postfix expression. Also, the program should check for the parenthesis first. Your program should have three separate functions: one for parenthesis checker, one for postfix conversion, and another one for postfix expression evaluation. The stacks should be dynamic stacks. Use linked list implementations to implement dynamic stacks. The algorithms of the problems are given below:
Algorithm for parenthesis checker:
```Struct stack s
s=empty_stack // initialize the stack

valid =true
while( not read entire string)
{
	read the next symbol (symb) of the string
if(symb = = ‘(‘ || symb = = ‘[‘ || symb = = ‘{‘  )
	push(&s, symb)

if(symb = = ‘)‘ || symb = = ‘]‘ || symb = = ‘}‘  )
	if(empty_stack)
		valid = false
	else{
i = pop(&s)
if( i is not the matching opener of symb)
	valid = false
  		       }
}

if(!empty_stack)
	valid = false

if(valid)
	cout<<”String is valid”;
else
	cout<<”String is not valid (invalid)”;```


Algorithm For Infix/Postfix Conversion: 

```struct stack s
s=empty stack
while(not end of input)
{
	symb=next input character
if(symb is an operand)
	add symb to the postfix string
else{

	while(!is_empty(&s) && prcd(stackTop(&s), sybm))
	{
		topsymb= pop(&s)
		add topsymb to the postfix string
}

if(is_empty(&s) || symb!=’)’)
	push(&s, symb)
else
	topsymb=pop(&s)  //pop the open parenthesis and discard it
       
      }

}

while(!is_empty(&s)) //output any remaining operators
{
	topsymb=pop(&s)
	add topsymb to the postfix string
}```
Process can be summarized by two simple rules:
1.	If the precedence of the input operator is higher then the precedence of the operator currently in the stack, then push the input operator onto the stack.
2.	If the precedence of the input operator is lower (or equal) then the precedence of the operator currently in the stack, then pop the operator from the stack and send it to the postfix string.
Note That: 
```Preceding function:
 (if this function is return true then operator is popped, See Rule 2)
prcd(stackTop(&s), sybm)


prcd( ‘+’, ’+’);  true
prcd( ‘+’, ’-’);  true
prcd( ‘+’, ’*’);  false
prcd( ‘+’, ’/’);  false	
prcd( ‘-’, ’+’);  true
prcd( ‘-’, ’-’);  true
prcd( ‘-’, ’*’);  false
prcd( ‘-’, ’/’);  false
	
prcd( ‘*’, ’+’);  true
prcd( ‘*’, ’-’);  true
prcd( ‘*’, ’*’);  true
prcd( ‘*’, ’/’);  true
	
prcd( ‘/’, ’+’);  true
prcd( ‘/’, ’-’);  true
prcd( ‘/’, ’*’);  true
prcd( ‘/’, ’/’);  true```



Algorithm of Evaluation of the Postfix Expressions:
….
```Struct stack s;
s.top=-1 //Initialize stack
while(not end of input)
{
	symb = next input string
	if(symb is an operand)
		push(&s, symb)
	else {
		oprd2=pop(&s)
		oprd1=pop(&s)
		value = result of applying symb to oprd1 and oprd2
		push(&s, value)
}
}
result =pop(&s)
return ( result ) // return result
…..	return ( pop(&s) )```


IMPORTANT NOTES:
•	Write user defined functions when necessary.
•	Use dynamic structures: Linked Lists for stack implementations.
•	Please upload your source code as .cpp file through the Moodle. 
•	The source codes will undergo similarity check process.


## Installation:
In order for this to work a c/c++ compiler is needed. Search online for Dev-C++.
## Usage:
download the .cpp file and compile using the dev-c++ and run.
## License:
MIT