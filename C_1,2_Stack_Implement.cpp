#include <iostream>
#include <stdio.h>
#define Sz 10005
using namespace std;
int Stack[Sz];
int top;
void push(int x){
    if(top>=Sz)
        printf("Stack Overflow\n");
    else Stack[++top] = x;
}

int pop(){
    if(top<=0)
        printf("Stack Underflow\n");
    else return Stack[top--];
}

int main(){
    int i , j , n;
    push(10);
    push(20);
    cout<<pop()<<endl;
    push(30);
    cout<<pop()<<endl;

    return 0;
}
