#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <stdio.h>

using namespace std;

string strToChar(string str)
{
    int index=0;
    string text;
    
    for(int j=0;j<str.size()/8;j++)
    {
        int res = 0;
        for (int i=7; i>=0; i--)
        {
            if (str[index] != '0') {
                res+=int(pow(2,i));
            }
                
            index++;
        }
        text[j] = res;
        cout << text[j];
    }
    return text;
}
int main()
{
    string binary="01101000";
    string word=strToChar(binary);
    cout<<word << endl;

    return 0;
}