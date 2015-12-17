#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void reverse(string &s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}


void ReverseWords1(string &s)
{
	 int start, end;
        int metchar = 0;
        int j = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                s[j] = s[i];
                j++;
                
                if (!metchar)
                {
                    start = j-1;
                    metchar = 1;
                }
                
                //if there is no trailing space in the last word
                if (i == s.length() - 1)
                {
                    reverse(s, start, i);
                }
            }
            else
            {
                if (j >= 1 && s[j-1] != ' ')
                {
                    reverse(s, start, j-1);
                    
                    s[j] = ' ';
                    j++;
                    
                    metchar = 0;
                }
                
            }
        }
        
        if (j >= 1 && s[j-1] != ' ')
            s.resize(j);
        else
        {
        	if (j >= 1)
        	{
            	s.resize(j-1);
            }
            else
            	s.resize(0);
        }
            
        //reverse the whole string
        reverse(s, 0, s.length()-1);
}

void RemoveSpace(string &s)
{
	 int j = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' || ((j >= 1) && s[j-1] != ' '))
            {
                s[j] = s[i];
                j++;
            }
        }
        

        if (s[j-1] != ' ')
        	s.resize(j);
        else
        	s.resize(j-1);
        
}

void ReverseWords(string &s)
{
	//reverse the whole string
    reverse(s, 0, s.length()-1);
    int end = -2;
    int start = 0;
           
    //reverse the individual words
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            start = end + 2;
            end = i-1;
                   
            reverse(s, start, end);
        }
    }
    
    //reverse the last word       
    reverse(s, end+2, s.length()-1);
}


int main()
{
	string s = "      ";
	ReverseWords1(s);

	cout << s;

	cout << max(10,4) << endl;


	return 0;
}