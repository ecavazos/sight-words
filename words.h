#ifndef WORDS_H
#define WORDS_H

#include <string>
#include <vector>

using namespace std;

class Words {
  private:
    static const string words_[];
    static const vector<string> vwords_;
  public:
    static const vector<string> GetWords();
};

#endif
