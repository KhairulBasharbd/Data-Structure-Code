#include <bits/stdc++.h>
using namespace std;

int a[10000];

void Insert_Int(int n ,int num , int x){
    int i , save , tmp;
    tmp = a[x-1];
    for(i=x-1;i<n;i++){
        save = a[i+1];
        a[i+1] = tmp;
        tmp = save;
    }
    a[x-1] = num;

}
int main(){
    int i , j, n , num ,x;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>num>>x;
    if(x>n){cout<<"Invalid Input for the Position ... Position > Size\n";
            return 0;
    }
    else
        Insert_Int(n , num , x);
    for(i=0;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;

    return 0;
}
