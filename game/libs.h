#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<math.h>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

#include"Container.h"

using namespace sf;

#ifndef GLOBAL_WORLD_GRIDSIZE
#define GLOBAL_WORLD_GRIDSIZE 100
#endif // !GRIDSIZE

#ifndef GLOBAL_PHYSICS_GRAVITY
#define GLOBAL_PHYSICS_GRAVITY 2500.f
#endif // !GRAVITY

/*
ERROR FORMAT:
ERROR::CLASSNAME::FUNCTION::ERROR_SPECIFICATION

SUCCESS FORMAT:
CLASSNAME::SUCCESS_SPECIFICATION
*/

/*
private:
	//Variables

	//Private functions

public:
	//Constructors/Destructors

	//Operators

	//Accessors

	//Modifiers

	//Functions
*/