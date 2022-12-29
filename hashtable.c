#include "hashtable.h"

hnode *new_hash_node(int value, int key)
{
    hnode *nnode = (hnode *)malloc(sizeof(hnode));
    nnode->key = key;
    nnode->value = value;
    return nnode;
}

hashtable *new_hashtable(int size)
{
    hashtable *nhash = (hashtable *)malloc(sizeof(hashtable));
    nhash->data = (hnode **)malloc(sizeof(hnode) * size);
    nhash->length = 0;
    nhash->size = size;
    for (int index = 0; index < size; index++)
        nhash->data[index] = NULL;
    return nhash;
}

int get_hash(int key, int size)
{
    return ((key * key) * 64) % size;
}

int linear_hashing(int key, int size, int collisions)
{
    return (get_hash(key, size) + collisions) % size;
}

void add_hash_node(hashtable *table, int value, int key)
{
    if (table->data == NULL || table->length == table->size)
        return;
    hnode *nnode = new_hash_node(value, key);
    int collisions = 0;
    while (table->data[linear_hashing(key, table->size, collisions)] != NULL)
        collisions++;
    table->data[linear_hashing(key, table->size, collisions)] = nnode;
    table->length++;
}

void print_hashtable(hashtable *table)
{
    if (table->data == NULL)
        return;
    for (int index = 0; index < table->size; index++)
    {
        printf("Indice %d: ", index);
        if (table->data[index] == NULL)
            printf("Vazio.\n");
        else
            printf("{key=%d,value=%d}\n", table->data[index]->key, table->data[index]->value);
    }
}