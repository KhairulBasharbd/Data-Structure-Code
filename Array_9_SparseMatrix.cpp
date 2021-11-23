#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int i , j , k , l = 1 , n;
    printf("Enter the n for two dimensional n x n triangular matrix:\n");
    cin>>n;
    int A[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>A[i][j];
    int sz = 0.5 * n * (n + 1) + 5;
    int B[sz];
    for(i=0;i<n;i++){
        for(j =0 ; j <=i ; j++){
            B[l++] = A[i][j];
        }
    }
    //For location formula ind = (0.5 * j * (j - 1)) + k;
    printf("Enter the row and column index you want search:\n");
    cin>>j>>k;
    int ind = 0.5 * j * (j - 1) + k;
    cout<<B[ind]<<endl;
    return 0;
}
