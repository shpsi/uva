#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
#define EPS 1e-4
double area(double a, double b, double c){
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
double gcd(double x, double y){
    while (fabs(x) > EPS && fabs(y) > EPS)
    {
        if (x > y)
                x -= floor(x / y) * y;
        else
                y -= floor(y / x) * x;
    }
    return x + y;
}
int main(){
    double x1, y1, x2, y2, x3, y3;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>x3>>y3;
    double a, b, c;
    c = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    a = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double S = area(a,b,c);
    double R = (a*b*c) / (4*S);
    double A, B, C;
    A = acos((b*b+c*c-a*a)/(2*b*c));
    B = acos((a*a+c*c-b*b)/(2*a*c));
    C = acos((a*a+b*b-c*c)/(2*a*b));
    double g = gcd(A, gcd(B, C));
    double n = PI / g;
    double ans = n*R*R*sin((2*PI)/n)/2;
    printf("%.8lf\n", ans);
    return 0;
}    
