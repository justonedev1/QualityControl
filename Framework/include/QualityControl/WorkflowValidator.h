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

#ifndef QC_CORE_WORKFLOW_VALIDATOR_H
#define QC_CORE_WORKFLOW_VALIDATOR_H

#include <Framework/WorkflowSpec.h>

namespace o2::quality_control::core
{

struct WorkflowValidator {
  WorkflowValidator() = delete;

  /// \brief Checks given workflow whether there are specs with the same names.
  ///
  /// \param workflow
  static void sameOutputSpecs(const framework::WorkflowSpec& workflow);
};

} // namespace o2::quality_control::core

#endif
