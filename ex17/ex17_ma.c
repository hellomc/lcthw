/* Create a program that manages a database.
 *
 * Topics: Struct, Heap, Malloc, Stack
 * Author: Michelle Adea
 */

// Preprocessor directives
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Global vars define
#define MAX_DATA 512
#define MAX_ROWS 100

// Address contains info of id, set, name, and email.
struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

// Database contains many Address structs
struct Database {
    struct Address rows[MAX_ROWS];
};

// Connection contains info for file and database
struct Connection {
    FILE *file;           // pointer to a file datatype
    struct Database *db;  // pointer to a Database struct
};

// Outputs Error Message: 1) perror or 2) msg err
void die(const char *message)
{
    if (errno) {
        perror(message);  // error msg
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);             // error?
};

// Outputs Address information
void Address_print(struct Address *addr)
{
   printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// Gets database information
void Database_load(struct Connection *conn)
{
    // read file
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    // checks for err with fread
    if (rc != 1)
        die("Failed to load database.");
}

// ?
struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn)
        die("Memory Error");

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db)
        die("Memory Error");

    if (mode == 'c') {
        conn->file = fopen(filename, "w");    // open file to write to
    } else {
        conn->file = fopen(filename, "r+");    // open file to read/write/append?

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file)
        die("Failed to open the file");

    return conn;
}

// ?
void Database_close(struct Connection *conn)
{
    if (conn) {
        if (conn->file)
            fclose(conn->file);    // close file
        if (conn->db)
            free(conn->db);        // frees mem alloc to ptr db
        free(conn);                // frees struct conn
    }
}

// ?
void Database_write(struct Connection *conn)
{
    rewind(conn->file);    // func?

    // write to file
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        die("Failed to write database");

    rc = fflush(conn->file);    // flushes the buffer
    if (rc == -1)
        die("Unable to flush database");
}

// ?
void Database_create(struct Connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // prototype db to initialize with
        struct Address addr = {.id = i, .set = 0};
        // assign prototype to db
        conn->db->rows[i] = addr;
    }
}

// ?
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];   // gets the Address from rows[id] in db
    if (addr->set)
        die("Addr already set, delete it first.");

    addr->set = 1;   // set is a flag indicating if addr is given
    // BUG HERE
    char *res = strncpy(addr->name, name, MAX_DATA);
    // DEMO strncpy bug
    if (!res)
        die("Name copy failed.");

    res = strncpy(addr->email, email, MAX_DATA);
    if (!res)
        die("Email copy failed.");
}

// ?
void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];  // gets the Address from rows[id] in db

    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

// ?
void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

// ?
void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur->set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        die("USAGE: ex17 <dbfile> <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if (argc > 3)
        id = atoi(argv[3]);
    if (id >= MAX_ROWS)
        die("That many records do not exist.");

    switch (action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if (argc != 4)
                die("Need id to get.");

            Database_get(conn, id);
            break;

        case 's':
            if (argc != 6)
                die("Need id, name, and email to set");

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if (argc != 4)
                 die("Need id to delete.");
            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;

        default:
            die("INVALID ACTION: c=create, g=get, s=set, d=delete, l=list");
    }

    Database_close(conn);

    return 0;
}
