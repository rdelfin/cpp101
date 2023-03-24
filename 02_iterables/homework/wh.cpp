#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

int main() {
    //Find the lenght of characters in the string
    char n[] = "When the sun shines, we will shine together. Told you I will be here forever. Said I will always be your friend. Took an oath, I'ma stick it out to the end. Now that it is raining more than ever. Know that we will still have each other. You can stand under my umbrella. You can stand under my umbrella, ella, ella, eh, eh, eh. Under my umbrella, ella, ella, eh, eh, eh. Under my umbrella, ella, ella, eh, eh, eh. Under my umbrella, ella, ella, eh, eh, eh, eh, eh-eh";

    string specials = "*()[]{}/,:;\'\".#€£$%^&*=!";
    int len = strlen(n);

    // Remove the special characters from the input string (uses '.find' to find in each character from 'n' which ones are special characters. Replaces special character with a space)
    for (int i = 0; i < len; i++) {
        if (specials.find(n[i]) != string::npos) {
            n[i] = ' ';
        }
    }

    // for each character, make the letter lowercase
    for(int i = 0; i < len;i++){
        n[i] = tolower(n[i]);
    }
    //turn the string into a token and store each word in a vector (each word in a separate line)
    char * word;
    word = strtok(n, " ");
    vector<string>words;

    while (word != NULL) { 
        words.push_back(word);
        word = strtok (NULL, " "); 
    }  
    
    //sort the words alphabetically
    // sort(words.begin(), words.end());

    // Constructing a Map with a string (words) and int
    map< string, int> counts;

    for (string w: words){ 
        int current_count = counts[w];       //read map
        int new_count = current_count + 1;   //compute
        counts[w] = new_count;               //write to map
    }

    //store the map contents in a vector to sort the sorted_counts using a lambda function as a comparator. 
    //comparing the int first, if they are not equal, sort them in descending order and higher int comes first on the list.
    //if the pairs are equal, sort the string alphabetically
    vector <pair<string, int>> sorted_counts(counts.begin(), counts.end());
    sort(sorted_counts.begin(), sorted_counts.end(), [](const pair <string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        else{
        return a.first < b.first;
        }
    });

    //Pair my string and int and write output
    for(const auto& word_mapping : sorted_counts) {
        cout << word_mapping.first << " " << word_mapping.second << endl;
    }

    return 0;
}