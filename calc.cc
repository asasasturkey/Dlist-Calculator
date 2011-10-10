#include <iostream>
#include <string>
#include <cstdlib>
#include "altnew.h"
#include "dlist.h"

using namespace std;

void notEnoughOperandError(){
	cout << "Not enough operands\n";
}
void badInputError(){
	cout << "Bad input\n";
}
void divZeroError(){
	cout << "Divide by zero\n";
}
void add(Dlist<double> *stack){
	double *operand1=NULL,*operand2=NULL;
	try{
		operand1=stack->removeFront();
		operand2=stack->removeFront();
		double *result=new double(*operand2+*operand1);
		stack->insertFront(result);
		result=NULL;
		delete operand1;
		delete operand2;
	}
	catch(emptyList e){
		if(operand1!=NULL){
			stack->insertFront(operand1);
		}
		notEnoughOperandError();
	}
}
void sub(Dlist<double> *stack){
	double *operand1=NULL,*operand2=NULL;
	try{
		operand1=stack->removeFront();
		operand2=stack->removeFront();
		double *result=new double(*operand2-*operand1);
		stack->insertFront(result);
		result=NULL;
		delete operand1;
		delete operand2;
	}
	catch(emptyList e){
		if(operand1!=NULL){
			stack->insertFront(operand1);
		}
		notEnoughOperandError();
	}
}
void mult(Dlist<double> *stack){
	double *operand1=NULL,*operand2=NULL;
	try{
		operand1=stack->removeFront();
		operand2=stack->removeFront();
		double *result=new double(*operand2 * *operand1);
		stack->insertFront(result);
		result=NULL;
		delete operand1;
		delete operand2;
	}
	catch(emptyList e){
		if(operand1!=NULL){
			stack->insertFront(operand1);
		}
		notEnoughOperandError();
	}
}

void div(Dlist<double> *stack){
	double *operand1=NULL,*operand2=NULL;
	try{
		operand1=stack->removeFront();
		operand2=stack->removeFront();
		if(*operand1==0){
			divZeroError();
			stack->insertFront(operand2);
			stack->insertFront(operand1);
		}
		else{
			double *result=new double(*operand2 / *operand1);
			stack->insertFront(result);
			result=NULL;
			delete operand1;
			delete operand2;
		}
	}
	catch(emptyList e){
		if(operand1!=NULL){
			stack->insertFront(operand1);
		}
		notEnoughOperandError();
	}
}

void neg(Dlist<double> *stack){
	double *operand;
	if(stack->isEmpty()){
		cout << "Not enough operands\n";
	}
	else{
		operand=stack->removeFront();
		*operand=-*operand;
		stack->insertFront(operand);
	}
	operand=NULL;
}

void dup(Dlist<double> *stack){
	double *operand;
	if(!stack->isEmpty()){
		operand=stack->removeFront();
		double *copy=new double(*operand);
		stack->insertFront(operand);
		stack->insertFront(copy);
	}
	else{
		notEnoughOperandError();
	}
	operand=NULL;
}


void print(Dlist<double> *stack){
	double *operand;
	if(!stack->isEmpty()){
		operand=stack->removeFront();
		cout<<*operand<<endl;
		stack->insertFront(operand);
	}
	else{
		notEnoughOperandError();
	}
	operand=NULL;
}

void clear(Dlist<double> *stack){
	stack->~Dlist();
}

void rev(Dlist<double> *stack){
	double *operand1=NULL,*operand2=NULL;
	try{
		operand1=stack->removeFront();
		operand2=stack->removeFront();
		stack->insertFront(operand1);
		stack->insertFront(operand2);
	}
	catch(emptyList e){
		if(operand1!=NULL){
			stack->insertFront(operand1);
		}
		notEnoughOperandError();
	}
}
void printa(Dlist<double> *stack){
	double *operand;
	Dlist<double> *temp=new  Dlist<double>;
	bool first=true;
	while(!stack->isEmpty()){
		operand=stack->removeFront();
		if(first){
			cout<<*operand;first=false;
		}
		else{
			cout<<" "<<*operand;
		}
		temp->insertBack(operand);
	}
	cout<<endl;
	*stack=*temp;
	delete temp;
	operand=NULL;
}

int main(){
	Dlist<double> *stack=new Dlist<double>;
	string input;
	unsigned int dotc=0;
	unsigned int digitc=0;
	while(true){
		getline(cin,input);
		if(input.compare("q")==0){
			return 0;
		}
		else if(input.compare("a")==0){
			printa(stack);
		}
		else if(input.compare("p")==0){
			print(stack);
		}
		else if(input.compare("d")==0){
			dup(stack);
		}
		else if(input.compare("n")==0){
			neg(stack);
		}
		else if(input.compare("c")==0){
			clear(stack);
		}
		else if(input.compare("r")==0){
			rev(stack);
		}
		else if(input.compare("+")==0){
			add(stack);
		}
		else if(input.compare("-")==0){
			sub(stack);
		}
		else if(input.compare("*")==0){
			mult(stack);
		}
		else if(input.compare("/")==0){
			div(stack);
		}
		else{//number
			for(unsigned int i=0;i<input.size();i++){
				if(input[i]=='.'){
					dotc++;
					if (!(dotc>1||i==0||i==input.size()-1)){
						digitc++;
					}
				}
				if (input[i]>='0'&&input[i]<='9'){
					digitc++;
				}
			}
			if(digitc==input.size()&&digitc>=1){
				double *num=new double(atof(input.c_str()));
				stack->insertFront(num);
			}
			else{
				badInputError();
			}
			digitc=0;
			dotc=0;
		}
		cout<<bytes_allocated()<<endl;
	}
	return 0;
}