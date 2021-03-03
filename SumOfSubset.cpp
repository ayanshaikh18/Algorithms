#include <bits/stdc++.h>
using namespace std;

int zeroOneKnapsack(int p[],int w[],int c,int n){
    int i,j,t[n+1][c+1];
    for(i=0;i<=n;i++)
        t[i][0]=0;
    for(i=0;i<=c;i++)
        t[0][i]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=c;j++){
            if(j<w[i-1])
                t[i][j]=t[i-1][j];
            else
                t[i][j]=max(t[i-1][j],p[i-1]+t[i-1][j-w[i-1]]);
        }
    }
    return t[n][c];
}

bool sumOfSubset(int s[],int m,int n){
    return (zeroOneKnapsack(s,s,m,n)==m);
}

int main(){
    int n,m;
    cout<<"Enter number of items : ";
    cin>>n;
    cout<<"Enter value of sum : ";
    cin>>m;
    int s[n];
    cout<<"Enter elements of set : ";
    for(int i=0;i<n;i++)
        cin>>s[i];
    if(sumOfSubset(s,m,n))
        cout<<"There exists a subset with sum =  "<<m<<endl;
    else
        cout<<"There is no subset with sum = "<<m<<endl;
    return 0;
}