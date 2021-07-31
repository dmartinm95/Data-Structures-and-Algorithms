#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_set>
#include <vector>

// Any Hash Table implementation has the folowing three components:
// A good Hash Function to map keys to values
// A Hash Table Data Structure that supports insert, search, and delete operations
// A Data Structure to account for collision of keys

// Simple has function that simply sums the ADCII value of the string
#define CAPACITY 50000 // Size of the Hash Table
unsigned long hash_function(const char *str) {
    unsigned long i = 0;
    for (int j = 0; str[j]; j++)
        i += str[j];
    return i % CAPACITY;
}

// Define our item structure
typedef struct Ht_item Ht_item;
struct Ht_item {
    char *key;
    char *value;
};

// Now define our Hash Table
typedef struct HashTable HashTable;
struct HashTable {
    // Contains an array of pointers to items
    Ht_item **items;
    int size;
    int count;
};

// Allocate memory for the item, both its key and value and return a pointer to the item
Ht_item *create_item(const char *key, const char *value) {
    Ht_item *item = (Ht_item *)malloc(sizeof(Ht_item));
    item->key = (char *)malloc(strlen(key) + 1);
    item->value = (char *)malloc(strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

// Create the table, allocates memory for the wrapper structure and sets all its items to NULL
HashTable *create_table(int size) {
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item **)calloc(table->size, sizeof(Ht_item *));
    for (int i = 0; i < table->size; i++) {
        table->items[i] = NULL;
    }
    return table;
}

// Free up memory that we've allocated using malloc() and calloc()
void free_item(Ht_item *item) {
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        Ht_item *item = table->items[i];
        if (item != NULL) {
            free_item(item);
        }
    }
    free(table->items);
    free(table);
}

// Insert into the Hash Table steps:
// Create the item based on the {key:value} pair
// Compute the index based on the hash function
// Check if the index is already occupied or not, by comparing key
//      If it is NOT occupied, we can directly insert it into index
//      Otherwise, it is a collision, and we need to handle it
void ht_insert(HashTable *table, const char *key, const char *value) {
    // Create the item
    Ht_item *item = create_item(key, value);

    // Compute the index
    int index = hash_function(key);

    Ht_item *current_item = table->items[index];
    if (current_item == NULL) {
        // Key does not exist
        if (table->count == table->size) {
            // Hash Table Full
            printf("Insert Error: Hash Table is full\n");
            free_item(item);
            return;
        }

        // Insert directly
        table->items[index] = item;
        table->count++;
    } else {
        // Scenario 1: We only need to update value
        if (strcmp(current_item->key, key) == 0) {
            strcpy(table->items[index]->value, value);
            return;
        }
        // Scenario 2: Collision
        else {
            printf("Collision detected\n");
            return;
        }
    }
}

// Search Items in the Hash Table
// It checks if the key exists or not, and returns the corresponding value if it does
char *ht_search(HashTable *table, const char *key) {
    // Searches the key in the hash table
    // and returns NULL if it doesn't exist
    int index = hash_function(key);
    Ht_item *item = table->items[index];

    if (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
    }
    return NULL;
}

// Delete from Hash Table
// Compute the hash index and get the item
// If it is NULL, we don't need to do anything
// Otherwise, after comparing keys, if there is no collision chain for that index, simply remove the item from the table
// If a collision chain exists, we must remove that element and shift the links accordingly
void ht_delete(HashTable *table, const char *key) {
    int index = hash_function(key);
    Ht_item *item = table->items[index];

    if (item == NULL) {
        return;
    } else {
        if (strcmp(item->key, key) == 0) {
            // No collision chain, remove the item
            table->items[index] = NULL;
            free_item(item);
            table->count--;
            return;
        } else {
            // There might be a collision, need to handle that
        }
    }
}

void print_search(HashTable *table, const char *key) {
    char *val;
    if ((val = ht_search(table, key)) == NULL) {
        printf("Key:%s does not exist\n", key);
        return;
    } else {
        printf("Key:%s, Value:%s\n", key, val);
    }
}

// Print Hash Table for illustration
void print_table(HashTable *table) {
    printf("\nHash Table\n------------------\n");
    for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
            printf("Index:%d, Key:%s, Value:%s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("------------------\n\n");
}

int get_first_recurring_number(const std::vector<int> &nums) {
    std::unordered_set<int> seen_numbers;
    for (int i = 0; i < nums.size(); i++) {
        if (seen_numbers.find(nums[i]) != seen_numbers.end()) {
            return nums[i];
        } else {
            seen_numbers.insert(nums[i]);
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    return -1;
}

int main() {
    // Testing our basic model
    HashTable *ht = create_table(CAPACITY);
    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");
    ht_insert(ht, "Hel", "Third address");
    print_search(ht, "1");
    print_search(ht, "2");
    print_search(ht, "3");
    print_search(ht, "Hel");
    print_table(ht);
    ht_delete(ht, "1");
    print_table(ht);
    free_table(ht);

    std::vector<int> nums{2, 3, 4, 5, 6};
    printf("Number is %d", get_first_recurring_number(nums));

    return 0;
}