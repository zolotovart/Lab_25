// Lab_25.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Lab_25.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void Cross(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, cx - size, cy, NULL);
    LineTo(hdc, cx+size, cy);
    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx, cy+size);
    DeleteObject(hPen);

}

void Triangle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, cx, cy - size, NULL);
    LineTo(hdc, cx + size, cy + size);
    LineTo(hdc, cx - size, cy + size);
    LineTo(hdc, cx, cy - size);

    DeleteObject(hPen);
}
void Triangle2(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
    SelectObject(hdc, hPen);

    MoveToEx(hdc, cx - size, cy - size, NULL);
    LineTo(hdc, cx + size, cy - size);
    LineTo(hdc, cx, cy + size);
    LineTo(hdc, cx - size, cy - size);

    DeleteObject(hPen);
}
void Circle(HDC hdc, int cx, int cy, int size) {
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, cx - size, cy - size, cx + size, cy + size);

    DeleteObject(hPen);
}
void Image2(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy - size; 
    int x2 = cx + size / 2;
    int y2 = cy - size;
    int x3 = cx - size;
    int y3 = cy + size;
    int x4 = cx + size;
    int y4 = cy + size;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Image3(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy;
    int x3 = cx;
    int y3 = cy + size;
    int x4 = cx - size;
    int y4 = cy;

    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Image4(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size/4;
    int y2 = cy - size/4;
    int x3 = cx+size;
    int y3 = cy;
    int x4 = cx + size/4;
    int y4 = cy + size/4;
    int x5 = cx;
    int y5 = cy + size;
    int x6 = cx - size / 4;
    int y6 = cy + size / 4;
    int x7 = cx - size;
    int y7 = cy;
    int x8 = cx - size / 4;
    int y8 = cy - size / 4;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(100, 200, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Image5(HDC hdc, int cx, int cy, int size) {
    int x1 = cx;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy;
    int x3 = cx + size/2;
    int y3 = cy+size;
    int x4 = cx - size / 2;
    int y4 = cy + size;
    int x5 = cx-size;
    int y5 = cy;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(100, 200, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Image6(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size/2;
    int y1 = cy - size;
    int x2 = cx + size;
    int y2 = cy - size;
    int x3 = cx;
    int y3 = cy - size * 3 / 4;
    int x4 = cx + size / 2;
    int y4 = cy + size;
    int x5 = cx - size;
    int y5 = cy + size;
    int x6 = cx;
    int y6 = cy + size * 3 / 4;
    int x7 = cx - size / 2;
    int y7 = cy - size;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(100, 200, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);

    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Image7(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 2;
    int y1 = cy - size;
    int x2 = cx + size/2;
    int y2 = cy - size;
    int x3 = cx + size/2;
    int y3 = cy + size/2;
    int x4 = cx + size;
    int y4 = cy + size/2;
    int x5 = cx;
    int y5 = cy + size;
    int x6 = cx-size;
    int y6 = cy + size/2;
    int x7 = cx - size / 2;
    int y7 = cy + size/2;
    int x8 = cx - size / 2;
    int y8 = cy - size;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(100, 200, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);

    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Dop1(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size;
    int y1 = cy - size;
    int x2 = cx;
    int y2 = cy - size/2;
    int x3 = cx + size;
    int y3 = cy - size;
    int x4 = cx +size;
    int y4 = cy - size/2;
    int x5 = cx;
    int y5 = cy;
    int x6 = cx + size;
    int y6 = cy + size / 2;
    int x7 = cx + size;
    int y7 = cy + size;
    int x8 = cx;
    int y8 = cy + size/2;
    int x9 = cx - size;
    int y9 = cy + size;
    int x10 = cx - size;
    int y10 = cy + size / 2;
    int x11 = cx;
    int y11 = cy;
    int x12 = cx - size;
    int y12 = cy - size / 2;
    int x13 = cx - size;
    int y13 = cy - size;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(100, 200, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x9, y9);
    LineTo(hdc, x10, y10);
    LineTo(hdc, x11, y11);
    LineTo(hdc, x12, y12);
    LineTo(hdc, x13, y13);

    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void Dop2(HDC hdc, int cx, int cy, int size) {
    int x1 = cx - size / 4 *3;
    int y1 = cy - size/2;
    int x2 = cx - size/2;
    int y2 = cy;
    int x3 = cx;
    int y3 = cy + size;
    int x4 = cx + size/2;
    int y4 = cy;
    int x5 = cx+size/4*3;
    int y5 = cy - size/2;
    int x6 = cx + size;
    int y6 = cy;
    int x7 = cx;
    int y7 = cy + size / 2;
    int x8 = cx - size;
    int y8 = cy;
    int x9 = cx - size / 4 * 3;
    int y9 = cy - size / 2;
    HPEN hPen;
    hPen = CreatePen(PS_SOLID, 2, RGB(100, 200, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    LineTo(hdc, x3, y3);
    LineTo(hdc, x4, y4);
    LineTo(hdc, x5, y5);
    LineTo(hdc, x6, y6);
    LineTo(hdc, x7, y7);
    LineTo(hdc, x8, y8);
    LineTo(hdc, x9, y9);

    LineTo(hdc, x1, y1);

    DeleteObject(hPen);
}
void recCross(HDC hdc, int cx, int cy, int size){
    Cross(hdc, cx, cy, size);
    if (size < 2) {
        return;
    }
    recCross(hdc, cx - size, cy, size / 2);
}
void recCross2(HDC hdc, int cx, int cy, int size) {
    HPEN hpen;
    Cross(hdc, cx, cy, size);
    if (size < 10) {
        return;
    }
    recCross2(hdc, cx, cy-size, size / 2);
}
void RecursiveCross(HDC hdc, int cx, int cy, int size) {
    Cross(hdc, cx, cy, size);
    if (size < 10) {
        return;
    }
    RecursiveCross(hdc, cx - size, cy, size / 2);
    RecursiveCross(hdc, cx, cy - size, size / 2);
}
void RecursiveTriangle(HDC hdc, int cx, int cy, int size) {
    Triangle(hdc, cx, cy, size);
    if (size < 10) {
        return;
    }
    RecursiveTriangle(hdc, cx, cy - size, size / 2);
}
void recImage1_1(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage1_1(hdc, cx - size/2, cy - size, size/2);
}
void recImage1_2(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage1_2(hdc, cx - size, cy - size, size / 2);
    recImage1_2(hdc, cx + size, cy - size, size / 2);
}
void recImage1_3(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage1_3(hdc, cx - size, cy - size, size / 2);
    recImage1_3(hdc, cx, cy + size, size / 2);
}
void recImage1_4(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage1_4(hdc, cx - size, cy - size, size / 2);
    recImage1_4(hdc, cx + size, cy - size, size / 2);
    recImage1_4(hdc, cx, cy + size, size / 2);
}
void recImage1_5(HDC hdc, int cx, int cy, int size) {
    Triangle2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage1_5(hdc, cx - size, cy, size / 2);
    recImage1_5(hdc, cx + size, cy, size / 2);
    recImage1_5(hdc, cx, cy - size, size / 2);
}


void recImage2_1(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    recImage2_1(hdc, cx - size, cy + size, size/ 2);
}
void recImage2_2(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    recImage2_2(hdc, cx - size/2, cy - size, size / 2);
    recImage2_2(hdc, cx + size/2, cy - size, size / 2);
}
void recImage2_3(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 5) {
        return;
    }
    recImage2_3(hdc, cx - size, cy + size, size / 2);
    recImage2_3(hdc, cx + size, cy + size, size / 2);
}
void recImage2_4(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage2_4(hdc, cx - size, cy + size, size / 2);
    recImage2_4(hdc, cx + size, cy + size, size / 2);
    recImage2_4(hdc, cx + size/2, cy - size, size / 2);
    recImage2_4(hdc, cx - size/2, cy - size, size / 2);


}
void recImage2_5(HDC hdc, int cx, int cy, int size) {
    Image2(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage2_5(hdc, cx - size, cy, size / 2);
    recImage2_5(hdc, cx + size, cy, size / 2);
}
void recImage3_1(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage3_1(hdc, cx + size, cy, size / 2);
}
void recImage3_2(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage3_2(hdc, cx - size, cy, size / 2);
    recImage3_2(hdc, cx + size, cy, size / 2);
}
void recImage3_3(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage3_3(hdc, cx - size, cy, size / 2);
    recImage3_3(hdc, cx + size, cy, size / 2);
    recImage3_3(hdc, cx, cy+size, size / 2);
}
void recImage3_4(HDC hdc, int cx, int cy, int size) {
    Image3(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage3_4(hdc, cx - size, cy, size / 2);
    recImage3_4(hdc, cx + size, cy, size / 2);
    recImage3_4(hdc, cx, cy + size, size / 2);
    recImage3_4(hdc, cx, cy - size, size / 2);
}
void recImage4_1(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage4_1(hdc, cx + size, cy, size / 2);
}
void recImage4_2(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage4_2(hdc, cx + size, cy, size / 2);
    recImage4_2(hdc, cx - size, cy, size / 2);
}
void recImage4_3(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage4_3(hdc, cx, cy + size, size / 2);
    recImage4_3(hdc, cx, cy - size, size / 2);
}
void recImage4_4(HDC hdc, int cx, int cy, int size) {
    Image4(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }
    recImage4_4(hdc, cx, cy + size, size / 2);
    recImage4_4(hdc, cx, cy - size, size / 2);
    recImage4_4(hdc, cx - size, cy, size / 2);
}
void recImage5(HDC hdc, int cx, int cy, int size) {
    Image5(hdc, cx, cy, size);
    
    if (size < 80) {
        return;

    }
    recImage5(hdc, cx - size, cy, size / 2);
    recImage5(hdc, cx + size, cy, size / 2);
    recImage5(hdc, cx, cy - size, size / 2);
    recImage5(hdc, cx - size/3*2, cy+size, size / 2);
    recImage5(hdc, cx + size/3*2, cy+size, size / 2);
}
void recImage6(HDC hdc, int cx, int cy, int size) {
    Image6(hdc, cx, cy, size);

    if (size < 80) {
        return;

    }
    recImage6(hdc, cx - size, cy + size, size / 2);
    recImage6(hdc, cx + size, cy - size, size / 2);
    recImage6(hdc, cx + size/2, cy + size, size / 2);
    recImage6(hdc, cx - size/2, cy - size, size / 2);
}
void recImage7(HDC hdc, int cx, int cy, int size) {
    Image7(hdc, cx, cy, size);

    if (size < 80) {
        return;

    }
    recImage7(hdc, cx - size, cy + size/2, size / 2);
    recImage7(hdc, cx + size, cy + size/2, size / 2);
    recImage7(hdc, cx + size / 2, cy - size, size / 2);
    recImage7(hdc, cx - size / 2, cy - size, size / 2);
    recImage7(hdc, cx, cy + size, size / 2);

}
void recDop1(HDC hdc, int cx, int cy, int size) {
    Dop1(hdc, cx, cy, size);
    if (size < 20) {
        return;

    }
    recDop1(hdc, cx, cy + size / 2, size / 2);
    recDop1(hdc, cx, cy - size / 2, size / 2);
    recDop1(hdc, cx +size /2, cy, size / 2);
    recDop1(hdc, cx - size / 2, cy, size / 2);
}
void recDop2(HDC hdc, int cx, int cy, int size) {
    Dop2(hdc, cx, cy, size);
    if (size < 20) {
        return;

    }
    recDop2(hdc, cx, cy + size / 2, size / 2);
    recDop2(hdc, cx, cy - size / 2, size / 2);
    recDop2(hdc, cx + size / 2, cy, size / 2);
    recDop2(hdc, cx - size / 2, cy, size / 2);

}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB25, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB25));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB25));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB25);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            //RecursiveCross(hdc, 200, 160, 80);
            //RecursiveTriangle(hdc, 200, 160, 80);
            
            //recImage1_1(hdc, 200, 160, 80);
            //recImage1_2(hdc, 200, 160, 80);
            //recImage1_3(hdc, 200, 160, 80);
            //recImage1_4(hdc, 200, 160, 80);
            //recImage1_5(hdc, 200, 160, 80);

            //recImage2_1(hdc, 200, 160, 80);
            //recImage2_2(hdc, 200, 160, 80);
            //recImage2_3(hdc, 200, 160, 80);
            //recImage2_4(hdc, 200, 160, 80);
            //recImage2_5(hdc, 200, 160, 80);

            //recImage3_1(hdc, 900, 160, 80);
            //recImage3_2(hdc, 900, 160, 80);
            //recImage3_3(hdc, 900, 160, 80);
            //recImage3_4(hdc, 900, 160, 80);

            //recImage4_1(hdc, 900, 160, 80);
            //recImage4_2(hdc, 900, 160, 80);
            //recImage4_3(hdc, 900, 160, 80);
            //recImage4_4(hdc, 900, 160, 80);

            //recImage5(hdc, 900, 160, 80);
            //recImage6(hdc, 900, 160, 80);
            //recImage7(hdc, 900, 160, 80);

            //dop zadachi
            recDop1(hdc, 900, 480, 80);
            recDop2(hdc, 250, 480, 80);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
