// Project_P.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Map.h"
#include "Headers/Enemy.h"

class GameEngine {
public:
    GameEngine();

    void run();

private:
    enum class GameState {
        paused,
        run,
        victory_screen,
    };
    /*float width_;
    float height_;*/
    sf::RenderWindow window;
    Map map;
    Player player;
    sf::View main_view = sf::View(sf::FloatRect(0, 0, 800, 600));
    sf::IntRect playground_size;
    sf::VertexArray background;
    EnemyContainer enemyContainer; //added by KWAMPEK

    void input(float const& delta_time); //delta_time here untill we setup this in update func
    void update(float const& delta_time);

    void draw();

    void restart();
};