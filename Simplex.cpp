#include <bits/stdc++.h>
using namespace std;

struct table{
    int cb,xb;
    float ratio,rhs;
    float x[4];
};

int main(){
    int i,j,x1,x2,z[2],ans;
    int constraints[2][3];
    table t[2];
    int cjMinusZj[4]={0},zj[5]={0},cj[4]={0};

    cout<<"Enter Coefficient of x1 & x2 in objective function : ";
    cin>>z[0]>>z[1];
    cout<<"Enter Constraint 1 (Coeff of x1, Coeff of x2, Constant) : ";
    cin>>constraints[0][0]>>constraints[0][1]>>constraints[0][2];
    cout<<"Enter Constraint 2 (Coeff of x1, Coeff of x2, Constant) : ";
    cin>>constraints[1][0]>>constraints[1][1]>>constraints[1][2];

    cj[0]=z[0];
    cj[1]=z[1];
    cj[2]=cj[3]=0;
    t[0].x[0]=constraints[0][0];
    t[0].x[1]=constraints[0][1];
    t[0].x[2]=1;
    t[0].x[3]=0;
    t[0].rhs=constraints[0][2];
    t[0].xb=2;
    t[0].cb=0;

    t[1].x[0]=constraints[1][0];
    t[1].x[1]=constraints[1][1];
    t[1].x[2]=0;
    t[1].x[3]=1;
    t[1].rhs=constraints[1][2];
    t[1].xb=3;
    t[1].cb=0;

   while(1){
        int max=-1,keyColIndex;
        for(i=0;i<3;i++){
            zj[i]=( t[0].cb * t[0].x[i] ) + ( t[1].cb * t[1].x[i] );
            cjMinusZj[i]=cj[i]-zj[i];
            if(cjMinusZj[i]>max){
                max=cjMinusZj[i];
                keyColIndex=i;
            }
        }

        zj[4]=( t[0].cb * t[0].rhs ) + ( t[1].cb * t[1].rhs );
        t[0].ratio=(float)t[0].rhs/t[0].x[keyColIndex];
        t[1].ratio=(float)t[1].rhs/t[1].x[keyColIndex];


        if(cjMinusZj[0]<=0 && cjMinusZj[1]<=0 && cjMinusZj[2]<=0 && cjMinusZj[3]<=0){
            ans=zj[4];
            break;
        }

        int keyRowIndex=0;
        float keyElement=t[0].x[keyColIndex];
        if(t[1].ratio<t[0].ratio){
            keyRowIndex=1;
            keyElement=t[1].x[keyColIndex];
        }

        t[keyRowIndex].cb=z[keyColIndex];
        t[keyRowIndex].xb=keyColIndex;

        int nonKeyRowIndex=!keyRowIndex;
        float nonKeyColEle=t[nonKeyRowIndex].x[keyColIndex];    
        for(i=0;i<4;i++){
            t[nonKeyRowIndex].x[i] -= (t[keyRowIndex].x[i] * nonKeyColEle / keyElement);
            t[keyRowIndex].x[i] /= keyElement;
        }
        t[nonKeyRowIndex].rhs -= (t[keyRowIndex].rhs * nonKeyColEle / keyElement);
        t[keyRowIndex].rhs /= keyElement;
    }
    if(t[0].xb==0){
        cout<<"x1 : "<<t[0].rhs<<"\n";
        cout<<"x2 : "<<t[1].rhs<<"\n";
    }
    else{
        cout<<"x1 : "<<t[1].rhs<<"\n";
        cout<<"x2 : "<<t[0].rhs<<"\n";
    }
    cout<<"Maximum oalue of objective function : "<<ans<<"\n";

    return 0;
}