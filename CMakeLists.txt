cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(CMAKE_TOOLCHAIN_FILE "~/software/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(roguelike)

include_directories(src)

# find packages
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
find_package(box2d CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

# add_executable(roguelike main.cpp)
add_executable(roguelike
  src/main.cpp
  src/app/app.cpp
  src/shared/rigid_body/rigid_body.cpp
  src/shared/entity/entity.cpp
)

# link libraries
target_link_libraries(roguelike PRIVATE box2d::box2d)
target_link_libraries(roguelike PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(roguelike PRIVATE imgui::imgui)
target_link_libraries(roguelike PRIVATE ImGui-SFML::ImGui-SFML)
