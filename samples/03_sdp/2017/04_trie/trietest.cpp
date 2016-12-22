#include <iostream>
#include <cassert>

#include "trie.cpp"

using namespace std;


void testTrie()

{
	Trie<int> m;

	cout << "here" << endl;


	m.set ("to",7);

	cout << "here" << endl;

	m.set ("tea",3);
	m.set ("inn",9);
	m.set ("A",15);
	m.set ("tower",100);


	assert (m.contains("to"));
	assert (m.contains("tower"));
	assert (!m.contains("tow"));

	assert (m.get("inn") == 9);

	Trie<int> m2 = m;

	assert (m2.contains("to"));
	assert (m2.contains("tower"));
	assert (!m2.contains("tow"));

	assert (m2.get("inn") == 9);

	m2.set ("ted",4);
	assert (!m.contains("ted"));

	//TODO: assignment

}

void testTrieIterator()
{

}

int main ()
{
	testTrie();

	return 0;
}