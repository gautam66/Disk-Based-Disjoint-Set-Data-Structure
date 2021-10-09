// TestBenches.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<fstream>
#include <iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<random>
#include <algorithm>

using namespace std;

using std::set;
using std::mt19937_64;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

void GetVID()
{
    // Amount to create;
    unsigned long long amount = 10000000;

    // Generate a number from 1 to 1,000,000
    unsigned long long min = 1;
    unsigned long long max = 100000000;

    // If the amount is greater than the max then this will fail
    if (amount > max)
    {
        cerr << "Amount must be less than max." << endl;
        return;
    }

    // Initialize the random_device
    random_device rd;

    // Seed the engine
    mt19937_64 generator(rd());

    // Specify the range of numbers to generate, in this case [min, max]
    uniform_int_distribution<unsigned long long> dist{ min, max };

    //uniform_int_distribution<unsigned short> dist0{ 6, 9 };
    //uniform_int_distribution<unsigned short> dist1{ 3, 8 };
    //uniform_int_distribution<unsigned short> dist2{ 2, 9 };

    // Create a set to hold the random numbers
    set<unsigned long long> results;

    // Generate the random numbers

    while (results.size() != amount)
    {
        unsigned long long v;
        v = dist(generator);
        unsigned short d;
        d = rand()%4 + 6;
        v = v + d * 1000000000000;
        d = rand()%6 +3;
        v = v + d * 100000000000;
        d = rand()%8 +2;
        v = v + d * 10000000000;
        //results.insert(dist(generator));
        results.insert(v);
    }

    /*
    // Display the results
    for (auto& n : results)
    {
        cout << n << " ";
    }
    */
    cout << endl;

}



void GenContacts(unsigned long parUID)
{
    //set<unsigned long> Contacts, CContacts;
    unordered_set<unsigned long> Contacts, CContacts;
    unordered_set<unsigned long> PerDayContacts, PerDayCContacts;
    unsigned short MinCC=10, MaxCC=40, MinC=100, MaxC=200;
    unsigned short MinPerDayCC = 0, MaxPerDayCC = 20, MinPerDayC = 0, MaxPerDayC = 50;
    unsigned short MinCCSamples = 5, MaxCCSamples = 100;
    unsigned short MinCSamples = 1, MaxCSamples = 4;
    unsigned short C, CC, CCSamples, CSamples, PerDayC, PerDayCC;
    C = (rand() % (MaxC - MinC)+1) + MinC;
    CC = (rand() % (MaxCC - MinCC) + 1) + MinCC;
    PerDayC = (rand() % (MaxPerDayC - MinPerDayC) + 1) + MinPerDayC;
    PerDayCC = (rand() % (MaxPerDayCC - MinPerDayCC) + 1) + MinPerDayCC;
    CSamples = (rand() % (MaxCSamples - MinCSamples) + 1) + MinCSamples;
    CCSamples = (rand() % (MaxCCSamples - MinCCSamples) + 1) + MinCCSamples;

    // Generate a number from 1 to 1,000,000
    unsigned long min = 1;
    unsigned long max = 10000000;

    // Initialize the random_device
    random_device rd;

    // Seed the engine
    mt19937_64 generator(rd());

    // Specify the range of numbers to generate, in this case [min, max]
    uniform_int_distribution<unsigned long> dist{ min, max };
    CContacts.insert(parUID);
    while (CContacts.size()!=(CC+1))
    {
        unsigned long v;
        v = dist(generator);
        CContacts.insert(v);
        //Contacts1.insert(v);
    }
    CContacts.erase(parUID);

    Contacts.insert(parUID);
    while (Contacts.size() != (C + 1))
    {
        unsigned long v;
        v = dist(generator);
        if (CContacts.count(v)==0)
            Contacts.insert(v);
        //Contacts1.insert(v);
    }
    Contacts.erase(parUID);
    
    cout << "Contacts=";
    for (auto& n : Contacts)
    {
        cout << n << " ";
    }
    cout <<endl<<endl<< "CContacts=";
    for (auto& n : CContacts)
    {
        cout << n << " ";
    }
    cout << endl;

    vector<unsigned long> VContacts;
    vector<unsigned long> VCContacts;
    std::copy(Contacts.begin(), Contacts.end(), std::back_inserter(VContacts));
    std::copy(CContacts.begin(), CContacts.end(), std::back_inserter(VCContacts));
    cout << "VContacts[0]=" << VContacts[0] << endl;
    cout << "VCContacts[0]=" << VCContacts[0] << endl;

    // Specify the range of numbers to generate, in this case [min, max]
    uniform_int_distribution<unsigned long> dist0{ 0, C};
    cout << "PerDayC=" << PerDayC << endl;
    while (PerDayContacts.size() != PerDayC)
    {
        unsigned long v;
        v = dist0(generator);
        PerDayContacts.insert(v);
    }
    cout << endl << endl << "PerDayContacts=";
    for (auto& n : PerDayContacts)
    {
        cout << n << " ";
    }
    cout << endl;

    // Specify the range of numbers to generate, in this case [min, max]
    uniform_int_distribution<unsigned long> dist1{ 0, CC };
    cout << "PerDayCC=" << PerDayCC << endl;
    while (PerDayCContacts.size() != PerDayCC)
    {
        unsigned long v;
        v = dist1(generator);
        PerDayCContacts.insert(v);
    }
    cout << endl << endl << "PerDayCContacts=";
    for (auto& n : PerDayCContacts)
    {
        cout << n << " ";
    }
    cout << endl;
}

