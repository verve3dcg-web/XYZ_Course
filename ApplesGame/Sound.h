#pragma once
#include <SFML/Audio.hpp>

namespace ApplesGame
{
    struct AudioResource
    {
        sf::SoundBuffer eatBuffer;
        sf::SoundBuffer deathBuffer;

        sf::Sound eatSound;
        sf::Sound deathSound;

        sf::Music music;
    };

    void InitAudio(AudioResource& resource);
    void PlayEatSound(AudioResource& resource);
    void PlayDeathSound(AudioResource& resource);
}