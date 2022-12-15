#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string ,string > dictionary; // a map to store words and theirs description
    string  word, // used to store the word
            line, // used to store a line of text
            description, // used to store the word description
            ignored_cell; // used to ignore unused text
    fstream dict_source; // used to open the file
    dict_source.open("words.txt",ios::in); // opening the file
    if(!dict_source) { // if the file couldn't be opened correctly
        cout << "error file not found\n";
        exit(-1);
    }
    while(getline(dict_source,line)){ // read the file line by line

        stringstream str(line);
        getline(str,ignored_cell,',');// unused cell (word_id)
        getline(str,word,',');// the word
        getline(str,ignored_cell,',');// unused cell (up_votes)
        getline(str,ignored_cell,',');// unused cell (down_votes)
        getline(str,ignored_cell,',');// unused cell (author)
        getline(str,description,',');
        //inserting the word, description pair into the map
        dictionary.insert(pair<string,string>(word,description));
    }
    dict_source.close();// closing the file
    // example of test
    cout<<"South Asia: "<<dictionary["South Asia"]<<endl;
    return 0;
}
