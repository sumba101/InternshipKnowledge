#include <bits/stdc++.h>
using namespace std;

void heapify(int a[],int root,int end){
    int l=2*root+1;
    int r=2*root+2;
    int change=root;
    if(l<=end && a[l]<a[change]){
        change=l;
    }
    if(r<=end && a[r]<a[change]){
        change=r;
    }
    if(a[change]<a[root]){
        swap(a[change],a[root]);
    }
}

void make_heap(int a[], int end) {
    for(int i=(end-1)/2; i >=0;i--){
        heapify(a,i,end);
    }
}

void printer(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void heap_down(int a[],int n,int root=0){
    int l=2*root+1;
    int r=2*root+2;
    int change=root;
    if(l<n && a[l]<a[change]){
        change=l;
    }
    if(r<n && a[r]<a[change]){
        change=r;
    }
    if(a[change]<a[root]){
        swap(a[change],a[root]);
        heap_down(a,n,change);
    }
}

int poptop(int arr[],int &n){
    int temp=arr[0];
    swap(arr[0],arr[n-1]);
    n--;
    heap_down(arr,n);
    return temp;
}

int main() {
    int arr[]={1,2,4,52,7,2,7,42,3};
    int size=sizeof(arr)/sizeof(int);
    make_heap(arr, size - 1);
    printer(arr,size);
    cout<<size<<endl;
    poptop(arr,size);
    cout<<size<<endl;
    printer(arr,size);
    return 0;
}
