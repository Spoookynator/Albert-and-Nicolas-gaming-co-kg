#include <iostream>
#include "objects.h"
#include "debugLog.h"

Object::Object(std::string name, std::string description, std::string interaction, std::string secret, std::string secretMessage)
{
	this->name = name;
	this->description = description;
	this->interaction = interaction;
	this->secret = secret;
	this->secretMessage = secretMessage;

	LOG("Object: \"" + name + "\" created!");
}

Object::~Object()
{
}