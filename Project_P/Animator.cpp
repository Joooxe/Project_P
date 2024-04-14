#include "Headers/Animator.h"

Animator::Animator() {
    #ifdef _WIN32
    map_texture_.loadFromFile("Resourses/map/map.png");
    std::cerr << "MAP TEXTURE LOADED: " << map_texture_.getSize().x << " " << map_texture_.getSize().y << "\n";
    player_texture_.loadFromFile("Resourses/hero/Side Movement.png");
    slime_texture_.loadFromFile("Resourses/enemy/slime/slime-Sheet.png");

    #elif __linux__
    map_texture_.loadFromFile("../../Resourses/map/map.png");
    std::cerr << "MAP TEXTURE LOADED: " << map_texture_.getSize().x << " " << map_texture_.getSize().y << "\n";
    player_texture_.loadFromFile("../../Resourses/hero/Side Movement.png");
    slime_texture_.loadFromFile("../../Resourses/enemy/slime/slime-Sheet.png");
    #endif
}

sf::Texture& Animator::getMapTexture() {
    return map_texture_;
}

sf::Texture& Animator::getPlayerTexture() {
    std::cout << "GET\n";
    return player_texture_;
}

sf::Texture& Animator::getEnemyTexture() {
    return slime_texture_;
}

void Animator::LoadPLayerTextures() {
    //player_textures_.resize(8);
    //TODO
}