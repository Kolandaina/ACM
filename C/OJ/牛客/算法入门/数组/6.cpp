#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,a[100];
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int max=0,min=0;
    for(i=0;i<n;i++){
        if(a[max]<a[i])max=i;
        if(a[min]>a[i])min=i;
    }
    int d[4];
    d[0]=max-0;
    d[1]=min-0;
    d[2]=n-1-max;
    d[3]=n-1-min;
    cout<<*max_element(d,d+4);
    return 0;
}