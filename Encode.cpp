#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

int main (){
	unordered_map <string, int> EncodedMap;
	int counter = 0;
	char previous , current;
	string prev = "" , curr = "";
	fstream encodedfile ("EncodedFile.bin" , ios :: binary | ios::in |ios::out | ios::trunc); 
	 while(counter <= 255) { 
        string ch = ""; 
        ch += char(counter); 
		EncodedMap.insert(pair<string, int>(ch, counter++)); 
    } 
    fstream filecontent;
	// read InputFile character by character and perform LZW algorithm
	filecontent.open("InputFile");
	filecontent.get(previous);
	prev += previous;
	while (filecontent.get(current)){
		curr += current;
		if (EncodedMap.find(prev+curr) != EncodedMap.end()){
			prev = prev + curr;
		}
		else{
        encodedfile.write( (char*)&EncodedMap[prev] , 3);
		EncodedMap.insert(pair<string, int>(prev + curr, counter++));
		prev = curr;
		}
	curr = "";
	}
	encodedfile.write( (char*)&EncodedMap[prev] , 3);
	filecontent.close();
	encodedfile.close();
	return 0;
}