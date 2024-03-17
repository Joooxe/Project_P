#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "Headers\GameEngine.h"

// Project_P.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.


GameEngine::GameEngine() {
    window.create(sf::VideoMode(800, 600), "Project_P");
    main_view.setSize(800, 600);
    restart();
}

void GameEngine::run() {
    sf::Clock clock;
    while(window.isOpen()) {
        float delta_time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        delta_time = delta_time / 600;

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        input(delta_time);
        update(delta_time);
        draw();
    }
}

void GameEngine::input(float const& delta_time) { //delta_time here untill we setup this in update func
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        window.close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //*
        if(map.isStaticY(player.getPosition().x, window.getSize().x)) {
            player.move(Player::playermove::LeftPressed, delta_time);
        } else {
            map.move(Map::mapmove::LeftPressed, delta_time);
        }
        player.addX(-0.1 * delta_time);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(map.isStaticY(player.getPosition().x, window.getSize().x)) {
            player.move(Player::playermove::RightPressed, delta_time);
        } else {
            map.move(Map::mapmove::RightPressed, delta_time);
        }
        player.addX(0.1 * delta_time);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(map.isStaticY(player.getPosition().y, window.getSize().y)) {
            player.move(Player::playermove::UpPressed, delta_time);
        } else {
            map.move(Map::mapmove::UpPressed, delta_time);
        }
        player.addY(-0.1 * delta_time);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //*
        if(map.isStaticY(player.getPosition().y, window.getSize().y)) {
            player.move(Player::playermove::DownPressed, delta_time);
        } else {
            map.move(Map::mapmove::DownPressed, delta_time);
        }
        player.addY(0.1 * delta_time);
    }
    //std::cout << player.getPosition().y << "     " << player.getPosition().x << "   " << window.getSize().x << "   "
    //          << window.getSize().y << "\n";
}

void GameEngine::update(float const& delta_time) {
    enemyContainer.update(delta_time, player);
}

void GameEngine::draw() {
    //if state == playing
    window.clear();
    map.draw(window);
    enemyContainer.drawAll(window, player);
    player.draw(window);
    window.display();
    window.setView(main_view);

}

void GameEngine::restart() {
    player.setCentre(window);
}

int main() {
    std::unique_ptr <GameEngine> myGame = std::make_unique<GameEngine>();
    myGame->run();
}
