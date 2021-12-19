#pragma once
class gameObject
{
public:
	virtual void init() = 0; //init de entity
	virtual void update(float delta) = 0; //update entity
	virtual void draw(float delta)const = 0; //draw de l'entity apr�s l'update
	//delta:la diff�rence de temps avec le frame rate)
};