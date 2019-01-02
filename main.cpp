#include "head.h"
#include "compress.h"
#include "decompress.h"

int main()
{
    setlocale(LC_ALL, NULL);

    string InputFileCoding = "InputFileCoding.bin";
    string InputFileDecoding = "InputFileDecoding.txt";
    string OutputFileDecoding = "OutputFileDecoding.txt";
    string OutputFileCoding = "OutputFileCoding.bin";

    cout << "Enter 0 to compress, enter 1 to decompress" << endl;

    bool flag;

    cim >> flag;

    if(flag)
        decompress(InputFileCoding, OutputFileDecoding);

    else
        compress(InputFileDecoding,  OutputFileCoding);


    return 0;
}
