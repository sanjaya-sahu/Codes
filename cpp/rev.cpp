#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char * reverse_string(char * str)
{
    int len = strlen(str);
    if (len <= 1)
        return str;
    else {
        char * rev_substr = reverse_string(str+1);
        char * temp = new char[2];
        temp[0] = str[0];
        temp[1] = '\0';
        int new_len = strlen(rev_substr) + strlen(temp) + 1;
        char * new_str = new char[new_len];
        strcpy(new_str,rev_substr);
        strcat(new_str,temp);
        delete [] temp;
        return new_str;
    }
}
int main()
{
   cout << "Hello World" << endl; 
   
   char * mystr = new char [11];
   strcpy(mystr, "HelloWorld");
   char * rev_str = reverse_string(mystr);
   cout << rev_str << endl;
   
   return 0;
}