/*
template<class A, class B, class C>
class ForestElement
{
private:
    A Parent; //Every element belongs to a particular tree. Here parent is root of this tree.
    B Size; //When it is root node, then it holds size of the tree. 
    A Link; //All nodes in the tree are inter-connected by this link 
    C EdgeIndex; //Edge index or number by which this node is related with other node. 
public:
    ForestElement() { Parent = 0; Size = 1; Link = 0; EdgeIndex = -1; }
    ForestElement(A parParent, B parSize, A parLink) { Parent = parParent; Size = parSize; Link = parLink; EdgeIndex = -1; }
    bool SetParent(A parParent) { Parent = parParent; return true; }
    A GetParent() { return Parent; }
    bool SetSize(B parSize) { Size = parSize; return true; }
    B GetSize() { return Size; }
    bool SetLink(A parLink) { Link = parLink; return true; }
    A GetLink() { return Link; }
    bool SetEdgeIndex(C parEdgeIndex) { EdgeIndex = parEdgeIndex; return true; }
    C GetEdgeIndex() { return EdgeIndex; }
    friend ostream& operator<<(ostream& Out, const ForestElement& parForestElement)
    {
        Out << endl << "(";
        Out << parForestElement.Parent << ",";
        Out << parForestElement.Size << ",";
        Out << parForestElement.Link << ",";
        Out << parForestElement.EdgeIndex << ")" << endl;
    }
};
*/

class DSDSTreeElement
{
private:
    unsigned long Parent; //Every element belongs to a particular tree. Here parent is root of this tree.
    unsigned long Size; //When it is root node, then it holds size of the tree.
    unsigned long Link; //All nodes in the tree are inter-connected by this link
    long long EdgeIndex; //Edge index or number by which this node is related with other node.
public:
    DSDSTreeElement() { Parent = 0; Size = 1; Link = 0; EdgeIndex = -1; }
    DSDSTreeElement(unsigned long parParent) { Parent = parParent; Size = 1; Link = parParent; EdgeIndex = -1; }
    bool SetParent(unsigned long parParent) { Parent = parParent; return true; }
    unsigned long GetParent() { return Parent; }
    bool SetSize(unsigned long parSize) { Size = parSize; return true; }
    unsigned long GetSize() { return Size; }
    bool SetLink(unsigned long parLink) { Link = parLink; return true; }
    unsigned long GetLink() { return Link; }
    bool SetEdgeIndex(long long parEdgeIndex) { EdgeIndex = parEdgeIndex; return true; }
    long long GetEdgeIndex() { return EdgeIndex; }
    friend ostream& operator<<(ostream& Out, const DSDSTreeElement& parForestElement)
    {
        Out << endl << "(";
        Out << parForestElement.Parent << ",";
        Out << parForestElement.Size << ",";
        Out << parForestElement.Link << ",";
        Out << parForestElement.EdgeIndex << ")" << endl;
    }
};

class DSDSForest
{
private:
    const char ForestFileName[19] = "DSDSForest.bin"; //File Contains all about the forest structure.
    unsigned long NoOfObjects; //size of the forest i.e. size of the data structure.
    const char ForestRootsFileName[19] = "DSDSRoots.bin"; //File Contains all roots of different trees in the forest structure.
    unsigned long NoOfRoots; //No of trees in the forest
    const char ForestRelationsFileName[19] = "DSDSRelations.bin"; //File Contains all about the different relations of the objects.
    unsigned long NoOfRelations;//Number of relations among the objects
    unsigned int q; // Number of adjacent members
public:
    DSDSForest();
    DSDSForest(unsigned long parNoOfObjects);
    bool Unite(unsigned long parObject1Index, unsigned long parObject2Index, long long parEdgeIndex); 
    bool Find(unsigned long parObjectIndex, unsigned long& parRootObjectIndex);
    bool ProcessRelation(unsigned long long parRelationIndex);
    bool GetRootIndex(unsigned long parObjectIndex, unsigned long& parRoot);
    bool GetTreeSize(unsigned long parTreeObjectIndex, unsigned long &parSize);
    bool GetTreeObjects(unsigned long parTreeObjectIndex, set<unsigned long>& parSet);
    bool Create(); //Create DSDS for given relations in the form of data file. 
    bool CreateArtificialDSs();//Create an synthesized relations set for a given number of objects.
};


