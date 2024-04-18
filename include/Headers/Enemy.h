#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "Headers/Player.h"

struct Enemy {
    sf::Sprite enemy_sprite_;

    sf::Vector2f position_ = {10, 10};
    sf::Vector2f correction_ = {0, 0};
    float health_ = 100;
    float damage_ = 100;
    float shield_ = 100;
    float hit_distance = 5;

    Enemy(Animator& animator);

    [[nodiscard]] sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f);
    void draw(sf::RenderWindow& window, Player& player);
    [[nodiscard]] float getHealth() const;
    void hit(Player& player);
    void setTexture(sf::Texture& texture);
    void update(Player& player, Animator& animator, const float& delta_time);
};


class EnemyContainer {
private:
    static const size_t kMaxContainerSize_ = 100;
    std::vector<Enemy*> container_;
    time_t last_spawned_ = 0;
public:
    void spawnNew(Animator& animator);
    void drawAll(sf::RenderWindow& window, Player& player) const;
    std::vector<Enemy*>& getEnemyDeque(int index);
    void update(Player& player, Animator& animator, float const& delta_time);
    sf::Vector2f getNearest(Player& player);
};