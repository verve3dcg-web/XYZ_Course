#include "Sound.h"
#include "Consts.h"
#include <iostream>

namespace ApplesGame
{
    void InitAudio(AudioResource& resource)
    {

        if (!resource.eatBuffer.loadFromFile(SOUND_EAT_PATH)) {
            std::cerr << "Failed to load eat sound!" << std::endl;
        }
        if (!resource.deathBuffer.loadFromFile(SOUND_DEATH_PATH)) {
            std::cerr << "Failed to load death sound!" << std::endl;
        }


        resource.eatSound.setBuffer(resource.eatBuffer);
        resource.deathSound.setBuffer(resource.deathBuffer);


        resource.eatSound.setVolume(20.f);
        resource.deathSound.setVolume(20.f);

        if (!resource.music.openFromFile(MUSIC_THEME_PATH)) {
            std::cerr << "Failed to load music!" << std::endl;
        }
        else {
            resource.music.setLoop(true);
            resource.music.setVolume(10.f);
        }

        resource.music.play();
    }

    void PlayEatSound(AudioResource& resource)
    {
        resource.eatSound.play();
    }

    void PlayDeathSound(AudioResource& resource)
    {
        resource.deathSound.play();
    }
}