bool DSDSForest::Unite(unsigned long parObject1Index, unsigned long parObject2Index, long long parEdgeIndex)
{
    if (parObject1Index < 0 || parObject1Index >= NoOfObjects || parObject2Index < 0 || parObject2Index >= NoOfObjects)
    {
        std::cout << "Error: DSDSForest::Unite()-Any of the input object index or both the input object indices are invalid " << endl;
        return false;
    }
    if (parEdgeIndex < 0 || parEdgeIndex >= NoOfRelations)
    {
        std::cout << "Error: DSDSForest::Unite()-Invalid edge index number" << endl;
        return false;
    }
    fstream Fpt1;
    Fpt1.open(ForestRootsFileName, ios::out | ios::in | ios::binary);
    if (!Fpt1.is_open())
    {
        std::cout << "Error: DSDSForest::Unite()-DSDSForest.bin not found and new file is to be created" << endl;
        return false;
    }
    Fpt1.seekp(0, ios::beg);
    fstream Fpt2;
    Fpt2.open(ForestFileName, ios::out | ios::in | ios::binary);
    if (!Fpt2.is_open())
    {
        std::cout << "Error: DSDSForest::Unite()-DSDSForest.bin not found and new file is to be created" << endl;
        return false;
    }
    unsigned long Pos1, Pos2;
    Pos1 = sizeof(DSDSForest) + parObject1Index * sizeof(DSDSTreeElement);
    Pos2 = sizeof(DSDSForest) + parObject2Index * sizeof(DSDSTreeElement);
    DSDSTreeElement E1, E2;
    Fpt2.seekg(Pos1, ios::beg);
    Fpt2.read((char*)&E1, sizeof(E1));
    Fpt2.seekg(Pos2, ios::beg);
    Fpt2.read((char*)&E2, sizeof(E2));
    unsigned long c, d;
    c = E1.GetParent(); //Get index of the root for first element
    d = E2.GetParent(); //Get index of the root for second element
    if ((c == d)) //When roots are equal then they are in same tree, no need for further unite 
    {
        std::cout << "Objects are in same disjoint set" << endl;
        return true;
    }
    //Access roots of the corresponding trees
    Pos1 = sizeof(DSDSForest) + c * sizeof(DSDSTreeElement);
    Pos2 = sizeof(DSDSForest) + d * sizeof(DSDSTreeElement);

    Fpt2.seekg(Pos1, ios::beg);
    Fpt2.read((char*)&E1, sizeof(E1));
    Fpt2.seekg(Pos2, ios::beg);
    Fpt2.read((char*)&E2, sizeof(E2));
    
    //get the size of the corresponding trees
    unsigned long z,t;
    z = E1.GetSize(); //Get the size of the tree with root c
    t = E2.GetSize(); //Get the size of the tree with root d
    if (t > z) //Tree with root d is larger than tree with root c
    {   //so interchange to indicate that tree with root c is larger than tree with root d
        unsigned long s;
        s = c; c = d; d = s;
       //Access the roots of the trees
        Pos1 = sizeof(DSDSForest) + c * sizeof(DSDSTreeElement);
        Pos2 = sizeof(DSDSForest) + d * sizeof(DSDSTreeElement);
        
        Fpt2.seekg(Pos1, ios::beg);
        Fpt2.read((char*)&E1, sizeof(E1));
        Fpt2.seekg(Pos2, ios::beg);
        Fpt2.read((char*)&E2, sizeof(E2));
    }
    //root with index c is larger or equal tree than the tree with root index d.
    // E1 is storing root element for c and E2 is storing root element for d. 
    //Smaller tree will be united with the larger tree for less number of operations.
    E2.SetParent(c);//Parent of all elements in the smaller tree i.e. tree with root d will be now c.
    unsigned long Ptr;
    Ptr = E2.GetLink();//Get next node in the chain of all nodes currently under the tree with root c. It is a circular list, last node pointing to the root i.e. c.
    E2.SetEdgeIndex(parEdgeIndex);
    E2.SetSize(0);
    //update root index for all nodes in the tree with root d
    while (Ptr != c)
    {
        Fpt2.seekp(Pos2, ios::beg);
        Fpt2.write((char*)&E2, sizeof(E2));
        Pos2 = sizeof(DSDSForest) + Ptr * sizeof(DSDSTreeElement);
        Fpt2.seekg(Pos2, ios::beg);
        Fpt2.read((char*)&E2, sizeof(E2));
        E2.SetParent(c);
        Ptr = E2.GetLink();
    }
    //merge two circular link structure of the tree nodes into a single circular link list structure.
    Pos2 = sizeof(DSDSForest) + d * sizeof(DSDSTreeElement);
    Fpt2.seekg(Pos2, ios::beg);
    Fpt2.read((char*)&E2, sizeof(E2));
    Ptr = E2.GetLink();
    E2.SetLink(E1.GetLink());
    E1.SetLink(Ptr);
    //root on the new tree holds the size of the whole tree structure
    E1.SetSize(z + t);
    //store the updated root nodes
    Pos2 = sizeof(DSDSForest) + d * sizeof(DSDSTreeElement);
    Fpt2.seekp(Pos2, ios::beg);
    Fpt2.write((char*)&E2, sizeof(E2));
    Pos1 = sizeof(DSDSForest) + c * sizeof(DSDSTreeElement);
    Fpt2.seekp(Pos1, ios::beg);
    Fpt2.write((char*)&E1, sizeof(E1));
    //Delete the tree root for tree with root d from the file kept for roots of the trees under the forest structure 
    Pos1 = d * sizeof(unsigned long); //Get the root position of the deleted tree 
    Fpt1.seekp(Pos1, ios::beg); //Move file pointer there
    unsigned long Del = -1; //Get the deletion flag
    Fpt1.write((char*)&Del, sizeof(unsigned long));//Store the deletion flag in place of corresponding root.
    Fpt1.close();
    Fpt2.close();
    return true;
}

