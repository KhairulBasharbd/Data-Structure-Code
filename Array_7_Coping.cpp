#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int i , j , n , m , k = 0 , limit;
    printf("Enter Number of Row and Column:\n");
    cin>>n>>m;
    int a[n+5][m+5];
    int sz = n * m + 5;
    int ar1D[sz];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>a[i][j];
            ar1D[k++] = a[i][j];//copying sequentially
        }
    }
    //For Group 3
    n = (3 - 1) * m;
    limit = n + m;

    for(i=n;i<limit;i++)
        cout<<ar1D[i]<<' ';
    cout<<endl;

    return 0;
}
