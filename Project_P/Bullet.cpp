#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

#include "Headers/Bullet.h"

float abs(const sf::Vector2f& vect) {
    return std::sqrt(vect.x * vect.x + vect.y + vect.y);
}


Bullet::Bullet(Player& spawn_coords, const sf::Vector2f& target) {
    time(&spawn_time_);
    position_ = spawn_coords.getPosition(); //   + sf::Vector2f(24, 30);
    target_position_ = (target - spawn_coords.getPosition());
    target_position_ /= abs(target_position_);
}

void Bullet::setSprite(Animator& animator) {
    bullet_sprite_.setTexture(animator.getBulletTexture());
    bullet_sprite_.setTextureRect(sf::IntRect(24, 18, 9, 24));
}

void Bullet::update(Player& player, float const& delta_time) {
    position_ += target_position_ * delta_time;
    bullet_sprite_.setPosition(player.hero_sprite.getPosition() + position_ - player.getPosition());
}

bool Bullet::alive(const time_t& timer) {
    return (timer < (spawn_time_ + life_tyme_));
}

void BulletContainer::spawnNew(Animator& animator, Player& player, const sf::Vector2f& target) {
    time_t timer;
    time(&timer);
    if(timer < last_spawned_ + Bullet::delay_) {
        return;
    }
    last_spawned_ = timer;
    container_.push_back(new Bullet(player, target));
    container_[container_.size() - 1]->setSprite(animator);
}


void BulletContainer::drawAll(sf::RenderWindow& window, Player& player) const {
    for(auto bullet : container_) {
        window.draw(bullet->bullet_sprite_);
    }
}

void BulletContainer::update(const float& delta_time, Animator& animator, Player& player) {
    if(container_.empty()) {
        return;
    }
    time_t timer;
    time(&timer);
    int live_index = container_.size() - 1;
    for(int bullet_index = 0; bullet_index < live_index; ++bullet_index) {
        container_[bullet_index]->update(player, delta_time);
        if(!container_[bullet_index]->alive(timer)) {
            std::swap(container_[live_index], container_[bullet_index]);
            --live_index;
        }
    }
    int dead_num = container_.size();
    for(size_t dead = live_index + 1; dead < dead_num; ++dead) {
        container_.pop_back();
    }
}
