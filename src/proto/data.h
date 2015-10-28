/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* vim: set ts=8 sts=4 et sw=4 tw=80: */
/*
 * Copyright (C) 2015. Jefferson Lab, xMsg framework (JLAB). All Rights Reserved.
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for educational, research, and not-for-profit purposes,
 * without fee and without a signed licensing agreement.
 *
 * Contact Vardan Gyurjyan
 * Department of Experimental Nuclear Physics, Jefferson Lab.
 *
 * IN NO EVENT SHALL JLAB BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL,
 * INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF
 * THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF JLAB HAS BEEN ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * JLAB SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE. THE CLARA SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED
 * HEREUNDER IS PROVIDED "AS IS". JLAB HAS NO OBLIGATION TO PROVIDE MAINTENANCE,
 * SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */

#ifndef XMSG_PROTO_DATA_H_
#define XMSG_PROTO_DATA_H_

#include "data.pb.h"

#include <cstdint>
#include <memory>
#include <vector>

namespace xmsg {
namespace proto {

inline std::vector<std::uint8_t> serialize_data(const Data& data)
{
    auto buffer = std::vector<std::uint8_t>(data.ByteSize());
    data.SerializeToArray(buffer.data(), buffer.size());
    return buffer;
}

inline Data parse_data(const std::vector<std::uint8_t>& buffer)
{
    auto xdata = Data{};
    xdata.ParseFromArray(buffer.data(), buffer.size());
    return xdata;
}


inline bool operator==(const Data& lhs, const Data& rhs)
{
    return lhs.SerializeAsString() == rhs.SerializeAsString();
}

inline bool operator!=(const Data& lhs, const Data& rhs)
{
    return !(lhs == rhs);
}

} // end namespace proto
} // end namespace xmsg

#endif // XMSG_PROTO_DATA_H_
