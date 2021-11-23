#include <iostream>
#include <stdio.h>
using namespace std;

void StringProcess(string str[] , int num_of_element , string element_to_delete){
    int i , save , tmp , pos;
    //find karim by binary search or linear search
    //As array is given sorted Binary search is preferable
    //In no. 5) Array Sorting Binary search will be implemented
    //I am using liner search

    for(i=0;i<num_of_element;i++)
        if(str[i] == element_to_delete){
            pos = i;
            break;//No need to search more
        }

    //Shift the index starting at position of element_to_delete;

    num_of_element = num_of_element - 1;
    for(i=pos; i < num_of_element; i++)
        str[i] = str[i+1];

    //print the array
    for(i=0;i<num_of_element;i++)
        cout<<str[i]<<' ';
    printf("\n");
}

void IntegerProcess(int a[] , int num_of_element , int pos){
    int i , save , tmp;
    pos--;//As we indexed from zero
    num_of_element = num_of_element - 1;

    for(i=pos; i < num_of_element; i++)
        a[i] = a[i+1];

    for(i=0;i<num_of_element;i++)
        printf("%d ",a[i]);
    printf("\n");

}

int main(){
    int i , j , n;
    //b)
    printf("Enter the number of Integer element you want to insert\n");
    cin>>n;
    int a[n+5];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    IntegerProcess(a,n,2);
    //a)
    printf("Enter the number of String element you want to insert\n");
    cin>>n;
    string str[n+5];
    for(i=0;i<n;i++){
        cin>>str[i];
    }
    StringProcess(str,n,"karim");

    return 0;
}
