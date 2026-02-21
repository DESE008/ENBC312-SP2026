#include <iostream>
using namespace std;


void number_between(int a, int b){
     if (a >= b){
        cout << "Error: b must be greater than a "<< endl;



      return;
}

      for (int number = a +1 ; number < b; number++){
       cout << number << " ";
        }
        
       cout << endl;

}


int main() {
   int a,b;


   cout << "Enter integer value for a : ";
   cin >> a;

    cout << "Enter integer value for b : ";
    cin >> b;

     number_between(a,b);

     return 0;

}
