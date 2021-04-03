cmake_minimum_required(VERSION 3.17)
project(rotmgGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH /opt/homebrew/opt/sfml)

find_package(SFML 2.5 COMPONENTS audio graphics network system window REQUIRED)
add_executable(rotmgGame main.cpp Player.h Window.h Game.h Bullet.h Beholder.h HealthBar.h BeholderBullet.h PlayerBullet.h
        Player.cpp PlayerBullet.cpp Beholder.cpp BeholderBullet.cpp Game.cpp Window.cpp HealthBar.cpp Bullet.cpp Text.cpp
        Text.h assets.h assets.cpp)
target_link_libraries(rotmgGame PUBLIC sfml-audio sfml-graphics sfml-network sfml-system sfml-window)