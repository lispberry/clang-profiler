#include <Sql.h>
#include <sqlite3.h>

namespace
{
const char* kSchema = R"(
        PRAGMA journal_mode = WAL;
        PRAGMA synchronous = NORMAL;
        PRAGMA cache_size = 10000;
        PRAGMA temp_store = MEMORY;
        PRAGMA locking_mode = EXCLUSIVE;

        CREATE TABLE IF NOT EXISTS BuildEvents (
            id INTEGER PRIMARY KEY,
            type INTEGER,
            ts INTEGER,
            dur INTEGER,
            detailIndex INTEGER,
            parent INTEGER
        );
        CREATE TABLE IF NOT EXISTS BuildNames (
            id INTEGER PRIMARY KEY,
            name TEXT
        );
        CREATE INDEX IF NOT EXISTS idx_name ON BuildNames(name);
    )";
}

bool SaveBuildEventsToDatabase(BuildEventsParser* parser, const std::string& fileName)
{
    sqlite3* db;
    char* errMsg = nullptr;
    int rc = sqlite3_open(fileName.c_str(), &db);
    if (rc)
    {
        printf("ERROR: Can't open database: %s\n", sqlite3_errmsg(db));
        return false;
    }

    rc = sqlite3_exec(db, kSchema, nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return false;
    }

    sqlite3_stmt* stmt;
    const char* insertEventSQL = "INSERT INTO BuildEvents (type, ts, dur, detailIndex, parent) VALUES (?, ?, ?, ?, ?)";
    rc = sqlite3_prepare_v2(db, insertEventSQL, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        printf("ERROR: Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }

}
