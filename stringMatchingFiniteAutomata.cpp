#include <bits/stdc++.h>
using namespace std;

int main(){
    string T="cabaabcaababacaaa";
    string p="ababaca";
    int table[8][3]={
        {1,0,0},
        {1,2,0},
        {3,0,0},
        {1,4,0},
        {5,0,0},
        {1,4,6},
        {7,0,0},
        {1,2,0},       
    };
    int n=T.length(),q=0,m=7;
    for(int i=0;i<n;i++){
        int curChar=T[i]-'a';
        q=table[q][curChar];
        if(q==m){
            int s=i-m+1;
            cout<<"Pattern occurs with shift : "<<s<<endl;
        }
    }
    return 0;
}