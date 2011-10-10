#include <iostream>
#include "dlist.h"

using namespace std;

int main(){
Dlist<int> ilist;
int aa [5] = { 16, 2, 77, 40, 12071 };
for (int i=0;i<5;i++){
	ilist.insertBack(&aa[i]);
}
//int *result = ilist.removeBack();
//cout << *result << endl;

//ilist.~Dlist();
Dlist<int> ilist2=ilist;

int *result = ilist2.removeBack();
cout << *result << endl;
return 0;
}