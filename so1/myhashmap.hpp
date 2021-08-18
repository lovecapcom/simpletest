#pragma once

template<class Key, class Value>
class HashNode
{
public:
    Key    _key;
    Value  _value;
    HashNode *next;

    HashNode(Key key, Value value)
    {
        _key = key;
        _value = value;
        next = NULL;
    }
    ~HashNode()
    {

    }
    HashNode& operator=(const HashNode& node)
    {
        _key = node.key;
        _value = node.key;
        next = node.next;
        return *this;
    }
};

class HashFunc
{
public:
    int operator()(const std::string& key )
    {
        int hash = 0;
        for(int i = 0; i < key.length(); ++i)
        {
            hash = hash << 7 ^ key[i];
        }
        return (hash & 0x7FFFFFFF);
    }
};


class EqualKey
{
public:
    bool operator()(const std::string& A, const std::string& B)
    {
        if (A.compare(B) == 0)
            return true;
        else
            return false;
    }
};

template <class Key, class Value, class HashFunc, class EqualKey>
class MyHashMap
{
public:
    MyHashMap(int size);
    ~MyHashMap();
    bool insert(const Key& key, const Value& value);
    bool del(const Key& key);
    Value& find(const Key& key);
    Value& operator [](const Key& key);

private:
    HashFunc hash;
    EqualKey equal;
    HashNode<Key, Value> **table;
    unsigned int _size;
    Value ValueNULL;
};


template <class Key, class Value, class HashFunc, class EqualKey>
MyHashMap<Key, Value, HashFunc, EqualKey>::MyHashMap(int size) : _size(size)
{
    hash = HashFunc();
    equal = EqualKey();
    table = new HashNode<Key, Value>*[_size];
    for (unsigned i = 0; i < _size; i++)
        table[i] = NULL;
}



template <class Key, class Value, class HashFunc, class EqualKey>
MyHashMap<Key, Value, HashFunc, EqualKey>::~MyHashMap()
{
    for (unsigned i = 0; i < _size; i++)
    {
        HashNode<Key, Value> *currentNode = table[i];
        while (currentNode)
        {
            HashNode<Key, Value> *temp = currentNode;
            currentNode = currentNode->next;
            delete temp;
        }
    }
    delete table;
}


template <class Key, class Value, class HashFunc, class EqualKey>
bool MyHashMap<Key, Value, HashFunc, EqualKey>::insert(const Key& key, const Value& value)
{
    int index = hash(key)%_size;
    HashNode<Key, Value> * node = new HashNode<Key, Value>(key,value);
    node->next = table[index];
    table[index] = node;
    return true;
}


template <class Key, class Value, class HashFunc, class EqualKey>
bool MyHashMap<Key, Value, HashFunc, EqualKey>::del(const Key& key)
{
    unsigned index = hash(key) % _size;
    HashNode<Key, Value> * node = table[index];
    HashNode<Key, Value> * prev = NULL;
    while (node)
    {
        if (node->_key == key)
        {
            if (prev == NULL)
            {
                table[index] = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            delete node;
            return true;
        }
        prev = node;
        node = node->next;
    }
    return false;
}

template <class Key, class Value, class HashFunc, class EqualKey>
Value& MyHashMap<Key, Value, HashFunc, EqualKey>::find(const Key& key)
{
    unsigned  index = hash(key) % _size;
    if (table[index] == NULL)
        return ValueNULL;
    else
    {
        HashNode<Key, Value> * node = table[index];
        while (node)
        {
            if (node->_key == key)
                return node->_value;
            node = node->next;
        }
    }
}


template <class Key, class Value, class HashFunc, class EqualKey>
Value& MyHashMap<Key, Value, HashFunc, EqualKey>::operator [](const Key& key)
{
    return find(key);
}


