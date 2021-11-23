#include <bits/stdc++.h>
#define ll long long
#define Size 1000000
using namespace std;

char Stack[Size],top=0;

void push(char x){
    if(top>=Size)
        printf("Stack Overflow\n");
    else Stack[++top] = x;
}

int pop(){
    if(top<=0)
        printf("Stack Underflow\n");
    else return Stack[top--];
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


int main(){
    int i , j , n , cnt=0 , len , tc;
    string a,res;
    char ch;
    getline(cin,a);
    res = "";
    a.insert(0,"(");
    a.append(")");
    len = a.size();
    for(i=0;i<len;i++){
        ch = a[i];
        if(Operator(ch) && Operator(Stack[top])){
            if(Precedence(ch) < Precedence(Stack[top])){
                res += pop();
                push(ch);
            }
            else push(ch);
        }

        else if(Operator(ch) || ch == '(')
            push(ch);
        else if(ch == ')'){
            while(Stack[top]!='('){
                res +=pop();
            }
            pop();
        }
        else res +=ch;
    }
    cout<<res<<endl;
    return 0;

}

