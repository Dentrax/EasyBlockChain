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
public:
	virtual void SetNull();

	virtual bool IsNull() const;

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

private:
	Crypt::PublicKey m_key;
	uint64_t m_amount;

public:
	CTXOutput() {
		this->SetNull();
	}

	CTXOutput(Crypt::PublicKey key, uint64_t amount) {
		this->m_key = key;
		this->m_amount = amount;
	}

	bool operator==(const CTXOutput& other) const;

	void SetNull();

	bool IsNull() const;

	Crypt::PublicKey GetKey() const;

	uint64_t GetAmount() const;

	string ToString() const;
};

class CTXPrefix {

protected:
	uint64_t m_time;
	vector<CTXInput> m_inputs;
	vector<CTXOutput> m_outputs;
	vector<uint8_t> m_extras;

public:

	uint64_t GetTime() const;

	vector<CTXInput> GetInputs() const;

	vector<CTXOutput> GetOutputs() const;

	vector<uint8_t> GetExtras() const;

};

class CTransactionX final : public CTXPrefix {

private:
	int m_version;
	int m_lockTime;
	Crypt::PublicKey m_from;
	Crypt::PublicKey m_to;

public:
	CTransactionX() {
		this->SetNull();
	}

	bool operator==(const CTransactionX& other) const;

	int GetVersion() const;

	int GetLockTime() const;

	void SetNull();

	bool IsNull() const;

	string ToString() const;


};