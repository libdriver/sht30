/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_sht30_alert_test.h
 * @brief     driver sht30 alert test header file
 * @version   2.0.0
 * @author    Shifeng Li
 * @date      2021-03-05
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2021/03/05  <td>2.0      <td>Shifeng Li  <td>format the code
 * <tr><td>2020/11/03  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_SHT30_ALERT_TEST_H
#define DRIVER_SHT30_ALERT_TEST_H

#include "driver_sht30_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @addtogroup sht30_test_driver
 * @{
 */

/**
 * @brief  alert test irq
 * @return status code
 *         - 0 success
 *         - 1 run failed
 * @note   none
 */
uint8_t sht30_alert_test_irq_handler(void);

/**
 * @brief     alert test
 * @param[in] addr_pin iic device address
 * @param[in] high_limit_temperature high limit temperature
 * @param[in] high_limit_humidity high limit humidity
 * @param[in] low_limit_temperature low limit temperature
 * @param[in] low_limit_humidity low limit humidity
 * @param[in] timeout timeout in ms
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t sht30_alert_test(sht30_address_t addr_pin, 
                         float high_limit_temperature, float high_limit_humidity,
                         float low_limit_temperature, float low_limit_humidity,
                         uint32_t timeout);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
