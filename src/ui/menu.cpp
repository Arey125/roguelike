#include <imgui.h>
#include <imgui-SFML.h>

#include "menu.h"

Menu::Menu(sf::Window &window): window(window), menuIsOpen(false) {}


void Menu::processEvent(sf::Event &event) {
    auto type = event.type;

    if (type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape)
            menuIsOpen = !menuIsOpen;
}

void Menu::showMenu() {
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

void Menu::update() {
    if (menuIsOpen) {
        showMenu();
    }
}

void Menu::render(sf::RenderTarget &target) {}
