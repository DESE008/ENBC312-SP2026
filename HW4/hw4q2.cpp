#include <iostream>
#include <string>
using namespace std;


class Book{

private: 

string title;
int pages;

public:

void setTitle(string a){
title = a;

}

void setPages(int p){

pages = p;

}

void display(){

cout << "Title : "<< title<<endl;
cout << "Pages : "<< pages<< endl;


}

};

int main(){

Book b;

b.setTitle("Alchemist");
b.setPages(208);

b.display();

return 0;
}
