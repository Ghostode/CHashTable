#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#ifdef _cplusplus
extern 'C'{
#endif

#include<stdio.h>
#define HashMaxSize 1000
typedef int KeyType;
typedef char ValType;
typedef size_t (*HashFunc)(KeyType key );
typedef struct HashEelem{
    KeyType key;
    ValType val;
    struct HashEelem* next;
}HashEelem;
typedef struct HashTable{
    HashEelem* data[HashMaxSize];
    size_t size; //哈希桶不需要填装因子和状态枚举
    HashFunc func;
}HashTable;

size_t hash_func( KeyType key);
void HashInit(HashTable* ht,HashFunc hash_func);
void HashDestory(HashTable* ht);
void HashInsert(HashTable* ht,HashEelem elem);
ValType HashFind(HashTable* ht, KeyType key);
size_t hash_func( KeyType key);
void HashRemove(HashTable* ht, KeyType key);
void HashPrint(HashTable* ht);


#ifdef _cplusplus
}
#endif
#endif // HASH_H_INCLUDED
