#include<iostream>
#include<string>  
#include <cmath>

using namespace std;
string com(string b)
{
    int count=0;
    for(int i=8;i>=0;i--)
    {
        if(count>0)
        {
            if(b[i]=='1')
            {
                b[i]='0';
            }
            else
            {
                b[i]='1';
            }
        }
        if(b[i]=='1')
        {
            count++;
        }
    }
    return b;
}
string add(string a, string b)
{
    string c = "00000000";
    char cary = '0';
    cout<<"\a";
    for(int i=8;i>=0;i--)
    {
        if(cary=='0'&&a[i]=='0'&&b[i]=='0')
        {
            cary='0';
            c[i]='0';
        }
        else if(cary=='0'&&a[i]=='0'&&b[i]=='1')
        {
            cary='0';
            c[i]='1';
        }
         else if(cary=='0'&&a[i]=='1'&&b[i]=='0')
        {
            cary='0';
            c[i]='1';
        }
        else if(cary=='0'&&a[i]=='1'&&b[i]=='1')
        {
            cary='1';
            c[i]='0';
        }
        else if(cary=='1'&&a[i]=='1'&&b[i]=='1')
        {
            cary='1';
            c[i]='1';
        }
        else if(cary=='1'&&a[i]=='0'&&b[i]=='0')
        {
            cary='0';
            c[i]='1';
        }
        else if(cary=='1'&&a[i]=='0'&&b[i]=='1')
        {
            cary='1';
            c[i]='0';
        }
        else if(cary=='1'&&a[i]=='1'&&b[i]=='0')
        {
            cary='1';
            c[i]='0';
        }
        else if(cary=='1'&&a[i]=='1'&&b[i]=='1')
        {
            cary='1';
            c[i]='1';
        }
    }
    return c;
}
string convertDecimalToBinary(int n)
{
    string binaryNumbers="00000000";
    int count = 0;
    for(int i=0; n>0; i++)    
    {
        binaryNumbers[count]=(char)((n%2) + 48);
        n= n/2;
        count++;
        
    }
    string binaryNumbers1="00000000";
    int n1 = 65;
    int count1 = 0;
    for(int i=0; n1>0; i++)    
    {
        binaryNumbers1[count1]=(char)((n1%2) + 48);
        n1= n1/2;
        count1++;
    }
    string ans = com(binaryNumbers1);
    ans = add(binaryNumbers,ans);
    // int count1 = 0;
    // for(int i = 0; i < 4; i++) {
    //     binaryNumbers1[3-count1] = binaryNumbers[i];
    //     count1++;
    // }
    
    return ans;
}

int main() {
    string Ps[16] = {"\0", "A", "B", "C", "D", "AB", "AC", "AD", "BC", "BD", "CD", "ABC", "ABD", "ACD","BCD", "ABCD"};
    string dt[16] = {"0000", "0001", "0010", "0100", "1000", "0011", "0101", "0110", "1001", "1010", "1100", "0111","1011", "1101", "1110","1111"};
    string ds[16] = {};
    for (int i = 0; i < 16; i++) {
        if(Ps[i][0] == '\0') {
            ds[0] = Ps[i];
            continue;
        }
        for(int j = 0; j < Ps[i].length(); j++) {
            int num = Ps[i][j];
            string numBin = convertDecimalToBinary(num);
            cout << num << " " << numBin << endl;
            
            
        }        
    }
    cout << ds[0];
}