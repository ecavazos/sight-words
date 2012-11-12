#ifndef WORD_CACHE_H
#define WORD_CACHE_H

class WordCache {
  private:
    int cache_size_;
    int* cached_words_;
  public:
    WordCache(int);
    ~WordCache();
    bool IsIndexInCache(int);
    void UpdateCache(int);
};

#endif
