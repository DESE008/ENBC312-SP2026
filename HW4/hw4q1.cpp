#include <iostream>
#include <string>
using namespace std;


class Car{
 
private: 

string brand;

int year;


public: 

void  setBrand(string a){

brand = a;


}

void  setYear(int b){

year = b;


}

void display(){

cout << "Brand : " << brand <<endl;
cout << "year : " << year<< endl;

}

};


int main(){

Car c;

c.setBrand ("Toyota");
c.setYear (2020);

c.display();

 return 0;
}
