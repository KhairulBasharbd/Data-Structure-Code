#include <bits/stdc++.h>
#define ll long long
using namespace std;

int Maximum(int n , int a[]){
    int i,mx = 0;
    for(i=0;i<n;i++){
        if(a[i] > mx)mx = a[i];
    }
    return mx;

}
int Minimum(int n , int a[]){
    int i , mn =0;
    mn = a[0];
    for(i=1;i<n;i++){
        if(a[i] < mn) mn = a[i];
    }
    return mn;
}

double Average(int n , int a[]){
    double avg, sum=0;
    for(int i=0;i<n;i++){
        sum +=a[i];
    }
    avg = sum/n;
    return avg;
}

int Total(int n , int a[]){
    int i , sum =0;
    for(i=0;i<n;i++){
        sum = sum + a[i];
    }
    return sum;
}
void Sin(int n , int a[]){
    int i ;
    for(i=0;i<n;i++){
        cout<<sin(a[i])<<' ';
    }
    cout<<endl;
}


int main(){
    int i , j , n;
    cin>>n;
    int a[n+2];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Maximum value is: "<<Maximum(n ,a)<<endl;
    cout<<"Minimum value is: "<<Minimum(n,a)<<endl;
    cout<<"Average value is: "<<Average(n , a)<<endl;
    cout<<"Total value is: "<<Total(n,a)<<endl;
    cout<<"Sin value is: ";Sin(n , a);
    return 0;
}
