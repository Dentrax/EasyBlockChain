// ====================================================
// EasyBlockChain Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#include "BlockChain.h"
#include <string>

CBlockChain::CBlockChain() {
	//this->m_chain.emplace_back(CBlock(0, "Genesis Block"));
	this->m_difficulty = 10;
}

void CBlockChain::AddGenesis() {
	CBlock genesis(0, "");
	genesis.SetAsGenesis();
	this->m_chain.emplace_back(genesis);
}

void CBlockChain::AddBlock(CBlock newBlock) {
	newBlock.PrevHash = GetLastBlock().GetHash();
	newBlock.DOMine(this->m_difficulty);
	this->m_chain.push_back(newBlock);
}

void CBlockChain::PrintBlocks() {
	cout << endl << "All blocks:" << endl;
	for (const auto &block : this->m_chain) {
		cout << "Index: " << block.GetIndex()
			 << " Time: " << block.GetTime()
			 << " Hash: " << block.GetHash() 
			 << endl;
	}
	cout << endl;
}

const CBlock CBlockChain::GetLastBlock() const {
	return this->m_chain.back();
}

const uint32_t CBlockChain::GetChainSize() const {
	return this->m_chain.size();
}

//const uint32_t CBlockChain::GetChainCapacity() const {
//	return this->m_chain.capacity;
//}
