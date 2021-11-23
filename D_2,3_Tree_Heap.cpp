/*Write a program to insert an element and delete an element on Heap*/

/*A heap is a tree-based data structure in which all the nodes of the tree are in a specific order.
    Two type of heap that's are max_heap and min_heap.In max_heap every parent is greater than or equal to
    it's child and in min_heap every parent is less than or equal to it's child
         4     ind = 0
       /   \
      7     8
     / \   / \
    3   2 6   5

*/

#include <bits/stdc++.h>
#define Mx 10000009
#define Sz 1000005
using namespace std;

int tree[1000005];
int last;

void PrintTree(int n);

void max_heapify (int i, int N){

        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i; // Need to find the largest value among parent and two child;

        if(left < N && tree[left] > tree[i] )//change > to < for min_heap;
              largest = left;
        if(right < N && tree[right] > tree[largest] )//change > to < for min_heap;
            largest = right;

        if(largest != i )// child found that is greater than parent
        {
            swap (tree[i] , tree[largest]);
            max_heapify (largest,N);
        }
}

void Insert(int i){
    /*like max_heapify*/
    int parent = (i - 1)/2;
    if(parent < 0)
        return;
    else if(tree[i] > tree[parent]){
        swap(tree[i] , tree[parent]);
        Insert(parent);
    }

}
void Deletion(int i , int n){
    tree[i] = tree[n];//last indexed element should inserted on item index;
    for(i=n/2-1;i>=0;i--)
        max_heapify(i , n);//Rearrange the heap
    PrintTree(n);
}

void PrintTree(int n){
     for(int i=0;i<n;i++){
        cout<<i<<' '<<tree[i]<<endl;
    }
}


int main(){
    int n , i , j, item , x , root=0;
    int ind = -1;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>item;
        tree[i] = item;//building tree according to input
    }
    for(i=n/2-1;i>=0;i--)
        max_heapify(i , n);//as parent of one/two child is tree[i/2];

    PrintTree(n);

    /*Write a program to insert an element into the heap*/

    printf("Input the element to be inserted:\n");
    cin>>x;
    n = n + 1;
    tree[n - 1] = x; // at last index put the item number
    Insert(n-1);
    PrintTree(n);

    /*Write a program to delete an element into the heap*/

    printf("Input the element to be deleted:\n");
    cin>>x;
    for(i = 0 ; i < n ; i++){
        if(tree[i] == x){
            ind = i;
            break;
        }
    }
    if(ind != -1)
        n--,Deletion(ind , n);
    else printf("The item is not in the tree\n");

    return 0;
}
