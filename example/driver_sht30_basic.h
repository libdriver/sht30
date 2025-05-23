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
 * @file      driver_sht30_basic.h
 * @brief     driver sht30 basic header file
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

#ifndef DRIVER_SHT30_BASIC_H
#define DRIVER_SHT30_BASIC_H

#include "driver_sht30_interface.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup sht30_example_driver sht30 example driver function
 * @brief    sht30 example driver modules
 * @ingroup  sht30_driver
 * @{
 */

/**
 * @brief sht30 basic example default definition
 */
#define SHT30_BASIC_DEFAULT_RATE                 SHT30_RATE_10HZ                 /**< rate 100Hz */
#define SHT30_BASIC_DEFAULT_REPEATABILITY        SHT30_REPEATABILITY_HIGH        /**< set high */
#define SHT30_BASIC_DEFAULT_HEATER               SHT30_BOOL_FALSE                /**< disable heater */

/**
 * @brief     basic example init
 * @param[in] addr_pin iic device address
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t sht30_basic_init(sht30_address_t addr_pin);

/**
 * @brief      basic example read
 * @param[out] *temperature pointer to a converted temperature buffer
 * @param[out] *humidity pointer to a converted humidity buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t sht30_basic_read(float *temperature, float *humidity);

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t sht30_basic_deinit(void);

/**
 * @brief      basic example get serial number
 * @param[out] *sn pointer to a serial number buffer
 * @return     status code
 *             - 0 success
 *             - 1 get failed
 * @note       none
 */
uint8_t sht30_basic_get_serial_number(uint8_t sn[4]);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
