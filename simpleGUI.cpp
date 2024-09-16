#include <windows.h>
#include <exdisp.h>
#include <mshtml.h>
#include <comdef.h>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")


const char g_szClassName[] = "myWindowClass";
const int ID_BTN_OPEN_BROWSER = 2;


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;


    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc; 
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Class Registration Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

   
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Simple GUI Application",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    
    CreateWindow("BUTTON", "Open Browser",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        20, 20, 150, 30,
        hwnd, (HMENU)ID_BTN_OPEN_BROWSER, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    
    while (GetMessage(&Msg, NULL, 0, 0))
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static IWebBrowser2 *pWebBrowser = NULL;

    switch (msg)
    {
    case WM_DESTROY:
        if (pWebBrowser)
        {
            pWebBrowser->Release();
            pWebBrowser = NULL;
        }
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == ID_BTN_OPEN_BROWSER)
        {
            
            CoInitialize(NULL);

            
            IWebBrowser2 *pWebBrowser = NULL;
            HRESULT hr = CoCreateInstance(CLSID_InternetExplorer, NULL, CLSCTX_LOCAL_SERVER, IID_IWebBrowser2, (void**)&pWebBrowser);
            if (SUCCEEDED(hr))
            {
                pWebBrowser->put_Visible(VARIANT_TRUE);
                BSTR bstrURL = SysAllocString(L"https://www.example.com");
                pWebBrowser->Navigate(bstrURL, NULL, NULL, NULL, NULL);
                SysFreeString(bstrURL);
            }
            CoUninitialize();
        }
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
