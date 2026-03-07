#include <iostream>
using namespace std;

int main(void){
      
   int  arr[]={1,2,3,4,5};
    cout << "Original (before swap)"<< endl;
    cout << "Second element : "<< arr[1]<<endl;
    cout << "Forth element : "<< arr[3] << endl;
 

    int*  y1 = &arr[1];  // address storing for element 2 
  
    int*  y2 = &arr[3];   // address storing for element 4 
     
     int  temp= *y1;
     *y1 = *y2;
      *y2= temp ;


       cout<< "After swap"<< endl;
       cout << "Second element : "<< arr[1]<<endl;
    cout << "Forth element : "<< arr[3] << endl;


 
}
