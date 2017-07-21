#include<windows.h>
int WINAPI WinMain(HINSTANCE i,HINSTANCE previ,LPSTR j,int k)
{
	HWND h;
	h=CreateWindow ("BUTTON","Hit Me",WS_OVERLAPPEDWINDOW,10,10,150,100,0,0,1,0);
	ShowWindow(h,k);
	MessageBox(0,"Second Win Program!","Waiting!!!",MB_OK);
	return 0;
}
