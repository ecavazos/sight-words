#include "words.h"

const string Words::words_[] = {
  "And", "Bland", "Sand", "Hand",
  "The",
  "Said", "Red", "Bed", "Head",
  "Have",
  "To", "Do", "Moo", "Boo", "Who", "Blue",
  "Go", "Snow", "Blow", "Grow", "Show",
  "Here",
  "Is", "His", "Fizz",
  "For", "More", "Store", "Core", "Bore", "Boar", "Door",
  "He", "She", "We", "Three", "Free", "Me", "Tee", "Be", "Knee",
  "Like", "Hike", "Tyke", "Bike", "Spike", 
  "A", "Play", "Stay", "Fray", "Way", "Hay", "May", "Bay", "Day", "Lay",
  "Look", "Book", "Took", "Crook",
  "I", "My", "Cry", "Why", "Try", "Fly", "Fry", "Sky", "Hi", "Shy", "Lie", "Tie",
  "Nice", "Ice", "Twice", "Slice", "Spice", "Dice", "Mice",
  "Dog", "Fog", "Hog", "Log",
  "At", "Fat", "Cat", "Hat", "Mat", "Splat", "Stat",
  "How", "Cow", "Pow", "Bow", "Now", "Wow",
  "Stop", "Cop", "Hop", "Shop", "Plop", "Mop", "Crop", "Pop",
  "Where", "Care", "Hair", "Wear", "Bear", "Dare", "Pair"
};

const vector<string> Words::vwords_(Words::words_,
    Words::words_ + (sizeof(Words::words_)/sizeof(string)));

const vector<string> Words::GetWords() {
  return Words::vwords_;
}

