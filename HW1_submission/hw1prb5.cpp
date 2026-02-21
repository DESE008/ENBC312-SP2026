#include <iostream>
using namespace std;

int main(){
   
  int n;
  cout << "Enter integer count : ";
  cin >> n;


  int sum = 0;
  int number ;


  cout << "Enter the desired " << n << " integers (press enter after  each integer)  :"<< endl;

  for (int i =0; i < n; i++){
  cin >> number;
  sum += number; 


} 

  cout << " The sum of the desired integers =  " << sum << endl;

  return 0;




}
