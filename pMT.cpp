#include"pMT.h"


pMT::pMT(int hashSelect)
/**
 * @brief 
 * @param hashSelect a number corresponding to the hashfunction to use for this pMT
 * @return 
 */
{
	bTREE newTree;
	if (hashSelect >= 1 && hashSelect <= 3) {
		selectedHash = hashSelect;
	}
	else {
		//If invalid input, default to 1
		selectedHash = 1;
	}
}

pMT::~pMT()
/**
 * @brief destructor
 * @return nada
 */
{
}

int pMT::insert(string vote, int time)
/**
 * @brief insert a vote and time into a leaf node of tree
 * @param vote - a string
 * @param time - an int representing the time
 * @return the number of operations needed to do the insert, -1 if out of memory
 */
{
	if (selectedHash == 1)
	{
		myMerkle.insert(myMerkle.tree, hash_1(vote), time);
		return 1;
	}
	else if (selectedHash == 2)
	{
		myMerkle.insert(myMerkle.tree, hash_2(vote), time);
		return 1;
	}
	else if (selectedHash == 3)
	{
		myMerkle.insert(myMerkle.tree, hash_3(vote), time);
		return 1;
	}
	else
	{
		return -1;
	}
}

int pMT::find(string vote, int time, int hashSelect)
/**
 * @brief given a vote, timestamp, and hash function, does this vote exist in the tree?
 * @param vote, a string
 * @param time, an int
 * @param hashSelect, an int corresponding to the hash functions _1, _2, and _3
 * @return 0 if not found, else number of opperations required to find the matching vote
 */
{
	int numOps = 0;
	if (1 == (find(vote, time, selectedHash)))
	{
		numOps++;
		return numOps;
	}
	else
	{
		return numOps;
	}
}

int pMT::findHash(string mhash)
/**
 * @brief does this hash exist in the tree?
 * @param mhash, a string to search for in the tree
 * @return 0 if not found, else number of opperations required to find the matching hash
 */
{
	int numOps = 0;
	if (0 != myMerkle.numNodes(myMerkle.tree))
	{
		numOps++;
		myMerkle.locate(myMerkle.tree, mhash);
		return numOps;
	}
	else
	{
		return numOps;
	}
}


string pMT::locateData(string vote)
/**
 * @brief Function takes a hash of Vote and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param vote, the data to search for 
 * @return sequence of L's and R's comprising the movement to the leaf node; else return a dot '.'
 */
{
	return myMerkle.locate(myMerkle.tree, vote);
}

string pMT::locateHash(string mhash)
/**
 * @brief Function takes a hash and returns the sequence of (L)eft and (R)ight moves to get to that node starting from root. 
 * @param mhash, the hash to search for 
 * @return sequence of L's and R's comprising the movement to the hash node, ; else return a dot '.'
 */
{
	return myMerkle.locate(myMerkle.root, mhash);
}


//RS Hash
string pMT::hash_1(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = hash * a + key[i];
		a = a * b;
	}
	//convert hash to string
	return to_string(hash);
}


//BKDR Hash
string pMT::hash_2(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	unsigned int seed = 131;
	unsigned int hash = 0;

	for (std::size_t i = 0; i < key.length(); i++)
	{
		hash = (hash * seed) + key[i];
	}
	//Convert hash to string
	return to_string(hash);
}

//Weak Hash
string pMT::hash_3(string key)
/**
 * @brief A function that takes in a key and returns a hash of that key using some custom function
 * @param key, a string
 * @return a hash of the key
 */
{
	unsigned int b = 3751;
	unsigned int a = 689;
	unsigned int hash = 0;

	for (std::size_t i = key.length() - 4; i < key.length() - 1; i++)
	{
		hash = hash * a + key[i];
		a = a * b;
	}
	//Convert hash to string
	return to_string(hash);
}


/*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		* Please note that we tried to do some of these friend functions, but	*
		* Visual Studio was giving us a hard time about it, so we left them		*
		* alone.																*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

//bool pMT::operator ==(const pMT& lhs, const pMT& rhs)
///**
// * @brief Comparison between two merkle trees
// * @param lhs, the left hand side of the equality statment
// * @param rhs, the right hand side of the equality statement
// * @return true if equal, false otherwise
// */
//{
//	if (rhs == lhs)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

//bool pMT::operator !=(const pMT& lhs, const pMT& rhs)
///**
// * @brief Comparison between two merkle trees
// * @param lhs, the left hand side of the equality statment
// * @param rhs, the right hand side of the equality statement
// * @return true if not equal, false otherwise
// */
//{
//	if (rhs != lhs)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

//friend pMT pMT::operator ^=(const pMT& lhs, const pMT& rhs)
///**
// * @brief XOR between two merkle trees
// * @param lhs, the left hand side of the equality statment
// * @param rhs, the right hand side of the equality statement
// * @return true if not equal, false otherwise
// */
//{
//    
//}
//
//
//friend std::ostream& pMT::operator <<(std::ostream& out, const pMT& p)
///**
// * @brief Print out a tree
// * @param out
// * @param p
// * @return a tree to the screen
// */
//{
//}


//friend pMT pMT::operator ^(const pMT& lhs, const pMT& rhs)
///**
// * @brief Where do two trees differ
// * @param lhs
// * @param rhs
// * @return a tree comprised of the right hand side tree nodes that are different from the left
// */
//{
//}
