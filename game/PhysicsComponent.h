#pragma once
#include"libs.h"

class PhysicsComponent
{
private:
	Vector2f velocity;
	float maxSpeed;
	float acceleration;
	Vector2f degeneration;

	void calculateDegeneration(const float& dt)
	{
		//X degeneration
		if (velocity.x > 0.f) //Moving Right
		{
			this->velocity.x -= this->degeneration.x * dt;

			if (velocity.x <= 0.f)
				this->velocity.x = 0.f;
		}
		else if (velocity.x < 0.f) //Moving Left
		{
			this->velocity.x += this->degeneration.x * dt;

			if (velocity.x >= 0.f)
				this->velocity.x = 0.f;
		}
		else //Standing still
		{
			this->velocity.x = 0.f;
		}

		//Y degeneration
		if (velocity.y > 0.f) //Moving Right
		{
			this->velocity.y -= this->degeneration.y * dt;

			if (velocity.y <= 0.f)
				this->velocity.y = 0.f;
		}
		else if (velocity.y < 0.f) //Moving Left
		{
			this->velocity.y += this->degeneration.y * dt;

			if (velocity.y >= 0.f)
				this->velocity.y = 0.f;
		}
		else //Standing still
		{
			this->velocity.y = 0.f;
		}

	}
	Vector2f normalize(const Vector2f& vector)
	{
		float vectorLength = sqrt((pow(vector.x, 2) + pow(vector.y, 2)));
		Vector2f normalizedVector = vector / vectorLength;
		
		if (vectorLength <= 0.f)
			return Vector2f(0.f, 0.f);
		else
			return normalizedVector;
	}

public:
	//Constructors / Destructors
	PhysicsComponent(
		const Vector2f& velocity = Vector2f(0.f, 0.f),
		const float& maxSpeed = 0.f,
		const float& acceleration = 0.f,
		const Vector2f& degeneration = Vector2f(0.f, 0.f))
	{
		this->velocity = velocity;
		this->maxSpeed = maxSpeed;
		this->acceleration = acceleration;
		this->degeneration = degeneration;
	}

	//Accessors
	inline const Vector2f& getVelocity() const
	{
		return this->velocity;
	}

	inline const float& getMaxSpeed() const
	{
		return this->maxSpeed;
	}

	inline const float& getAcceleration() const
	{
		return this->acceleration;
	}

	inline const Vector2f& getDegeneration() const
	{
		return this->degeneration;
	}

	inline const Vector2f& getDirectionVector()
	{
		return this->normalize(this->velocity);
	}


	//Modifiers
	inline void setVelocity(const float& x, const float& y)
	{
		this->velocity.x = x;
		this->velocity.y = y;
	}

	inline void incrementVelocity(const float& dirX, const float& dirY, const float& dt)
	{
		/* ASSUMES DIRECTION IS NORMALIZED!!!*/
		this->velocity += this->acceleration * Vector2f(dirX, dirY) * dt;
	}

	inline void setMaxSpeed(const float& maxSpeed)
	{
		this->maxSpeed = maxSpeed;
	}

	inline void setAcceleration(const float& acceleration)
	{
		this->acceleration = acceleration;
	}

	inline void setDegeneration(const Vector2f& degeneration)
	{
		this->degeneration = degeneration;
	}
	
	//Functions
	void update(const float& dt)
	{
		//Move
		if (Keyboard::isKeyPressed(Keyboard::D))
			this->incrementVelocity(1.f, 0.f, dt);
		if (Keyboard::isKeyPressed(Keyboard::A))
			this->incrementVelocity(-1.f, 0.f, dt);
		if (Keyboard::isKeyPressed(Keyboard::W))
			this->incrementVelocity(0.f, -1.f, dt);
		if (Keyboard::isKeyPressed(Keyboard::S))
			this->incrementVelocity(0.f, 1.f, dt);

		//Slow the entity down
		this->calculateDegeneration(dt);

		system("CLS");
		std::cout << "VelocityX: " << this->velocity.x << " " << "VelocityY: " << this->velocity.y << "\n";
		std::cout << "DirectionX: " << this->getDirectionVector().x << " " << "DirectionY: " << this->getDirectionVector().y << "\n";
	}
};