// Displays a random sight word for your little one to guess.
//

#include <iostream>
#include <string>

using namespace std;

const int WORD_COUNT = 60;
const int CACHE_SIZE = WORD_COUNT / 2;

bool IsIndexInCache(int [], int, int);
void UpdateCache(int (&)[CACHE_SIZE], int);

int main() {

  int index = 0;
  int last_n_words [CACHE_SIZE] = {};

  string words[WORD_COUNT] = {
    "And"    , "The"   , "Is"    , "He"    , "Like" ,
    "Said"   , "Play"  , "A"     , "For"   , "Here" ,
    "She"    , "Have"  , "Me"    , "To"    , "Go"   ,
    "Look"   , "My"    , "Are"   , "Book"  , "Game" ,
    "Fat"    , "Cat"   , "Dog"   , "Car"   , "Bat"  ,
    "Who"    , "What"  , "Where" , "Why"   , "How"  ,
    "I"      , "Boy"   , "Girl"  , "Stop"  , "Man"  ,
    "Woman"  , "Hello" , "Hi"    , "Yes"   , "No"   ,
    "Please" , "Help"  , "Nice"  , "Bad"   , "Good" ,
    "Ice"    , "One"   , "Win"   , "End"   , "Bend" ,
    "In"     , "Get"   , "Water" , "Gas"   , "Fast" ,
    "Bed"    , "Cup"   , "Food"  , "Happy" , "Sad"
  };

  srand( time(0) );

  while (true) {
    system("clear");
    index = rand() % WORD_COUNT;

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

