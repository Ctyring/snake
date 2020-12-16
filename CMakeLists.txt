cmake_minimum_required(VERSION 3.17)
project(snake C)

set(CMAKE_C_STANDARD 11)
add_executable(snake main.c common/BASE.h common/BASE.c view/panel.h view/panel.c view/controlpanel.h view/controlpanel.c view/keyhander.c view/keyhander.h view/SettingPanel.h view/SettingPanel.c view/GamePanel.c view/GamePanel.h control/GameControl.c control/GameControl.h model/GameData.c model/GameData.h)