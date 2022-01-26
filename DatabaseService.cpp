//
// Created by krzysztof on 16.06.2021.
//

#include "DatabaseService.h"

std::list<std::string> DatabaseService::results = {};

void DatabaseService::createTable(){
    int exit = 0;
    char *messageError;

    std::string sql = "CREATE TABLE IF NOT EXISTS SCORES("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "NAME TEXT NOT NULL, "
                      "SCORE INT NOT NULL, "
                      "DATE DATE NOT NULL, "
                      "LEVEL TEXT NOT NULL)";
    exit = sqlite3_exec(database, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Creating Table: " << messageError << std::endl;
        sqlite3_free(messageError);
    }
}

void DatabaseService::insertData(std::string nickname, int score, std::string date, std::string level) {
    int exit = 0;
    char *messageError;

    sqlite3_open("data.sq", &database);

    createTable();

    if(nickname == ""){
        nickname = "anon";
    }

    std::string sql =  "INSERT INTO SCORES(NAME, SCORE, DATE, LEVEL) VALUES('" + nickname + "', " + std::to_string(score) + ", '" + date + "', '" + level + "')";
    exit = sqlite3_exec(database, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert Data: " << messageError << std::endl;
        sqlite3_free(messageError);
    }
    sqlite3_close(database);
}

std::list<std::string> DatabaseService::getData(std::string order){
    int exit = 0;

    DatabaseService::results.clear();

    sqlite3_open("data.sq", &database);

    createTable();

    std::string sql = "SELECT NAME, SCORE, DATE, LEVEL FROM SCORES ORDER BY " + order;
    exit = sqlite3_exec(database, sql.c_str(), callback, NULL, NULL);

    if (exit != SQLITE_OK) {
        std::cerr << "Error Get Data: " << std::endl;
    }
    sqlite3_close(database);

    return DatabaseService::results;
}