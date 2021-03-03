#include <bits/stdc++.h>
using namespace std;

long long random(long long lower_bound,long long upper_bound){
    return lower_bound + rand()%(upper_bound-lower_bound+1);
}

long long  gcd(long long a,long long b){
    if(a<b)
        return gcd(b,a);
    if((a%b)==0)
        return b;
    return gcd(b,a%b);
}

long long power(long long a,long long n,long long mod){
    long long res=1;
    a=a%mod;
    while(n>0){
        if(n&1)
            res=(res*a)%mod;
        n=n>>1;
        a=(a*a)%mod;
    }    
    return res;
}

bool isPrime(long long n){
    int k=10000;
    if(n<=1 || n==4)
        return false;
    if(n<=5)
        return true;
    while(k--){    
        srand(time(0));
        long long a=random(2,n-3);
        if(gcd(n,a)!=1)
            return false;
        if(power(a,n-1,n)!=1)
            return false;
    }
    return true;
}

int main(){
    long long n;
    cout<<"Enter the number : ";
    cin>>n;
    if(isPrime(n))
        cout<<n<<" is Prime Number\n";
    else             
        cout<<n<<" is Composite Number\n";
    return 0;
}
