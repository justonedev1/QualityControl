// Copyright 2019-2024 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

#include "QualityControl/WorkflowValidator.h"
#include "QualityControl/QcInfoLogger.h"
#include <Framework/OutputSpec.h>
#include <unordered_set>

namespace std
{

template <>
struct hash<o2::framework::OutputSpec> {
  std::size_t operator()(const o2::framework::OutputSpec& spec) const noexcept
  {
    return std::hash<decltype(spec.binding.value)>{}(spec.binding.value);
  }
};

} // namespace std

namespace o2::quality_control::core
{

struct DataSpecUtilsMatch {
  bool operator()(const framework::OutputSpec& left, const framework::OutputSpec& right) const noexcept
  {
    return framework::DataSpecUtils::match(left, right);
  }
};

void WorkflowValidator::sameOutputSpecs(const framework::WorkflowSpec& workflow)
{
  std::unordered_set<framework::OutputSpec, std::hash<framework::OutputSpec>, DataSpecUtilsMatch> uniqueOutputSpecs;
  for (const auto& workflowSpec : workflow) {
    for (const auto& outputSpec : workflowSpec.outputs) {
      if (uniqueOutputSpecs.contains(outputSpec)) {
        ILOG(Fatal) << "Found duplicate output specs!: " << outputSpec;
      } else {
        uniqueOutputSpecs.insert(outputSpec);
      }
    }
  }
}

} // namespace o2::quality_control::core
