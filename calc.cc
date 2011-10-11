#include <iostream>
#include <string>
#include <cstdlib>
#include "dlist.h"

using namespace std;
void notEnoughOperandsError(const char* op) { 
  cout << op << ": Not enough operands" << endl; 
}
void badInputError(string input) { cout << "Bad input: " << input << endl; }
void divZeroError() { cout << "Divide by zero" << endl; }

Dlist<double> stack;
void add() {
  double* operand1 = NULL, *operand2 = NULL;
  try{
    operand1 = stack.removeFront();
    operand2 = stack.removeFront();
    stack.insertFront(new double(*operand2 + *operand1));
    delete operand1;
    delete operand2;
  }
  catch(emptyList e) {
    if (operand1) stack.insertFront(operand1);
    notEnoughOperandsError("add");
  }
}

void sub() {
  double* operand1 = NULL,*operand2 = NULL;
  try{
    operand1 = stack.removeFront();
    operand2 = stack.removeFront();
    stack.insertFront(new double(*operand2 - *operand1));
    delete operand1;
    delete operand2;
  }
  catch(emptyList e) {
    if (operand1) stack.insertFront(operand1);
    notEnoughOperandsError("sub");
  }
}

void mult() {
  double* operand1 = NULL,*operand2 = NULL;
  try{
    operand1 = stack.removeFront();
    operand2 = stack.removeFront();
    stack.insertFront(new double(*operand2 * *operand1));
    delete operand1;
    delete operand2;
  }
  catch(emptyList e) {
    if (operand1) stack.insertFront(operand1);
    notEnoughOperandsError("mult");
  }
}

void div() {
  double* operand1 = NULL,*operand2 = NULL;
  try{
    operand1 = stack.removeFront();
    operand2 = stack.removeFront();
    if (*operand1 == 0) {
      divZeroError();
      stack.insertFront(operand2);
      stack.insertFront(operand1);
    }
    else{
      stack.insertFront(new double(*operand2 / *operand1));
      delete operand1;
      delete operand2;
    }
  }
  catch(emptyList e) {
    if (operand1) stack.insertFront(operand1);
    notEnoughOperandsError("div");
  }
}

void neg() {
  if (stack.isEmpty()) 
    notEnoughOperandsError("neg");

  double* operand = stack.peekFront();
  *operand = -*operand;
}

void rev() {
  double* operand1 = NULL,*operand2 = NULL;
  try{
    operand1 = stack.removeFront();
    operand2 = stack.removeFront();
    stack.insertFront(operand1);
    stack.insertFront(operand2);
  }
  catch(emptyList e) {
    if (operand1) stack.insertFront(operand1);
    notEnoughOperandsError("rev");
  }
}

void dup() {
  if (stack.isEmpty())
    notEnoughOperandsError("dup");

  stack.insertFront(new double(*stack.peekFront()));
}


void print() {
  if (stack.isEmpty())
    notEnoughOperandsError("print");

  cout << *stack.peekFront() << endl;
}

void printa() {
  double* operand;
  Dlist<double> temp;
  cout << *stack.removeFront();
  while(!stack.isEmpty()) {
    operand = stack.removeFront();
    cout << " " << *operand;
    temp.insertBack(operand);
  }
  cout << endl;
  stack = temp;
}

void clear() { stack.clear(); }
void help();

typedef void (*cmdFunc)();
struct Command {
  string cmd;
  cmdFunc func;
  string funcName;
};
Command cmds[] = {
  {"*", mult, "multiply"},
  {"+", add, "add"},
  {"-", sub, "subtract"},
  {"/", div, "divide"},
  {"a", printa, "print all"},
  {"c", clear, "clear"},
  {"d", dup, "duplicate top item"},
  {"n", neg, "negate top item"},
  {"p", print, "print top item"},
  {"r", rev, "reverse top 2 items"},
  {"help", help, "help"}
};

void help() {
  int end = sizeof(cmds)/sizeof(Command);
  cout << end << " commands:" << endl;
  for (unsigned int i = 0; i < end; ++i) {
    cout << "  " << cmds[i].cmd << " : " << cmds[i].funcName << endl;
  }
}

bool execCommand(string input) {
  int end = sizeof(cmds)/sizeof(Command);
  for (unsigned int i = 0; i < end; ++i) {
    if (input.compare(cmds[i].cmd) == 0) {
      cmds[i].func();
      return true;
    }
  }
  return false;
}

bool addInteger(string input) {
  int digitc = 0, dotc = 0;
  for(unsigned int i = 0; i < input.size(); i++) {
    if (input[i] == '.') {
      dotc++;
      if (!(dotc > 1 || i == 0 || i == input.size() - 1))
        digitc++;
    }
    if (input[i] >= '0'&&input[i] <= '9')
      digitc++;
  }
  if (digitc == input.size() && digitc >= 1) {
    double* num = new double(atof(input.c_str()));
    stack.insertFront(num);
    return true;
  }
  return false;
}
int main() {
  string input;
  while(true) {
    getline(cin,input);
    if (input.compare("q") == 0)
      break;
    if (execCommand(input) || addInteger(input))
      continue;
    else
      badInputError(input);
  }
  return 0;
}