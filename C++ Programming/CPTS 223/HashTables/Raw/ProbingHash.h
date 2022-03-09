#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    vector<pair<K, V>> data;
    vector<EntryState> states;
    int elements;
    int buckets;
    int probe;

public:
    ProbingHash(int n = 11) {
        for(int i = 0; i < n; i++) {
            data.push_back(pair<K, V>());
            states.push_back(EMPTY);
        }

        elements = 0;
        buckets = n;
        probe = 0;
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return elements;
    }

    V operator[](const K& key) {
        return data.at(hash(key)).second;
    }

    bool insert(const std::pair<K, V>& pair) {
        elements++;
        if(load_factor() >= 0.75){
            int temp = buckets;
            buckets = findNextPrime(buckets);

            for(; temp < buckets; temp++){
                data.push_back(::pair<K, V>());
            }
        }

        while(states.at(hash(pair.first)) == VALID)
            probe++;

        data.at(hash(pair.first)).second = pair.second;
        states.at(hash(pair.first)) = VALID;

        return true;
    }

    void erase(const K& key) {
        states.at(key) = DELETED;
    }

    void clear() {
        data.clear();
        states.clear();
        elements = 0;
        buckets = 0;
        probe = 0;
    }

    int bucket_count() {
        return buckets;
    }

    float load_factor() {
        return elements/bucket_count();
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return key % bucket_count() + probe;
    }
    
};

#endif //__PROBING_HASH_H
