/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/machinelearning/model/Algorithm.h>
#include <aws/core/utils/HashingUtils.h>

using namespace Aws::Utils;

static const int sgd_HASH = HashingUtils::HashString("sgd");

namespace Aws
{
namespace MachineLearning
{
namespace Model
{
namespace AlgorithmMapper
{


Algorithm GetAlgorithmForName(const Aws::String& name)
{
  int hashCode = HashingUtils::HashString(name.c_str());
  if (hashCode == sgd_HASH)
  {
     return Algorithm::sgd;
  }
  return Algorithm::NOT_SET;
}

Aws::String GetNameForAlgorithm(Algorithm enumValue)
{
  switch(enumValue)
  {
  case Algorithm::sgd:
    return "sgd";
  default:
    return "";
  }
}

} // namespace AlgorithmMapper
} // namespace Model
} // namespace MachineLearning
} // namespace Aws