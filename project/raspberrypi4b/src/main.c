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
 * @file      main.c
 * @brief     main source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2021-03-05
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2021/03/05  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "driver_sht30_register_test.h"
#include "driver_sht30_read_test.h"
#include "driver_sht30_alert_test.h"
#include "driver_sht30_basic.h"
#include "driver_sht30_shot.h"
#include "driver_sht30_alert.h"
#include "gpio.h"
#include <getopt.h>
#include <stdlib.h>

uint8_t (*g_gpio_irq)(void) = NULL;        /**< gpio irq */

/**
 * @brief     interface receive callback
 * @param[in] type receive type
 * @note      none
 */
static void a_receive_callback(uint16_t type)
{
    switch (type)
    {
        case SHT30_STATUS_ALERT_PENDING_STATUS :
        {
            sht30_interface_debug_print("sht30: irq alert pending status.\n");
            
            break;
        }
        case SHT30_STATUS_HUMIDITY_ALERT :
        {
            sht30_interface_debug_print("sht30: irq humidity alert.\n");
            
            break;
        }
        case SHT30_STATUS_TEMPERATURE_ALERT :
        {
            sht30_interface_debug_print("sht30: irq temperature alert.\n");
            
            break;
        }
    }
}

/**
 * @brief     sht30 full function
 * @param[in] argc arg numbers
 * @param[in] **argv arg address
 * @return    status code
 *            - 0 success
 *            - 1 run failed
 *            - 5 param is invalid
 * @note      none
 */
