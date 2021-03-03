#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x,y;
    
    Point(){}
    Point(int a,int b){
        x=a;
        y=b;
    }

    float distance(Point &p){
        return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
    }
    
};

void findClosestPair(int n,Point points[]){
    float min_dist=INFINITY;
    int i,j,index1,index2;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            float cur_dist=points[i].distance(points[j]);
            if(cur_dist<min_dist){
                min_dist=cur_dist;
                index1=i;
                index2=j;
            }
        }
    }
    cout<<"Point : "<<(index1+1)<<" & Point : "<<(index2+1)<<" are closest\n";
    cout<<"Minimum Distance : "<<min_dist<<"\n";
}

int main(){
    int i,n;
    cout<<"Enter Number of Points : ";
    cin>>n;
    Point points[n];
    cout<<"Enter Points(x,y) : \n";
    for(i=0;i<n;i++)
        cin>>points[i].x>>points[i].y;
    findClosestPair(n,points);
    return 0;
}