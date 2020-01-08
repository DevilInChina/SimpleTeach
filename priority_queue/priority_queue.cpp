#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct Integer{
    int value;
    Integer(int a){
        value = a;
    }
    bool operator<(const Integer&a)const{
        return value>a.value;
    }
};

struct cmp{
    ///重载圆括号运算符。
    bool operator()(const Integer&a,const Integer&b){
        return a.value<b.value;
    }
};

int main(int argc,char **argv){
    int k = atoi(argv[1]);

    priority_queue<Integer,vector<Integer> , cmp>great_heap;

    priority_queue<Integer>less_heap;

    for(int i = 0 ; i < k ; ++i){
        great_heap.push(i);
        less_heap.push(i);
    }
    while (!less_heap.empty()){
        cout<<less_heap.top().value<<' ' <<great_heap.top().value<<endl;
        less_heap.pop();
        great_heap.pop();
    }
}