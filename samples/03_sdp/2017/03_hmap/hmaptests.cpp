#include <iostream>
#include <string>

using namespace std;

#include "hmap.cpp"

size_t stringhash1 (const string& s, size_t htsize)
{

	size_t x = 0;

	for (char c : s)
	{
		x += c;
	}

	return x % htsize;
}

void testHMapCore ()
{

	//m(size,hashfn)
	HashMap<string,double> m(7,stringhash1);

	m["Kalin"] = 1.84;
	m["Kalin"] = 1.85;
	m["Ivan"] = 1.86;

	assert (m["Kalin"] == 1.85);
	assert (m["Ivan"] == 1.86);

	assert (m.containsKey("Kalin") == true);
	assert (m.containsKey("Petar") == false);

}
void testHMapCannonical ()
{
	HashMap<string,double> m(7,stringhash1);

	m["Kalin"] = 1.85;
	m["Ivan"] = 1.86;

	HashMap<string,double> m1(m);
	assert (m1["Kalin"] == 1.85);
	assert (m1["Ivan"] == 1.86);
	assert (m1.containsKey("Kalin") == true);
	assert (m1.containsKey("Petar") == false);

	m["Petar"] = 1.75;
	assert (m1.containsKey("Petar") == false);

	m1  = m;
	assert (m1.containsKey("Petar") == true);

	m["Zdravko"] = 1.79;
	assert (m1.containsKey("Zdravko") == false);
}

void testHMapIterator ()
{

	HashMap<string,double> m(7,stringhash1);

	m["Kalin"] = 1.85;
	m["Ivan"] = 1.86;

	int count = 0;
	for (string key : m)
	{
		assert (key == "Kalin" || key == "Ivan");
		cout << "key:" << count << "=" << key << endl;
		count++;
	}

	assert (count == 2);
}

void testHMapResize ()
{
	HashMap<string,double> m(1,stringhash1);

	m["Kalin"] = 1.85;
	m["Ivan"] = 1.86;

	m.resize (7);

	assert (m["Kalin"] == 1.85);
	assert (m["Ivan"] == 1.86);
	assert (m.containsKey("Kalin") == true);
	assert (m.containsKey("Petar") == false);

}

void testHMMultiply ()
{
	HashMap<string,double> m(5,stringhash1);

	m["Kalin"] = 1.85;
	m["Ivan"] = 1.86;

	HashMap<string,double> m1(3,stringhash1);

	m1["Kalin"] = 2;
	m1["Petar"] = 2;

	HashMap<string,vector<double>> mult = m * m1;

	mult = mult * mult;

	assert (mult.containsKey("Kalin"));
	assert (!mult.containsKey("Ivan"));
	assert (!mult.containsKey("Petar"));

	assert (mult["Kalin"].size() == 4);

	for (string key : mult)
	{
		cout << key << ":";
		for (double val : mult[key])
		{
			cout << val << " "; 
		}
		cout << endl;
	}

}

int main ()
{
	testHMapCore();
	testHMapCannonical();
	testHMapIterator();
	testHMapResize();

	testHMMultiply();

}