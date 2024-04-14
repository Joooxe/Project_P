#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include "Headers\GameEngine.h"


using key = sf::Keyboard;


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
    if(key::isKeyPressed(key::Escape)) {
        window.close();
    }
    if(key::isKeyPressed(key::Space)) {
        std::cout << "DASHED\n";
        player.move(Player::playermove::Dash, delta_time);
    } else if(key::isKeyPressed(key::A) && key::isKeyPressed(key::W)) {
        player.move(Player::playermove::UpLf, delta_time);
    } else if(key::isKeyPressed(key::A) && key::isKeyPressed(key::S)) {
        player.move(Player::playermove::DownLf, delta_time);
    } else if(key::isKeyPressed(key::W) && key::isKeyPressed(key::D)) {
        player.move(Player::playermove::UpRg, delta_time);
    } else if(key::isKeyPressed(key::D) && key::isKeyPressed(key::S)) {
        player.move(Player::playermove::DownRg, delta_time);
    } else if(key::isKeyPressed(key::A)) { //*
        player.move(Player::playermove::LeftPressed, delta_time);
    } else if(key::isKeyPressed(key::D)) {
        player.move(Player::playermove::RightPressed, delta_time);
    } else if(key::isKeyPressed(key::W)) {
        player.move(Player::playermove::UpPressed, delta_time);
    } else if(key::isKeyPressed(key::S)) { //*
        player.move(Player::playermove::DownPressed, delta_time);
    }
}

void GameEngine::update(float const& delta_time) {
    enemyContainer.update(delta_time, animator, player);
}

void GameEngine::draw() {
    //if state == playing
    window.clear();
    player.loadArea(window);
    enemyContainer.drawAll(window, player);
    player.draw(window);
    window.display();
    window.setView(main_view);

}

void GameEngine::restart() {
    player.setCentre(window);
}

int main() {
    std::unique_ptr<GameEngine> myGame = std::make_unique<GameEngine>();
    myGame->run();
}
