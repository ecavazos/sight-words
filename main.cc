// Displays a random sight word for your little one to learn.
//

#include <iostream>
#include <vector>
#include <string>

#include "words.h"

using namespace std;

const int CACHE_SIZE = 25;

bool IsIndexInCache(int [], int, int);
void UpdateCache(int (&)[CACHE_SIZE], int);

int main() {

  int index = 0;
  int last_n_words[CACHE_SIZE] = {};

  const vector<string> words = Words::GetWords();

  srand( time(0) );

  while (true) {
    system("clear");

    index = rand() % Words::GetWords().size();

    if (IsIndexInCache(last_n_words, index, CACHE_SIZE)) continue;

    UpdateCache(last_n_words, index);

    cout << words[index] << endl;
    cin.ignore();
  }

  return 0;
}

bool IsIndexInCache(int cache[], int new_index, int cache_size) {
  // This is to prevent words from displaying too often.
  for (int i = 0; i < CACHE_SIZE; i++) {
    // cout << cache[i] << endl;
    if (new_index == cache[i]) return true;
  }
  return false;
}

void UpdateCache(int (&cached_words)[CACHE_SIZE], int new_index) {
  // Add the new index to the front of the cached and shift the remaining items
  // over by one. This will drop off the oldest index in the cache.
  for (int i = (CACHE_SIZE - 1); i > 0; i--) {
    cached_words[i] = cached_words[i-1];
  }
  cached_words[0] = new_index;
}

