#pragma once

class Object
{
public:
	Object(std::string name, std::string description, std::string interaction = "There is nothing i can do", std::string secret = "Nothing", std::string secretMessage = "I dont see anything special");
	~Object();

	std::string getName();
	std::string getDescription();
	std::string getInteraction();
	std::string getSecret();
	std::string getSecretMessage();

private:
	std::string name, description, secret, secretMessage, interaction;
};
