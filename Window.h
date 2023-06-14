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
public:
	Window():
		WinW(1024.f),
		WinH(768.f),
		onGame(false)
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

		while (window->isOpen())
		{
			sf::Event* event= new sf::Event;
			window->clear(sf::Color(0, 0, 0));
			//**//
			while (window->pollEvent(*event))
			{
				if (event->type == sf::Event::Closed)
					window->close();
			}
			if (onGame)
			{
				game::on_game(window, event);
			}
			//**//
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
	}
};