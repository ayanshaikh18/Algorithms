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

    Point operator - (Point &obj){
        Point res;
        res.x=x-obj.x;
        res.y=y-obj.y;
        return res;
    }

    int product(Point obj){
        return (x*obj.y)-(y*obj.x);
    }
};

int direction(Point p1,Point p2,Point p3){
    Point p=p3-p1;
    return p.product(p2-p1);
}

bool onSegment(Point pi,Point pj,Point pk){
    if(min(pi.x,pj.x)<=pk.x<=max(pi.x,pj.x) && min(pi.y,pj.y)<=pk.y<=max(pi.y,pj.y))
        return true;
    return false;
}

bool segmenIntersect(Point p1,Point p2,Point p3,Point p4){
    int d1,d2,d3,d4;
    d1=direction(p3,p4,p1);
    d2=direction(p3,p4,p2);
    d3=direction(p1,p2,p3);
    d4=direction(p1,p2,p4);

    if(d1*d2<0 && d3*d4<0)
        return true;

    if(d1==0 && onSegment(p3,p4,p1))
        return true;
    if(d2==0 && onSegment(p3,p4,p2))
        return true;
    if(d3==0 && onSegment(p1,p2,p3))
        return true;
    if(d4==0 && onSegment(p1,p2,p4))
        return true;
    return false;
}

int main(){
    int x,y;
    cout<<"Enter 1 st Point of 1 st line segment : ";
    cin>>x>>y;
    Point p1(x,y);
    cout<<"Enter 2 nd Point of 1 st line segment : ";
    cin>>x>>y;
    Point p2(x,y);
    cout<<"Enter 1 st Point of 2 nd line segment : ";
    cin>>x>>y;
    Point p3(x,y);
    cout<<"Enter 2 nd Point of 2 nd line segment : ";
    cin>>x>>y;
    Point p4(x,y);
    if(segmenIntersect(p1,p2,p3,p4))
        cout<<"Both line segments intersect\n";
    else
        cout<<"Both line segments don't intersect\n";
    return 0;
}