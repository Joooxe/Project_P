#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Animator {
private:
    sf::Texture map_texture_;
    //sf::Sprite map_sprite_;


    sf::Texture player_texture_;
    //std::vector<sf::Texture> player_textures_;
    //sf::Sprite player_sprite_;


    // Enemies textures
    sf::Texture slime_texture_;
    //sf::Sprite slime_sprite_;
public:
    Animator();


    void LoadPLayerTextures();

    sf::Texture& getMapTexture();
    sf::Texture& getPlayerTexture();
    sf::Texture& getEnemyTexture();

};