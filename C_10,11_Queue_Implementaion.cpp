#include <iostream>
#include <stdio.h>
#define Sz 10005
using namespace std;
int Queue[Sz];
int q_size,q_front;
void push(int x){
    if(q_size >= Sz)
        printf("Queue Overflow\n");
    else Queue[++q_size] = x;
}

int pop(){
    if(q_size == q_front)
        printf("Queue is empty\n");
    else return Queue[++q_front];
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

