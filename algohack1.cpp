#include <iostream>
using namespace std;

int main()
{    int n,t,i,j,count=0,a[1000],b[1000],c[1000],p[1000],temp,temp1[1000],max=-1,l=0,q1,q2=0;
	cout<<"enter total no: of persons\n";
	cin>>n;
	for(i=0;i<n;i++)
		{	cout<<"enter id,arrivaltime,tasktime and priority\n";
		cin>>a[i]>>b[i]>>c[i]>>p[i];//where a is id,b is time they arrived, c is required completion time and p is priority
	}
	cout<<"in FCFS method\n";
	for(i=0;i<n;i++)
	for(j=i;j<n;j++)
	{
		if(b[i]>b[j])
		{
			temp=b[i];
			b[i]=b[j];
			b[j]=temp;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			temp=c[i];
			c[i]=c[j];
			c[j]=temp;
			temp=c[i];
			p[i]=p[j];
			p[j]=temp;
		}
	}
	for(i=0;i<n;i++)
	{   count+=c[i];
		cout<<"for customer "<<a[i]<<" departure time= "<<count<<",\tturnabouttime taken= "<<count-b[i]<<"\n";
	}
	count=0;
	j=0;
      cout<<"in priority method\n";
		for(i=0;i<n;i++)
		temp1[i]=c[i];
	while(1)
   { l=0;
	  for(i=j+1;i<=n;i++)
	  { 
	   if(i!=n)
	   {
	    if(p[j]<p[i])
		{
			if((b[j]+temp1[j]-b[i])>0)
			{
			  temp1[j]=b[j]+temp1[j]-b[i];
			  count+=b[i]-b[j];
		    }
			else
		    {
		      count+=temp1[j];
		      cout<<"for customer "<<a[j]<<" departure time= "<<count<<",\tturnabouttime taken= "<<count-b[j]<<"\n";
		      temp1[j]=0;
		      p[j]=0;
		    }
		    j=i;
			break;
		}
		else
	   {   if((b[j]+temp1[j])<=b[i])
		   {  count+=temp1[j];
			  cout<<"for customer "<<a[j]<<" departure time= "<<count<<",\tturnabouttime taken= "<<count-b[j]<<"\n";
			  temp1[j]=0;
			  p[j]=0;
			  break;
		    }
		}
	   }
	   if(i==n)
		{
			count+=temp1[j];
			  cout<<"for customer "<<a[j]<<" departure time= "<<count<<",\tturnabouttime taken= "<<count-b[j]<<"\n";
			  temp1[j]=0;
			  p[j]=0;
		}
      }
      max=-1;
	   if(j!=i)
	   for(int k=0;k<i;k++)
	   {
	   	if(max<p[k])
	   	 {
		   max=p[k];
		   j=k;
	     }
	   }
	   for(int k=0;k<n;k++)
	   {
	   	if(p[k]!=0)
	    {
	   	  l=1;	
	   	  break;
	     }
	   }
	   if(l==0)
	   break;
    }
    count=0;
    cout<<"In RoundRobin method\nEnter t(time allocated)\n";
    cin>>t;
    while(1)
    {l=0;
    for(i=0;i<n;i++)
    {   if(c[i]!=0)
      {
    	if(c[i]>t)
    	{
    		c[i]-=t;
    		count+=t;
		}
    	else
    	{
    		cout<<"for customer "<<a[i]<<" departure time= "<<count+c[i]<<",\tturnabouttime taken= "<<count+c[i]-b[i]<<"\n";
    		count+=c[i];
    		c[i]=0;
		}
	  }
	}
	for(int k=0;k<n;k++)
	{
		if(c[k]!=0)
		{
			l=1;
			break;
		}
	}
	if(l==0)
	break;
    }
    return 0;
}
