#include<bits/stdc++.h>
using namespace std;

int total_comparisons;

int random(int start,int end){
    return start + rand()%(end-start+1);
}

int partition(int start,int end,int a[]){
    int random_index=random(start,end);
    // swap(a[end],a[random_index]);
    int pivot=a[end],i=start-1;
    for(int j=start;j<end;j++){
        total_comparisons++;
        if (a[j]<pivot){
            i++;
            swap(a[j],a[i]);
        } 
    }
    swap(a[i+1],a[end]);
    return (i+1);
}

void quick_sort(int start,int end,int a[]){
    if(start<end){
        int pivot_index=partition(start,end,a);
        quick_sort(start,pivot_index-1,a);
        quick_sort(pivot_index+1,end,a);
    }
}

void print_array(int n,int a[]){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    freopen("input.txt","r",stdin);
    srand(time(NULL));
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quick_sort(0,n-1,a);
    print_array(n,a);
    cout<<"\nTotal Comparisons : "<<total_comparisons<<"\n";
    return 0;
}