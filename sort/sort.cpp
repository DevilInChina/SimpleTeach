/**
 * @这组测试程序完成对结构体Node进行不同规则的排序
 * 使用各种各样的方法完成这一操作
 */


#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdlib>///stdlib.c
using namespace std;
enum CPP_SORT_STYLE{FunctionPointer,Operator,Functional,Lambda};
#define N 100005

struct Node{
    int first,second;
    void showSelf()const{
        cout<<first<<' '<<second<<endl;
    }


    /**
     * @note 通过c++重载运算符的方法设置默认比较的函数。
     * @param a
     * @return
     */
    bool operator<(const Node&a)const{
        return first<a.first;
    }

};

void showResult(const Node*beg_p,const Node *end_p) {
    for (const Node *p = beg_p; p != end_p; ++p) {
        p->showSelf();
    }
}

Node vec[N];///编写程序时不知道要排序多少的空间，提前分派较大的空间


int CStyleCompare(const void*a,const void*b){
    int fa = ((Node*)a)->first;
    int fb = ((Node*)b)->first;
    return fa-fb;
}

void SortInCStyle(int k){
    qsort(vec,k, sizeof(Node),CStyleCompare);

}

bool CppStyleCompare(const Node&a,const Node&b){
    return a.first<b.first;
}

void SortInCppStyle(int k,int cmd = FunctionPointer){
    switch (cmd) {
        case FunctionPointer:
            sort(vec,vec+k,CppStyleCompare);
            break;
        case Operator:
            sort(vec,vec+k);
            break;
        case Functional: {
            function<bool(const Node &, const Node &)> cmp(CppStyleCompare);
            ///使用已经定义好的函数进行function类的初始化
            ///也可以使用lambda表达式进行初始化,使用方法很多可自行研究。
            sort(vec,vec+k,cmp);
        }
            break;
        case Lambda:
            sort(vec, vec + k, [](const Node &a, const Node &b) {
                return a.first < b.first;
            });
            break;
    }
}

int main(int argc,char **argv){
    srand(time(nullptr));
    int k = atoi(argv[argc-1]);
    for(int i = 0 ; i < k ; ++i){
        vec[i].first = rand()%N;
        vec[i].second = rand()%N;
    }
    SortInCppStyle(k,Functional);
    showResult(vec,vec+k);

}