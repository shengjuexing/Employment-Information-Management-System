#pragma once
#include<mysql.h>
#include<windows.h>
#include<iostream>
using namespace std;


class manage {
public:
    manage();
    ~manage();
    void init();
    bool connect();
    void close();

protected:
    MYSQL mysql;
    const char* host = "127.0.0.1";
    const char* user = "root";
    const char* pass = "ldm610600";
    const char* db = "eims";
};