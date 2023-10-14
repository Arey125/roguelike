#pragma once

#include <imgui.h>
#include <imgui-SFML.h>

void showMenu(sf::RenderWindow &window) {
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    
    ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoCollapse
    );
    if (ImGui::Button("Quit")) {
        window.close();
    }
    ImGui::End();
}
