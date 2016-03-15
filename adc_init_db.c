#include <stdio.h>
#include <sqlite3.h>
#include "adc.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char **argv) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *stmt = "CREATE TABLE IF NOT EXISTS residents(id text, lastname text, firstname text, schedule text);";

    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: %s DATABASE\n", argv[0]);
        return (1);
    }
    */

    //rc = sqlite3_open(argv[1], &db);
    rc = sqlite3_open(database_name, &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    }
    
    rc = sqlite3_exec(db, stmt, callback, 0, & zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
    return 0;
}
