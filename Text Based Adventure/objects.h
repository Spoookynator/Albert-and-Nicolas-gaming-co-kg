#pragma once
#include <iostream>
#include <vector>

class Object
{
public:
	Object(int scene, std::string name, std::string description, bool aquirable, std::string interaction = "It's existing...", std::string secret = "Nothing", std::string secretMessage = "I dont see anything special");
	~Object();

	std::string getName();
	std::string getDescription();
	std::string getInteraction();
	std::string getSecret();
	std::string getSecretMessage();
	bool getAquirable();
	int getScene();
	void setScene(int input);


private:
	std::string name, description, secret, secretMessage, interaction;
	int scene;
	bool aquirable;
};

class Keyword
{
public:
	Keyword(bool found_, std::vector<std::string> keywords = {"empty"});
	~Keyword();
	bool foundWords();
	void foundWords(bool foundWord);
	std::vector<std::string> getKeywords();

private:
	bool found;
	std::vector<std::string> keywords;
};

