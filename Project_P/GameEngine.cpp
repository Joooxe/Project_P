#include <SFML/Graphics.hpp>
#include <Headers/GameEngine.h>
#include <filesystem>

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
		delta_time = delta_time / 100;

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
		player.move(Player::playermove::LeftPressed, delta_time); 
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		player.move(Player::playermove::RightPressed, delta_time);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player.move(Player::playermove::UpPressed, delta_time);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //*
		player.move(Player::playermove::DownPressed, delta_time);
	}
}

void GameEngine::update(float const& delta_time) {

}

void GameEngine::draw() {
	//if state == playing
	window.clear();
	player.draw(window);
	window.display();
	window.setView(main_view);
}

void GameEngine::restart() {
	player.setCentre();
}

int main() {
	std::unique_ptr <GameEngine> myGame = std::make_unique<GameEngine>();
	myGame->run();
}