bool DSDSForest::Find(unsigned long parObjectIndex, unsigned long& parRootObjectIndex)
{
    fstream Fpt;
    Fpt.open(ForestFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error:DSDSForest::Find()-DSDSForest.bin not found and new file is to be created" << endl;
        return false;
    }
    unsigned long Pos;
    Pos = sizeof(DSDSForest) + parObjectIndex * sizeof(DSDSTreeElement);
    Fpt.seekp(Pos, ios::beg);
    DSDSTreeElement R;
    Fpt.read((char*)&R, sizeof(DSDSTreeElement));
    parRootObjectIndex = R.GetParent();
    Fpt.close();
    return true;
}


bool DSDSForest::Create()
{
    fstream Fpt;
    Fpt.open(ForestRelationsFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error: DSDSForest::DSDSForest() - DSDSRelations.bin cannot be opened" << endl;
        return false;
    }
    unsigned long long i=1, Pos;
    while (i <= NoOfRelations)
    {
        Pos = sizeof(NoOfObjects) + sizeof(NoOfRelations) + i * 2 * sizeof(unsigned long long);
        unsigned long u, v;
        Fpt.seekg(Pos, ios::beg);
        Fpt.read((char*)&u, sizeof(u));
        Fpt.read((char*)&v, sizeof(v));
        Unite(u, v, i);
    }
    Fpt.open(ForestRootsFileName, ios::out | ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error: DSDSForest::DSDSForest() - DSDSRelations.bin cannot be opened" << endl;
        return false;
    }
    long u;
    unsigned long r, s;
    r = 0;
    while (r <= NoOfObjects)
    {
        Pos = r * sizeof(unsigned long);
        Fpt.seekg(Pos, ios::beg);
        Fpt.read((char*)&u, sizeof(u));
        if (u != -1)
        {
            Fpt.seekp(0, ios::beg);
            Fpt.write((char *)&r,sizeof(unsigned long));
            s = 0;
            r++;
            break;
        }
    }

    while (r <= NoOfObjects)
    {
        Pos = r * sizeof(unsigned long);
        Fpt.seekg(Pos, ios::beg);
        Fpt.read((char*)&u, sizeof(u));
        if (u != -1)
        {
            s++;
            Pos = s * sizeof(unsigned long);
            Fpt.seekp(Pos, ios::beg);
            Fpt.write((char*)&u, sizeof(unsigned long));
        }
        r++;
    }
    Fpt.close();
    return true;
}

bool DSDSForest::ProcessRelation(unsigned long long parRelationIndex)
{
    fstream Fpt;
    Fpt.open(ForestRelationsFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error: DSDSForest::DSDSForest() - DSDSRelations.bin cannot be opened" << endl;
        return false;
    }
    unsigned long long Pos;
    Pos = sizeof(NoOfObjects) + sizeof(NoOfRelations) +  parRelationIndex * 2 * sizeof(unsigned long long);
    unsigned long u, v;
    Fpt.seekg(Pos, ios::beg);
    Fpt.read((char*)&u, sizeof(u));
    Fpt.read((char*)&v, sizeof(v));
    Unite(u, v, parRelationIndex);
    return true;
}

