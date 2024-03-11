#include "Headers/Player.h"

Player::Player() {
    resetPlayer();
}

void Player::resetPlayer() {
    // position = /*проставить базу*/;
    hero_texture.loadFromFile("Resourses/hero/Side Movement.png");
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(sf::IntRect(24, 18, 9, 24));
    hero_sprite.scale(sf::Vector2f(4, 4));
    //anim_player = Animator(hero_sprite);
    max_health = 10000;
    cur_health = 10000;
    regeneration = 500;
    max_speed = 10;
    speed_x = 0;
    speed_y = 0;
    damage_modifier = 0;
    firerate_modifier = 0;
}

void Player::move(playermove move_direction, float const& delta_time) { //delta_time here untill we setup this in update func
    switch(move_direction) {
    case playermove::DownLf:
        //speed_x = -max_speed;
        //speed_y = -max_speed;
        break;
    case playermove::DownPressed:
        hero_sprite.move(0, 0.1 * delta_time);
        //speed_x = 0;
        //speed_y = -max_speed;
        break;
    case playermove::DownRg:
        //speed_x = max_speed;
        //speed_y = -max_speed;
        break;
    case playermove::LeftPressed:
        hero_sprite.move(-0.1 * delta_time, 0);
        //speed_x = -max_speed;
        //speed_y = 0;
        break;
    case playermove::RightPressed:
        hero_sprite.move(0.1 * delta_time, 0);
        //speed_x = max_speed;
        //speed_y = 0;
        break;
    case playermove::Stop:
        //speed_x = 0;
        //speed_y = 0;
        break;
    case playermove::UpLf:
        //speed_x = -max_speed;
        //speed_y = max_speed;
        break;
    case playermove::UpPressed:
        hero_sprite.move(0, -0.1 * delta_time);
        //speed_x = 0;
        //speed_y = max_speed;
        break;
    case playermove::UpRg:
        //speed_x = max_speed;
        //speed_y = max_speed;
        break;
    }
}

void Player::draw(sf::RenderWindow& window) const { //*
    window.draw(hero_sprite);
}

void Player::setCentre() {
    hero_sprite.setPosition(300, 400);
}

void Player::hit(int damage) {
    increaseCurHealth(-damage);
}

void Player::die() {
    // приводим здоровье ровно к 0 для корректного отображения
    increaseCurHealth(-getCurHealth());
    /* наверное отправляем сигнал в гейм енджин */
}

void Player::update(sf::Time deltaTime, sf::Vector2i mousePosition) {
    increaseCurHealth(getRegeneration());

    setPosition(getPosition().x + speed_x, getPosition().y + speed_y);
}

void Player::setPosition(float new_x, float new_y) {
    float left_limit = 0;
    float right_limit = 2999;
    new_x = std::max(left_limit, new_x);
    new_x = std::min(right_limit, new_x);
    new_y = std::max(left_limit, new_y);
    new_y = std::min(right_limit, new_y);
    sf::Vector2f new_position(new_x, new_y);
    position = new_position;
}

sf::Vector2f Player::getPosition() {
    return position;
}

float Player::getMaxSpeed() {
    return max_speed;
}

void Player::increaseMaxSpeed(float max_speed_change) {
    max_speed += max_speed_change;
}

float Player::getSpeedX() {
    return speed_x;
}

void Player::setSpeedX(float new_speed_x) {
    speed_x = new_speed_x;
}

float Player::getSpeedY() {
    return speed_y;
}

void Player::setSpeedY(float new_speed_y) {
    speed_y = new_speed_y;
}

sf::Sprite Player::getSprite() {
    return sprite;
}

//Animator Player::getAnimPlayer() {
//    return anim_player;
//}

int Player::getMaxHealth() {
    return max_health;
}

void Player::increaseMaxHealth(int max_health_change) {
    max_health += max_health_change;
}

int Player::getCurHealth() {
    return cur_health;
}

void Player::increaseCurHealth(int cur_health_change) {
    cur_health += cur_health_change;
    cur_health = std::min(cur_health, getMaxHealth());
    if(getCurHealth() <= 0) {
        die();
    }
}

int Player::getRegeneration() {
    return regeneration;
}

void Player::increaseRegeneration(int regeneration_change) {
    regeneration += regeneration_change;
}

int Player::getDamageModifier() {
    return damage_modifier;
}

void Player::increaseDamageModifier(int damage_modifier_change) {
    damage_modifier += damage_modifier_change;
}

int Player::getFirerateModifier() {
    return firerate_modifier;
}

void Player::increaseFirerateModifier(int firerate_modifier_change) {
    firerate_modifier += firerate_modifier_change;
}
