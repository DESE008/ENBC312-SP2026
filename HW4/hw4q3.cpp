#include <iostream>
#include <string>
using namespace std;

class Animal{

private:

string species;

public:

void setSpecies(string a){

species = a;

 }
string getSpecies(){
 return species;

}
};
 
class Dog: public Animal{

private:

string breed;

public:

void setBreed(string b){
 breed = b;
}
void display(){
 cout << "Species : " <<getSpecies() << endl;
 cout << "Breed : " << breed << endl;

}


};

int main (){

Dog d;
d.setSpecies("Mamal");
d.setBreed("Labrador");
 

d.display();


return 0;

}
