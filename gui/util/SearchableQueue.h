#pragma once
#include <map>
#include <unordered_map>
#include "gui/lang/Drawable.h"

template <typename T>
class SearchableQueue {
private:
    int headIndex = -1;
    int tailIndex = 1;
    std::map<int, T> forward;
    std::unordered_map<T, int> inverse;
public:
    SearchableQueue();
    void push_front(T obj);
    void push_back(T obj);
    bool contains(T obj);
    void remove(T ojb);
    void clear();
    std::map<int, T> const& getMap();
    ~SearchableQueue();
};

template <typename T>
inline SearchableQueue<T>::SearchableQueue() {}

template<typename T>
inline void SearchableQueue<T>::push_front(T obj) {
    forward[headIndex] = obj;
    inverse[obj] = headIndex;
    headIndex--;
}

template<typename T>
inline void SearchableQueue<T>::push_back(T obj) {
    forward[tailIndex] = obj;
    inverse[obj] = tailIndex;
    tailIndex++;
}

template<typename T>
inline bool SearchableQueue<T>::contains(T obj) {
    return inverse[obj];
}

template<typename T>
inline void SearchableQueue<T>::remove(T obj) {
    if (contains(obj)) {
        forward.erase(inverse[obj]);
        inverse.erase(obj);
    }
}

template<typename T>
inline void SearchableQueue<T>::clear() {
    forward.clear();
    inverse.clear();
}

template<typename T>
inline std::map<int, T> const& SearchableQueue<T>::getMap() {
    return forward;
}

template <typename T>
inline SearchableQueue<T>::~SearchableQueue() {}