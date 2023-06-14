#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "Window.h"
#include <Windows.h>
#include <iostream>
#define IDS_SCORE 101


int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    wchar_t buffer[256];

    if (LoadString(hInstance, IDS_SCORE, buffer, sizeof(buffer) / sizeof(wchar_t)))
    {
        // Ресурс успешно загружен
        std::wcout << L"Text: " << buffer << std::endl;

        // Изменение строки на "New Text"
        std::wstring newString = L"New Text";
        wcscpy_s(buffer, newString.c_str());

        std::wcout << L"Modified string: " << buffer << std::endl;
    }
    else
    {
        // Ошибка при загрузке ресурса
        std::cout << "Error loading resource" << std::endl;
    }
    //system("pause");
	Window window;
	window.Render();
	return 0;
}