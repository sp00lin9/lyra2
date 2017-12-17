// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_HASH2_H
#define BITCOIN_HASH2_H

#include "uint256.h"
#include "serialize.h"
#include "Lyra2REV2/sph_keccak.h"
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <vector>
#include <string>

template<typename T1>
inline uint256 HashKeccak(const T1 pbegin, const T1 pend)
{
    sph_keccak256_context ctx_keccak;
    static unsigned char pblank[1];
    uint256 hash;

    sph_keccak256_init(&ctx_keccak);
    sph_keccak256 (&ctx_keccak, (pbegin == pend ? pblank : static_cast<const void*>(&pbegin[0])), (pend - pbegin) * sizeof(pbegin[0]));
    sph_keccak256_close(&ctx_keccak, static_cast<void*>(&hash));

    return hash;
}

#endif
