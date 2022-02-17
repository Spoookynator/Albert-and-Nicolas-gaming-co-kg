#pragma once

class Object
{
public:
	Object(std::string name, std::string description, std::string interaction, std::string secret, std::string secretMessage);
	~Object();

	std::string getName();
	std::string getDescription();
	std::string getInteraction();
	std::string getSecret();
	std::string getSecretMessage();

private:
	std::string name, description, secret, secretMessage, interaction;
};
