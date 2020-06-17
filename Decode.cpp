#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	unordered_map <int , string> DecodedMap;
	int oldnum , n;
	int counter = 0;
	while (counter <= 255) { 
        string ch = ""; 
        ch += char(counter); 
		DecodedMap.insert(pair<int , string>(counter++, ch)); 
    }
	fstream encodedfile ("EncodedFile.bin" , ios :: binary | ios::in | ios::out);
	ofstream DecodedFile("Decoded_File.txt");
	encodedfile.seekg(0);
	encodedfile.read((char*)&oldnum , 3);
	string word = DecodedMap[oldnum];
	string c = "";
	c += word[0];
	DecodedFile << word;
	while (encodedfile.read((char*)&n , 3)) { 	
	if (DecodedMap.find(n) == DecodedMap.end()){
	 word = DecodedMap[oldnum]; 
     word = word + c; 
	}
	else{
	word = DecodedMap[n];
	}
	DecodedFile << word;
	c = "";
	c += word[0];
	DecodedMap[counter++] = DecodedMap[oldnum] + c; 
    oldnum = n;
	}
	encodedfile.close();
	DecodedFile.close();
	return 0;
}