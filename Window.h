#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"
#include "GUI.h"

class Window
{
	/// <summary>
	/// ������ ����
	/// </summary>
	float WinW;
	/// <summary>
	/// ������ ����
	/// </summary>
	float WinH;
	/// <summary>
	/// ��������� �� ������� ����
	/// </summary>
	sf::RenderWindow* window;
	/// <summary>
	/// �������� �� ����
	/// </summary>
	bool onGame;

	bool onMainMenu;

	bool onPauseMenu;
public:
	Window():
		WinW(1024.f),
		WinH(768.f),
		onGame(false),
		onMainMenu(true),
		onPauseMenu(false)

	{
		//��������� ������ ��� ��� SFML
		window = new sf::RenderWindow(sf::VideoMode(WinW, WinH), "FlappyBird");
		imguiInit();
		game::init();

	}
	/// <summary>
	/// ������� ���� ���� SFML
	/// </summary>
	void Render()
	{
		sf::Clock clock;

		while (window->isOpen())
		{
			sf::Time deltatime = clock.restart();
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
				if (event->type == sf::Event::KeyPressed)
				{
					if (event->key.code == sf::Keyboard::Escape&&!onMainMenu)
					{
						onPauseMenu = 1;
					}
				}
			}
			ImGui::SFML::Update(*window, sf::seconds(1.f / 60.f));
			if (onGame){
				game::on_game(window, deltatime,onPauseMenu);
			}
			if (onMainMenu){GUI::MainMenu(onGame,onMainMenu);}
			if (onPauseMenu) { 
				GUI::PauseMenu(onGame, onMainMenu, onPauseMenu);
				if (onMainMenu)
				{
					game::new_game();
				}
			}
			//**//
			
			ImGui::SFML::Render(*window);
			window->display();
			


			delete event;
		}
	}
	/// <summary>
	/// ������� ���� �� ����
	/// </summary>
	~Window() {
		delete window;
	}
private:
	/// <summary>
	/// ������������� imgui
	/// </summary>
	void imguiInit()
	{
		ImGui::SFML::Init(*window);
		// �������� ������ ��� imgui
		ImGuiIO& io = ImGui::GetIO();
		io.Fonts->Clear();
		io.Fonts->AddFontFromFileTTF("Resources\\Fonts\\impact.ttf", 20.f, nullptr, io.Fonts->GetGlyphRangesCyrillic());

		// ��������� �������� ������
		ImGui::SFML::UpdateFontTexture();

		// ��������� ������ ��� imgui
		ImGui::StyleColorsLight();
		ImGui::GetStyle().WindowBorderSize = 0.f;

		ImGuiStyle& style = ImGui::GetStyle(); // �������� ������� �����

		// �������� ���� ���� ������
		style.Colors[ImGuiCol_Button] = ImVec4(255.0f / 255.f, 21.0f / 255.f, 102.0f / 255.f, 1.0f);

		// �������� ���� ������ �� ������
		style.Colors[ImGuiCol_Text] = ImVec4(250.0f / 255.f, 250.0f / 255.f, 255.0f / 255.f, 1.0f);

		// �������� ������ ������ ������
		style.FramePadding = ImVec2(10.0f, 5.0f);

		// �������� ������������ ������ �� ������
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);


	}
};