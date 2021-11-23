#include <iostream>
#include <stdio.h>
using namespace std;

int BS_String(string a[] , int n, string item){
    int low = 0 , high = n - 1 , mid; //As indexed from zero
    while(low <= high){
        mid = (low + high) / 2;
        if(a[mid] == item)
            return mid;
        else if(a[mid] > item)
            high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

void StringProcess(string str[] , int num_of_element , string item){
   int i , ind;
    ind = BS_String(str,num_of_element,item);//one can also return yes or no bool value from BS
    if(str[ind] != item)
        cout<<"No such element on array\n"<<endl; // if told that insert the element
                                            // on its suitable position then start insert from the ind;
    else cout<<"The element is at index "<<ind + 1<<endl;//As indexed from zero
}

int BS_Integer(int a[] , int n, int item){
    int low = 0 , high = n - 1 , mid; //As indexed from zero
    while(low <= high){
        mid = (low + high) / 2;
        if(a[mid] == item)
            return mid;
        else if(a[mid] > item)
            high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
void IntegerProcess(int a[] , int num_of_element , int item){
    int i , ind;
    ind = BS_Integer(a,num_of_element,item);//one can also return yes or no bool value from BS
    if(a[ind] != item)
        cout<<"No such element on array\n"<<endl; // if told that insert the element
                                            // on its suitable position then start insert from the ind;
    else cout<<"The element is at index "<<ind + 1<<endl<<endl;//As indexed from zero
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
    IntegerProcess(a,n,77);
    //a)
    printf("Enter the number of String element you want to Sort\n");
    cin>>n;
    string str[n+5];
    for(i=0;i<n;i++){
        cin>>str[i];
    }
    StringProcess(str,n,"karim");

    return 0;
}


