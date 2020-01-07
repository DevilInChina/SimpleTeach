#include <vector>
#include <iostream>
using namespace std;
void My_Swap(int &A,int &B){
    if(A!=B)
    A^=B^=A^=B;
}

int main(int argc,char **argv){
    int k = atoi(argv[1]);
    vector<int>vec;///在初始化的时候传入一个整形数指定初始长度
    for(int i = 0 ; i < k ; ++i){
        vec.push_back(i);
    }
    for(int i = 0 ; i < k ; ++i){
        cout<<vec[i]<<' ';
    }
    cout<<endl;
    for(int it:vec){
        cout<<it<<' ';
        it = 1;
    }
    cout<<endl;
    for(int it:vec){
        cout<<it<<' ';
        it = 1;
    }
    cout<<endl;
    for(int &it:vec){
        cout<<it<<' ';
        it = 1;
    }
    cout<<endl;
    for(int it:vec){
        cout<<it<<' ';
    }
    cout<<endl;
    for(auto &it:vec){
        cout<<it<<' ';
    }
    cout<<endl;
}