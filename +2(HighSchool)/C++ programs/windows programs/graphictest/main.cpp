#include<sstream>
#include<iostream>
#include<fstream>
#include <windows.h>
#include<cmath>
//#include "helper.h"
#include"linked list.hpp"
#define sstream stringstream
using namespace std;
namespace matter{enum{anti,norm,hv};};
void OnPaint(HWND hWnd);

string ec()
{
	string n;
	ifstream fin("ec.txt");
	getline(fin,n);
	fin.close();
	return n;
}
int mtype()
{
	string s=ec();
	if(!isdigit(s[0])) return matter::hv;
	if(s[1]=='s') return matter::norm;
	else return matter::anti;
}
bool octate(int e)
{
	int i;
	for(i=0;e>=(9+8*i);i++)
	if(e==(9+8*i)) return true;
	return false;
}
int numify(char n)
{
	int i;
	sstream ss;
	ss<<n;
	ss>>i;
	ss.str("");
	return i;
}
int shell_no()
{
	int n=0;
	string s=ec();
	for(int i=0;i<s.size();i++) {
		if(n<numify(s[i])) n=numify(s[i]);
		while(s[i]!=' ') i++;		
	}
	return n;	
}
llist<int> build_eps()
{
	llist<int> eps;
	int i,n,r;
	string s=ec();
	for(i=0;i<s.size();i++) {
			for(r=0;isdigit(s[i]);i++) r=r*10+numify(s[i]);
			n=r,i++;			
			for(r=0;isdigit(s[i]);i++) r=r*10+numify(s[i]);
			eps[n]+=r;
	}
	return eps;
}
int meps(int shc)
{
	llist<int> a=build_eps();	
	return a[shc];	
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) { /* This is where all the input to the window goes to */
	switch(Message) {		
		case WM_DESTROY: { /* Upon destruction, tell the main thread to stop */
			PostQuitMessage(0);
			break;
		}
		case WM_KEYDOWN: { /* Upon destruction, tell the main thread to stop */
			PostQuitMessage(0);
			break;
		}
		case WM_PAINT:{  
			OnPaint (hwnd);   
		    break;	
		}
		default:/* All other messages (a lot of them) are processed using default procedures */
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { /* The 'main' function of Win32 GUI programs: this is where execution starts */
	
	//MSG m; /* A temporary location for all messages */	
	//InitInstance(hInstance,nCmdShow,"Electronic Configuration Diagram");
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG m; /* A temporary location for all messages */
	
	memset(&wc,0,sizeof(wc)); /* zero out the struct and set the stuff we want to modify */
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
		
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1); /* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Electronic Configuration Diagram",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		690, /* x */
		0, /* y */
		700, /* width */
		700, /* height */
		NULL,NULL,hInstance,NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	while(GetMessage(&m, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&m); /* Translate key codes to chars if present */
		DispatchMessage(&m); /* Send it to WndProc */
	}
	return 0;
}

void OnPaint ( HWND hWnd )
{ 
	 HDC hdc ;
	 PAINTSTRUCT ps ;
	 HBRUSH hbr;
	 HGDIOBJ holdbr ;	 
	 hdc = BeginPaint ( hWnd, &ps ) ;	 
	 
	 int epc;//  e- per shell counter	 
	 int n=shell_no(),x=350,y=350,nuc=30;//shell no,nucleus and position
	 int i,p=x-nuc/2,q=y-nuc/2,r=x+nuc/2,s=y+nuc/2,f;//shell and its size factor
	 int a,b,c,d,el=5,pos=12;//electron size(el) and other factors
	 int sf,sc; //shell const shell factor	 	 
	 
	 for(i=n;i>=1;i--) {
	 	f=i*(30+i);
	 	pos=15+10*(i-1);//rectify this!!!// before-12+8*(i-1)
	 	
	 	if(mtype()==matter::norm) hbr = CreateSolidBrush ( RGB (5+i*30,255,40+i*30) ) ;
	 	else hbr = CreateSolidBrush ( RGB (40+i*30,255,5+i*30) ) ;
		holdbr = SelectObject ( hdc, hbr ) ;			
	 	Ellipse ( hdc, a=p-f, b=q-f, c=r+f, d=s+f ) ;	 	
	 	if(mtype()==matter::norm) hbr = CreateSolidBrush ( RGB (255*((i%2==0)?1:0),175*((i%2==0)?1:0),255*((i%2!=0)?1:0))) ;
	 	else hbr = CreateSolidBrush ( RGB (255*((i%2!=0)?1:0),175*((i%2==0)?1:0),255*((i%2==0)?1:0))) ;
		holdbr = SelectObject ( hdc, hbr ) ;
		
		for(sf=0,epc=1;epc<=meps(i);epc++) { 
			if(octate(epc)) sf++;
			sc=8*sf;
			switch((epc-1)%8+1) {
				case 1:Ellipse ( hdc, x-el, b-el-sc, x+el, b+el-sc ) ;break;//t
			 	case 2:Ellipse ( hdc, x-el, d-el+sc, x+el, d+el+sc ) ;break;//b	
				case 3:Ellipse ( hdc, a-el-sc, y-el, a+el-sc, y+el ) ;break;//l
			 	case 4:Ellipse ( hdc, c-el+sc, y-el, c+el+sc, y+el ) ;break;//r			 		 	
			 	case 5:Ellipse ( hdc, a-el+pos-sc, b-el+pos-sc, a+el+pos-sc, b+el+pos-sc ) ;break;//lt
			 	case 6:Ellipse ( hdc, c-el-pos+sc, d-el-pos+sc, c+el-pos+sc, d+el-pos+sc ) ;break;//rb
			 	case 7:Ellipse ( hdc, c-el-pos+sc, b-el+pos-sc, c+el-pos+sc, b+el+pos-sc ) ;break;//rt
			 	case 8:Ellipse ( hdc, a-el+pos-sc, d-el-pos+sc, a+el+pos-sc, d+el-pos+sc ) ;break;//lb				 		 	
		 	}
		}
	 }
	 if(mtype()==matter::anti) 	 hbr = CreateSolidBrush ( RGB (0,0,255) ) ;
	 else if(mtype()==matter::hv) hbr = CreateSolidBrush ( RGB (255,255,0) ) ;	 
	 else hbr = CreateSolidBrush ( RGB (255,0,0) ) ;
	 holdbr = SelectObject ( hdc, hbr ) ;	 
	 Ellipse ( hdc, p, q, r, s ) ;	 	 
	 
	 SelectObject ( hdc, holdbr ) ;
	 DeleteObject ( hbr ) ;  
	 EndPaint ( hWnd, &ps ) ;
} 



/*int inner_shell(int i)
{
	i--;
	if(i==0) return 0;
	else return (2*pow(i,2)+inner_shell(i));
}
int ulti_shell(int elec,int i)
{
	return (elec-inner_shell(i));	
}


*/


 
/*void OnPaint(HWND hWnd) 
{  
	HDC hdc;
	PAINTSTRUCT ps;
	HFONT hfont;   
	LOGFONT f={0}; 
	HGDIOBJ holdfont; 
	char *fonts[]={"Arial","Times New Roman","Comic Sans MS"};
	int i;
	hdc=BeginPaint(hWnd,&ps);  
	for(i=0;i<3;i++) {   
		strcpy(f.lfFaceName,fonts[i]);  /* copy font name */    
	//	f.lfHeight=40*(i+1);  /* font height */   
	//	f.lfItalic=1;  /* italic */     
	/*	hfont=CreateFontIndirect(&f);  
		holdfont=SelectObject(hdc,hfont);  
	  	SetTextColor(hdc,RGB(0,0,255));  
	  	TextOut(hdc,10,70*i,"Hello Windows",13);
		SelectObject(hdc,holdfont);    
		DeleteObject(hfont);  
	}  
	EndPaint (hWnd,&ps); 
} */
/*bool ec2_state(int ec2,int i,int n,int elec)
{
	if(i==n){
		if(ec2<=ulti_shell(elec,i)) return true;//please rectify!!! //here elec-innershell=outershell !! //earlier in place of innershell was 2*pow(i-1,2)
		else return false;
	}	
	else if(ec2<=2*(pow(i,2))) return true;
	else return false;	
}

*/



/*case 1:Ellipse ( hdc, a-el+pos, b-el+pos, a+el+pos, b+el+pos ) ;break;//lt
		 	case 2:Ellipse ( hdc, c-el-pos, d-el-pos, c+el-pos, d+el-pos ) ;break;//rb
		 	case 3:Ellipse ( hdc, c-el-pos, b-el+pos, c+el-pos, b+el+pos ) ;break;//rt
		 	case 4:Ellipse ( hdc, a-el+pos, d-el-pos, a+el+pos, d+el-pos ) ;break;//lb	 	
		 	
		 	case 5:Ellipse ( hdc, a-el, y-el, a+el, y+el ),ec++ ;break;//l
		 	case 6:Ellipse ( hdc, c-el, y-el, c+el, y+el ),ec++ ;break;//r
		 	case 7:Ellipse ( hdc, x-el, b-el, x+el, b+el ),ec++ ;break;//t
		 	case 8:Ellipse ( hdc, x-el, d-el, x+el, d+el ),ec++ ;break;//b	 */
/*bool ec2_state(int ec2,int i,int n,int elec,int &chk1,int &chk2)
{
	if(i==n){
		if(ec2<=ulti_shell(elec,i)) return true;//please rectify!!! //here elec-innershell=outershell !! //earlier in place of innershell was 2*pow(i-1,2)
		if((elec-inner_shell(i))<0) {chk1=1; return true;} 
		else return false;
	}
	if(chk1) {
		if(ec2<=(2*pow(i,2)-ulti_shell(elec,i+1))) return true;
		else return false;
	}
	if(chk2) {
		
	}
	else if(ec2<=2*(pow(i,2))) return true;
	else return false;	
}*/
/*
int ulti_shell(int elec,int i)
{
	if((elec-inner_shell(i))>=0) return (elec-inner_shell(i));
	else return (elec-inner_shell(i)+inner_shell(i-1)*(i-3));
}*/
/*int shell_no(int e)
{
	int a=0,l,b,o,x,n;
	for(n=1,x=1;x<=e;n++){				
		for(l=0;l<n&&x<=e;l++) { 
			a=n;
			for(o=0;o<2*(2*l+1)&&x<=e;o++,x++);
		}				
	}
	return a;
} */
