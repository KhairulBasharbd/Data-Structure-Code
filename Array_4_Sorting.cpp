#include <iostream>
#include <stdio.h>
using namespace std;

void StringProcess(string str[] , int num_of_element){
    int i , j ;
    string tmp;

    for(i=0;i<num_of_element;i++){
       for(j = i +1 ; j < num_of_element ; j++){
           if(str[i] > str[j]){
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
           }
       }
    }

    //print the array
    for(i=0;i<num_of_element;i++)
        cout<<str[i]<<' ';
    printf("\n");
}

void IntegerProcess(int a[] , int num_of_element){
    int i , j , tmp;

    for(i=0; i < num_of_element; i++){
        for(j = i + 1 ; j < num_of_element ; j++){
            if(a[i] > a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }

    for(i=0;i<num_of_element;i++)
        printf("%d ",a[i]);
    printf("\n");

}

int main(){
    int i , j , n;
    //b)
    printf("Enter the number of Integer element you want to Sort\n");
    cin>>n;
    int a[n+5];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    IntegerProcess(a,n);
    //a)
    printf("Enter the number of String element you want to Sort\n");
    cin>>n;
    string str[n+5];
    for(i=0;i<n;i++){
        cin>>str[i];
    }
    StringProcess(str,n);

    return 0;
}