bool DSDSForest::GetRootIndex(unsigned long parObjectIndex, unsigned long& parRootIndex)
{
    fstream Fpt;
    Fpt.open(ForestFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error: DSDSForest::GetRootIndex()-DSDSForest.bin not found" << endl;
        return false;
    }
    unsigned long Pos;
    Pos = sizeof(DSDSForest) + parObjectIndex * sizeof(DSDSTreeElement);
    DSDSTreeElement E;
    Fpt.seekg(Pos, ios::beg);
    Fpt.read((char*)&E, sizeof(E));
    parRootIndex = E.GetParent();
    return true;
}

bool DSDSForest::GetTreeSize(unsigned long parTreeObjectIndex, unsigned long &parSize)
{
    fstream Fpt;
    Fpt.open(ForestFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error: DSDSForest::GetRootIndex()-DSDSForest.bin not found" << endl;
        return false;
    }
    unsigned long Pos;
    Pos = sizeof(DSDSForest) + parTreeObjectIndex * sizeof(DSDSTreeElement);
    DSDSTreeElement E;
    Fpt.seekg(Pos, ios::beg);
    Fpt.read((char*)&E, sizeof(E));
    unsigned long Root;
    Root = E.GetParent();
    Pos = sizeof(DSDSForest) + Root * sizeof(DSDSTreeElement);
    Fpt.seekg(Pos, ios::beg);
    Fpt.read((char*)&E, sizeof(E));
    parSize = E.GetSize();
    return true;
}

bool DSDSForest::GetTreeObjects(unsigned long parTreeObjectIndex, set<unsigned long>& parSet)
{
    fstream Fpt;
    Fpt.open(ForestFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error: DSDSForest::GetRootIndex()-DSDSForest.bin not found" << endl;
        return false;
    }
    unsigned long Pos;
    Pos = sizeof(DSDSForest) + parTreeObjectIndex * sizeof(DSDSTreeElement);
    DSDSTreeElement E;
    Fpt.seekg(Pos, ios::beg);
    Fpt.read((char*)&E, sizeof(E));
    unsigned long Root;
    Root = E.GetParent();
    Pos = sizeof(DSDSForest) + Root * sizeof(DSDSTreeElement);
    Fpt.seekg(Pos, ios::beg);
    Fpt.read((char*)&E, sizeof(E));
    unsigned long Ptr;
    parSet.insert(Root);
    Ptr = E.GetLink();
    while (Ptr != Root)
    {
        Pos = sizeof(DSDSForest) + Ptr * sizeof(DSDSTreeElement);
        Fpt.seekg(Pos, ios::beg);
        Fpt.read((char*)&E, sizeof(E));
        parSet.insert(Ptr);
        Ptr = E.GetLink();
    }
    return true;
}


DSDSForest::DSDSForest()
{
    fstream Fpt;
    Fpt.open(ForestRelationsFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "Error: DSDSForest::DSDSForest() - DSDSRelations.bin cannot be opened" << endl;
        std::cout << "A synthesis process runs for the generation of artificial relations ";
        std::cout << "and these are stored in the corresponding relations keeping file.";
        CreateArtificialDSs();//Run the synthesis for the DSDS relations
        Fpt.open(ForestRelationsFileName, ios::in | ios::binary);
        if (!Fpt.is_open())
        {
            std::cout << "DSDSRelations.bin cannot be created" << endl;
            exit(0);
        }
    }
    Fpt.seekg(0, ios::beg);
    Fpt.read((char*)&NoOfObjects, sizeof(NoOfObjects));
    Fpt.read((char*)&NoOfRelations, sizeof(NoOfRelations));
    NoOfRoots = NoOfObjects; //Number of trees in the forest
    Fpt.close();

    Fpt.open(ForestRootsFileName, ios::out | ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "DSDSForest.bin not found and new file is to be created" << endl;
        //exit(0);
        Fpt.open(ForestRootsFileName, ios::out | ios::binary);
        if (!Fpt.is_open())
        {
            std::cout << "Error: DSDSForest.bin file cannot be created" << endl;
            exit(0);
        }
        Fpt.close();
        Fpt.open(ForestRootsFileName, ios::out | ios::in | ios::binary);
    }
    Fpt.seekp(0, ios::beg);
    for (unsigned long i = 0; i < NoOfObjects; i++)
    {
        Fpt.write((char*)&i, sizeof(i));
    }
    Fpt.close();
    Fpt.open(ForestFileName, ios::out | ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "DSDSForest.bin not found and new file is to be created" << endl;
        //exit(0);
        Fpt.open(ForestFileName, ios::out | ios::binary);
        if (!Fpt.is_open())
        {
            std::cout << "Error: DSDSForest.bin file cannot be created" << endl;
            exit(0);
        }
        Fpt.close();
        Fpt.open(ForestFileName, ios::out | ios::in | ios::binary);
    }
    Fpt.seekp(0, ios::beg);
    Fpt.write((char*)this, sizeof(DSDSForest));
    for (unsigned long i = 0; i < NoOfObjects; i++)
    {
        DSDSTreeElement E(i);
        Fpt.write((char*)&E, sizeof(E));
    }
    Fpt.close();
    /*
    if (Create())
    {
        cout << "Forests for Disjoint sets successfully created" << endl;
        return;
    }
    else
    {
        cout<< "Unsuccessful to create the Forests for Disjoint sets" << endl;
        return;
    }
    */
}

