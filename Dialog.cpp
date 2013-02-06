#include "Dialog.h"

Dialog::Dialog() {
    currentLine = 0;
    for(int i=0; i<10; i++) {
        dialog.push_back("");
    }
}

void Dialog::openDialog(std::string file) {

    FILE* pathFile = fopen(file.c_str(), "r");
    char temp [50];
    int i=0;

    while(!feof(pathFile)) {
        fscanf(pathFile, "%s", temp);
        std::string str = std::string (temp);
        dialog.at(i).append(str);
        dialog.at(i).append(" ");
        if(str.at(str.size()-1) == '|') //If "end line" character is reached
            i++;
    }

    int j=0;
    while(dialog.at(j) != "") {
        dialog.at(j).erase(dialog.at(j).size()-2); //Why is this -2 and not -1? Have to erase the \n
        j++;
    }

    delete[] temp;
}
