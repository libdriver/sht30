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
 * @file      driver_sht30_shot.c
 * @brief     driver sht30 shot source file
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

#include "driver_sht30_shot.h"

static sht30_handle_t gs_handle;        /**< sht30 handle */

/**
 * @brief     shot example init
 * @param[in] addr_pin is the iic device address
 * @return    status code
 *            - 0 success
 *            - 1 init failed
 * @note      none
 */
uint8_t sht30_shot_init(sht30_address_t addr_pin)
{
    uint8_t res;
    
    /* link functions */
    DRIVER_SHT30_LINK_INIT(&gs_handle, sht30_handle_t);
    DRIVER_SHT30_LINK_IIC_INIT(&gs_handle, sht30_interface_iic_init);
    DRIVER_SHT30_LINK_IIC_DEINIT(&gs_handle, sht30_interface_iic_deinit);
    DRIVER_SHT30_LINK_IIC_READ_ADDRESS16(&gs_handle, sht30_interface_iic_scl_read_address16);
    DRIVER_SHT30_LINK_IIC_WRITE_ADDRESS16(&gs_handle, sht30_interface_iic_write_address16);
    DRIVER_SHT30_LINK_DELAY_MS(&gs_handle, sht30_interface_delay_ms);
    DRIVER_SHT30_LINK_DEBUG_PRINT(&gs_handle, sht30_interface_debug_print);

    /* set addr pin */
    res = sht30_set_addr_pin(&gs_handle, addr_pin);
    if (res != 0)
    {
        sht30_interface_debug_print("sht30: set addr pin failed.\n");
        
        return 1;
    }
    
    /* sht30 init */
    res = sht30_init(&gs_handle);
    if (res != 0)
    {
        sht30_interface_debug_print("sht30: init failed.\n");
        
        return 1;
    }
    
    /* wait 10 ms */
    sht30_interface_delay_ms(10);
    
    /* set default repeatability */
    res = sht30_set_repeatability(&gs_handle, SHT30_SHOT_DEFAULT_REPEATABILITY);
    if (res != 0)
    {
        sht30_interface_debug_print("sht30: set repeatability failed.\n");
        (void)sht30_deinit(&gs_handle);
        
        return 1;
    }
    
    /* set art */
    res = sht30_set_art(&gs_handle);
    if (res != 0)
    {
        sht30_interface_debug_print("sht30: set art failed.\n");
        (void)sht30_deinit(&gs_handle);
        
        return 1;
    }
    
    /* wait 10 ms */
    sht30_interface_delay_ms(10);
   
    /* set default heater */
    res = sht30_set_heater(&gs_handle, SHT30_SHOT_DEFAULT_HEATER);
    if (res != 0)
    {
        sht30_interface_debug_print("sht30: set heater failed.\n");
        (void)sht30_deinit(&gs_handle);
        
        return 1;
    }
    
    return 0;
}

/**
 * @brief      shot example read
 * @param[out] *temperature points to a converted temperature buffer
 * @param[out] *humidity points to a converted humidity buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t sht30_shot_read(float *temperature, float *humidity)
{
    uint16_t temperature_raw;
    uint16_t humidity_raw;
   
    /* read data */
    if (sht30_single_read(&gs_handle, SHT30_SHOT_DEFAULT_CLOCK_STRETCHING, (uint16_t *)&temperature_raw, temperature, 
                          (uint16_t *)&humidity_raw, humidity) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief  shot example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t sht30_shot_deinit(void)
{
    /* close sht30 */
    if (sht30_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
