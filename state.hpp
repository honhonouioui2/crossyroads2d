#pragma once
class state
{
public:
	virtual void init() = 0; //init de state
	virtual void handleInput() = 0; //tous les input de la fenêtre
	virtual void update(float delta) = 0; //update la fenêtre après le input
	virtual void draw(float delta)const = 0; //draw la fenêtre après le update (delta est
	//la différence de temps avec le frame rate)
	virtual void pause() {} //pause et resume le state
	virtual void resume() {}
};