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

#include "custom_job_parser.h"

int8_t customParser_parseJobDocFile( const char * jobDoc,
                                     const size_t jobDocLength,
                                     CustomJobDocumentFields_t * result )
{
    JSONStatus_t jsonResult = JSONNotFound;
    const char * jsonValue = NULL;
    size_t jsonValueLength = 0U;
    char queryString[ 33 ];
    size_t queryStringLength;

    /* Parse the version */
    jsonResult = JSON_SearchConst( jobDoc,
                                   jobDocLength,
                                   "version",
                                   8U, /* Length of "version"*/
                                   &jsonValue,
                                   &jsonValueLength,
                                   NULL );
    result->version = jsonValue;

    /* Parse the name of the action */
    jsonResult = JSON_SearchConst( jobDoc,
                                   jobDocLength,
                                   "steps[0].action.name",
                                   21U, /* Length of "steps[0].action.name"*/
                                   &jsonValue,
                                   &jsonValueLength,
                                   NULL );

    result->stepActions.name = jsonValue;

    /* Parse the name of the input handler of the action */
    jsonResult = JSON_SearchConst( jobDoc,
                                   jobDocLength,
                                   "steps[0].action.input[0].handler",
                                   33U, /* Length of "steps[0].action.input[0].handler"*/
                                   &jsonValue,
                                   &jsonValueLength,
                                   NULL );

    result->stepActions.handler = jsonValue;

    return 0;
}
