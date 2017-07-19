#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream fin,fout;
	fin.open("in2.dat",ios::in);
	int x,x1,n,a,b,c,d;//,tn;	
	//cout<<"\nEnter no. of tries: ";
	fin>>n;
		
	for(x=1;x<=n;x++) {
		//cout<<"\nEnter the size for each of the 4 sets of integers: ";
		fin>>a>>b>>c>>d;
		//tn=a+b+c+d;
		int p[a],q[b],r[c],s[d];
		int q1=0,o1=a,i,j,k,l,sum=0;
		//cout<<"\nFill each of the sets with integers:\n";
		for(i=0;i<o1;i++) {		
			if(!q1){/*cout<<"p:";*/ fin>>p[i];}			
			else
			if(q1==1){/*cout<<"q:";*/ fin>>q[i];}		
			else
			if(q1==2){/*cout<<"r:";*/ fin>>r[i];}
			else
			if(q1==3){/*cout<<"s:";*/ fin>>s[i];}		
			
			if(i==o1-1){ 
				q1++;
				i=-1;
				if(q1==1) o1=b;
				else
				if(q1==2) o1=c;
				else
				if(q1==3) o1=d;
				else break;
			}		
		}		 
		fin.close();
		
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
				for(k=0;k<c;k++)
					for(l=0;l<d;l++) {
						sum=p[i]+q[j]+r[k]+s[l];
						if(sum==0) {
							x1=0;							
							fout.open("out2.dat",ios::out);
							fout<<p[i]<<" "<<q[j]<<" "<<r[k]<<" "<<s[l];
							fout.close();
							goto out;
						} 
					}		
		out:
		//if(x1) cerr<<"\nError!";
		/*if(x<n) cout<<"\nTry again:\n\n"*/;
	}
	//cout<<"\n\nThank you!";
	return 0;	
}

