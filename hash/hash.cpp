#include <bits/stdc++.h>
using namespace std;
struct Person{
    int age;
    string name;
    Person(int AGE,const string &Name){
        age = AGE;
        name = Name;
    }
    Person(const Person&cp):Person(cp.age,cp.name){}
};
size_t hashInt(long int x)
{
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x);
    return x;
}

// http://www.cse.yorku.ca/~oz/hash.html
// hash function for string keys djb2
size_t hashString(const char * str)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

struct Hash{
    size_t operator()(const Person&cp) const noexcept  {
        return hashInt(cp.age)+hashString(cp.name.c_str());
    }
};
struct Equal{
    bool operator()(const Person&a,const Person&b) const noexcept {
        return a.name==b.name && a.age==b.age;
    }
};
int main(int argc,char**argv){
    unordered_set<Person,Hash,Equal>st;
    //Person me(17,"Jojo");
    st.insert(Person(17,"JoJo"));
    st.insert(Person(29,"Jotaro"));

    auto it = st.find(Person(17,"JoJo"));
    cout<<(it==st.end())<<endl;

    it = st.find(Person(118,"DIO"));
    cout<<(it==st.end())<<endl;

    st.erase(Person(17,"JoJo"));
    it = st.find(Person(17,"JoJo"));
    cout<<(it==st.end())<<endl;
    cout<<"size:"<<st.size()<<endl;
}