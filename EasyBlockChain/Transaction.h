// ====================================================
// EasyBlockChain Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#pragma once

#include <cstdint>
#include <vector>
#include "Block.h"
#include "Crypto.h"

using namespace std;

class CTXBase {
	virtual string ToString() const = 0;
};

class CTXInput final : CTXBase {

private:
	uint32_t m_index;
	uint64_t m_amount;
	vector<uint8_t> m_datas;

public:
	CTXInput() {
		this->SetNull();
	}

	CTXInput(uint32_t index, uint64_t amount, vector<uint8_t> datas) {
		this->m_index = index;
		this->m_amount = amount;
		this->m_datas = datas;
	}

	bool operator==(const CTXInput& other) const;

	void SetNull();

	bool IsNull() const;

	uint32_t GetIndex() const;

	uint64_t GetAmount() const;

	vector<uint8_t> GetDatas() const;

	string ToString() const;
};

class CTXOutput final : CTXBase {
	Crypt::PublicKey m_key;
	uint64_t m_amount;
};

class CTXPrefix {
	uint64_t m_time;
	vector<CTXInput> m_inputs;
	vector<CTXOutput> m_outputs;
	vector<uint8_t> m_extras;
};

class CTX final : public CTXPrefix {
	Crypt::PublicKey m_from;
	Crypt::PublicKey m_to;
};