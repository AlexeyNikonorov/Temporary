#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;

wstring_convert<codecvt_utf8_utf16<wchar_t>> g_codec;

wstring s2ws(const string& i_str)
{
  return g_codec.from_bytes(i_str);
}

string ws2s(const wstring& i_str)
{
  return g_codec.to_bytes(i_str);
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    return -1;
  }

  cout.imbue(locale(cout.getloc(), new codecvt_utf8_utf16<wchar_t>));
  cin.imbue(locale(cin.getloc(), new codecvt_utf8_utf16<wchar_t>));
  wcout.imbue(locale(wcout.getloc(), new codecvt_utf8_utf16<wchar_t>));
  wcin.imbue(locale(wcin.getloc(), new codecvt_utf8_utf16<wchar_t>));

  string mode = argv[1];

  if (mode == "cc")
  {
    string s;
    getline(cin, s);
    cout << ws2s(s2ws(s));
  }
  else if (mode == "cw")
  {
    string s;
    getline(cin, s);
    wcout << s2ws(s);
  }
  else if (mode == "wc")
  {
    wstring s;
    getline(wcin, s);
    cout << ws2s(s);
  }
  else if (mode == "ww")
  {
    wstring s;
    getline(wcin, s);
    wcout << s2ws(ws2s(s));
  }
}
