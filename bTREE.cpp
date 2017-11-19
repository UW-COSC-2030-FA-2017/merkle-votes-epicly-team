#include "bTREE.h"


//look at descriptions in pMT.h for guidance on what you might need for these function to actually do
bTREE::bTREE()
	:tree(NULL)
{
}

bTREE::~bTREE()
{
	destroyTree(tree);
}

void bTREE::destroyTree(treeNode* &subTree)
{
	if (subTree != NULL)
	{
		destroyTree(subTree->right);
		destroyTree(subTree->left);
		delete subTree;
		subTree = NULL;
	}
}

int bTREE::dataInserted()
{
	return 1;
}

int bTREE::numberOfNodes(const treeNode* subTree)
{
	if (subTree == NULL)
	{
		return 0;
	}
	else
	{
		return (1 + (numberOfNodes(subTree->left)
			+ numberOfNodes(subTree->right)));
	}
}

int bTREE::insert(treeNode* subTree, string data, int timeStamp)
{
	if (subTree == NULL)
	{
		//New node
		subTree->timeStamp = timeStamp;
		subTree->data = data;
	}
	if (data < subTree->data)
	{
		return insert(subTree->left,data,timeStamp);
	}
	else if (subTree->data < data)
	{
		return insert(subTree->right,data,timeStamp);
	}
	return subTree->timeStamp;
}

int bTREE::find(const treeNode* subTree, string key)
{
}

string bTREE::locate(const treeNode* subTree, string key)
{
}

bool bTREE::operator==(const bTREE& lhs, const bTREE& rhs)
{
}

bool bTREE::operator!=(const bTREE& lhs, const bTREE& rhs)
{
}

std::ostream& bTREE::operator<<(std::ostream& out, const bTREE& p)
{
}
