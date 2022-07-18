//
// Copyright (C) 2011 David Eckhoff <eckhoff@cs.fau.de>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

import veins.base.utils.Coord;
import veins.modules.messages.BaseFrame1609_4;
import veins.base.utils.SimpleAddress;

cplusplus {{
#include <string>
#include "/usr/include/crypto++/eccrypto.h"
#include "/usr/include/crypto++/osrng.h"
#include "/usr/include/crypto++/oids.h"
#include "/usr/include/crypto++/files.h"
#include "/usr/include/crypto++/hex.h"

using namespace std;
using CryptoPP::ECDSA;
using CryptoPP::ECP;
using CryptoPP::SHA256;

typedef CryptoPP::ECDSA<ECP, CryptoPP::SHA256>::PublicKey cryp;
typedef std::string charpi;
}}

class cryp{
@existingClass;
}

class charpi{
@existingClass;
}

namespace veins;

packet DemoSafetyMessage extends BaseFrame1609_4 {
    Coord senderPos;
    Coord senderSpeed;
    cryp senderPK;
    charpi MsgSignature;
}
