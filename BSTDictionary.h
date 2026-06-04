#pragma once
#include <iostream>
#include <stdexcept>
#include "BSTree.h"
#include "Dictionary.h"
#include "Pair.h"
#include "List.h"
#include "ArrayList.h"
#include "BSTNode.h"

using std::cout;
using std::runtime_error;
using std::endl;

template <typename K, typename V>
class BSTDictionary : public Dictionary<K, V>{
private:
	BSTree<Pair<K, V>>* tree;

public:
	BSTDictionary() {
		tree = new BSTree<Pair<K, V>>();
	}

	~BSTDictionary() {
		delete tree;
	}

	void insert(K key, V value) {
		if (tree->contains(key)) {
			throw runtime_error("Duplicated key");
		}
		Pair<K, V> p(key, value);
		tree->insert(p);
	}

	V remove(K key) {
		if (!tree->contains(key)) {
			throw runtime_error("Key not found");
		}
		Pair<K, V> p = tree->remove(key);
		return p.value;
	}

	V getValue(K key) {
		if (!tree->contains(key)) {
			throw runtime_error("Key not found");
		}
		Pair<K, V> p = tree->find(key);
		return p.value;
	}

	void setValue(K key, V value) {
		if (!tree->contains(key)) {
			throw runtime_error("Key not found");
		}
		Pair<K, V> p(key, value);
		tree->setElement(p);
	}

	bool contains(K key) {
		return tree->contains(key);
	}

	void clear() {
		tree->clear();
	}

	bool isEmpty() {
		return tree->isEmpty();
	}

	//acordarse de usar delete
	List<K>* getKeys() {
		List<K>* keys = new DLinkedList<K>();
		List<Pair<K, V>>* elements = tree->getElements();
		for (elements->goToStart(); !elements->atEnd(); elements->next()) {
			keys->append(elements->getElement().key);
		}
		delete elements;
		return keys;
	}

	List<V>* getValues() {
		List<V>* values = new DLinkedList<V>();
		List<Pair<K, V>>* elements = tree->getElements();
		for (elements->goToStart(); !elements->atEnd(); elements->next()) {
			values->append(elements->getElement().value);
		}
		delete elements;
		return values;
	}

	int getSize() {
		return tree->getSize();
	}

	void print() {
		tree->print();
	}

	void update(Dictionary<K,V> *D) {
		List<K>* keys = D->getKeys();
		for (keys->goToStart(); !keys->atEnd(); keys->next()) {
			K currentKey = keys->getElement();
			V currentValue = D->getValue(currentKey);
			if (contains(currentKey)) {
				setValue(currentKey, currentValue);
			}
			else {
				insert(currentKey, currentValue);
			}
		}
		delete keys;
	}

	void zip(List<K>* keys, List<V>* values) {
		keys->goToStart();
		values->goToStart();
		while (!keys->atEnd() && !values->atEnd()) {
			K currentKey = keys->getElement();
			V currentValue = values->getElement();
			if (contains(currentKey)) {
				setValue(currentKey, currentValue);
			}
			else {
				insert(currentKey, currentValue);
			}
			keys->next();
			values->next();
		}
	}

};

