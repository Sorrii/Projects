#include "Hangman.h"

Hangman::Hangman() { 
	printf("Starting game...");
	Sleep(3000);
	system("cls");
}

Hangman::Hangman(string difficulty) : difficulty(difficulty) { 
	this->wordToGuess = "";
	this->currGuesses = 0;
	this->maxGuesses = 0;
	this->checker = nullptr;
	this->guessedLetters = "";
}

void Hangman::SetGame() {
	this->maxGuesses = 10;
	this->currGuesses = 0;

	for (int i = 0; i < wordToGuess.length(); i++) {
		checker[i] = 0;
	}
	guessedLetters = "";
}

bool Hangman::CheckWinByLetters() {
	for (int i = 0; i < wordToGuess.length(); i++) {
		if (checker[i] != 1) {
			return false;
		}
	}

	return true;
}

bool Hangman::CheckLossByGuesses() {
	if (currGuesses == maxGuesses) {
		return true;
	}
	return false;
}

bool Hangman::CheckLetters() {
	int pos = 0;
	string letter;
	short foundLetter = 0;

	printf("\n");
	printf("----------------------------------------------------\n");
	printf("Number of remaining tries: %d\n", maxGuesses - currGuesses);
	printf("Write a letter ->  ");
	std::cin >> letter;
	if (letter.length() == wordToGuess.length()) {
		if (letter == wordToGuess) {
			for (int i = 0; i < wordToGuess.length(); i++) {
				checker[i] = 1;
			}
			this->PrintWord();
			return true;
		}
	}

	for (int i = 0; i < wordToGuess.length(); i++) {
		if (checker[i] && wordToGuess[i] == letter[0]) {
			foundLetter = 1;
		}
		else if (wordToGuess[i] == letter[0] && checker[i] == 0) {
			checker[i] = 1;
			foundLetter = 2;
		}
	} 

	if (foundLetter == 2) {
		this->PrintWord();
		return true;
	}
	else if (foundLetter == 1) {
		printf("Letter already guessed!\n");
		return true;
	}

	for (int i = 0; i < guessedLetters.length(); i++) {
		if (guessedLetters[i] == letter[0]) {
			printf("Letter already guessed!\n");
			return true;
		}
	}

	guessedLetters += letter;
	currGuesses++;

	this->DrawHangman();
	printf("\n");
	printf("\n");
	this->PrintWord();
	return false;
}

void Hangman::PrintWord() {
	printf("Word: ");
	for (int i = 0; i < wordToGuess.length(); i++) {
		if (checker[i]) {
			printf("%c ", wordToGuess[i]);
		}
		else printf("_ ");
	}
	printf("\n");
}

void Hangman::SetWordToGuess() {
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<string> wordsToGuessFrom;
	string word;
	int numberOfWords = 0, randWord = 0;

	if (difficulty == "hard") {
		ifstream file("hardwords.txt");
		while (file >> word) {
			wordsToGuessFrom.push_back(word);
			numberOfWords++;
		}
		randWord = rand() % numberOfWords;
		file.close();
	}
	else if (difficulty == "medium") {
		ifstream file("mediumwords.txt");
		while (file >> word) {
			wordsToGuessFrom.push_back(word);
			numberOfWords++;
		}
		randWord = rand() % numberOfWords;
		file.close();
	}
	else {
		ifstream file("easywords.txt");
		while (file >> word) {
			wordsToGuessFrom.push_back(word);
			numberOfWords++;
		}
		randWord = rand() % numberOfWords;
		file.close();
	}

	wordToGuess = wordsToGuessFrom[randWord];
	checker = new bool[wordToGuess.length() + 1];

	for (int i = 0; i < wordToGuess.length(); i++) {
		checker[i] = 0;
	}
}

void Hangman::DrawHangman() {
	switch (currGuesses) {
	case 1:
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 2:
		std::cout << std::endl;
		std::cout << "   |     " << std::endl;
		std::cout << "   |     " << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 3:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     " << std::endl;
		std::cout << "   |     " << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 4:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |     " << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 5:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |     O" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 6:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |     O" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 7:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |     O" << std::endl;
		std::cout << "   |    /|" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 8:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |     O" << std::endl;
		std::cout << "   |    /|\\" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 9:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |     O" << std::endl;
		std::cout << "   |    /|\\" << std::endl;
		std::cout << "   |    /" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	case 10:
		std::cout << "    _____" << std::endl;
		std::cout << "   |     |" << std::endl;
		std::cout << "   |     O" << std::endl;
		std::cout << "   |    /|\\" << std::endl;
		std::cout << "   |    / \\" << std::endl;
		std::cout << "   |" << std::endl;
		std::cout << "  ===" << std::endl;
		break;
	}
}

void Hangman::Game() {
	bool ongoing_round = 1;
	printf("Game has started!\n");
	printf("Be careful! You have a maximum of 10 wrong guesses!\n");
	printf("Either guess letter by letter or full word at once! No other ways to guess are allowed!\n");
	printf("Choose difficulty: ");
	printf("easy | ");
	printf("medium | ");
	printf("hard\n");
	printf("Difficulty -> ");
	string difficulty;
	std::cin >> difficulty;
	Hangman game(difficulty);
	game.SetGame();
	game.SetWordToGuess();
	printf("Word has %zu letters.\n", game.GetWordLength());
	while (ongoing_round) {
		game.CheckLetters();
		if (game.CheckWinByLetters()) {
			string answer;
			printf("----------------------------------------------------\n");
			printf("GAME WON!\n");
			printf("Word was indeed: %s\n", game.GetWordToGuess().c_str());

			int frequency = 523; // C5 note
			int duration = 500; // duration in milliseconds

			for (int i = 0; i < 10; i++) {
				Beep(frequency, duration);
				Sleep(duration);
			}
			printf("Play again? [Y/N]: ");
			std::cin >> answer;
			if (answer == "N") {
				ongoing_round = 0;
			}
			else {
				system("cls");
				game.SetGame();
				game.SetWordToGuess();
				printf("Game has started!\n");
				printf("Word has %zu letters.\n", game.GetWordLength());
			}
		}
		if (game.CheckLossByGuesses()) {
			string answer;
			printf("----------------------------------------------------\n");
			printf("                  GAME OVER\n");
			printf("Maximum number of guesses has been reached!\n");
			printf("Word was: %s\n", game.GetWordToGuess().c_str());
			int frequency = 261; // C4 note
			int duration = 250; // duration in milliseconds

			for (int i = 0; i < 4; i++) {
				Beep(frequency, duration);
				Sleep(duration);
			}

			frequency = 196; // G3 note
			duration = 500; // duration in milliseconds

			for (int i = 0; i < 4; i++) {
				Beep(frequency, duration);
				Sleep(duration);
			}
			printf("Try again? [Y/N]: ");
			std::cin >> answer;
			if (answer == "N") {
				ongoing_round = 0;
			}
			else {
				system("cls");
				game.SetGame();
				game.SetWordToGuess();
				printf("Game has started!\n");
				printf("Word has %zu letters.\n", game.GetWordLength());
			}
		}
	}
}

size_t Hangman::GetWordLength() {
	return this->wordToGuess.length();
}

string Hangman::GetWordToGuess() {
	return this->wordToGuess;
}

unsigned short Hangman::GetCurrGuesses() {
	return this->currGuesses;
}

unsigned short Hangman::GetMaxGuesses() {
	return this->maxGuesses;
}