bool DSDSForest::CreateArtificialDSs()
{
    fstream Fpt;
    Fpt.open(ForestRelationsFileName, ios::out | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "DSDSForest::Constructor error - DSDSRelations.bin cannot be created" << endl;
        exit(0);
    }
}

DSDSForest::DSDSForest(unsigned long parNoOfObjects)
{
    NoOfObjects = parNoOfObjects;
    if (!CreateArtificialDSs())
    {
        std::cout << "DSDSForest::Constructor error - DSDS Synthesis cannot be done" << endl;
        exit(0);
    }

    fstream Fpt;
    Fpt.open(ForestRelationsFileName, ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "DSDSForest::Constructor error - DSDSRelations.bin cannot be opened" << endl;
        exit(0);
    }

    Fpt.seekg(0, ios::beg);
    
    Fpt.read((char*)&NoOfRelations, sizeof(NoOfRelations));
    NoOfRoots = NoOfObjects; //Number of trees in the forest
    Fpt.close();
    Fpt.open(ForestRootsFileName, ios::out | ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "DSDSForest.bin not found and new file is to be created" << endl;
        //exit(0);
        Fpt.open(ForestRootsFileName, ios::out | ios::binary);
        if (!Fpt.is_open())
        {
            std::cout << "Error: DSDSForest.bin file cannot be created" << endl;
            exit(0);
        }
        Fpt.close();
        Fpt.open(ForestRootsFileName, ios::out | ios::in | ios::binary);
    }
    Fpt.seekp(0, ios::beg);
    for (unsigned long i = 0; i < NoOfObjects; i++)
    {
        Fpt.write((char*)&i, sizeof(i));
    }
    Fpt.close();
    Fpt.open(ForestFileName, ios::out | ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "DSDSForest.bin not found and new file is to be created" << endl;
        //exit(0);
        Fpt.open(ForestFileName, ios::out | ios::binary);
        if (!Fpt.is_open())
        {
            std::cout << "Error: DSDSForest.bin file cannot be created" << endl;
            exit(0);
        }
        Fpt.close();
        Fpt.open(ForestFileName, ios::out | ios::in | ios::binary);
    }
    Fpt.seekp(0, ios::beg);
    Fpt.write((char*)this, sizeof(DSDSForest));
    for (unsigned long i = 0; i < NoOfObjects; i++)
    {
        DSDSTreeElement E(i);
        Fpt.write((char*)&E, sizeof(E));
    }
    Fpt.close();
    /*
    if (Create())
    {
        cout << "Forests for Disjoint sets successfully created" << endl;
        return;
    }
    else
    {
        cout<< "Unsuccessful to create the Forests for Disjoint sets" << endl;
        return;
    }
    */
}


class DisjointSetDataStructure
{

};



class Vector1
{
private:
    vector<char> Data1;
public:
    Vector1()
    {
        Data1.resize(10, 0x00);
    }
    Vector1(int m, int n)
    {
        int Size;
        Size = (int) ceil((m * n)/8.0);
        Data1.resize(Size, 0x00);
    }
};

class Theta
{
private:
    vector<int> T;
    int n;
public:
    Theta() 
    {
        n = 10;
        T.resize(n, 0);
    }
    Theta(int m)
    {
        n = m;
        T.resize(n, 0);
    }

};

struct CONTACT_TAG
{
    unsigned long UID;
    unsigned long long CVID;
    CONTACT_TAG *Link;
};

typedef CONTACT_TAG CONTACT;

CONTACT* GetNode()
{
    CONTACT* New;
    New = (CONTACT*)malloc(sizeof(CONTACT));
    New->CVID = 0UL;
    New->UID = 0L;
    New->Link = NULL;
    return New;
}
CONTACT *Insert(CONTACT* Start, unsigned long parUID, unsigned long long parCVID)
{
    CONTACT* New;
    New = GetNode();
    New->CVID = parCVID;
    New->UID = parUID;
    New->Link = Start;
    Start = New;
    return Start;
}

