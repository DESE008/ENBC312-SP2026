#include <iostream>
#include <string>

using namespace std;

int main(){

  int marks;
  cout << "Enter student marks: ";
  cin>> marks;


  if (marks >= 90){
   cout <<"Corresponding Letter Grade : A " << endl;
   }

 else if (marks >= 80){
   cout <<"Corresponding Letter Grade : B " << endl;
   }

    else if (marks >= 70){
   cout <<"Corresponding Letter Grade : C " << endl;
   }


  else if (marks >= 60){
   cout <<"Corresponding Letter Grade : D " << endl;
   }


  else{
   cout <<"Corresponding Letter Grade : F " << endl;
   }
   
   return 0;

}
