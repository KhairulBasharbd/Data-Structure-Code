/*1.
    Write a program that takes an Adjacency matrix A with m vertices as input and output following:*/

#include <bits/stdc++.h>
#define Sz 105
using namespace std;

int Path[Sz][Sz];
int res[100][100][100];
int B[100][100][100];
int A[100][100];

int main(){
    int i , j , n , m , x , y , ind1 , ind2 , k , sum , mul;
    freopen("riyad.txt","r",stdin);
    cin>>n;// n = number of vertices , m = number of edge;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>res[1][i][j];
            A[i][j] = res[1][i][j];
        }
    }
    //a) adjacent of v1,v2,..,vn;
    for(m=2;m<=n;m++){
         for(k=1;k<=n;k++){
             for(i=1;i<=n;i++){
                sum = 0;
                for(j=1;j<=n;j++){
                    mul = res[m-1][k][j] * res[1][j][i];
                    sum +=mul;
                }
                res[m][k][i]=sum;
            }
        }
    }
    for(i=1;i<=n;i++){
        cout<<"Matrix A"<<i<<endl;
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                cout<<res[i][j][k]<<' ';
            }
        cout<<endl;
        }
    }
    /*2))Question extended : find Bn , path matrix and strongly connected or not;
        if path matrix does not belong any zero element then it's strongly connected otherwise not*/
        // Br = B1 + B2 + B3 + .....+ Bn;

    /*For Bn*/
    cout<<"B"<<n<<" Matrix"<<endl;

    for(i = 1; i <= n ; i++){
        for(j = 1; j <= n ; j++){
            sum = 0;
            for(k = 1 ; k <= n ; k++){
                B[i][j][k] = res[i][j][k] + B[i-1][j][k];
                if(i == 4)
                    cout<<B[i][j][k]<<' ';
            }
            if(i == 4)
                cout<<endl;
        }
    }
    cout<<"Path Matrix"<<endl;
    bool flag = false;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(B[n][i][j] != 0){//As we check Bn for Path patrix
                Path[i][j] = 1;
            }
            else {
                Path[i][j] = 0;
                flag = true;
            }
            cout<<Path[i][j]<<' ';
        }
        cout<<endl;
    }
    if(flag)
        cout<<"The Matrix is Not Strongly Connected :("<<endl;
    else cout<<"The Matrix is Strongly Connectd :)"<<endl;
    /*Find out path matrix with n nodes using Warshall's Algorithm*/
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(A[i][j] == 0)
                Path[i][j] = 0;
            else Path[i][j] = 1;
        }
    }

    for(k=1;k<=n;k++){
         for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                Path[i][j] = Path[i][j] | (Path[i][k] & Path[k][j]);
            }
        }
    }
    cout<<"Path Matrix Using Warshall Algorithm"<<endl;
     for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
          cout<<Path[i][j]<<' ';
        }
        cout<<endl;
    }


    return 0;
}
