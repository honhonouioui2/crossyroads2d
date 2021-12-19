#include "Player.h"

float lerp(float a, float b, float t) {
	return (1 - t) * a + t * b;
}
// when moving something, dont forget to multiply speed by dt
Player::Player(gameDataRef data) : _data(data)
{
	_state = 0;
}

void Player::init() {
	_sprite.first.setTexture(_data->assets.getTexture("chick up"));
	_sprite.first.setScale(3, 3);
}

/*
//si on veut que l’animation dure .4 seconde et qu’on a 4 images, chaque image
//durera .1 seconde. D’où la division par la taille du vecteur de frame
if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size()
*/

#define state_critical 2; // when the player gets hit and starts flashing & moving back a few tiles, view should follow
#define state_jumping 1;
#define state_idle (0);

#define direction_up 0;
#define direction_down 1;
#define direction_left 2;
#define direction_right 3

int getDirection(Vector2f from, Vector2f to) {
	int direction = 3; // right
	int diff = (to.x - from.x);
	if (diff == 0) {
		diff = (to.y - from.y);
		direction = diff < 0 ? 0 : direction_down;
	}
	else if (diff < 0) {
		// left
		direction = direction_left;
	}
	return direction;
}

void Player::update(float dt)
{
	if (_state == 1) {
		int direction = getDirection(_initialPosition, _goalPosition);
		cout << direction << endl;

		float alpha = (_clock.getElapsedTime().asSeconds()) / JUMP_ANIMATION_DURATION;
		//cout << alpha << endl;
		
		float offset_y = sin(_clock.getElapsedTime().asSeconds()*10)*50;
		//cout << offset_y << endl;

		Vector2f position(lerp(_initialPosition.x, _goalPosition.x, alpha), lerp(_initialPosition.y, _goalPosition.y + (offset_y), alpha));
		_sprite.first.setPosition(position);
		if (_clock.getElapsedTime().asSeconds() >= JUMP_ANIMATION_DURATION) {
			_sprite.first.setPosition(_goalPosition);
			_state = 0;
		}
	}
}

void Player::draw(float dt) const
{
	_data->window.draw(_sprite.first);
}

void Player::move(Vector2f goalPosition)
{
	_state = 1;
	_clock.restart();
	_goalPosition = goalPosition;
	_initialPosition = _sprite.first.getPosition();
}

void Player::setPosition(Vector2f position){
	_sprite.first.setPosition(position);
	_sprite.second.setPosition(position);
}

const Vector2f Player::getPosition() const
{
	return _sprite.first.getPosition();
}

const int Player::getState() const
{
	return _state;
}
