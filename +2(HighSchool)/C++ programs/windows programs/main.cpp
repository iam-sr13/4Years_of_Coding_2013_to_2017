#include<windows.h>
void OnPaint(HWND hWnd) 
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
		f.lfHeight=40*(i+1);  /* font height */   
		f.lfItalic=1;  /* italic */     
		hfont=CreateFontIndirect(&f);  
		holdfont=SelectObject(hdc,hfont);  
	  	SetTextColor(hdc,RGB(0,0,255));  
	  	TextOut(hdc,10,70*i,"Hello Windows",13);
		SelectObject(hdc,holdfont);    
		DeleteObject(hfont);  
	}  
	EndPaint(hWnd,&ps); 
} 
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) { /* This is where all the input to the window goes to */
	switch(Message) {		
		case WM_DESTROY: { /* Upon destruction, tell the main thread to stop */
			PostQuitMessage(0);
			break;
		}	
		case WM_PAINT :  {  
			OnPaint ( hwnd ) ;   
		    break ;	
		}
		default:/* All other messages (a lot of them) are processed using default procedures */
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { /* The 'main' function of Win32 GUI programs: this is where execution starts */
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG Msg; /* A temporary location for all messages */
	
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
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	MessageBox(0,"This is Window test!","Message:",0);
	while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate key codes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	return Msg.wParam;
}
