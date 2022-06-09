// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

std::string low(std::string str) {
std::string t = "";
for (auto x = str.begin(); x != str.end(); ++x) {
t += tolower(*x);
}
return t;
}

BST<std::string> makeTree(const char* filename) {
BST<std::string> newTree;
std::ifstream file(filename);
std::string word = "";
if (file.is_open()) {
while (!file.eof()) {
word = "";
while (true) {
char letter = file.get();
if ((letter >= 97 && letter <= 122) || (letter >= 65 && letter <= 90)) {
word += tolower(letter);
} else {
break;
}
}
while (!file.eof()) {
char let = file.get();
if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z')) {
word += let;
} else {
word = low(word);
newTree.add(word);
word = "";
}
return newTree;
} else {
throw std::string("Did`t open!");
}
return newTree;
}


