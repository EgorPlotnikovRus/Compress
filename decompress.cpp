#include "head.h"

bool to_bool(char s) {
     return s != '0';
}

void decompress(string InF, string OuF)
{
    string str, s;
    map<char, vector<bool> > table;
    ifstream File(InF);

    while(getline(File, str)){s += str;}
    File.close();

    s.resize(s.size() - str.size());

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
            c = str[n];
            code.clear();
        }
    }
    table[c] = code;

    code.clear();

    File.open(InF);
    ofstream OFile(OuF);

    char byte;
    byte = File.get();

    bool b;
    for(int i = 0; i < s.size(); ++i)
    {
        byte = s[i];
        for(int count = 0; count < 8; ++count)
        {
        b = byte & (1 << (7 - count));
        code.push_back(b);

        for(map<char, vector<bool>>::iterator it = table.begin(); it != table.end(); ++it)
            if(code == it -> second)
            {
                OFile << it -> first;
                code.clear();
            }
        }
    }

    code.push_back(b);
    for(map<char, vector<bool>>::iterator it = table.begin(); it != table.end(); ++it)
        if(code == it -> second)
        {
            OFile << it -> first;
            code.clear();
        }

    OFile.close();
    File.close();
}
