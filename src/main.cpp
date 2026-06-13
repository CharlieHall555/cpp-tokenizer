#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "lexer.h"
using namespace std;

int main(int argc , char *argv[])
{

    if (argc < 3){
        cerr << "Incorrect usage, Correct usage..." << endl;
        cerr << "./tokenizer <input_filepath> <output_filepath>" << endl;
        return EXIT_FAILURE;
    }

    string in_filepath = argv[1];
    string out_filepath = argv[2];

    ifstream file(in_filepath);

    if (!file) {
        cerr << "Runtime Error: Could not open input file @" << in_filepath << endl;
        return EXIT_FAILURE;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string source = buffer.str();
    file.close();

    ofstream out(out_filepath);

    Lexer lexer(source);
    vector<Token> tokens = lexer.tokenize();
    if (!out) {
        cerr << "Runtime Error: Could not access output file @" << out_filepath << endl;
        return EXIT_FAILURE;
    }

    lexer.writeTokensToAFile(out);
    out.close();

    return EXIT_SUCCESS;
}