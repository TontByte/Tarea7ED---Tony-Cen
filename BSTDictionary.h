#pragma once
#include <iostream>
#include <stdexcept>
#include "BSTree.h"
#include "Dictionary.h"
#include "Pair.h"
#include "List.h"
#include "ArrayList.h"

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

	//fix
	List<K>* getKeys() {
		List<K>* keys = new ArrayList<K>(getSize());
		List<K>* elements = tree->getElements();
		for (elements.goToStart(); !elements.atEnd(); elements.next()) {
			Pair<K, V> p = elements.getElement();
			keys->append(p.key);
		}
		return keys;
	}

	//fix
	List<V>* getValues() {
		List<K>* values = new ArrayList<K>(getSize());
		List<K>* elements = tree->getElements();
		for (elements.goToStart(); !elements.atEnd(); elements.next()) {
			Pair<K, V> p = elements.getElement();
			values->append(p.value);
		}
		return values;
	}

	int getSize() {
		tree->getSize();
	}

	void print() {
		cout << "luego" << endl;
	}

	void update(Dictionary<K,V> *D) {}

	void zip(List<K>* keys, List<V>* values) {}

};

