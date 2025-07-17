// Copyright 2025 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

///
/// \file   ObjectMetadataKeysHelpers.h
/// \author Michal Tichak
///

#include <optional>
#include <string>

namespace o2::quality_control::repository::metadata_keys
{
/**
 * \brief Parses metadata value stored under metadata_keys::cycle
 * @param cycleStr string expecting unsigned number
 * @return if parsing fails (eg. too big of a number, string wasn't a number) it returns nullopt
 *
 */
std::optional<unsigned long> parseCycle(const std::string& cycleStr);
} // namespace o2::quality_control::repository::metadata_keys
