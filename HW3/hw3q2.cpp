#include <iostream>
using namespace std;


int main(){

int a;
int b;

 cout << "Enter two integers followd by 'Enter' after each"<< endl;
 cin >> a ;
cin >> b ;


int *p1 = &a;
int *p2 = &b;

int sum = *p1 + *p2;

cout << "The sum of the entered two integers : "<<sum <<endl;
 return 0;

}
