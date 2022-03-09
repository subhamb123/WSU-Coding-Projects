/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {
private:
    vector<list<pair<K, V>>> data;
    vector<list<pair<K, V>>> tempVect;
    int elements;
    int buckets;

public:
    ChainingHash(int n = 11) {
        for(int i = 0; i < n; i++)
            data.push_back(list<pair<K, V>>());

        elements = 0;
        buckets = n;
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return elements;
    }

    V operator[](const K& key) {
        int val = hash(key);

        for(pair<K, V> p : data[hash(key)]){
            if(p.first == key)
                return p.second;
        }

        return -1;
    }

    bool insert(const std::pair<K, V>& pair) {
        elements++;

        data[hash(pair.first)].push_back(pair);

        if(load_factor() >= 0.75){
            buckets = findNextPrime(buckets*2+1);

            data.resize(buckets);

            for(int i = 0; i < data.size(); i++) {
                typename list<std::pair<K, V>>::iterator it = data[i].begin();

                tempVect.push_back(list<std::pair<K, V>>());
                for(int j = 0; j < data[i].size(); j++){
                    it->first = hash(it->first);

                    tempVect[i].push_back(*it);
                    it++;
                }
            }

            data = tempVect;
            tempVect.clear();
        }

        return true;
    }

    void erase(const K& key) {
        elements -= data.at(key % buckets).size();
        data.at(key % buckets).clear();
    }

    void clear() {
        data.clear();
        elements = 0;
        buckets = 0;
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
        return (key+1) % buckets;
    }
};

#endif //__CHAINING_HASH_H
