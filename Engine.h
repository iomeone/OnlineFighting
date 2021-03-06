#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <ggponet.h>
#include <Windows.h>
#include <iostream>
#include "Character.h"
#include "NonGameState.h"
#include "GameState.h"

#define FRAME_DELAY 3
#define FRAMERATE 60

void AdvanceFrame(int inputs[], int disconnect_flags, float time);
int ReadInputs(sf::RenderWindow* Window);

class Engine
{
private:
	sf::RenderWindow* _window;
	Character* _characters[MAX_PLAYERS];

	bool Init(int LocalPort, int NumberOfPlayers, GGPOPlayer* Players, int NumberOfSpectators);
	void MainLoop();
	void ProcessInput();
	void RenderFrame(GameState& gameState);
	void Update(GameState* gameState, float time);
	void RunFrame(float time);
	void Idle(int time);

public:
	void Go(int LocalPort, int NumberOfPlayers, GGPOPlayer* Players, int NumberOfSpectators);

	Engine();
	~Engine();
};

#endif