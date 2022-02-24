#include <iostream>
#include <vector>
#include "objects.h"
#include "debugLog.h"


Object::Object(int scene, std::string name, std::string description, bool aquirable, std::string interaction, std::string secret, std::string secretMessage)
{
	this->scene = scene;
	this->name = name;
	this->description = description;
	this->interaction = interaction;
	this->aquirable = aquirable;
	this->secret = secret;
	this->secretMessage = secretMessage;

	LOG("Object: \"" + name + "\" created!");
}

Object::~Object()
{
	LOG("Object: \"" + name + "\" deleted!");
}

int Object::getScene()
{
	return scene;
}
std::string Object::getName()
{
	return name;
}
std::string Object::getDescription()
{
	return description + "\n";
}
bool Object::getAquirable()
{
	return aquirable;
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
void Object::setScene(int input)
{
	scene = input;
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
