#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
bool flag2 = false;
int i = 0;
int count_line = 0;
//Lexical Code//
// CHECK KEYWORDS   //
bool Check_Keywords(string word)
{
    bool flag = false;

    string keywords[20] = {"Shot", "Corner", "Penalty", "Flick", "Freekick", "Goal", "Post", "Pick", "Target", "var", "HandBall", "Save", "Line", "constant", "Kit", "Toe", "Whistle", "Win", "Loose", "Stadium"};

    for (int i = 0; i < 20; i++)
    {
        if (word == keywords[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}
// CHECK DATATYPES   //
bool Check_Data_Types(string word)
{
    bool flag = false;

    string DT[] = {"Flame", "Ice", "Crystal", "Dark", "Light", "Nature"};
    string result = "";
    for (int i = 0; i < 6; i++)
    {
        if (DT[i] == word)
        {
            flag = true;
            break;
        }
    }
    return flag;
}
//  CHECK OPERATORS   //
bool Check_Operators(char word)
{
    bool flag = false;
    char operators[12] = {'+', '-', '*', '/', '%', '=', '!', '>', '<', '&', '|', '^'};
    for (int i = 0; i < 12; i++)
    {
        if (word == operators[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}
// CHECK PUNCTUATERS   //
bool Check_Punctuators(char word)
{
    bool flag = false;
    char punctuators[12] = {'{', '}', '[', ']', '(', ')', ':', ',', '?', '\\', '#', '.'};
    for (int i = 0; i < 12; i++)
    {
        if (word == punctuators[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}
// CHECK COMBINE OPERATERS   //
bool Check_Combine_Operaters(string word)
{
    bool flag = false;

    string comb_op[] = {"<=", ">=", "!=", "==", "++", "--", "&&", "||", "+=", "-=", "/=", "*="};
    for (int i = 0; i < 12; i++)
    {
        if (word == comb_op[i])
        {
            flag = true;
            break;
        }
    }
    return flag;
}

//CHECK IDENTIFIER   //
bool Check_Identifier(string str)
{
    int cs = 0, fs = 1;

    int arr[3][3] = {{1, 1, 2},
                     {1, 1, 1},
                     {2, 2, 2}};

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '_')
            cs = arr[cs][0];

        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            cs = arr[cs][1];

        else if (str[i] >= '0' && str[i] <= '9')
            cs = arr[cs][2];

        else
        {
            cs = 2;
            break;
        }
    }

    if (cs == fs)
        return true;
    else
        return false;
}

bool Check_Int_Const(string str)
{
    int cs = 0, fs = 1;
    int arr[4][3] = {{2, 2, 1},
                     {3, 3, 1},
                     {3, 3, 1},
                     {3, 3, 3}};

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '+')
            cs = arr[cs][0];

        else if (str[i] == '-')
            cs = arr[cs][1];

        else if (str[i] >= '0' && str[i] <= '9')
            cs = arr[cs][2];

        else
        {

            cs = 3;
            break;
        }
    }

    if (cs == fs)
        return true;
    else
        return false;
}
//          CHAR COSNSTANT       //
bool Check_Char_Const(string str)
{
    int cs = 0, fs = 4;
    int arr[6][3] = {{1, 5, 5},
                     {5, 2, 3},
                     {3, 3, 3},
                     {4, 5, 5},
                     {5, 5, 5},
                     {5, 5, 5}};

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '\'')
            cs = arr[cs][0];

        else if (str[i] == '\\')
            cs = arr[cs][1];

        else if (str[i] != '\'' && str[i] != '\\' || str[i] == ' ')
            cs = arr[cs][2];

        else
        {
            cs = 5;
            break;
        }
    }

    if (cs == fs)
        return true;
    else
        return false;
}

//********************************"FLOAT CONSTANT" *********************************
bool Check_Float_Const(string str)
{
    int cs = 0, fs = 3;

    int arr[5][4] = {{1, 1, 1, 2},
                     {4, 4, 1, 2},
                     {4, 4, 3, 4},
                     {4, 4, 3, 4},
                     {4, 4, 4, 4}};

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] == '+')
            cs = arr[cs][0];

        else if (str[i] == '-')
            cs = arr[cs][1];

        else if (str[i] >= '0' && str[i] <= '9')
            cs = arr[cs][2];

        else if (str[i] == '.')
            cs = arr[cs][3];

        else
        {
            cs = 4;
            break;
        }
    }

    if (cs == fs)
        return true;
    else
        return false;
}

bool num(char s)
{
    if (s >= '0' && s <= '9')
        return true;

    return false;
}

//Parser code start
int pi = 0,c=0;

