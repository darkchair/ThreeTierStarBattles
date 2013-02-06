#ifndef DIALOG_H_INCLUDED
#define DIALOG_H_INCLUDED

#include <vector>
#include <string>
#include <stdio.h>

class Dialog {

    public:
        Dialog();

        int currentLine;

        void openDialog(std::string file);

    public:
        std::vector<std::string> dialog;

};

#endif // DIALOG_H_INCLUDED
