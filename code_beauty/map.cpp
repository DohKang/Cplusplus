#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
//map is dictionary


//function size
//key will be ordered ascending order.
int mapmain() 
{
	map<string, string> myDictionary;
	/*unordered_map<string, string> myDictionary;*/
	myDictionary.insert(pair<string, string>("apple", "der apfel"));
	myDictionary.insert(pair<string, string>("banana", "die banane"));
	myDictionary.insert(pair<string, string>("strawberry", "die erdbeere"));
	myDictionary.insert(pair<string, string>("orange", "die orange, die apfelsine"));
	//key has to be unique
	myDictionary["strawberry"] = "Die Erdbeere";
	cout << myDictionary.size() << endl;
	/*myDictionary.clear();*/
	for (auto pair : myDictionary) 
		cout << pair.first << " - " << pair.second << endl;

	
	system("pause>0");
	return 0;
}