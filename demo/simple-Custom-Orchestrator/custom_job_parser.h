/*
 * Copyright Amazon.com, Inc. and its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: MIT
 *
 * Licensed under the MIT License. See the LICENSE accompanying this file
 * for the specific language governing permissions and limitations under
 * the License.
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "custom_job_doc.h"
#include "core_json.h"

int8_t customParser_parseJobDocFile( const char * jobDoc,
                                     const size_t jobDocLength,
                                     CustomJobDocumentFields_t * result );
