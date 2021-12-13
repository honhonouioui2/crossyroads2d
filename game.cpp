#include "game.h"
#include <time.h>
#include <stdlib.h>
#include "gameState.h"

game::game(int width, int height, string title)
{
	_data = make_shared<gameData>();//création de la game en mémoire dynamique
	//création de la fenêtre qui changera de contenu selon la state créée ensuite
	_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);
	//todo création d’un 1er état de jeu (1ère fenêtre)
	_data->machine.addState(stateRef(new gameState(_data)));
	//todo initialisation du random avec srand pour la création des pipes de hauteur aléatoire
	srand(time(0));
	run();
}

//le game loop de tout jeu fonctionne comme suit : on exécute à chaque loop la méthode 
//processStateChanges qui vérifie si on ajoute, on modifie ou on retire une state pour ensuite 
//ajuster le temps passé et exécuter des traitements particuliers à chaque (1/60sec)
//ces traitements sont gérer par la state machine. Ensuite, on dessine les changements 
void game::run()
{
	float newTime, frameTime, interpolation;
	float currentTime = _clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;
	while (_data->window.isOpen())
	{
		_data->machine.processStateChanges();
	}
}