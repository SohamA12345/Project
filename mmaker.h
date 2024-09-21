#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include "func.h"

using namespace std;

class item
{
    public:
        string name, desc;
        int ret;
        int y;
        item();
        item(string s1, int a, string s2);
        void display();
        void disp_selected();
};

class menu
{
    item head;
    vector<item> entries;
    int num;
    public:
    menu();
    void add(string, int, string);
    void menu_head(string);
    int display();
    void readfromfile(string);
};

void menumaker();