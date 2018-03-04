// ====================================================
// EasyBlockChain Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#pragma once

#include <cstdint>
#include <iostream>


using namespace std;

class CBlock final {

public:
	string PrevHash;

	CBlock(std::uint32_t indexIn, const string & dataIn);

	void SetAsGenesis();

	uint32_t GetIndex() const;

	time_t GetTime() const;

	string GetHash() const;

	void DOMine(uint32_t difficulty);

private:
	uint32_t m_index;
	int64_t m_nonce;
	string m_data;
	string m_hash;
	time_t m_time;

	const string CalculateHash() const;
};