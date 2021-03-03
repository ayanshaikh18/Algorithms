#include <bits/stdc++.h>
using namespace std;

int horsepoolStringMatching(string t,string p){
    int n=t.length(),m=p.length();
    map<char,int> shift;
    
    for(int i=97;i<123;i++)
        shift.insert(pair<char,int>(i,m));
    shift.insert(pair<char,int>(' ',m));

    for(int i=0;i<m-1;i++)
        shift[p[i]]=m-i-1;
    
    int j=0;
    while ((j+m)<=n){
        if (p[m-1]==t[j+m-1]){
            int i=m-2;
            while (i>=0 && p[i]==t[j+i])
                i--;
            if(i==-1)
                return j;
        }
        j+=shift[t[j+m-1]];
    }
    return n;
    
}
int main(){
    string t,p;
    cout<<"Enter Text : ";
    getline(cin,t);
    cout<<"Enter Pattern : ";
    getline(cin,p);
    int shifts=horsepoolStringMatching(t,p);
    if(shifts==t.length())
        cout<<"Pattern Not Found!!!\n";
    else
        cout<<"Pattern occurs with shift : "<<shifts<<endl;
    return 0;
}