struct tok
{
    string cp;
    string vp;
    string line;
}t[10000];
string cp[1000];

bool Program();
bool Start_Program();
bool Main_Part();
// INTIALIAZATION   ///
bool Init(){
    bool flag=false;
     if(t[pi].cp=="="){
        pi++;
        if(t[pi].cp=="IDENTIFIER"){
            pi++;
            if(Init()){
                flag= true;
            }
        }
        else if(t[pi].cp=="INTEGER CONSTANT" || t[pi].cp=="STRING CONSTANT"||t[pi].cp=="FLOAT CONSTANT"||t[pi].cp=="CHARACTER CONSTANT"){
            flag=true;
        }
    }
    
        else if(t[pi].cp=="INTEGER CONSTANT" || t[pi].cp=="STRING CONSTANT"||t[pi].cp=="FLOAT CONSTANT"||t[pi].cp=="CHARACTER CONSTANT"){
            flag=true;
        }
        
    
    
    return flag;
}

//  LIST   ///
bool List(){
    bool flag=false;
    if(t[pi].cp==","){
        pi++;
        if(t[pi].cp=="IDENTIFIER"){
            pi++;
            if(Init()){
                pi++;
                if(List()){
                    flag=true;
                }
            }
        }
     }
        else if(t[pi].cp=="?"){
            flag=true;
        }
        
return flag;
}
/// ASSIGNMENT   //
bool Assign(){
    bool flag=false;
    if(t[pi].cp=="IDENTIFIER"){
        pi++;
        if(t[pi].cp=="="){
            i++;
            if(t[pi].cp=="IDENTIFIER" || t[pi].cp=="INTEGER CONSTANT" || t[pi].cp=="STRING CONSTANT"||t[pi].cp=="FLOAT CONSTANT"||t[pi].cp=="CHARACTER CONSTANT"){
                flag=true;
            }
        }
    }   
    return flag;
}
/// DECLARATION   //   
bool Dec(){
    bool flag=false;
     if(t[pi].cp=="DATA TYPE"){
        pi++;
        if(t[pi].cp=="IDENTIFIER"){
             pi++;
            if(Init()){
                 pi++;
                if(List()){                          
                    flag= true;
                }
            }   
        }
     }
     
     return flag;
}
///   MAIN     //
bool Main_Part(){
    bool flag=false;
    if(t[pi].cp == "DATA TYPE"){
        pi++;
        if(t[pi].cp=="SECTOR"){
            pi++;
            if(t[pi].cp=="("){
                pi++;
                if(t[pi].cp==")"){
                    pi++;
                    if(t[pi].cp=="{"){
                       pi++;
                if(Program()){
                    pi++;
                                if(t[pi].cp=="INTEGER CONSTANT" || t[pi].cp=="IDENTIFIER" || t[pi].cp=="STRING CONSTANT"||t[pi].cp=="CHARACTER CONSTANT"||t[pi].cp=="FLOAT CONSTANT"){
                                    pi++;
                                    if(t[pi].cp=="?"){
                                        pi++;
                                        if(t[pi].cp=="}"){
                                flag=true;
                            }
                                       }
                                   }
                            
                else if(t[pi].cp=="}"){
                        flag=true;
                    }
                }
            }
                }
            }
            
        }
    }
    return flag;
}
//   PROGRAM     ///
bool Program(){
    bool flag=false;
    if(Dec()){
        pi++;
        if(Program()){
            flag=true;
        }
        else if(t[pi].cp=="}"){
            pi--;
            flag=true;
        }
    }
    
    return flag;
}
//  START PROGRAM     //
bool Start_Program(){
    bool flag=false;
    if( Main_Part()){
        pi++;
        if(Start_Program()){
            flag=true;
        }
        else if(t[pi].cp==""){
            flag=true;
        }
    }
    
    return flag;
}

//Parser code end

