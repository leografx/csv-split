#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void write2File(std::string fileName, std::string data) {
    std::ofstream outputFile(fileName);
    outputFile << data;
    outputFile.close();
}

int main() {
    int i = 0;
    int count = 1;
    std::string head = "FULLNAME,DELADDR,CITY,ST,ZIPCODE,Sequence_Number,Sack,Intelligent_Mail_barcode,Prop_Name,Prop_Lic,Prop_Add,Prop_City,PROP_STATE,Prop_Zip\n";
    std::string line;
    std::string newFileName = "spliteast/part1.csv";
    std::string data = "";
    std::ifstream myfile("EAST.csv");

    if (myfile.is_open())
    {
        while (!myfile.eof())
        //while (count < 5)
        {
            if (i < 2000)
            {
                if (i == 0)
                    data += head;

                getline(myfile, line);
                std::cout << line << std::endl;
                data += line;
                i++;
            }else{ 
                newFileName = "spliteast/part" + std::to_string(count) + ".csv";
                write2File(newFileName, data);
                count++;
                data = "";
                std::cout << newFileName << std::endl;
                i = 0;
            }
        }
        myfile.close();
    }
    else
        std::cout << "Unable to open file";
    std::cin.get();
}