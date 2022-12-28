#ifndef HASH_HEADER
#define HASH_HEADER

typedef struct hnode
{
    int key;
    int value;
};

typedef struct hashtable
{
    int length; // current amount of elements
    int size;   // max amount of elements
    hnode *data;
};

hashtable *new_hashtable(int size);
int get_hash(int key);
void add_hash_node(hashtable *table, int value, int key);
void print_hashtable(hashtable *table);

#endif