#pragma once

class Object
{
public:
	Object(std::string name, std::string description, std::string interaction, std::string secret, std::string secretMessage);
	~Object();

private:
	std::string name, description, secret, secretMessage, interaction;
};
