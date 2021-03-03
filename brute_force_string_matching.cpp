#include <bits/stdc++.h>
using namespace std;

void bruteForceStringMatching(string t,string p){
    int n=t.length(),m=p.length();
    for(int i=0;i<=n-m;i++)
        if(t.substr(i,m)==p)
            cout<<"Pattern occurs with shift = "<<i<<endl;
}

int main(){
    string t,p;
    cout<<"Enter Text : ";
    getline(cin,t);
    cout<<"Enter Pattern : ";
    cin>>p;
    bruteForceStringMatching(t,p);
    return 0;
}