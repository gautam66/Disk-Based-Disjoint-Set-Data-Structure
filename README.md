# Disk-Based-Disjoint-Set-Data-Structure
This is an implementation of object-orient Disjoint Set Data Structure (DSDS) based on disk based storage for large problem environment using Microsoft C++ programming language.
Here each disjoint set is a tree. Root of the tree is the identity of the disjoint set. Each element of any disjoint set points to its parent. The root element point to itself. 
A set may have one or more disjoint sets. So, for the whole set we have a set of tree and these trees are forming a forest structure. Each set element is an object we define 
corresponding class - DSDSTreeElement. All memebers of the set are stored in an one-dimensional array stored inside a disk file named as "DSDSForest.bin". It is a binary file.
All trees are belonging to a Forest structure and we define 'DSDSForest' class to hold these tree. The header part of the "DSDSForest.bin" file stores information regarding this
forest structure and then set element objects are stored. Which element is root of the tree is store in a separate binary file which name is "DSDSRoots.bin". There is another 
binary file "DSDSRelations.bin" which is storing all relations among these set elements for which all different disjoint sets are forming. If this relation file is available then
at the time of any forest object creation automatically the underlying tree structures for disjoints sets are forming. Number of objects and number of relations are available from
the "DSDSRelations.bin" data file. So, initially all these objects are in different disjoint sets and hence these are all in single element rooted trees. Now, each relation from 
this relation file is fetched and if there are two different trees for current relation then these two are united into a single tree and according the root information in the 
roots keeping file is updated. Once all relations are processed and we get the final tree structures for the different disjoint sets. In our implementation all elements of a
disjoint set are maintained in singly circular linked list. Also, every element is directly storing the identity of the tree root element, so no search or processing is require 
to know dijoint set membership. Root element is storing the size of the disjoint set. The linked list chain for the disjoint set is also storing the edges / relations which are 
being used to form this disjoint set. Each set element object is a fixed size record in the disk file so array link random accessing is possible. Only difference with primary 
memory based implementation is that access time for electronic primary memory is very less than access time of secondary storage. However, here we can store very big size 
disjont set data structure,which are needed for different applications like image processing etc.
