#include <bits/stdc++.h>
using namespace std;
struct Person{
    string name;
    int age;
    Person(int Age,const string &Name){
        cout<<Name<<" just called base constructor"<<endl;
        age = Age;
        name = Name;
    }
    Person(const Person&cp):Person(cp.age,cp.name){
        cout<<name<<" just called copy constructor"<<endl;
    }

    Person(Person&&mv):name(move(mv.name)){
        age = mv.age;
        cout<<name<<" just called move constructor"<<endl;
    }

};
void check1(Person a){
    cout<<"after first check"<<endl;
}

void check2(const Person &a){
    cout<<"after second check"<<endl;
}
int main(int argc,char**argv){
    Person me(17,"JoJo");
    cout<<"Begin parameter test<<"<<endl;
    check1(me);
    check2(me);
    cout<<"Begin move constructor test<<"<<endl;
    vector<Person>PP;
    PP.emplace_back(Person(118,"DIO"));
    PP.emplace_back(Person(17,"Jotaro"));
    cout<<PP.size()<<endl;
}