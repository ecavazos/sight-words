#import "word_cache.h"

WordCache::WordCache(int cache_size) {
  cache_size_ = cache_size;
  cached_words_ = new int [cache_size_];
}

WordCache::~WordCache() {
  delete cached_words_;
}

bool WordCache::IsIndexInCache(int new_index) {
  // This is to prevent words from displaying too often.
  for (int i = 0; i < cache_size_; i++) {
    // cout << cache[i] << endl;
    if (new_index == cached_words_[i]) return true;
  }
  return false;
}

void WordCache::UpdateCache(int new_index) {
  // Add the new index to the front of the cached and shift the remaining items
  // over by one. This will drop off the oldest index in the cache.
  for (int i = (cache_size_ - 1); i > 0; i--) {
    cached_words_[i] = cached_words_[i-1];
  }
  cached_words_[0] = new_index;
}

