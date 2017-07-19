#include<iostream>
#include<string>

using namespace std;

class interleaf
{
	string s1,s2,s3;
	//vector<string> p;
	public:
		interleaf(string a="", string b=""){s1=a; s2=b;}
		void getData()
		{
			cout<<"\nEnter s1: "; cin>>s1;
			cout<<"\nEnter s2: "; cin>>s2;
		}
		void interleave()
		{
			/*for(int i=-1;i<=s1.size();i++) {
				if(i>=0 && i<s1.size()) cout<<s1[i];
				for(int j=0;j<s2.size();j++) {
					cout<<s2[j];
				}
				
			}*/
			inter(s1,s2,s3,0,0);
			
		}
		
		void inter(string s1,string s2,string s3, int i,int j)
		{
			if(i!=s1.size()) {
				s3+=s1[i];
				inter(s1,s2,s3,i+1,j);
			}
			if(j!=s2.size()) {
				s3+=s2[j];				
				inter(s1,s2,s3,i,j+1);
			}
			if(s3.size()==s1.size()+s2.size()) cout<<s3<<endl;
		}
};

int main()
{
	interleaf z;
	z.getData();
	z.interleave();
	return 0;
}
