### 1. Chip

#### 1.1 Chip Info

Chip Name: STM32F407ZGT6.

Extern Oscillator: 8MHz.

UART Pin: TX/RX PA9/PA10.

IIC Pin: SCL/SDA PB8/PB9.

### 2. Development and Debugging

#### 2.1 Integrated Development Environment

LibDriver provides both Keil and IAR integrated development environment projects.

MDK is the Keil ARM project and your Keil version must be 5 or higher.Keil ARM project needs STMicroelectronics STM32F4 Series Device Family Pack and you can download from https://www.keil.com/dd2/stmicroelectronics/stm32f407zgtx.

EW is the IAR ARM project and your IAR version must be 9 or higher.

#### 2.2 Serial Port Parameter

Baud Rate: 115200.

Data Bits : 8.

Stop Bits: 1.

Parity: None.

Flow Control: None.

#### 2.3 Serial Port Assistant

We use '\n' to wrap lines.If your serial port assistant displays exceptions (e.g. the displayed content does not divide lines), please modify the configuration of your serial port assistant or replace one that supports '\n' parsing.

### 3. SHT30

#### 3.1 Command Instruction

1. Show sht30 chip and driver information.

   ```shell
   sht30 (-i | --information)
   ```

2. Show sht30 help.

   ```shell
   sht30 (-h | --help)
   ```

3. Show sht30 pin connections of the current board.

   ```shell
   sht30 (-p | --port)
   ```

4. Run sht30 register test.

   ```shell
   sht30 (-t reg | --test=reg) [--addr=<0 | 1>]
   ```

5. Run sht30 read test, num is test times.

   ```shell
   sht30 (-t read | --test=read) [--addr=<0 | 1>] [--times=<num>]
   ```

6. Run sht30 read function, num is read times.

   ```shell
   sht30 (-e read | --example=read) [--addr=<0 | 1>] [--times=<num>]
   ```

7. Run sht30 shot function, num is read times.

   ```shell
   sht30 (-e shot | --example=shot) [--addr=<0 | 1>] [--times=<num>]
   ```

#### 3.2 Command Example

```shell
sht30 -i

sht30: chip is Sensirion SHT30.
sht30: manufacturer is Sensirion.
sht30: interface is IIC.
sht30: driver version is 2.0.
sht30: min supply voltage is 2.4V.
sht30: max supply voltage is 5.5V.
sht30: max current is 1.50mA.
sht30: max temperature is 125.0C.
sht30: min temperature is -40.0C.
```

```shell
sht30 -p

sht30: SCL connected to GPIOB PIN8.
sht30: SDA connected to GPIOB PIN9.
```

```shell
sht30 -t reg --addr=0

sht30: chip is Sensirion SHT30.
sht30: manufacturer is Sensirion.
sht30: interface is IIC.
sht30: driver version is 2.0.
sht30: min supply voltage is 2.4V.
sht30: max supply voltage is 5.5V.
sht30: max current is 1.50mA.
sht30: max temperature is 125.0C.
sht30: min temperature is -40.0C.
sht30: start register test.
sht30: sht30_set_addr_pin/sht30_get_addr_pin test.
sht30: set address pin 0.
sht30: check addr pin ok.
sht30: set address pin 1.
sht30: check addr pin ok.
sht30: sht30_set_repeatability/sht30_get_repeatability test.
sht30: set repeatability high.
sht30: check repeatability pin ok.
sht30: set repeatability medium.
sht30: check repeatability pin ok.
sht30: set repeatability low.
sht30: check repeatability pin ok.
sht30: set art test.
sht30: check art ok.
sht30: set heater test.
sht30: enable heater.
sht30: check heater ok.
sht30: disable heater.
sht30: check heater ok.
sht30: get status test.
sht30: check status 0x8070.
sht30: clear status test.
sht30: check clear status ok.
sht30: finish register test.
```

