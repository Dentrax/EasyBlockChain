// ====================================================
// EasyBlockChain Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#include <ctime>
#include <sstream>
#include "Block.h"
#include "SHA256.h"

CBlock::CBlock(uint32_t indexIn, const string & dataIn) : m_index(indexIn), m_data(dataIn) {
	this->m_nonce = -1;
	this->m_time = time(nullptr);
}

uint32_t CBlock::GetIndex() const {
	return this->m_index;
}

time_t CBlock::GetTime() const {
	return this->m_time;
}


string CBlock::GetHash() const {
	return this->m_hash;
}

void CBlock::SetAsGenesis() {
	this->m_nonce = -1;
	this->m_time = time(nullptr);
	this->m_index = 0;
	this->m_data = "";
	this->m_hash = "Genesis";
}

void CBlock::DOMine(uint32_t difficulty) {
	char * cstr = new char[difficulty + 1];

	for (uint32_t i = 0; i < difficulty; ++i) {
		cstr[i] = '0';
	}
	cstr[difficulty] = '\0';

	string str(cstr);

	do {
		this->m_nonce++;
		this->m_hash = CalculateHash();
	} while (!str.compare(this->m_hash.substr(0, difficulty)));

	cout << "Block mined: " << this->m_hash << endl;
}


inline const string CBlock::CalculateHash() const {
	stringstream ss;
	ss << this->m_index << this->m_time << this->m_data << this->m_nonce << this->PrevHash;
	return sha256(ss.str());
}