// Simple program to test native C-style regular expressions
//
// Compile with something like:
//
//      make regex_test

#include <iostream>
#include <string>
#include <fstream>

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxregex.h>
#include <scxcorelib/stringaid.h>

#include <scxcorelib/scxdefaultlogpolicyfactory.h> // Using the default log policy.

using namespace std;
using namespace SCXCoreLib;

void usage(const char* program)
{
    cerr << "usage: " << program << " {-p pattern | -f pattern-file} [filename ...]" << endl;
    exit(1);
}

wstring ReadPatternFromFile(const wstring& filename)
{
    vector<wstring> lines;
    SCXStream::NLFs nlfs;

    SCXFile::ReadAllLines(SCXFilePath(filename), lines, nlfs);

    for (size_t i = 0; i < lines.size(); i++)
    {
        // Trim leading and trailing whitespace

        wstring line = StrTrim(lines[i]);

        if (line.length())
        {
            return line;
        }
    }

    wcerr << L"no pattern found in [" << filename << L"]: exiting" << endl;
    exit(2);

    return L"";                         // Never reached; pacify compiler
}

void ReadLinesFromFile(SCXHandle<SCXRegex>& re, wistream& ifs)
{
    vector<wstring> lines;
    SCXStream::NLFs nlfs;

    SCXStream::ReadAllLines(ifs, lines, nlfs);

    for (size_t i = 0; i < lines.size(); i++)
    {
        wstring line = lines[i];

        if (re->IsMatch(line))
        {
            wcout << L"***";
        }
        wcout << L"\t" << line << endl;
    }
}

int main(int argc, char *argv[])
{
    int exitStatus = 0;
    bool p_flag = false;
    bool f_flag = false;
    wstring pattern;
    wstring patternFilename;
    int c;

    while((c = getopt(argc, argv, "p:f:")) != -1) {
        switch(c) {
            case 'p':
                p_flag = true;
                pattern = StrFromMultibyte(optarg);
                break;
            case 'f':
                f_flag = true;
                patternFilename = StrFromMultibyte(optarg);
                break;
            default:
                usage(argv[0]);
                /*NOTREACHED*/
                break;
        }
    }

    if (!p_flag && !f_flag) {
        usage(argv[0]);
        /*NOTREACHED*/
    }

    if (f_flag) {
        pattern = ReadPatternFromFile(patternFilename);
    }

    SCXHandle<SCXRegex> re;
    try
    {
        re = new SCXRegex(pattern);
    }
    catch (SCXException& e)
    {
        wcerr << L"Fatal error: " << e.What() << endl;
        exit(3);
    }

    if (optind == argc) {
        // read from stdin
        ReadLinesFromFile(re, wcin);
    } else {
        // read each of the files named
        for(int index = optind; index < argc; index++) {
            wifstream ifs(argv[index], ifstream::in);
            if (!ifs.fail())
            {
                ReadLinesFromFile(re, ifs);
            }
            else
            {
                wcerr << L"Filename \"" << StrFromMultibyte(argv[index]) << L"\" empty or does not exist" << endl;
                exitStatus = 4;  // One or more of the filenames couldn't be opened
            }
        }
    }

    exit(exitStatus);
}
