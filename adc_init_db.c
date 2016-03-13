#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char **argv) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s DATABASE\n", argv[0]);
        return (1);
    }

    rc = sqlite3_open(argv[1], &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return(1);
    }

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL Error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);
    return 0;
}
