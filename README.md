#autoSerie "WARNING: unstable, Experimental"
**This is not working for now**

#PRIMARY GOALS (ordered)
- memory allocation independant (can deserialize/serialize anywere even on stack)
- stream independant (does not even particulary need buffuring)
- speed
- low memory (comes after speed)
- compatibility within the same endianness, types (use stdint)
 
#GOALS
- nothing is virtual but feel free to use it
- binary only
- type aware compression
- fully customizable
- handle multiple as a whole when permitted
- no type resolving when deserializing but feel free to use some
- no specific allocation for reading (you can read data to the same location without problems)
  althought object of dynamic size with their own allocator can have their contents resized
  (calling reserve on vector)
  can break const because sometimes memory is just copy onto your object data

- custom stream serialization (you define a stream with a standart write and read method)
- there is no packing of bytes in structures (direct transfer) by default
  this is for faster transfer in the case that the time for packing,
- serialization of standart types, collection
- you can implement custom serialization with static dispatch by inheriting interface
- you can implement custom serialization with in a contiguous way (you can specify how to write and read contiguous object data)
- compatible with standart c++ stream (but a bit overkill, you might just use boost)

#Why ?

serialization of Contiguous collection of objects with virtual method is at serious cost (you must write them one by one), it makes it not usable for real time data management.
This template lib can be used outside a standart c++ stream, you actually define your stream, you could write in a device mapped in memory or in PCI bus, you just have to implement a read and a write method
Sometimes buffering is to avoid and then c++ stream are simply too overkill

it will soon support linked structures with ref and pointers (for the link beetween the serialized structures to be preserved)


it can provide powerfull abstraction with the cost of couples memcpy

#What to not do with it

there already exists many serialization lib
if you attend to serialize many objects with virtual methods (even destructor) this lib will is useless (but it support it)
because objects will be written one by one


#Future features
- address translation within the same allocator (will be handled by sharing and updating memory chunks, contiguous chunk will be detected) 
- compression on numeric types
- cache for data/requests
