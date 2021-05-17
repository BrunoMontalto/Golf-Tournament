#include <iostream>
#include <fstream>
#include<string>
#include "dinamicArray.h"
#include "Player.h"
using namespace std;


bool load(DinamicArray<Player>* dest, string filename = "Punteggi.txt"){
	ifstream file;
	file.open(filename);
}




int main() {
	DinamicArray<Player> test(10);
	return 0;
}