#include <iostream>
#include <string>

using namespace std;

int calfunc(int a, int b){
          return a*b+200;
}


int main(){

    cout << " Calculation try 1 for integers 5,3 :" <<  calfunc(5,3) << endl;
    cout << " Calculation try 2 for integers 22,10 :" <<  calfunc(22,10) << endl;
    cout << " Calculation try 3 for integers 1,1 :" << calfunc(1,1) << endl;
    return 0;
}
