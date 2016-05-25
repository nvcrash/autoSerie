#autoSerie "WARNING: unstable, Experimental"
**This is not working for now**

#What to do with it

- custom stream serialization (you define a stream with a standart write and read method)
- there is no allocation for fixed type, you can use your own allocators, handle memory as you like
- serialization of standart types, collection
- you can implement custom serialization with static dispatch
- you can implement custom serialization with in a contiguous way (you can specify how to write and read contiguous object data)

#Why ?

serialization of Contiguous collection of objects with virtual method is at serious cost (you must write them one by one), it makes it not usable for real time data management
it could be used outside a standart c++ stream, you actually define it, you could write in a device mapped in memory.
Sometimes buffering is to avoid and then c++ stream are simply too overkill

it can provide powerfull abstraction with the cost of couples memcpy

#What to not do with it

there already exists many serialization lib
if you attend to serialize many objects with virtual methods (even destructor) this lib will is useless
