#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Headers/Player.h"

struct Enemy {
    sf::Texture texture_;
    sf::Sprite sprite_;
    sf::Vector2f position_ = {10, 10};
    float health_ = 100;
    float damage_ = 100;
    float shield_ = 100;
    float hit_distance = 5;
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f);
    void draw(sf::RenderWindow& window, const Player& player);
    float getHealth() const;
    void hit(Player& player);
    void setTexture(const sf::Texture& texture);
    void update(const Player& player, const float& delta_time);
    Enemy(const std::string& link);
};


class EnemyContainer {
private:
    size_t cur_size_ = 0;
    static const size_t kMaxContainerSize_ = 100;
    std::vector<Enemy*> container_;
    time_t last_spawned_ = 0;
public:
    void spawnNew();
    void drawAll(sf::RenderWindow& window, const Player& player) const;
    std::vector<Enemy*>& getEnemyDeque(int index);
    void update(const float& delta_time, const Player& player);
};