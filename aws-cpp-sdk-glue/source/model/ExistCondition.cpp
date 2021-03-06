﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
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

#include <aws/glue/model/ExistCondition.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace Glue
  {
    namespace Model
    {
      namespace ExistConditionMapper
      {

        static const int MUST_EXIST_HASH = HashingUtils::HashString("MUST_EXIST");
        static const int NOT_EXIST_HASH = HashingUtils::HashString("NOT_EXIST");
        static const int NONE_HASH = HashingUtils::HashString("NONE");


        ExistCondition GetExistConditionForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == MUST_EXIST_HASH)
          {
            return ExistCondition::MUST_EXIST;
          }
          else if (hashCode == NOT_EXIST_HASH)
          {
            return ExistCondition::NOT_EXIST;
          }
          else if (hashCode == NONE_HASH)
          {
            return ExistCondition::NONE;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<ExistCondition>(hashCode);
          }

          return ExistCondition::NOT_SET;
        }

        Aws::String GetNameForExistCondition(ExistCondition enumValue)
        {
          switch(enumValue)
          {
          case ExistCondition::MUST_EXIST:
            return "MUST_EXIST";
          case ExistCondition::NOT_EXIST:
            return "NOT_EXIST";
          case ExistCondition::NONE:
            return "NONE";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace ExistConditionMapper
    } // namespace Model
  } // namespace Glue
} // namespace Aws
