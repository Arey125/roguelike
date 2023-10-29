#include <imgui.h>
#include <imgui-SFML.h>

#include "menu.h"

Menu::Menu(sf::Window &window):
    window(window),
    menuIsOpen(false),
    fps(60),
    v_sync(false)
{
    auto style = &ImGui::GetStyle();
    style->ScaleAllSizes(3);
    style->GrabRounding = 5;
    style->FrameRounding = 5;
    style->WindowRounding = 5;
}


int Menu::getFPS() {
    return fps;
}

void Menu::processEvent(sf::Event &event) {
    auto type = event.type;

    if (type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Escape) {
            state = MenuState::Main;
            menuIsOpen = !menuIsOpen;
        }
}

void Menu::showMainMenu() {
    if (ImGui::Button("Resume")) {
        menuIsOpen = false;
    }
    if (ImGui::Button("Settings")) {
        state = MenuState::Settings;
    }
    if (ImGui::Button("Quit")) {
        window.close();
    }
}

void Menu::showSettings() {
    ImGui::Text("Settings");
    
    if (ImGui::Checkbox("Vertical sync", &v_sync)) {
        window.setVerticalSyncEnabled(v_sync);
    }

    if (ImGui::SliderInt("FPS", &fps, 20, 120)) {
        window.setFramerateLimit(fps);
    }

    if (ImGui::Button("Back")) {
        state = MenuState::Main;
    }
}

void Menu::showMenu() {
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    
    ImGui::Begin("Menu", nullptr, ImGuiWindowFlags_NoMove
        | ImGuiWindowFlags_NoResize
        | ImGuiWindowFlags_NoCollapse
        | ImGuiWindowFlags_AlwaysAutoResize
    );

    if (state == MenuState::Main) {
        showMainMenu();
    }
    if (state == MenuState::Settings) {
        showSettings();
    }

    ImGui::End();
}

void Menu::update() {
    if (menuIsOpen) {
        showMenu();
    }
}

void Menu::render(sf::RenderTarget &target) {}
