#pragma once
#include <string>
using namespace std;

class bTREE
{
    struct treeNode{
        string data;
        int time;
		treeNode *left;
		treeNode *right;
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
	struct treeNode tree{

	};
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
    void insert(string, int);
    
    bool find(string);
    
    string locate(string);
    
	treeNode *root;

	//Function to test if a node is a leaf
	bool isLeaf(treeNode* node);

    friend bool operator ==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

