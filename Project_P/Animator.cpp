#include "Headers/Animator.h"

Animator::Animator() {
    #ifdef _WIN32
    map_texture_.loadFromFile("Resourses/map/map.png");
    std::cerr << "MAP TEXTURE LOADED: " << map_texture_.getSize().x << " " << map_texture_.getSize().y << "\n";
    side_movement.loadFromFile("Resourses/hero/Side Movement.png");
    front_movement.loadFromFile("Resourses/hero/Front Movement.png");
    back_movement.loadFromFile("Resourses/hero/Back Movement.png");
    slime_texture_.loadFromFile("Resourses/enemy/slime/slime-Sheet.png");
    bullet_texture_.loadFromFile("Resourses/bullet/default_bullet.png");

    currentPlayerTexture = front_movement;
    #elif __linux__
    map_texture_.loadFromFile("../../Resourses/map/map.png");
    std::cerr << "MAP TEXTURE LOADED: " << map_texture_.getSize().x << " " << map_texture_.getSize().y << "\n";
    player_texture_.loadFromFile("../../Resourses/hero/Side Movement.png");
    slime_texture_.loadFromFile("../../Resourses/enemy/slime/slime-Sheet.png");
    bullet_texture_.loadFromFile("../../Resourses/bullet/default_bullet.png");
    #endif
}

sf::Texture& Animator::getMapTexture() {
    return map_texture_;
}

sf::Texture& Animator::getPlayerTexture() {
    std::cout << "GET\n";
    return currentPlayerTexture;
}

sf::Texture& Animator::getEnemyTexture() {
    return slime_texture_;
}

sf::Texture& Animator::getBulletTexture() {
    return bullet_texture_;
}

void Animator::LoadPLayerTextures() {
    //player_textures_.resize(8);
    //TODO
}

void Animator::animatePlayer(const float& delta_time, int animInd, sf::Sprite& hero) {
    currentFrame += 0.007 * delta_time;
    if(currentFrame > 6) {
        currentFrame -= 6;
    }
    switch(animInd) {
    case 1:
    {   
        currentPlayerTexture = side_movement;
        currentFrame += 0.002 * delta_time;
        hero.setTextureRect(sf::IntRect(35 + 64 * int(currentFrame), 82, -12, 24));
        break;
    }
    case 2:
    {
        currentPlayerTexture = front_movement;
        hero.setTextureRect(sf::IntRect(24 + 64 * int(currentFrame), 82, 15, 24));
        break;
    }
    case 3:
    {   
        currentPlayerTexture = side_movement;
        currentFrame += 0.002 * delta_time;
        hero.setTextureRect(sf::IntRect(23 + 64 * int(currentFrame), 82, 12, 24));
        break;
    }
    case 4:
    {
        currentPlayerTexture = side_movement;
        hero.setTextureRect(sf::IntRect(35 + 64 * int(currentFrame), 82, -12, 24));
        break;
    }
    case 5:
    {   
        currentPlayerTexture = side_movement;
        hero.setTextureRect(sf::IntRect(23 + 64 * int(currentFrame), 82, 12, 24));
        break;
    }
    case 6:
    {
        currentPlayerTexture = side_movement;
        currentFrame += 0.002 * delta_time;
        hero.setTextureRect(sf::IntRect(35 + 64 * int(currentFrame), 82, -12, 24));
        break;
    }
    case 7:
    {
        currentPlayerTexture = back_movement;
        hero.setTextureRect(sf::IntRect(24 + 64 * int(currentFrame), 81, 15, 24));
        break;
    }
    case 8:
    {
        currentPlayerTexture = side_movement;
        currentFrame += 0.002 * delta_time;
        hero.setTextureRect(sf::IntRect(23 + 64 * int(currentFrame), 82, 12, 24));
        break;
    }
    case 0:
    {   
        currentPlayerTexture = front_movement;
        hero.setTextureRect(sf::IntRect(25 + 64 * int(currentFrame), 18, 18, 24));
        break;
    }
    }
}