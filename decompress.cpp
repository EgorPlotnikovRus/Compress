#include "head.h"

bool to_bool(char s) {
     return s != '0';
}

void decompress(string InF, string OuF)
{
    string str;
    string s;
    string buff;
    map<char, vector<bool> > table;
    ifstream File(InF);
    ofstream testText("/home/egor/Документы/Time/DecompressTestText");//**************************TEST*******************************
    ofstream testTable("/home/egor/Документы/Time/DecompressTestTable");//**************************TEST*******************************

    while(getline(File, str)){}
    File.close();

    char c = str[0];
    vector<bool> code;

    for(int n = 1; n < str.length(); ++n)
    {
        if(str[n] == '1' || str[n] == '0')
        {
            bool b = to_bool(str[n]);
            code.push_back(b);
        }

        else
        {
            table[c] = code;
            testTable << c << " - " << code << endl;//**************************TEST*******************************
            c = str[n];
            code.clear();
        }
    }
    table[c] = code;

    testTable << c << " - " << code << endl;//**************************TEST*******************************

    code.clear();

    File.open(InF);
    ofstream OFile(OuF);

    char byte;
    int count = 0;
    byte = File.get();

    while(!File.eof() || byte != '\n')
    {
        bool b = byte & (1 << (7 - count));
        testText << b; //**************************TEST*******************************
        code.push_back(b);

        for(map<char, vector<bool>>::iterator it = table.begin(); it != table.end(); ++it)
            if(code == it -> second)
            {
                OFile << it -> first;
                code.clear();
            }

        ++count;

        if(count == 8)
        {
            count = 0;
            byte = File.get();
        }
    }
    cout << endl;

    OFile.close();
    File.close();

    cout << "Decopmressing complete" << endl;
}
