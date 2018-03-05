#include "Transaction.h"

void CTXBase::SetNull()
{
}

bool CTXBase::IsNull() const
{
	return false;
}

string CTXBase::ToString() const {
	return "CTXBase";
}

//CTXInput

bool CTXInput::operator==(const CTXInput & other) const {
	return (this->m_index == other.GetIndex() && this->m_amount == other.GetAmount() && this->m_datas == other.GetDatas());
}

void CTXInput::SetNull() {
	this->m_index = -1;
	this->m_amount = 0;
}

bool CTXInput::IsNull() const {
	return this->m_index == -1;
}

uint32_t CTXInput::GetIndex() const {
	return this->m_index;
}

uint64_t CTXInput::GetAmount() const {
	return this->m_amount;
}

vector<uint8_t> CTXInput::GetDatas() const {
	return this->m_datas;
}

string CTXInput::ToString() const {
	return string();
}

//CTXOutput

bool CTXOutput::operator==(const CTXOutput & other) const {
	return (this->m_key == other.GetKey() && this->m_amount == other.GetAmount());
}

void CTXOutput::SetNull() {
	//this->m_key = 0;
	this->m_amount = 0;
}

bool CTXOutput::IsNull() const {
	//TODO: Fix
	return false;
}

Crypt::PublicKey CTXOutput::GetKey() const {
	return this->m_key;
}

uint64_t CTXOutput::GetAmount() const {
	return this->m_amount;
}

string CTXOutput::ToString() const {
	return string();
}

//CTXPrefix

uint64_t CTXPrefix::GetTime() const {
	return this->m_time;
}

vector<CTXInput> CTXPrefix::GetInputs() const {
	return this->m_inputs;
}

vector<CTXOutput> CTXPrefix::GetOutputs() const {
	return this->m_outputs;
}

vector<uint8_t> CTXPrefix::GetExtras() const {
	return this->m_extras;
}

//CTransactionX

bool CTransactionX::operator==(const CTransactionX & other) const {
	return (this->m_time == other.GetTime() &&
		this->m_inputs == other.GetInputs() &&
		this->m_outputs == other.GetOutputs() &&
		this->m_extras == other.GetExtras());
}

int CTransactionX::GetVersion() const {
	return this->m_version;
}

int CTransactionX::GetLockTime() const {
	return this->m_lockTime;
}

void CTransactionX::SetNull() {
	this->m_version = 1;
	this->m_inputs.clear();
	this->m_outputs.clear();
	this->m_lockTime = 0;
}

bool CTransactionX::IsNull() const {
	return (this->m_inputs.empty() && this->m_outputs.empty());;
}

string CTransactionX::ToString() const {
	return string();
}
