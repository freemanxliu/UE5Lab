#include<Windows.h>
//#pragma comment(lib,"winmm.lib") //导入声音头文件库
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrecInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("helloWin");
	
	HWND	 hwnd;		// HWND 窗口句柄
	MSG		 msg;		// MSG  消息结构
	WNDCLASS wndclass;  // WNDCLASS  窗口类

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("this program requires windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(
		szAppName,					//window class name		
		TEXT("The Hello Program"),	//window caption
		WS_OVERLAPPEDWINDOW,		//window style
		CW_USEDEFAULT,				//initial x position
		CW_USEDEFAULT,				//initial y position
		CW_USEDEFAULT,				//initial x size
		CW_USEDEFAULT,				//initial y size
		NULL,						//parent window handle
		NULL,						//window menu handle
		hInstance,					//program instance handle
		NULL);						//creation parameters
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
// 返回值类型为LRSULT,该类型等价于LONG
// CALLBACK是函数的类型,这个标识符被定义为__stdcall,它指定了在Windows和应用程序之间的函数调用的特定次序
// HWND 窗口句柄
// UINT 其实就是unsigned int,仅仅是为了书写方便,在Windows 98 中,表示一个32位的值.
// WPARAM 16位的无符号短整型
// LPARAM 32位的有符号的长整型
{
	HDC hdc; // HDC 设备环境句柄
	PAINTSTRUCT ps;  // PAINTSTRUCT  绘制结构
	RECT rect;  //RECT 矩形结构

	switch (message)
	{
	case WM_CREATE:
		//PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, TEXT("hello,veeja!"), -1, &rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);

}