void Display(CONTACT *Start)
{
    CONTACT* Ptr;
    Ptr = Start;
    while (Ptr!=NULL)
    {
        cout << "(" << Ptr->UID << "," << Ptr->CVID << ")";
        Ptr = Ptr->Link;
    }
}


class Contact
{
private:
    unsigned long UID;
    unsigned long long CVID;
public:
    Contact() { UID = 0; CVID = 0; }
    Contact(unsigned long parUID, unsigned long long parCVID) { UID = parUID; CVID = parCVID; }
    void SetUID(unsigned long parUID) { UID = parUID; }
    void SetCVID(unsigned long long parCVID) { CVID = parCVID; }
    unsigned long long GetCVID() { return CVID; }
    unsigned long GetUID() { return UID; }
    friend ostream& operator<<(ostream& out, Contact& parOut) 
    { 
        out << "UID=" << parOut.UID << "CVID=" <<parOut.CVID << endl;
        return out;
    }
};

void TestFileOperation()
{
    fstream Fpt;
    Fpt.open("TestFile.bin", ios::out|ios::in | ios::binary);
    if (!Fpt.is_open())
    {
        std::cout << "TestFile.bin not found and new file is created" << endl;
        //exit(0);
        Fpt.open("TestFile.bin", ios::out | ios::binary);
        if (!Fpt.is_open())
        {
            std::cout << "Error: TestFile.bin file cannot be created" << endl;
            exit(0);
        }
        Fpt.close();
        Fpt.open("TestFile.bin", ios::out | ios::in | ios::binary);
    }
    Fpt.seekp(0, ios::beg);
    Contact C(8, 6);
    Fpt.write((char*)&C, sizeof(C));
    Contact D(9, 6);
    Fpt.write((char*)&D, sizeof(D));
    Contact E(10, 6);
    Fpt.write((char*)&E, sizeof(E));
    cout << "C1 - File Pointer Pos=" << Fpt.tellg() << endl;
    //Fpt.close();

    /*
    ifstream Fpt1;
    Fpt1.open("TestFile.bin", ios::in | ios::binary);
    if (!Fpt1.is_open())
    {
        std::cout << "Error: TestFile.bin cannot be created" << endl;
        exit(0);
    }
    */
    int pos;
    pos = 1 * sizeof(Contact);
    Fpt.seekg(pos, ios::beg);
    cout << "C2-File Pointer Pos=" << Fpt.tellg() << endl;
    Contact T;
    Fpt.read((char*)&T, sizeof(E));
    cout << "T=" << T << endl;
    cout << "C3-File Pointer Pos=" << Fpt.tellg() << endl;
    Fpt.seekp(pos, ios::beg);
    T.SetUID(100);
    Fpt.write((char*)&T, sizeof(Contact));
    Fpt.seekg(pos, ios::beg);
    T.SetUID(0);
    Fpt.read((char*)&T, sizeof(E));
    cout << "T=" << T << endl;
    cout << "C3-File Pointer Pos=" << Fpt.tellg() << endl;
    Fpt.close();
}

class ContactHeader
{
private:
    long N;
    short q;
    char HFName[11] = "CHFile.bin";
    bool Flag;
public:
    ContactHeader()
    {
        strcpy_s(HFName, "CHFile.bin");
        N = 10000;
        q = 19;
        Flag = false;
        fstream Fpt;
        Fpt.open(HFName, ios::out | ios::in | ios::binary);
        if (!Fpt.is_open())
        {
            std::cout << "CHFile.bin not found and new file is created" << endl;
            //exit(0);
            Fpt.open(HFName, ios::out | ios::binary);
            if (!Fpt.is_open())
            {
                std::cout << "Error: CHFile.bin file cannot be created" << endl;
                exit(0);
            }
            Fpt.close();
            Fpt.open(HFName, ios::out | ios::in | ios::binary);
        }
        Fpt.seekp(0, ios::beg);
        Fpt.write((char*)this, sizeof(ContactHeader));
        cout << "After writing header current file position is:" << Fpt.tellp() << endl;
        cout << "Size of Header object is:" << sizeof(ContactHeader) << " or " << Size() << endl;

        int Pos;
        Pos = sizeof(ContactHeader);
        Fpt.seekp(Pos, ios::beg);
        Contact C(8, 6);
        Fpt.write((char*)&C, sizeof(C));
        Contact D(9, 6);
        Fpt.write((char*)&D, sizeof(D));
        Contact E(10, 6);
        Fpt.write((char*)&E, sizeof(E));
        cout << "Stored objects are:" << C << "," << D << "," << E << endl;
        cout << "File Pointer position after storing three contact obects=" << Fpt.tellp() << endl;

        Pos = sizeof(ContactHeader) + 1 * sizeof(Contact);
        Fpt.seekg(Pos, ios::beg);
        cout << endl;
        Contact T;
        Fpt.read((char*)&T, sizeof(E));
        cout << "Reading the second object:" << T << endl;
        Fpt.seekp(Pos, ios::beg);
        T.SetUID(100);
        cout << "Updated second object:" << T << endl;
        Fpt.write((char*)&T, sizeof(Contact));
        Fpt.seekg(Pos, ios::beg);
        T.SetUID(0);
        Fpt.read((char*)&T, sizeof(E));
        cout << "Reading the updated second object:" << T << endl;
        Fpt.close();
    }
    ContactHeader(long parN, short parq, bool parFlag)
    {
        strcpy_s(HFName, "CHFile.bin");
        N = parN;
        q = parq;
        Flag = parFlag;
    }
    int Size()
    {
        return sizeof(ContactHeader);
        //return strlen(HFName) + sizeof(long) + sizeof(short) + sizeof(bool);
    }
};


