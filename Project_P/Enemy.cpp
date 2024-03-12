#include "Headers/Enemy.h"
#include <cmath>

float distan(const sf::Vector2f& first, const sf::Vector2f& second) {
    return sqrt((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}


sf::Vector2f Enemy::getPosition() const {
    return position_;
}

void Enemy::setPosition(sf::Vector2f new_position) {
    position_ = new_position;
}

void Enemy::draw(sf::RenderWindow& window, const Player& player) {
    sf::Vector2f player_position = player.getPosition();
    sf::Vector2f player_sprite_position = player.hero_sprite.getPosition();
    sprite_.setPosition(player_sprite_position + position_ - player_position);
    //                    player_sprite_position.y + (position_.y - player_position.y));
    window.draw(sprite_);
    //std::cout << "\n\n" << sprite_.getPosition().x << "              " << sprite_.getPosition().y << "\n"; //*

}

float Enemy::getHealth() const {
    return health_;
}

void Enemy::hit(Player& player) {
    if(distan(player.getPosition(), position_) <= hit_distance) {
        //std::cout << "HIT\n";
    }
}

void Enemy::setTexture(const sf::Texture& texture) {
    texture_ = texture;
    sprite_.setTexture(texture_);
}

Enemy::Enemy(const std::string& link) {
    texture_.loadFromFile(link);
    sprite_.setTexture(texture_);
    sprite_.setTextureRect(sf::IntRect(1, 9, 29, 15));
    sprite_.scale(sf::Vector2f(4, 4));
}

//void Enemy::update(const Player& player, const float& delta_time) {
//    sf::Vector2f delta = (player.getPosition() - position_) / distan(player.getPosition(), position_);
//    position_ += delta * delta_time * static_cast<float>(0.1);
//}

void EnemyContainer::spawnNew() {
    time_t timer;
    time(&timer);
    if(timer - last_spawned_ >= 1) {
        last_spawned_ = timer;
        container_.push_back(new Enemy("Resourses/enemy/slime/slime-Sheet.png"));
        //std::cout << "                     SPAWNED\n"; //*
    }
}

void EnemyContainer::drawAll(sf::RenderWindow& window, const Player& player) const {
    for(Enemy* enemy : container_) {
        enemy->draw(window, player);
    }
}

std::vector<Enemy*>& EnemyContainer::getEnemyDeque(int index) {
    return container_;
}

void EnemyContainer::update(const float& delta_time, const Player& player) {
    spawnNew();
    for(Enemy* enemy : container_) {
        enemy->update(player, delta_time);
    }
}

void Enemy::update(const Player& player, float const& delta_time) {
    sf::Vector2f target = player.getPosition();
    sf::Vector2f correction_change((double)rand() / RAND_MAX / 2.5f - 0.2, (double)rand() / RAND_MAX / 2.5f - 0.2);
    correction_ += correction_change;
    target += correction_;
    sf::Vector2f delta = (target - position_) / distan(target, position_);
    position_ += delta * delta_time * static_cast<float>(0.1);
    //std::cout << "cringe";
}