/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <fpioa_cfg.h>
#include <fpioa.h>
#include <FreeRTOS.h>

const fpioa_cfg_t __attribute__((weak)) g_fpioa_cfg =
{
    .version = FPIOA_CFG_VERSION,
    .functions_count = 0
};

void fpioa_setup()
{
    configASSERT(g_fpioa_cfg.version == FPIOA_CFG_VERSION);

    uint32_t i;
    for (i = 0; i < g_fpioa_cfg.functions_count; i++)
    {
        fpioa_cfg_item_t item = g_fpioa_cfg.functions[i];
        fpioa_set_function(item.number, item.function);
    }
}
