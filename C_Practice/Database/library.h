#ifndef LIBRARY_H
#define LIBRARY_H
struct db {
    char name[100];
    char password[20];
    int timestamp;
};
struct db *a;
void push(struct db *a);
#endif