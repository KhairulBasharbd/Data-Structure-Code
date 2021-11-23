#include <stdio.h>
#include <iostream>
#define Sz 100000
using namespace std;

void PrintInt(int a[] , int n){
    for(int i = 0 ; i < n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}

void PrintChar(char ch[] , int n){
    for(int i = 0 ; i < n ; i++)
        cout<<ch[i]<<' ';
    cout<<endl;
}

int main(){
    int i , j , n , m;
    //a)
    int a[Sz];//Sz is macro written in top = 10^5
    printf("Enter the number of element in first array and elements\n");
    cin>>n;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the number of element in Second array and elements\n");
    cin>>m;
    int total_size = n + m;

    for(i=n;i<total_size;i++)
        scanf("%d",&a[i]);

    PrintInt(a,total_size);

    //b)
    //char ch[Sz];//Same process as array do it yourself

    return 0;
}