uint8_t sht30(uint8_t argc, char **argv)
{
    int c;
    int longindex = 0;
    const char short_options[] = "hipe:t:";
    const struct option long_options[] =
    {
        {"help", no_argument, NULL, 'h'},
        {"information", no_argument, NULL, 'i'},
        {"port", no_argument, NULL, 'p'},
        {"example", required_argument, NULL, 'e'},
        {"test", required_argument, NULL, 't'},
        {"addr", required_argument, NULL, 1},
        {"times", required_argument, NULL, 2},
        {"timeout", required_argument, NULL, 3},
        {"high-limit-temp", required_argument, NULL, 4},
        {"high-limit-humi", required_argument, NULL, 5},
        {"low-limit-temp", required_argument, NULL, 6},
        {"low-limit-humi", required_argument, NULL, 7},
        {NULL, 0, NULL, 0},
    };
    char type[33] = "unknown";
    uint32_t times = 3;
    uint32_t timeout = 10000;
    float high_limit_temperature = 30.0f;
    float high_limit_humidity = 50.0f;
    float low_limit_temperature = 25.0f;
    float low_limit_humidity = 30.0f;
    sht30_address_t addr = SHT30_ADDRESS_0;
    
    /* if no params */
    if (argc == 1)
    {
        /* goto the help */
        goto help;
    }
    
    /* init 0 */
    optind = 0;
    
    /* parse */
    do
    {
        /* parse the args */
        c = getopt_long(argc, argv, short_options, long_options, &longindex);
        
        /* judge the result */
        switch (c)
        {
            /* help */
            case 'h' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "h");
                
                break;
            }
            
            /* information */
            case 'i' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "i");
                
                break;
            }
            
            /* port */
            case 'p' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "p");
                
                break;
            }
            
            /* example */
            case 'e' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "e_%s", optarg);
                
                break;
            }
            
            /* test */
            case 't' :
            {
                /* set the type */
                memset(type, 0, sizeof(char) * 33);
                snprintf(type, 32, "t_%s", optarg);
                
                break;
            }
            
            /* addr */
            case 1 :
            {
                /* set the addr pin */
                if (strcmp("0", optarg) == 0)
                {
                    addr = SHT30_ADDRESS_0;
                }
                else if (strcmp("1", optarg) == 0)
                {
                    addr = SHT30_ADDRESS_1;
                }
                else
                {
                    return 5;
                }
                
                break;
            }
            
            /* running times */
            case 2 :
            {
                /* set the times */
                times = atol(optarg);
                
                break;
            } 
            
            /* timeout */
            case 3 :
            {
                /* set the timeout */
                timeout = atol(optarg);
                
                break;
            } 
            
            /* high_limit_temperature */
            case 4 :
            {
                /* set the high limit temperature */
                high_limit_temperature = (float)atof(optarg);
                
                break;
            } 
            
            /* high_limit_humidity */
            case 5 :
            {
                /* set the high limit humidity */
                high_limit_humidity = (float)atof(optarg);
                
                break;
            } 
            
            /* low_limit_temperature */
            case 6 :
            {
                /* set the low limit temperature */
                low_limit_temperature = (float)atof(optarg);
                
                break;
            } 
            
            /* low_limit_humidity */
            case 7 :
            {
                /* set the low limit humidity */
                low_limit_humidity = (float)atof(optarg);
                
                break;
            } 
            
            /* the end */
            case -1 :
            {
                break;
            }
            
            /* others */
            default :
            {
                return 5;
            }
        }
    } while (c != -1);

    /* run the function */
    if (strcmp("t_reg", type) == 0)
    {
        /* run reg test */
        if (sht30_register_test(addr) != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("t_read", type) == 0)
    {
        /* run read test */
        if (sht30_read_test(addr, times) != 0)
        {
            return 1;
        }
        
        return 0;
    }
    else if (strcmp("t_alert", type) == 0)
    {
        uint8_t res;
        
        /* gpio init */
        g_gpio_irq = sht30_alert_test_irq_handler;
        res = gpio_interrupt_init();
        if (res != 0)
        {
            g_gpio_irq = NULL;
            
            return 1;
        }
        
        /* run alert test */
        if (sht30_alert_test(addr, high_limit_temperature, high_limit_humidity,
                             low_limit_temperature, low_limit_humidity, timeout) != 0)
        {
            gpio_interrupt_deinit();
            g_gpio_irq = NULL;
            
            return 1;
        }
        
        gpio_interrupt_deinit();
        g_gpio_irq = NULL;
        
        return 0;
    }
    else if (strcmp("e_sn", type) == 0)
    {
        uint8_t res;
        uint8_t sn[4];
        
        /* basic init */
        res = sht30_basic_init(addr);
        if (res != 0)
        {
            return 1;
        }
        
        /* get serial number */
        res = sht30_basic_get_serial_number(sn);
        if (res != 0)
        {
            sht30_basic_deinit();
            
            return 1;
        }
        sht30_interface_debug_print("sht30: serial number is 0x%02X 0x%02X 0x%02X 0x%02X.\n", sn[0], sn[1], sn[2], sn[3]);
        
        /* basic deinit */
        (void)sht30_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_read", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        float temperature;
        float humidity;
        
        /* basic init */
        res = sht30_basic_init(addr);
        if (res != 0)
        {
            return 1;
        }
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* delay 1000ms */
            sht30_interface_delay_ms(1000);
            
            /* read data */
            res = sht30_basic_read((float *)&temperature, (float *)&humidity);
            if (res != 0)
            {
                (void)sht30_basic_deinit();
                
                return 1;
            }
            
            /* output */
            sht30_interface_debug_print("sht30: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)times);
            sht30_interface_debug_print("sht30: temperature is %0.2fC.\n", temperature);
            sht30_interface_debug_print("sht30: humidity is %0.2f%%.\n", humidity);
        }
        
        /* basic deinit */
        (void)sht30_basic_deinit();
        
        return 0;
    }
    else if (strcmp("e_shot", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        float temperature;
        float humidity;
        
        /* shot init */
        res = sht30_shot_init(addr);
        if (res != 0)
        {
            return 1;
        }
        
        /* loop */
        for (i = 0; i < times; i++)
        {
            /* delay 1000ms */
            sht30_interface_delay_ms(1000);
            
            /* read data */
            res = sht30_shot_read((float *)&temperature, (float *)&humidity);
            if (res != 0)
            {
                (void)sht30_shot_deinit();
                
                return 1;
            }
            
            /* output */
            sht30_interface_debug_print("sht30: %d/%d.\n", (uint32_t)(i + 1), (uint32_t)times);
            sht30_interface_debug_print("sht30: temperature is %0.2fC.\n", temperature);
            sht30_interface_debug_print("sht30: humidity is %0.2f%%.\n", humidity);
        }
        
        /* shot deinit */
        (void)sht30_shot_deinit();
        
        return 0;
    }
    else if (strcmp("e_alert", type) == 0)
    {
        uint8_t res;
        uint32_t i;
        
        /* gpio init */
        g_gpio_irq = sht30_alert_irq_handler;
        res = gpio_interrupt_init();
        if (res != 0)
        {
            g_gpio_irq = NULL;
            
            return 1;
        }
        
        /* output */
        sht30_interface_debug_print("sht30: high limit temperature is %.02fC.\n", high_limit_temperature);
        sht30_interface_debug_print("sht30: high limit humidity is %.02f%%.\n", high_limit_humidity);
        sht30_interface_debug_print("sht30: low limit temperature is %.02fC.\n", low_limit_temperature);
        sht30_interface_debug_print("sht30: low limit humidity is %.02f%%.\n", low_limit_humidity);
        
        /* alert init */
        res = sht30_alert_init(addr, a_receive_callback,
                               high_limit_temperature, high_limit_humidity,
                               high_limit_temperature - 1.0f, high_limit_humidity + 1.0f,
                               low_limit_temperature, low_limit_humidity,
                               low_limit_temperature - 1.0f, low_limit_humidity + 1.0f);
        if (res != 0)
        {
            gpio_interrupt_deinit();
            g_gpio_irq = NULL;
            
            return 1;
        }
        
        /* loop */
        for (i = 0; i < timeout; i++)
        {
            /* delay 1ms */
            sht30_interface_delay_ms(1);
        }
        
        gpio_interrupt_deinit();
        g_gpio_irq = NULL;
        
        /* finish */
        sht30_interface_debug_print("sht30: finish.\n");
        
        /* alert deinit */
        (void)sht30_alert_deinit();
        
        return 0;
    }
    else if (strcmp("h", type) == 0)
    {
        help:
        sht30_interface_debug_print("Usage:\n");
        sht30_interface_debug_print("  sht30 (-i | --information)\n");
        sht30_interface_debug_print("  sht30 (-h | --help)\n");
        sht30_interface_debug_print("  sht30 (-p | --port)\n");
        sht30_interface_debug_print("  sht30 (-t reg | --test=reg) [--addr=<0 | 1>]\n");
        sht30_interface_debug_print("  sht30 (-t read | --test=read) [--addr=<0 | 1>] [--times=<num>]\n");
        sht30_interface_debug_print("  sht30 (-t alert | --test=alert) [--addr=<0 | 1>] [--timeout=<ms>] [--high-limit-temp=<degree>] [--high-limit-humi=<percentage>]\n");
        sht30_interface_debug_print("        [--low-limit-temp=<degree>] [--low-limit-humi=<percentage>]\n");
        sht30_interface_debug_print("  sht30 (-e read | --example=read) [--addr=<0 | 1>] [--times=<num>]\n");
        sht30_interface_debug_print("  sht30 (-e shot | --example=shot) [--addr=<0 | 1>] [--times=<num>]\n");
        sht30_interface_debug_print("  sht30 (-e alert | --example=alert) [--addr=<0 | 1>] [--timeout=<ms>] [--high-limit-temp=<degree>] [--high-limit-humi=<percentage>]\n");
        sht30_interface_debug_print("        [--low-limit-temp=<degree>] [--low-limit-humi=<percentage>]\n");
        sht30_interface_debug_print("\n");
        sht30_interface_debug_print("Options:\n");
        sht30_interface_debug_print("      --addr=<0 | 1>    Set the addr pin.([default: 0])\n");
        sht30_interface_debug_print("  -e <read | shot | alert | sn>, --example=<read | shot | alert | sn>\n");
        sht30_interface_debug_print("                        Run the driver example.\n");
        sht30_interface_debug_print("      --low-limit-temp  Low limit temperature in degress.([default: 25.0])\n");
        sht30_interface_debug_print("      --low-limit-humi  Low limit humidity in percentage.([default: 30.0])\n");
        sht30_interface_debug_print("  -h, --help            Show the help.\n");
        sht30_interface_debug_print("      --high-limit-temp High limit temperature in degress.([default: 30.0])\n");
        sht30_interface_debug_print("      --high-limit-humi High limit humidity in percentage.([default: 50.0])\n");
        sht30_interface_debug_print("  -i, --information     Show the chip information.\n");
        sht30_interface_debug_print("  -p, --port            Display the pin connections of the current board.\n");
        sht30_interface_debug_print("  -t <reg | read | alert>, --test=<reg | read | alert>\n");
        sht30_interface_debug_print("                        Run the driver test.\n");
        sht30_interface_debug_print("      --times=<num>     Set the running times.([default: 3])\n");
        sht30_interface_debug_print("      --timeout=<ms>    Set timeout in ms.([default: 10000])\n");

        return 0;
    }
    else if (strcmp("i", type) == 0)
    {
        sht30_info_t info;
        
        /* print sht30 info */
        sht30_info(&info);
        sht30_interface_debug_print("sht30: chip is %s.\n", info.chip_name);
        sht30_interface_debug_print("sht30: manufacturer is %s.\n", info.manufacturer_name);
        sht30_interface_debug_print("sht30: interface is %s.\n", info.interface);
        sht30_interface_debug_print("sht30: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        sht30_interface_debug_print("sht30: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        sht30_interface_debug_print("sht30: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        sht30_interface_debug_print("sht30: max current is %0.2fmA.\n", info.max_current_ma);
        sht30_interface_debug_print("sht30: max temperature is %0.1fC.\n", info.temperature_max);
        sht30_interface_debug_print("sht30: min temperature is %0.1fC.\n", info.temperature_min);
        
        return 0;
    }
    else if (strcmp("p", type) == 0)
    {
        /* print pin connection */
        sht30_interface_debug_print("sht30: SCL connected to GPIO3(BCM).\n");
        sht30_interface_debug_print("sht30: SDA connected to GPIO2(BCM).\n");
        sht30_interface_debug_print("sht30: ALERT connected to GPIO17(BCM).\n");
        
        return 0;
    }
    else
    {
        return 5;
    }
}

/**
 * @brief     main function
 * @param[in] argc arg numbers
 * @param[in] **argv arg address
 * @return    status code
 *             - 0 success
 * @note      none
 */
int main(uint8_t argc, char **argv)
{
    uint8_t res;

    res = sht30(argc, argv);
    if (res == 0)
    {
        /* run success */
    }
    else if (res == 1)
    {
        sht30_interface_debug_print("sht30: run failed.\n");
    }
    else if (res == 5)
    {
        sht30_interface_debug_print("sht30: param is invalid.\n");
    }
    else
    {
        sht30_interface_debug_print("sht30: unknown status code.\n");
    }

    return 0;
}
