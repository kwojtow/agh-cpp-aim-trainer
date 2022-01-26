//
// Created by krzysztof on 16.06.2021.
//

#ifndef PROJECT_DATABSESERVICE_H
#define PROJECT_DATABSESERVICE_H

#include <sqlite3.h>
#include <iostream>
#include <list>

class DatabaseService {
private:
    sqlite3* database;

public:
    void createTable();

    static int callback(void* NotUsed, int argc, char** argv, char** azColName){
        for(int i = 0; i < argc; i++){
            DatabaseService::results.push_back(argv[i]);

        }
        return 0;
    }

    static std::list<std::string> results;

    void insertData(std::string nickname, int score, std::string date, std::string level) ;
    std::list<std::string> getData(std::string order);
};


#endif //PROJECT_DATABSESERVICE_H
