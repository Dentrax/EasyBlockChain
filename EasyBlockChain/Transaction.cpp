#include "Transaction.h"

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

string CTXBase::ToString() const {
	return "CTXBase";
}

string CTXInput::ToString() const {
	return string();
}


