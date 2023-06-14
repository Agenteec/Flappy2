#pragma once
#include <imgui.h>
#include <imgui-SFML.h>
class GUI
{
public:
	static void MainMenu(bool& onGame,bool& onMainMenu)
	{
		if (ImGui::Button(u8"Играть"))
		{
			onGame = onGame ? 0 : 1;
			onMainMenu = 0;
		}
	}
	static void OnGameGUI()
	{

	}
};

