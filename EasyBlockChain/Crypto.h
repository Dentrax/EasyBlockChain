// ====================================================
// EasyBlockChain Copyright(C) 2018 Furkan Türkal
// This program comes with ABSOLUTELY NO WARRANTY; This is free software,
// and you are welcome to redistribute it under certain conditions; See
// file LICENSE, which is part of this source code package, for details.
// ====================================================

#pragma once

#include <cstdint>
#include <array>

using namespace std;

namespace Crypt
{
	using Hash = array<uint8_t, 32>;
	using PublicKey = array<uint8_t, 25>;
	using SecretKey = array<uint8_t, 32>;
	using Signature = array<uint8_t, 65>;
}