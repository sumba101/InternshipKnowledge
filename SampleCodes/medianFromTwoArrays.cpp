//
// Created by spawnfire on 28/05/21.
//

int findMidSum(int ar1[], int ar2[], int n) {
    if(n<=0){
        return -1;
    }
    if(n==1){
        return ar1[0]+ar2[0];
    }
    if(n==2){
        return max(ar1[0],ar2[0])+min(ar1[1],ar2[1]);
    }
    int med1,med2;
    if(n%2==0){
        med1=(ar1[n/2]+ar1[n/2 -1] )/2;
        med2 = (ar2[n/2] + ar2[n/2 -1]) /2;
    }else{
        med1=ar1[n/2];
        med2=ar2[n/2];
    }
    if(med1<med2){
        if(n%2){
            return findMidSum(ar1+n/2 ,ar2 , n-n/2);
        }else{
            return findMidSum(ar1+ n/2 -1,ar2,n -n/2 +1);
        }
    }else{
        if(n%2){
            return findMidSum(ar1,ar2+n/2,n - n/2);
        }else{
            return findMidSum(ar1,ar2+n/2 -1,n -n/2 +1);
        }
    }
}
