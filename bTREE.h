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
		bool isLeaf();
    };
    
private:
    //some data structure to hold your treeNodes together ...
    //DATASTUCTURE treeNodes tree;
    //any helper private variables you need
	treeNode *tree_;
    
public:
    bTREE();
    ~bTREE();
    
    int dataInserted();
    int numberOfNodes();
    
    void insert(string, int);
    
    bool find(string);
    
    string locate(string);
    

    friend bool operator ==(const bTREE& lhs, const bTREE& rhs);
    friend bool operator!=(const bTREE& lhs, const bTREE& rhs);

    friend std::ostream& operator<<(std::ostream& out, const bTREE& p);
    
};

