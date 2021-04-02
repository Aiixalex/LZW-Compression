#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    vector<string> input_str_list;
    
    ifstream in_file;
    in_file.open("Q1.in", ios::in);
    if (in_file.is_open()) {
        string temp;
        while (getline(in_file, temp)) {
            for (size_t i=0; i<temp.size(); i++) {
                if (temp[i] != 'A' && temp[i] != 'B' && temp[i] != 'C') {
                    temp.erase(i, 1);
                }
            }
            if (!temp.empty() && temp[temp.size()-1] == '\0') {
                temp = temp.substr(0, temp.size() - 1);
            }
            input_str_list.push_back(temp);
        }
        in_file.close();
    }

    ofstream out_file;
    out_file.open("Q1.out", ios::out);

    for (vector<string>::iterator it = input_str_list.begin(); it < input_str_list.end(); it++) {
        string input_str = *it;
        string output_str = "";
        map<string, string> dictionary = {
            {"A", "0"},
            {"B", "1"},
            {"C", "2"}
        };

        string s = input_str.substr(0, 1);
        string c;
        int next_code_int = 3;
        string next_code = to_string(next_code_int);
        
        size_t i=1;
        while (i != input_str.size()) {
            c = input_str.substr(i, 1);
            string sc = s + c;
            
            if (dictionary.find(sc) != dictionary.end()) {
                s = sc;
            }
            else {
                output_str = output_str + dictionary.find(s)->second;
                dictionary.insert(pair<string, string>(sc, next_code));
                next_code_int += 1;
                next_code = to_string(next_code_int);
                s = c;
            }
            i++;
        }
        output_str = output_str + dictionary.find(s)->second;

        map<int, string> sorted_dict;
        for (auto element: dictionary) {
            sorted_dict.insert(pair<int, string>(stoi(element.second), element.first));
        }
        
        if (out_file.is_open()) {
            // write input sequence on file
            out_file << "Input sequence: " << input_str << "\n";

            // write output sequence on file
            out_file << "Output sequence: " << output_str << "\n";

            // write dictionary on file
            out_file << "Dictionary:\n";
            for (auto element : sorted_dict) {
                out_file << element.first << " " << element.second << "\n";
            }
            
            if (it != input_str_list.end() - 1) {
                out_file << "\n";
            }
        }
    }

    out_file.close();
}