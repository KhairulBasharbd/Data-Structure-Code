#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
    int data;
    Node *next;
};
Node *head = NULL;//Head will point first node
Node *tail = NULL;//tail will point last node/current node

void add_Node(int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;// save the address of the first node
        tail = new_node;//as current node is first node
    }
    else{
        tail -> next = new_node;//in previous node's *next box, we will put address of current node
        tail = new_node;//and tail point current node;
    }
}
void Display(){
    Node *ptr;
    ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<' ';
        ptr = ptr->next;
    }
    cout<<endl;
}

int find_max(){
    int mx = 0;
    Node *ptr;
    ptr = head;
    while(ptr != NULL){
        if(mx < ptr->data)
            mx = ptr -> data;

        ptr = ptr->next;
    }
    return mx;
}

int find_min(){
    int mn = 10000000;
    Node *ptr;
    ptr = head;
    while(ptr != NULL){
        if(mn > ptr->data)
            mn = ptr -> data;

        ptr = ptr->next;
    }
    return mn;

}

void Insert(int value , int pos){
    Node *ptr = head;
    Node *tmp , *save;
    int i = 1;
    while(ptr!=NULL && i!=pos){
        save = ptr;
        i++;
        ptr = ptr -> next;
    }
    tmp = new Node();//create a new block for insertion
    tmp ->data = value;//fill the data block
    tmp -> next = ptr;//in *next block , fill it with next node address
    save -> next = tmp;//in previous node's next block,fill it with current node address
    /*All are link up :)  Easy*/
}

void Delete(int pos){
    Node *ptr , *save, *tmp;
    ptr = head;
    int i = 1;
    while(ptr!=NULL && i!=pos){
        save = ptr;
        i++;
        ptr = ptr -> next;
    }
    if(ptr == NULL)
        cout<<"Invalid Position Entered"<<endl;
    else{
        save -> next = ptr ->next;//just overwrite previous node's next block , with next node's next block;
    }
}

void Sort(){
    //implementing bubble sort
    Node  *ptr, *curr;
    int tmp;
    ptr = head;
    for(;ptr != NULL;){
        curr = ptr -> next;
        for(;curr != NULL;){
            if(ptr->data > curr ->data){
                tmp = ptr ->data;
                ptr->data = curr -> data;
                curr ->data = tmp;
            }
            curr = curr -> next;
        }
        ptr = ptr -> next;
    }
}
int Search(int value){
    Node *ptr = head;
    int i = 1;
    while(ptr != NULL){
        if(ptr -> data == value)
            return i;
        ptr = ptr -> next;
        i++;
    }

    return 0;//value not found
}
int main(){
    int n , i , j , x;
    //freopen("Riyad.txt","r",stdin);
    while(scanf("%d",&x)!=EOF){//Till end of file (ctrl+z)
        add_Node(x);
    }
    Display();//To print all the element
    //2)) Traverse for maximum and minimum value like array operation
    cout<<"Maximum value is "<<find_max()<<endl;
    cout<<"Minimum value is "<<find_min()<<endl;
    //3))Insert a value at position x
    cout<<"Enter a value and its position that you want to insert"<<endl;
    cin>>n>>x;
    Insert(n,x);//To insert n at position x
    Display();
    //4))Delete an element at position x
    cout<<"Enter the position you want to delete"<<endl;
    cin>>x;
    Delete(x);//To delete the element of position x
    Display();
    //5))Sorting the contest of the list
    cout<<"The contents are in sorted form bellow :)"<<endl;
    Sort();
    Display();
    //5))Searching an element in link list
    cout<<"Enter the value you want to search"<<endl;
    cin>>x;
    int index = Search(x);
    if(index != 0)
        cout<<"Your value is at position: "<<index<<endl;
    else
        cout<<"No Such element found :( "<<endl;

    cout<<"                       H A P P Y    :)     C O D I N G     "<<endl;

    return 0;
}
