/*
 * Copyright Amazon.com, Inc. and its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: MIT
 *
 * Licensed under the MIT License. See the LICENSE accompanying this file
 * for the specific language governing permissions and limitations under
 * the License.
 */

#ifndef CUSTOM_JOB_DOC_H
#define CUSTOM_JOB_DOC_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/* Flattening this to a single Step+Action type due to the simplified example */
typedef struct
{
    /** @brief Name of the action of the step */
    const char * name;

    /** @brief Handler of the action of the step */
    const char * handler;

    /** @brief Argument for the action of the step */
    const char arg[ 10 ];
} JobStepAction_t;

typedef struct
{
    /** @brief Version string */
    const char * version;

    /** @brief Step+Action for the custom job */
    JobStepAction_t stepActions;
} CustomJobDocumentFields_t;

#endif /* ifndef CUSTOM_JOB_DOC_H */
