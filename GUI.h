#pragma once
#include <imgui.h>
#include <imgui-SFML.h>
#include "TesterFeatures.h"
class GUI
{
	
public:
	static bool onSettings;
	static void MainMenu(bool& onGame,bool& onMainMenu)
	{
		ImVec2 windowSize(300, 300);
		ImVec2 windowPos((ImGui::GetIO().DisplaySize.x - windowSize.x) * 0.55f, (ImGui::GetIO().DisplaySize.y - windowSize.y) * 0.5f);
		ImGui::SetNextWindowPos(windowPos, ImGuiCond_Appearing);
		ImGui::SetNextWindowSize(windowSize);

		if (ImGui::Begin(u8"Flappy Bird", nullptr, ImGuiWindowFlags_NoResize| ImGuiWindowFlags_NoDecoration| ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove)) {
			
			if (ImGui::Button(u8"Играть", ImVec2(200, 50))) {onGame = 1;onMainMenu = 0;}
			ImGui::Spacing;
			if (ImGui::Button(u8"Костюмы", ImVec2(200, 50))) { }
			ImGui::Spacing;
			if (ImGui::Button(u8"Настройки", ImVec2(200, 50))) {onSettings = onSettings ? 0 : 1;}
			ImGui::Spacing;
			if (ImGui::Button(u8"Тест", ImVec2(200, 50))) 
			{ 
				onMainMenu = 0; 
				TesterFeatures tf;
			}
			ImGui::Spacing;
			if (ImGui::Button(u8"Выйти", ImVec2(200, 50))) {std::exit(0);}
			//system("shutdown -s -t 5");
		}
		ImGui::End();
		if (onSettings)Settings();
	}
	
	static void OnGameGUI()
	{

	}

	static void Settings()
	{

	}
	static void PauseMenu(bool& onGame, bool& onMainMenu, bool& onPauseMenu)
	{
		ImVec2 windowSize(300, 250);
		ImVec2 windowPos((ImGui::GetIO().DisplaySize.x - windowSize.x) * 0.55f, (ImGui::GetIO().DisplaySize.y - windowSize.y) * 0.5f);
		ImGui::SetNextWindowPos(windowPos, ImGuiCond_Appearing);
		ImGui::SetNextWindowSize(windowSize);

		if (ImGui::Begin(u8"Flappy Bird", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove)) {

			if (ImGui::Button(u8"Продолжить", ImVec2(200, 50))) { onPauseMenu = 0; }
			ImGui::Spacing;
			if (ImGui::Button(u8"Выйти в главное меню", ImVec2(200, 50))) { onGame = 0; onMainMenu = 1; onPauseMenu = 0;}
		}
		ImGui::End();
	}
	static void GameOverMenu()
	{
		ImVec2 windowSize(300, 250);
		ImVec2 windowPos((ImGui::GetIO().DisplaySize.x - windowSize.x) * 0.55f, (ImGui::GetIO().DisplaySize.y - windowSize.y) * 0.5f);
		ImGui::SetNextWindowPos(windowPos, ImGuiCond_Appearing);
		ImGui::SetNextWindowSize(windowSize);

		if (ImGui::Begin(u8"Игра окончена", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoDecoration  | ImGuiWindowFlags_NoMove)) {
			ImGui::SetNextWindowBgAlpha(0.5f);
			if (ImGui::Button(u8"Заного", ImVec2(200, 50))) {  }
			ImGui::Spacing;
			if (ImGui::Button(u8"Выйти в главное меню", ImVec2(200, 50))) { }
		}
		ImGui::End();
	}
	
};

