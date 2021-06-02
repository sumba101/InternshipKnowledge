//
// Created by spawnfire on 18/05/21.
//

priority_queue<int>max_heap;
priority_queue<int,vector<int>,greater<int>>min_heap;
void insertHeap(int &x)
{
    int l_s= (max_heap.empty())?0:max_heap.size();
    int r_s= (min_heap.empty())?0:min_heap.size();
    int r= (min_heap.empty())?-1:min_heap.top();
    int l=  (max_heap.empty())?-1:max_heap.top();

    if(l_s==0){
        max_heap.emplace(x);
        l_s++;
    }
    else if(r_s==0){
        if(l>x){
            max_heap.pop();
            min_heap.emplace(l);
            max_heap.emplace(x);
        }else{
            min_heap.emplace(x);
        }
        r_s++;
    }
    else if(x>r){
        min_heap.emplace(x);
        r_s++;
    }else{
        max_heap.emplace(x);
        l_s++;
    }
    if(abs(l_s-r_s)>1){
        balanceHeaps();
    }
}

//Function to balance heaps.
void balanceHeaps()
{
    int l_s= (max_heap.empty())?0:max_heap.size();
    int r_s= (min_heap.empty())?0:min_heap.size();
    while(abs(l_s-r_s)){
        int temp=max_heap.top();
        max_heap.pop();
        l_s--;
        r_s++;
        min_heap.emplace(temp);
    }
}

//Function to return Median.
double getMedian()
{
    int x=max_heap.size();
    int y=min_heap.size();
    // cout<<"sizes "<<x<<"  "<<y<<endl;
    if((x+y)%2){
        if(x>y){
            return double(max_heap.top());
        }else{
            return double(min_heap.top());
        }
    }else{
        return ((double)max_heap.top()+(double)min_heap.top())/2.0;
    }
}
