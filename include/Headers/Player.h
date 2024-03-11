#include <iostream>
#include "Animator.h"

class Player {
public:
    enum class playermove {
        UpPressed,
        UpRg, 
        UpLf, 
        DownPressed,
        DownRg, 
        DownLf,
        LeftPressed, 
        RightPressed, 
        Stop
    };
    // конструктор
    Player();
    sf::Texture hero_texture;
    sf::Sprite hero_sprite;
    // установка параметров по умолчанию
    void resetPlayer();
    // снаружи нам говорят, какая клавиша была нажата
    void move(playermove move_direction, float const& delta_time); //delta_time here untill we setup this in update func
    // получение урона игроком
    void hit(int damage);
    // смерть игрока
    void die();
    // выполняется в каждом цикле Гейм Енджина
    void update(sf::Time deltaTime, sf::Vector2i mousePosition);
    // геттеры и сеттеры для всех полей, которым это нужно
    sf::Vector2f getPosition();
    void setPosition(float new_x, float new_y);
    float getMaxSpeed();
    void increaseMaxSpeed(float max_speed_change);
    float getSpeedX();
    void setSpeedX(float new_speed_x);
    float getSpeedY();
    void setSpeedY(float new_speed_y);
    sf::Sprite getSprite();
    Animator getAnimPlayer();
    int getMaxHealth();
    void increaseMaxHealth(int max_health_change);
    int getCurHealth();
    void increaseCurHealth(int cur_health_change);
    int getRegeneration();
    void increaseRegeneration(int regeneration_change);
    int getDamageModifier();
    void increaseDamageModifier(int damage_modifier_change);
    int getFirerateModifier();
    void increaseFirerateModifier(int firerate_modifier_change);
    void draw(sf::RenderWindow& window) const;
    void setCentre();
private:
    // позиция по x и y
    sf::Vector2f position;
    // максимальная скорость
    float max_speed;
    // текущая скорость по x
    float speed_x;
    // текущая скорость по y
    float speed_y;
    // внешний вид (спрайт и анимация)
    sf::Sprite sprite;
    //Animator anim_player;
    // максимум здоровья
    int max_health;
    // текущее здоровье
    int cur_health;
    // регенерация
    int regeneration;
    // бонус к урону
    int damage_modifier;
    // бонус к скорострельности
    int firerate_modifier;
};
