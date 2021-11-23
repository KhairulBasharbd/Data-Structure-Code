#include <bits/stdc++.h>
using namespace std;

void addition(int a[4][4],int b[4][4] ){
    cout<<"Matrix Addition\n";
    int res[4][4],i,j,sum=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            sum = a[i][j] + b[i][j];
            res[i][j]=sum;
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
}
void subtraction(int a[4][4] , int b[4][4]){

    cout<<"Matrix Subtraction\n";
     int res[4][4],i,j,sub=0;
     for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            sub = a[i][j] - b[i][j];
            res[i][j] = sub;
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
}
void multiplication(int a[4][4] , int b[4][4]){
    cout<<"Matrix Multiplication\n";
     int res[4][4],i,j,mul=1,sum=0,k;
     for(k=0;k<4;k++){
         for(i=0;i<4;i++){
            sum = 0;
            for(j=0;j<4;j++){
                mul = a[k][j] * b[j][i];
                sum +=mul;

            }
            res[k][i]=sum;
        }
     }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
}
}
int main(){
    int a[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    addition(a,b);
    subtraction(a,b);
    multiplication(a,b);
    return 0;
}
