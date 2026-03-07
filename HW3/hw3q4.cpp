#include <iostream>
using namespace std;

void SwapNumbers( int* a, int* b){
     

    int temp = *a ;
    *a = *b ;
    *b = temp; 

}

int main(){
   
   int x;
   int y;

   cout <<" Enter two numbers followed by the 'Enter' after each : " << endl;
   cin >> x;
   cin >> y;
   
   cout << "before swapping :" <<x << "," << y << endl;
   cout << endl;
  SwapNumbers(&x,&y);
  
  cout << "after swapping :" << x << "," << y<< endl; 
 return 0;

}