class Omega
{
private:
    long long y;
    char t;
public:
    Omega() { y = 0; t = 0; }
    Omega(long long parY, char parT)
    {
        y = parY; t = parT;
    }
    bool SetY(long long parY) { y = parY; }
};

class Node
{
private:
    unsigned long UID;
    unsigned int Count;
public:
    Node() { UID = 0; Count = 0; }
    Node(unsigned long parUID, unsigned int parCount)
    {
        UID = parUID;
        Count = parCount;
    }
    bool UpdateCount()
    {
        Count++;
    }
    unsigned long GetUID() { return UID; }
    unsigned int GetCount() { return Count; }
    bool SetUID(unsigned long parUID) { UID = parUID; }
};
#define Max 20

class Wind
{
private:
    unsigned int Len;
    vector<Node> Q[Max];
    int Front;
    int Rear;
public:
    Wind(unsigned int parLen)
    {
        Len = parLen;
        Front = Rear = -1;
    }
    Wind()
    {
        Len = Max;
        Front = Rear = -1;
    }
    bool IsEmpty() 
    { if (Rear == Front && Rear == -1)return true; 
    else return false; 
    }
    bool IsFull() 
    { //if (Rear > Front && (Rear - Front + 1) == Len)return true; 
    if ((Rear + 1) % Len == Front) return true; 
    return false;
    }
    bool Sliding(vector<Node> parInputVec, vector<Node> &parOutputVector)
    {
        parOutputVector.clear();
        if (Rear == -1)
        {
            Rear = Front = 0;
            Q[Rear] = parInputVec;
            return false;
        }
        //Empty/Gap - Queue should be re-initialized
       
        if (parInputVec.empty())
        {
            Rear = Front = -1;
            return false;
        }
        /*
        if (parInputVec.empty())
        {
            if (Front == Rear)
            {
                Q[Front].clear();
                Rear = Front = -1;
                return false;
            }
            Front = (Front + 1) % Len;
            return false;
        }
        */
        //update all appearances
        int p = Rear;
        do
        {
            //for every contacts in the current sample time do appearance counter update
            vector<Node>::iterator q;
            for (q = parInputVec.begin(); q < parInputVec.end(); q++)
            {

                vector<Node>::iterator r;
                for (r = Q[p].begin(); r < Q[p].end(); r++)
                    if (q->GetUID() == r->GetUID())
                        r->UpdateCount();
            }
            if (p == Front)break;
            p = (p + 1) % Len;
        } while (true);

        Rear = (Rear + 1) % Len;
        //Queue is full, so front list will be removed to place input list
        if (Rear == Front)
        {
            parOutputVector = Q[Front];
            Front = (Front + 1) % Len;
            Q[Rear] = parInputVec;
            return true;
        }
        else
        {   //Queue is not full so nothing to remove.
            Q[Rear] = parInputVec;
            return false;
        }
    }
};


int main()
{
    //GetVID();
    GenContacts(1);

    /*
    //ContactHeader CH;
    cout << "Size=" << CH.Size() << endl;
    cout << "sizeof(long)=" << sizeof(long) << "sizeof(short)=" << sizeof(short) << "sizeof(bool)=" << sizeof(bool) << endl;
    char HFName[11] = "CHFile.bin";
    cout << "sizeof(HFName)=" << sizeof(HFName) << endl;
    cout << "sizeof(Omega)=" << sizeof(Omega) << endl;
    
    TestFileOperation();

    vector<Contact> Cv;
    Contact C(7, 9);
    Cv.push_back(C);
    Cv.push_back(C);
    vector<Contact>::iterator P;
    for (P = Cv.begin(); P != Cv.end(); P++)
        cout << *P << endl;
    std::cout << "Hello World!\n";
    CONTACT* L = NULL;
    L = Insert(L, 9, 10);
    L = Insert(L, 9, 10);
    L = Insert(L, 9, 10);
    Display(L);
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
