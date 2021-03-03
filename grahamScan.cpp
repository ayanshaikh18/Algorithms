#include <bits/stdc++.h>
#define PI 3.14159265 
using namespace std;

class Point{
    public:
    
    int x,y;
    double slope;

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
    void find_slope(Point p){
        slope=atan(float(y-p.y)/(x-p.x))*180/PI;
        if(slope<0){
            slope+=180;
            return;
        }
    }
};

int direction(Point p1,Point p2,Point p3){
    Point p=p3-p1;
    return p.product(p2-p1);
}

bool compareSlopes(Point p1,Point p2){
    return (p1.slope<p2.slope);
}

int main(){
    int i,n,x,y,index_of_bottom_most_point=0;
    cout<<"Enter Number Of Points : ";
    cin>>n;
    vector<Point> points(n);
    Point bottom_most_point;
    cout<<"Enter Point 1(x,y) : ";
    cin>>points[0].x>>points[0].y;
    bottom_most_point=points[0];

    for(i=1;i<n;i++){
        cout<<"Enter Point "<<(i+1)<<"(x,y) : ";
        cin>>points[i].x>>points[i].y;
        if(points[i].y<bottom_most_point.y || (points[i].y==bottom_most_point.y && points[i].x<bottom_most_point.x)){
            bottom_most_point=points[i];   
            index_of_bottom_most_point=i;
        }
    }

    points.erase(points.begin()+index_of_bottom_most_point);
    for(i=0;i<n-1;i++)
        points[i].find_slope(bottom_most_point);
    sort(points.begin(),points.end(),compareSlopes);

    int top=2;
    vector<Point> stack;
    stack.push_back(bottom_most_point);
    stack.push_back(points[0]);
    stack.push_back(points[1]);

    for(i=2;i<n-1;i++){
        while(top>=1 && (direction(stack[top-1],stack[top],points[i])>0)){
            stack.pop_back();
            top--;
        }
        stack.push_back(points[i]);
        top++;
    }

    cout<<"Points in Convex Hull in Counter Clockwise direction : \n";
    for(i=0;i<stack.size();i++)
        cout<<"("<<stack[i].x<<","<<stack[i].y<<")\n";
    return 0;
}