#include <iostream>
#include <vector>
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
	return description + "\n";
}

std::string Object::getInteraction()
{
	return interaction + "\n";
}
std::string Object::getSecret()
{
	return secret;
}
std::string Object::getSecretMessage()
{
	return secretMessage + "\n";
}

Keyword::Keyword(bool found, std::vector<std::string> keywords)
{
	this->keywords = keywords;
	this->found = found;
}

Keyword::~Keyword()
{
}

std::vector<std::string> Keyword::getKeywords()
{
	return keywords;
}

bool Keyword::foundWords()
{
	return found;
}

void Keyword::foundWords(bool foundWord)
{
	found = foundWord;
}
