#include <vector>
#include <list>
#include <deque>
#include <iostream>

using namespace std;
void My_Swap(int &A,int &B){///传引用访问的一个例子。
    if(A!=B)
    A^=B^=A^=B;
}

int main(int argc,char **argv){
    int k = atoi(argv[1]);
    vector<int>vec;///在初始化的时候传入一个整形数指定初始长度
    list<int>ls;
    deque<int>deq;
    for(int i = 0 ; i < k ; ++i){
        if(i%2==0){
            ls.push_back(i);
            deq.push_front(i);
        }else{
            ls.push_front(i);
            deq.push_back(i);
        }
        vec.push_back(i);
    }
    cout<<"vector:";
    for(int i = 0 ; i < k ; ++i){
        cout<<vec[i]<<' ';
    }
    cout<<endl;

    cout<<"deque:";
    for(int i = 0 ; i < k ; ++i){
        cout<<deq[i]<<' ';
    }
    cout<<endl;

    cout<<"list:";
    for(list<int>::iterator it = ls.begin() ; it != ls.end() ; ++it){
        cout<<*it<<' ';///和指针相同
    }
    cout<<endl;
    ///注意的是迭代器 iterator 在可访问的容器中都有
    for(auto &it:ls){///使用auto自行指定类型，冒号进行迭代访问，&代表引用访问，否则是普通的传值访问。
        if(it%2)it+=1;
    }
    for(auto it:ls){///引用访问修改导致原值被修改，
        cout<<it<<' ';
    }
    cout<<endl;
}