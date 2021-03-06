#pragma once

#include <SFML/Graphics.hpp>

#include "Util/NonCopyable.hpp"
#include "Util/NonMoveable.hpp"
#include "States/StateMachine.hpp"
#include "Util/FPSCounter.hpp"
#include "ResourceManager/ResourceHolder.hpp"
#include "Wrapers/YamlConfig.hpp"


/**
    Main controlling class of the game.
    Handles state switches and the main loop, as well
    as counting the FPS
*/
class Game : public NonCopyable, public NonMovable
{
    public:
        Game(std::string path);

        void run();
        void exitGame();
        const sf::RenderWindow& getWindow() const;
        void setView(const sf::View view);
        void setDefaultView();

        StateMachine* m_pSM;

    private:
        void handleEvent();

        std::string path_to_game;

        YAML::Node  m_config;

        sf::RenderWindow m_window;

        StateMachine m_stateMachine;

        FPSCounter m_fpsCounter;
};