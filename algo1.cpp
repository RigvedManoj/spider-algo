#include <iostream>
using namespace std;

int main()
{
    int n,m,q,a[1000],b[1000],c[1000];
    //cout<<"enter no: of cloths available and no of queries\n";
    cin>>n>>m;
    for(int i=0;i<n;i++)
        {
        cin>>a[i];//enter cloth size
        c[i]=b[i]=a[i];
    }
    for(int i=0;i<m;i++)
        {
        int a1=0,min,b1,max,c1;
        cin>>q;//enter query
        for(int j=0;j<n;j++)
            if(a[j]>=q)
            {
            a[j]-=q;
            break;
        }
        for(int j=0;j<n;j++)
            cout<<a[j]<<" ";
        cout<<"\n";
        for(int j=0;j<n;j++)
            if(b[j]>=q)
                if(a1==0)
                    {
                    min=b[j];
                    a1=1;
                    b1=j;
                }
                else
                    if(b[j]<min)
                        {
                        min=b[j];
                        b1=j;
                    }
        a1=0;
        b[b1]-=q;
        for(int j=0;j<n;j++)
            cout<<b[j]<<" ";
        cout<<"\n";
        for(int j=0;j<n;j++)
            if(c[j]>=q)
                if(a1==0)
                    {
                    max=c[j];
                    a1=1;
                    c1=j;
                }
                else
                    if(c[j]>min)
                    {
                    max=c[j];
                    c1=j;
                }
        c[c1]-=q;
        for(int j=0;j<n;j++)
            cout<<c[j]<<" ";
        cout<<"\n\n";
    }
  return 0;
}
