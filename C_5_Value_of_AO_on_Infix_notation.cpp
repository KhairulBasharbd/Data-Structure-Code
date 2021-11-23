#include <stdio.h>
#include <iostream>
#define Sz 100005
using namespace std;
int value[Sz],value_size;
char store[Sz];
int store_size;

void store_push(char ch){
    store[++store_size] = ch;
}
char store_pop(){
    return store[store_size--];
}

void value_push(int item){
    value[++value_size] = item;
}
int value_pop(){
    return value[value_size--];
}

bool Operator(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return true;
    else return false;
}

int Precedence(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else return 1;
}

int apply(char ch , int a , int b){
    switch(ch){
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
    }
}

int Process_value(){
    int val1 = value_pop();
    int val2 = value_pop();
    char sign = store_pop();
    int val = apply(sign,val2,val1);
    return val;
}

int solve(string a){
    int len , i , j , x , digit = 0 , val;
    len = a.size();
    cout<<a<<endl;
    for(i = 0 ; i < len ; i++){
        if(a[i] == '(')
            store_push(a[i]);

        else if(a[i] >= '0' && a[i]<='9'){
            digit = 0;
            while(a[i]>='0' && a[i]<='9'){
                x = (int)a[i] - '0';
                digit = digit * 10 + x;
                i++;
            }
            i--;
            value_push(digit);
        }

        else if(a[i] == ')'){
            while(store_size>0 && store[store_size]!= '('){
                val = Process_value();
                value_push(val);
            }
            store_pop();
        }

       else if(Operator(a[i])){
            while(store_size>0 && Precedence(a[i]) < Precedence(store[store_size])){
                val = Process_value();
                value_push(val);
            }
            store_push(a[i]);
       }


    }
    return value_pop();
}

int main(){
    int i, j , n;
    //freopen("riyad.txt","r",stdin);
    string a , b;
    a = "(";
    getline(cin,b);
    a += b;a.append(")");
    cout<<solve(a)<<endl;

    return 0;
}
