#include "Enemy.h"


class Bullet {
public:
    static const time_t life_tyme_ = 1;
    static const time_t delay_ = 0.7;

    time_t spawn_time_;
    sf::Vector2f position_;
    sf::Vector2f target_position_;

    sf::Sprite bullet_sprite_;


    Bullet(Player& spawn_coords, const sf::Vector2f& target);

    void setSprite(Animator& animator);

    void update(Player& player_position, float const& delta_time);

    bool alive(const time_t& timer);
};




class BulletContainer {
private:
    std::vector<Bullet*> container_;
    time_t last_spawned_ = 0;
public:
    void spawnNew(Animator& animator, Player& player, const sf::Vector2f& target);
    void drawAll(sf::RenderWindow& window, Player& player) const;
    std::vector<Bullet*>& getEnemyList(int index);
    void update(float const& delta_time, Animator& animator, Player& player);
};