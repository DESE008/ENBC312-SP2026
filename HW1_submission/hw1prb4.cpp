#include <iostream>
#include <string>

using namespace std;

double calcfunc(double a, double b){
        return a*b+20.51;
}


int main(){

   cout << "Calculation trial 1 for 20.5,0.5:" << calcfunc(20.5,0.5)<< endl;
   cout << "Calculation trial 2 for 1.1,0.0: " << calcfunc(1.1,0.0)<<endl;
   cout << "Calculation trial 3 for 3.5,7.8: " << calcfunc(3.5,7.8)<<endl;

   return 0;
}
