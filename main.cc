// Displays a random sight word for your little one to learn.
//

#include <iostream>
#include <vector>
#include <string>

#include "words.h"
#include "word_cache.h"

using namespace std;

const int CACHE_SIZE = 25;

int main() {

  int word_index = 0;

  WordCache* cache = new WordCache(CACHE_SIZE);

  const vector<string> words = Words::GetWords();

  srand( time(0) );

  while (true) {
    system("clear");

    word_index = rand() % Words::GetWords().size();

    // Skip the word if it is in the cache
    if (cache->IsIndexInCache(word_index)) continue;

    // Add the word's index to the cache
    cache->UpdateCache(word_index);

    // Output the next word
    cout << words[word_index] << endl;

    // Wait for the Enter key
    cin.ignore();
  }

  delete cache;

  return 0;
}

