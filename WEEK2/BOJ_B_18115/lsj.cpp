#include<deque>
#include<stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main(){
    deque<int> dq;
    int N;
    cin>>N;
    stack<int> stk;
    for(int x=1;x<=N;x++){
        int input;
        cin>>input;
        stk.push(input);
    }
    for(int x=1;x<=N;x++){
        int input = stk.top();
        stk.pop();
        if(input==1){
            dq.push_front(x);
        }
        if(input==2){
            int temp = dq.front();
            dq.pop_front();
            dq.push_front(x);
            dq.push_front(temp);
        }
        if(input==3){
            dq.push_back(x);
        }
    }
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
}