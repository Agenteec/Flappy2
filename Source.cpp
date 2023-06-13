#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "Window.h"
#include <Windows.h>
#define IDS_SCORE 101


int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);
    wchar_t buffer[256];

    if (LoadString(hInstance, IDS_SCORE, buffer, sizeof(buffer)))
    {
        // Ресурс успешно загружен
        wprintf(L"Text: %s\n", buffer);
    }
    else
    {
        // Ошибка при загрузке ресурса
        wprintf(L"Error\n");
    }
    system("pause");
	Window window;
	window.Render();
	return 0;
}