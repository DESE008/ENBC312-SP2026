#include <iostream>
using namespace std;

int main(){

 cout << " array = {1,2,3,4,5}"<<endl;
cout <<""<<endl;

 int arr[] = {1,2,3,4,5};
 int size = 5;
 
 for (int i = 0; i <size/2 ; i++){
    int * p1 = &arr[i];
    int * p2 = &arr[size-1-i];
    
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    
   
}

     cout <<"The flipped array results : "<< endl;
 for (int i=0; i<size;i++){
     cout <<  arr[i] << " ";
}

 cout << endl;
return 0;

}
