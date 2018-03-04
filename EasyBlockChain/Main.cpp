// ====================================================
// EasyBlockChain Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#include "BlockChain.h"

#pragma warning(disable:4996)

int main(int argc, char* argv[]) {
	CBlockChain bChain = CBlockChain();

	cout << "Genesis..." << endl;
	bChain.AddGenesis();

	cout << "Mining block 1..." << endl;
	bChain.AddBlock(CBlock(1, "Block 1 Data"));

	cout << "Mining block 2..." << endl;
	bChain.AddBlock(CBlock(2, "Block 2 Data"));

	cout << "Mining block 3..." << endl;
	bChain.AddBlock(CBlock(3, "Block 3 Data"));

	bChain.PrintBlocks();

	system("pause");

	return 0;
}