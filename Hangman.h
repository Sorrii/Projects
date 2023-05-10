#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <windows.h>

using namespace std;

class Hangman {
private:
	string difficulty;
	string wordToGuess;
	string guessedLetters;
	unsigned short currGuesses;
	unsigned short maxGuesses;
	bool* checker;
public:
	Hangman();
	Hangman(string difficulty);
	void SetGame();
	void DrawHangman();
	bool CheckLetters();
	void PrintWord();
	bool CheckWinByLetters();
	bool CheckLossByGuesses();
	void SetWordToGuess();
	string GetWordToGuess();
	unsigned short GetCurrGuesses();
	unsigned short GetMaxGuesses();
	size_t GetWordLength();
	void Game();
};