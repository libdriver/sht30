[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver SHT30

[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/sht30/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE)

SHT30 is the next generation of Sensirion's temperature and humidity sensors. It builds on a new CMOSens sensor chip that is at the heart of Sensirion's new humidity and temperature platform. The SHT30 has increased intelligence, reliability and improved accuracy specifications compared to its predecessor. Its functionality includes enhanced signal processing, two distinctive and user selectable IIC addresses and communication speeds of up to 1 MHz. The DFN package has a footprint of 2.5 x 2.5 mm2 while keeping a height of 0.9 mm. This allows for integration of the SHT30 into a great variety of applications. Additionally, the wide supply voltage range of 2.4 V to 5.5 V guarantees compatibility with diverse assembly situations. All in all, the SHT30 incorporates 15 years of knowledge of Sensirion, the leader in the humidity sensor industry.

LibDriver SHT30 is the full function driver of SHT30 launched by LibDriver.It provides functions of temperature and humidity continuous mode reading and temperature and humidity single mode reading. LibDriver is MISRA compliant.

### Table of Contents

  - [Instruction](#Instruction)
  - [Install](#Install)
  - [Usage](#Usage)
    - [example basic](#example-basic)
    - [example shot](#example-shot)
  - [Document](#Document)
  - [Contributing](#Contributing)
  - [License](#License)
  - [Contact Us](#Contact-Us)

### Instruction

/src includes LibDriver SHT30 source files.

/interface includes LibDriver SHT30 IIC platform independent template.

/test includes LibDriver SHT30 driver test code and this code can test the chip necessary function simply.

/example includes LibDriver SHT30 sample code.

/doc includes LibDriver SHT30 offline document.

/datasheet includes SHT30 datasheet.

/project includes the common Linux and MCU development board sample code. All projects use the shell script to debug the driver and the detail instruction can be found in each project's README.md.

/misra includes the LibDriver MISRA code scanning results.

### Install

Reference /interface IIC platform independent template and finish your platform IIC driver.

Add the /src directory, the interface driver for your platform, and your own drivers to your project, if you want to use the default example drivers, add the /example directory to your project.

### Usage

You can refer to the examples in the /example directory to complete your own driver. If you want to use the default programming examples, here's how to use them.

#### example basic

```C
#include "driver_sht30_basic.h"

uint8_t res;
uint8_t i;
float temperature;
float humidity;

res = sht30_basic_init(SHT30_ADDRESS_0);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    sht30_interface_delay_ms(1000);
    res = sht30_basic_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)sht30_basic_deinit();

        return 1;
    }
    sht30_interface_debug_print("sht30: temperature is %0.2fC.\n", temperature);
    sht30_interface_debug_print("sht30: humidity is %0.2f%%.\n", humidity);
    
    ...
    
}

...

(void)sht30_basic_deinit();

return 0;
```

#### example shot

```C
#include "driver_sht30_shot.h"

uint8_t res;
uint8_t i;
float temperature;
float humidity;

res = sht30_shot_init(SHT30_ADDRESS_0);
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    sht30_interface_delay_ms(1000);
    res = sht30_shot_read((float *)&temperature, (float *)&humidity);
    if (res != 0)
    {
        (void)sht30_shot_deinit();

        return 1;
    }
    sht30_interface_debug_print("sht30: temperature is %0.2fC.\n", temperature);
    sht30_interface_debug_print("sht30: humidity is %0.2f%%.\n", humidity);
    
    ...
    
}

...

(void)sht30_shot_deinit();

return 0;
```

### Document

Online documents: [https://www.libdriver.com/docs/sht30/index.html](https://www.libdriver.com/docs/sht30/index.html).

Offline documents: /doc/html/index.html.

### Contributing

Please refer to CONTRIBUTING.md.

### License

Copyright (c) 2015 - present LibDriver All rights reserved



The MIT License (MIT) 



Permission is hereby granted, free of charge, to any person obtaining a copy

of this software and associated documentation files (the "Software"), to deal

in the Software without restriction, including without limitation the rights

to use, copy, modify, merge, publish, distribute, sublicense, and/or sell

copies of the Software, and to permit persons to whom the Software is

furnished to do so, subject to the following conditions: 



The above copyright notice and this permission notice shall be included in all

copies or substantial portions of the Software. 



THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR

IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,

FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE

AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER

LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,

OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE

SOFTWARE. 

### Contact Us

Please send an e-mail to lishifenging@outlook.com.