#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"
#include "GUI.h"

class Window
{
	/// <summary>
	/// Ширина окна
	/// </summary>
	float WinW;
	/// <summary>
	/// Высота окна
	/// </summary>
	float WinH;
	/// <summary>
	/// Указатель на главное окно
	/// </summary>
	sf::RenderWindow* window;
	/// <summary>
	/// Запущена ли игра
	/// </summary>
	bool onGame;

	bool onMainMenu;
public:
	Window():
		WinW(1024.f),
		WinH(768.f),
		onGame(false),
		onMainMenu(true)

	{
		//Выделение памяти под оно SFML
		window = new sf::RenderWindow(sf::VideoMode(WinW, WinH), "FlappyBird");
		imguiInit();
		game::init();

	}
	/// <summary>
	/// Главный цикл окна SFML
	/// </summary>
	void Render()
	{

		while (window->isOpen())
		{
			sf::Event* event= new sf::Event;
			window->clear(sf::Color(0, 0, 0));
			//**//
			while (window->pollEvent(*event))
			{
				ImGui::SFML::ProcessEvent(*event);
				if (event->type == sf::Event::Closed)
					window->close();
				if (onGame)
				{
					game::game_event(event);
				}
			}
			ImGui::SFML::Update(*window, sf::seconds(1.f / 60.f));
			if (onGame){game::on_game(window, event);}
			if (onMainMenu){GUI::MainMenu(onGame,onMainMenu);}
			//**//
			
			ImGui::SFML::Render(*window);
			window->display();
			


			delete event;
		}
	}
	/// <summary>
	/// Удаляем окно из кучи
	/// </summary>
	~Window() {
		delete window;
	}
private:
	/// <summary>
	/// Инициализация imgui
	/// </summary>
	void imguiInit()
	{
		ImGui::SFML::Init(*window);
		// Загрузка шрифта для imgui
		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->Clear();
		io.Fonts->AddFontFromFileTTF("Resources\\Fonts\\impact.ttf", 20.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());

		// Обновляем текстуру текста
		ImGui::SFML::UpdateFontTexture();

		// Настройка стилей для imgui
		ImGui::StyleColorsClassic();
		ImGui::GetStyle().WindowBorderSize = 0.f;

		ImGuiStyle& style = ImGui::GetStyle(); // получаем текущий стиль

		// изменяем цвет фона кнопок
		style.Colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);

		// изменяем цвет текста на кнопке
		style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);

		// изменяем отступ вокруг кнопки
		style.FramePadding = ImVec2(10.0f, 5.0f);

		// изменяем выравнивание текста на кнопке
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);


	}
};