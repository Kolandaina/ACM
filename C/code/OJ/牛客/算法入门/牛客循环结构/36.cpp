#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[100001],b=1,i=1,c,j,n,m,min;
    cin>>n>>m;
    cin>>a[1];
    if(a[1]>n/2)a[1]=n-a[1];
    min=a[1];
    for(i=2;i<=m;i++){
        scanf("%d",&a[i]);
        if(a[i]>n/2)a[i]=n-a[i];
        if(a[i]>min)min=a[i];
    }
    cout<<min;
    return 0;
}