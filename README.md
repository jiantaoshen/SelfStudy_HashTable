# Hash table
A Hashtable is a collection that stores key-value pairs. It uses a hash code to organize the keys for efficient data retrieval. 
The key can be any object, and each key is associated with a corresponding value.

## Set up
This project uses the compiler from Visual Studio. Please install Visual Studio, then use the Visual Studio Installer to install ".NET Desktop Development" and "Desktop Development with C++". Download uthash.h from https://github.com/troydhanson/uthash/tree/master/src for C.

## C#: Program.cs (Visual Studio)
Try to solve the two sum question in LeetCode.

## C: hashTable.c and hashTableWithUthash.c (Visual Studio Code)
Try to solve the two sum question in LeetCode using both manually and use uthash.h. 

## C++: hashtable.cpp (Visual Studio Code)
Try to solve the two sum question in LeetCode.

## Conclusion
A hash table is a data structure that stores key-value pairs using a hash function for fast access. A dictionary in C# is a type-safe, high-level implementation of a hash table that provides an easy way to store and retrieve data. In C++, std::unordered_map offers similar functionality. In C, hash tables must be implemented manually or by using external libraries such as uthash, which is commonly used in modern C development.

### When to Use Dictionary
A Dictionary is used when we need fast lookup, insertion, and deletion of data using unique keys. It is ideal for mapping relationships, caching, and counting occurrences due to its O(1) average time complexity.

#### Fast lookups
When you need to quickly get a value using a key (O(1) time)
#### Unique key-value mapping
When each key is unique (e.g., ID → User)
#### Known data types (type safety)
When keys and values have fixed types
#### Counting / frequency tracking
Example: counting words, occurrences, votes
#### Caching results
Store previously computed values to improve performance
#### Mapping relationships
Example: Country → Capital, Product → Price
#### Replacing long if/else or switch statements
Cleaner and more scalable logic
#### Frequent insert and read operations
When data is updated and accessed often

### When NOT to Use Dictionary
When order matters → use SortedDictionary or List
When duplicate keys are needed → use Lookup or List
When dataset is very small → Dictionary may be unnecessary


