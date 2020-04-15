#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

std::string getFileContents(std::ifstream &, std::string str); //Gets file contents

int main(int argc, char *argv[])
{
    std::string ip; // Used to obtain the string from user

    std::cin >> ip; // Read the input

    std::ifstream Reader("star_wars.txt"); //Open file

    std::string Art = getFileContents(Reader, ip); //Get file

    std::cout << Art << std::endl; //Print it to the screen

    Reader.close(); //Close file

    return 0;
}

std::string getFileContents(std::ifstream &File, std::string str)
{
    std::string Lines = ""; //All lines
    std::string temp;
    std::string TempLine; //Temp line

    if (File) //Check if everything is good
    {
        if (!(str == "comma" || str == "period" || str == "exclamation"))
        {
            while (File >> temp)
            {
                if (temp == str)
                {
                    while (1)
                    {
                        std::getline(File, TempLine); //Get temp line
                        if (TempLine[0] != str[0] + 1)
                        {
                            TempLine += "\n";  //Add newline character
                            Lines += TempLine; //Add newline
                        }
                        else
                            break;
                    }
                }
            }
        }
        else if (str == "period")
        {
            while (File >> temp)
            {
                if (temp == str)
                {
                    while (1)
                    {
                        std::getline(File, TempLine); //Get temp line
                        if (TempLine == "comma")
                            break;
                        else
                        {
                            TempLine += "\n";  //Add newline character
                            Lines += TempLine; //Add newline
                        }
                    }
                }
            }
        }
    }

    else //Return error
    {
        return "ERROR File does not exist.";
    }
    return Lines;
}
