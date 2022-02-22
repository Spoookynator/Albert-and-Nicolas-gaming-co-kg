#include <iostream>
#include "objects.h"
#include "debugLog.h"

Object::Object(std::string name, std::string description, bool aquirable, int scene, std::string interaction, std::string secret, std::string secretMessage)
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
	LOG("Object: \"" + name + "\" deleted!");
}

std::string Object::getName()
{
	return name;
}

std::string Object::getDescription()
{
	return description;
}

std::string Object::getInteraction()
{
	return interaction;
}
std::string Object::getSecret()
{
	return secret;
}
std::string Object::getSecretMessage()
{
	return secretMessage;
}