```shell
sht30 -t read --addr=0 --times=3

sht30: chip is Sensirion SHT30.
sht30: manufacturer is Sensirion.
sht30: interface is IIC.
sht30: driver version is 2.0.
sht30: min supply voltage is 2.4V.
sht30: max supply voltage is 5.5V.
sht30: max current is 1.50mA.
sht30: max temperature is 125.0C.
sht30: min temperature is -40.0C.
sht30: start read test.
sht30: continuous read.
sht30: set low repeatability.
sht30: set rate 0.5Hz.
sht30: temperature is 29.32C.
sht30: humidity is 24.72%.
sht30: temperature is 30.19C.
sht30: humidity is 24.44%.
sht30: temperature is 30.46C.
sht30: humidity is 23.84%.
sht30: set rate 1Hz.
sht30: temperature is 30.59C.
sht30: humidity is 23.82%.
sht30: temperature is 30.69C.
sht30: humidity is 23.76%.
sht30: temperature is 30.59C.
sht30: humidity is 23.62%.
sht30: set rate 2Hz.
sht30: temperature is 30.73C.
sht30: humidity is 23.43%.
sht30: temperature is 30.74C.
sht30: humidity is 23.36%.
sht30: temperature is 30.80C.
sht30: humidity is 23.29%.
sht30: set rate 4Hz.
sht30: temperature is 30.80C.
sht30: humidity is 23.22%.
sht30: temperature is 30.67C.
sht30: humidity is 23.07%.
sht30: temperature is 30.67C.
sht30: humidity is 23.07%.
sht30: set rate 10Hz.
sht30: temperature is 30.73C.
sht30: humidity is 23.01%.
sht30: temperature is 30.75C.
sht30: humidity is 23.08%.
sht30: temperature is 30.85C.
sht30: humidity is 22.84%.
sht30: set medium repeatability.
sht30: set rate 0.5Hz.
sht30: temperature is 30.73C.
sht30: humidity is 23.01%.
sht30: temperature is 30.74C.
sht30: humidity is 22.99%.
sht30: temperature is 30.77C.
sht30: humidity is 22.94%.
sht30: set rate 1Hz.
sht30: temperature is 30.78C.
sht30: humidity is 22.78%.
sht30: temperature is 30.78C.
sht30: humidity is 22.80%.
sht30: temperature is 30.77C.
sht30: humidity is 22.80%.
sht30: set rate 2Hz.
sht30: temperature is 30.77C.
sht30: humidity is 22.72%.
sht30: temperature is 30.80C.
sht30: humidity is 22.78%.
sht30: temperature is 30.75C.
sht30: humidity is 22.68%.
sht30: set rate 4Hz.
sht30: temperature is 30.81C.
sht30: humidity is 22.70%.
sht30: temperature is 30.80C.
sht30: humidity is 22.82%.
sht30: temperature is 30.77C.
sht30: humidity is 22.70%.
sht30: set rate 10Hz.
sht30: temperature is 30.83C.
sht30: humidity is 22.77%.
sht30: temperature is 30.77C.
sht30: humidity is 23.01%.
sht30: temperature is 30.83C.
sht30: humidity is 22.93%.
sht30: set high repeatability.
sht30: set rate 0.5Hz.
sht30: temperature is 30.84C.
sht30: humidity is 23.02%.
sht30: temperature is 30.78C.
sht30: humidity is 22.98%.
sht30: temperature is 30.78C.
sht30: humidity is 22.83%.
sht30: set rate 1Hz.
sht30: temperature is 30.80C.
sht30: humidity is 22.78%.
sht30: temperature is 30.83C.
sht30: humidity is 22.77%.
sht30: temperature is 30.78C.
sht30: humidity is 22.72%.
sht30: set rate 2Hz.
sht30: temperature is 30.88C.
sht30: humidity is 22.84%.
sht30: temperature is 30.80C.
sht30: humidity is 22.72%.
sht30: temperature is 30.78C.
sht30: humidity is 22.73%.
sht30: set rate 4Hz.
sht30: temperature is 30.85C.
sht30: humidity is 22.84%.
sht30: temperature is 30.77C.
sht30: humidity is 22.75%.
sht30: temperature is 30.78C.
sht30: humidity is 22.78%.
sht30: set rate 10Hz.
sht30: temperature is 30.71C.
sht30: humidity is 22.80%.
sht30: temperature is 30.78C.
sht30: humidity is 22.78%.
sht30: temperature is 30.77C.
sht30: humidity is 22.70%.
sht30: single read.
sht30: set low repeatability.
sht30: temperature is 30.83C.
sht30: humidity is 22.64%.
sht30: temperature is 30.85C.
sht30: humidity is 22.79%.
sht30: temperature is 30.74C.
sht30: humidity is 22.76%.
sht30: set medium repeatability.
sht30: temperature is 30.73C.
sht30: humidity is 22.70%.
sht30: temperature is 30.75C.
sht30: humidity is 22.70%.
sht30: temperature is 30.78C.
sht30: humidity is 22.90%.
sht30: set high repeatability.
sht30: temperature is 30.75C.
sht30: humidity is 22.78%.
sht30: temperature is 30.73C.
sht30: humidity is 22.80%.
sht30: temperature is 30.73C.
sht30: humidity is 22.80%.
sht30: disable clock stretching.
sht30: temperature is 30.73C.
sht30: humidity is 22.76%.
sht30: temperature is 30.73C.
sht30: humidity is 22.81%.
sht30: temperature is 30.73C.
sht30: humidity is 22.76%.
sht30: finish read test.
```

```shell
sht30 -e read --addr=0 --times=3

sht30: 1/3.
sht30: temperature is 29.91C.
sht30: humidity is 23.97%.
sht30: 2/3.
sht30: temperature is 29.61C.
sht30: humidity is 24.28%.
sht30: 3/3.
sht30: temperature is 29.46C.
sht30: humidity is 24.75%.
```

```shell
sht30 -e shot --addr=0 --times=3

sht30: 1/3.
sht30: temperature is 28.50C.
sht30: humidity is 25.78%.
sht30: 2/3.
sht30: temperature is 28.47C.
sht30: humidity is 25.78%.
sht30: 3/3.
sht30: temperature is 28.43C.
sht30: humidity is 25.76%.
```

```shell
sht30 -h

Usage:
  sht30 (-i | --information)
  sht30 (-h | --help)
  sht30 (-p | --port)
  sht30 (-t reg | --test=reg) [--addr=<0 | 1>]
  sht30 (-t read | --test=read) [--addr=<0 | 1>] [--times=<num>]
  sht30 (-e read | --example=read) [--addr=<0 | 1>] [--times=<num>]
  sht30 (-e shot | --example=shot) [--addr=<0 | 1>] [--times=<num>]

Options:
      --addr=<0 | 1>    Set the addr pin.([default: 0])
  -e <read | shot>, --example=<read | shot>
                        Run the driver example.
  -h, --help            Show the help.
  -i, --information     Show the chip information.
  -p, --port            Display the pin connections of the current board.
  -t <reg | read>, --test=<reg | read>
                        Run the driver test.
      --times=<num>     Set the running times.([default: 3])
```

