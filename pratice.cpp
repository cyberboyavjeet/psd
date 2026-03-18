#include<iostream>
using namespace std;
int main()
{
    int a=7,b=9,c=1,d=8,e=11,f;
    f=a%b*c+d-e/a*d+a*d+(!(a*b%c/d+e-a));
    cout<<f;
}