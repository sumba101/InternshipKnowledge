//
// Created by spawnfire on 27/05/21.
//
#include <bits/stdc++.h>
using namespace std;
int kth(int a1[],int a2[],int *e1,int *e2,int k){
    if(a1==e1){
        return a2[k];
    }
    if(a2==e2){
        return a1[k];
    }
    int mid1=(e1-a1)/2;
    int mid2=(e2-a2)/2;

    if(mid1+mid2 < k ){
        if(a1[mid1]<a2[mid2]){
            return kth(a1+1+mid1,a2,e1,e2,k-mid1-1);
        }else{
            return kth(a1,a2+1+mid2,e1,e2,k-mid2-1);
        }
    }else{
        if(a1[mid1]<a2[mid2]){
            return kth(a1,a2,e1,a2+mid2,k);
        }else{
            return kth(a1,a2,a1+mid1,e2,k);
        }
    }
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if((n+m)<k){
        return -1;
    }

    return kth(arr1,arr2,arr1+n,arr2+m,k-1);
}

int main(){
    int arr1[7] = {1 ,10 ,10 ,25, 40, 54 ,79};
    int arr2[11] = {15 ,24, 27, 32, 33, 39, 48, 68, 82, 88, 90};

    int k = 15;
    cout << kthElement(arr1, arr2,  7,  11,  k - 1);
}