int main()
{
	cout<<"---------------------------------Source Code From Program.txt----------------------------------\n\n";
    string temp2 = "";
    string temp = "", str1, str2;
    string line;
    ifstream myfile1;
    ofstream myfile2;
    myfile1.open("program.txt");
    myfile2.open("token.txt");
    if (myfile1.is_open())
    {

        while (!myfile1.eof())
        {
            getline(myfile1, temp);
            line += temp;
            line += '\n';
        }
        cout << line;
        cout << "************************************************************************\n";
        cout << "    Token Notation => ( Class_Part , Value_Part , Line_Number )\n";
        cout << "************************************************************************\n\n";

        temp.clear();
        for (i = 0; i < line.length(); i++)
        {

            //SINGLE LINE COMMENT //

            if (line[i] == '~' && line[i + 1] == '~')
            {

                while (line[i] != '\n')
                {
                    i++;
                }
                if (line[i] == '\n')
                    count_line++;
            }
            //MULTI LINE COMMENT //

            if (line[i] == '/' && line[i + 1] == '~')
            {
                i += 2;
                while (line[i] != '~' && line[i + 1] != '/')
                {
                    i++;
                    if (line[i] == '\n')
                        count_line++;
                }
                i++;
            }
            //CHECK PUNCTUATERS   ///
            temp.clear();
            temp += line[i];
            temp += line[i + 1];
            temp2 = temp;

            if (!Check_Operators(line[i]) && !Check_Punctuators(line[i]) && !Check_Combine_Operaters(temp) && line[i] != ' ' && line[i] != '\n' && line[i] != '?' && line[i] != '\'' && line[i] != '"')
            {
                temp.clear();
                str1 += line[i];
            }

            else
            {

                //CHECK DATA TYPE  //
                if (str1.length() > 0)
                {

                    if (Check_Data_Types(str1))
                    {
                        cout << "(DT," << str1 << "," << count_line << ")\n";
                        myfile2 << "(DT," << str1 << "," << count_line << ")\n";
                        str1.clear();
                    }
                    //CHECK KEYWORDS ///
                    else if (Check_Keywords(str1))
                    {
                        if (str1 == "Sector")
                        {
                            cout << "(Sector," << str1 << "," << count_line << ")\n";
                            myfile2 << "(Sector," << str1 << "," << count_line << ")\n";
                        }
                        else
                        {
                            cout << "(Keyword," << str1 << "," << count_line << ")\n";
                            myfile2 << "(Keyword," << str1 << "," << count_line << ")\n";
                        }
                        str1.clear();
                    }

                    else if (Check_Float_Const(str1))
                    {
                        cout << "(Float_Const," << str1 << "," << count_line << ")\n";
                        myfile2 << "(Float_Const," << str1 << "," << count_line << ")\n";

                        str1.clear();
                    }
                    else if (Check_Identifier(str1))
                    {
                        cout << "(ID," << str1 << "," << count_line << ")\n";
                        myfile2 << "(ID," << str1 << "," << count_line << ")\n";

                        str1.clear();
                    }
                    else if (str1 != "" || str1[1] != ' ')
                    {

                        str1.clear();
                    }
                    else
                    {
                        cout << "(Lexi_Err," << str1 << "," << count_line << ")\n";
                        myfile2 << "(Lexi_Err," << str1 << "," << count_line << ")\n";
                    }
                }

                if (Check_Combine_Operaters(temp))
                {
                    if (temp == "++")
                    {
                        cout << "(Inc," << temp << "," << count_line << ")\n";
                        myfile2 << "(Inc," << temp << "," << count_line << ")\n";
                        temp.clear();
                    }
                    else if (temp == "--")
                    {
                        cout << "(Dec," << temp << "," << count_line << ")\n";
                        myfile2 << "(Dec," << temp << "," << count_line << ")\n";
                        temp.clear();
                    }
                    else if ((temp == ">=") || (temp == "<=") || (temp == "==") || (temp == "!="))
                    {
                        cout << "(Re_Lop," << temp << "," << count_line << ")\n";
                        myfile2 << "(Re_Lop," << temp << "," << count_line << ")\n";
                        temp.clear();
                    }
                    else
                    {
                        cout << "(Comb_Op," << temp << "," << count_line << ")\n";
                        myfile2 << "(Comb_Op," << temp << "," << count_line << ")\n";
                    }
                    temp.clear();
                    i++;
                }
                else if (Check_Operators(line[i]))
                {
                    if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' || line[i] == '%' || line[i] == '^')
                    {
                        cout << "(Arth_Op," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(Arth_Op," << line[i] << "," << count_line << ")\n";
                    }
                    else if (line[i] == '!' || line[i] == '&' || line[i] == '|')
                    {
                        cout << "(Logical_Op," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(Logical_Op," << line[i] << "," << count_line << ")\n";
                    }
                    else if (line[i] == '=')
                    {
                        cout << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                    }
                    else if (line[i] == '>' || line[i] == '<')
                    {
                        cout << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                    }
                    else
                    {
                        cout << "(Lexi_Err," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(Lexi_Err," << line[i] << "," << count_line << ")\n";
                    }
                    //  i++;
                }
                else if (Check_Punctuators(line[i]))
                {
                    if (line[i] == '(' || line[i] == '{' || line[i] == '[')
                    {
                        cout << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                    }
                    else if (line[i] == ')' || line[i] == '}' || line[i] == ']')
                    {
                        cout << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                    }
                    else if (line[i] == '?')
                    {
                        cout << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                    }
                    else if (line[i] == '#')
                    {
                        cout << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                    }
                    else if (line[i] == ':' || line[i] == ',' || line[i] == '\\' || line[i] == '.')
                    {
                        cout << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(" << line[i] << "," << line[i] << "," << count_line << ")\n";
                    }
                    else
                    {
                        cout << "(Lexi_Err," << line[i] << "," << count_line << ")\n";
                        myfile2 << "(Lexi_Err," << line[i] << "," << count_line << ")\n";
                    }
                }
                else if (line[i] == '\n')
                {
                    count_line++;
                }

                //////  check float /////
                if (line[i] == '.' && num(line[i + 1]))
                {
                    if (Check_Int_Const(str1))
                    {
                        cout << "(Int_Cosnt," << str1 << "," << count_line << ")\n";
                        myfile2 << "(Int_Cosnt," << str1 << "," << count_line << ")\n";
                        str1.clear();
                    }
                    for (int j = i; j < line.length(); j++)
                    {
                        str1 += line[i];
                        i++;
                        if (line[i] == ' ' || line[i] == '\n' || Check_Punctuators(line[i]) || Check_Operators(line[i]))
                        { // str1=str1.substr(0,(str1.length()-1));

                            i--;
                            break;
                        }
                        if (line[i] == '\n')
                            count_line++;
                    }
                }

                //     CHECK STRING CONSTANT  //
                if (line[i] == '"')
                {
                    str1.clear();
                    bool flag = false;
                    for (int j = i; j < line.length(); j++)
                    {
                        str1 += line[i];
                        i++;

                        if (line[i] == '"' && line[i - 1] != '\\')
                        {
                            str1 += line[i];
                            flag = true;
                            break;
                        }
                        
                        else if (line[i] == '\n')
                        {
                            count_line++;
                            flag = false;
                            break;
                        }
                    }

                    if (flag == true)
                    {

                        cout << "(String_Const," << str1 << "," << count_line << ")\n";
                        myfile2 << "(String_Const," << str1 << "," << count_line << ")\n";

                        flag = false;
                        str1.clear();
                    }
                    else
                    {
                        cout << "(Lexi_Err," << str1 << "," << count_line << ")\n";
                        myfile2 << "(Lexi_Err," << str1 << "," << count_line << ")\n";
                    }
                    str1.clear();
                }

                //     CHECK CHAR CONSTANT  //

                string c;
                if (line[i] == '\'')
                {
                    int len = i + 2;
                    if (line[i + 1] == '\\')
                        len++;
                    int j = i;
                    while (j < line.length())
                    {
                        c += line[i];
                        if (j == len)
                            break;
                        j++;
                        i++;
                    }
                    if (Check_Char_Const(c))
                    {
                        cout << "(Char_Const," << c << "," << count_line << ")\n";
                        myfile2 << "(Char_Const," << c << "," << count_line << ")\n";
                    }
                    else
                    {
                        cout << "(Lexi_Err," << c << "," << count_line << ")\n";
                        myfile2 << "(Lexi_Err," << c << "," << count_line << ")\n";
                        c.clear();
                    }
                }
            }
        }
        cout << "DONE!\n";
        cout <<"-------------------------------------------Parser-------------------------------------------\n\n";
        
         ifstream myfile1;
    myfile1.open("token.txt");
    string line,temp;
    int n=0;
    while(!myfile1.eof())
    {
        getline(myfile1,line);
    
          for(int i=0;i<line.length();i++)
{
                
 
                if(line[0]=='(')
                { 
                i++;
                 while(line[i]!=','){
                 t[n].cp+=line[i];
                  i++;             
                  }
                 i++;
                 if(line[i]==',')
                 {
                 i++;
                 t[n].vp+=line[i];
                 i++;
                 }
                 else{
                 while(line[i]!=','){
                 t[n].vp+=line[i];
                  i++;             
                  }
                  i++;
                  }
                  while(line[i]!=')'){
                 t[n].line+=line[i];
                  i++;             
                  }
                                                  
                }
                 
}

        n++;
    }
      for(int i=0;i<=n;i++)
     {
        cout<<t[i].cp<<"\t"<<t[i].vp<<"\t"<<t[i].line<<endl;
     }
      if(Start_Program())
     cout<<"Parsed";
     else
     cout<<"Successfully finished with no errors";
        
        
    }
    else
    {
        cout << "Error In File!\n";
    }
    myfile1.close();
    myfile2.close();
}


