### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

GPIO Pin: INT GPIO17.

### 2. Install

#### 2.1 Dependencies

Install the necessary dependencies.

```shell
sudo apt-get install libgpiod-dev pkg-config cmake -y
```

#### 2.2 Makefile

Build the project.

```shell
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

#### 2.3 CMake

Build the project.

```shell
mkdir build && cd build 
cmake .. 
make
```

Install the project and this is optional.

```shell
sudo make install
```

Uninstall the project and this is optional.

```shell
sudo make uninstall
```

Test the project and this is optional.

```shell
make test
```

Find the compiled library in CMake. 

```cmake
find_package(sht30 REQUIRED)
```

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

6. Run sht30 alert test, ms is the timeout in ms, degree is the degree of limit, percentage is the percentage of limit.

   ```shell
   sht30 (-t alert | --test=alert) [--addr=<0 | 1>] [--timeout=<ms>] [--high-limit-temp=<degree>] [--high-limit-humi=<percentage>][--low-limit-temp=<degree>] [--low-limit-humi=<percentage>]
   ```

7. Run sht30 read function, num is read times.

   ```shell
   sht30 (-e read | --example=read) [--addr=<0 | 1>] [--times=<num>]
   ```

8. Run sht30 shot function, num is read times.

   ```shell
   sht30 (-e shot | --example=shot) [--addr=<0 | 1>] [--times=<num>]
   ```
9. Run sht30 alert function, ms is the timeout in ms, degree is the degree of limit, percentage is the percentage of limit.

   ```shell
   sht30 (-e alert | --example=alert) [--addr=<0 | 1>] [--timeout=<ms>] [--high-limit-temp=<degree>] [--high-limit-humi=<percentage>][--low-limit-temp=<degree>] [--low-limit-humi=<percentage>]
   ```
10. Run sht30 sn function.

    ```shell
   sht30 (-e sn | --example=sn) [--addr=<0 | 1>]
    ```

#### 3.2 Command Example

```shell
./sht30 -i

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
./sht30 -p

sht30: SCL connected to GPIO3(BCM).
sht30: SDA connected to GPIO2(BCM).
sht30: ALERT connected to GPIO17(BCM).
```

```shell
./sht30 -t reg --addr=0

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
sht30: sht30_get_status test.
sht30: check status 0x8070.
sht30: sht30_clear_status test.
sht30: check clear status ok.
sht30: sht30_get_serial_number test.
sht30: serial number is 0x10 0xE2 0x41 0x1F.
sht30: sht30_set_high_alert_limit/sht30_get_high_alert_limit test.
sht30: set is 0xF6F7.
sht30: clear is 0x934B.
sht30: check high alert limit set ok.
sht30: check high alert limit clear ok.
sht30: sht30_set_low_alert_limit/sht30_get_low_alert_limit test.
sht30: set is 0xDADD.
sht30: clear is 0x5609.
sht30: check low alert limit set ok.
sht30: check low alert limit clear ok.
sht30: sht30_alert_limit_convert_to_register test.
sht30: 80.00% 60.00C converted 0xCD33.
sht30: 22.00% -9.00C converted 0x3869.
sht30: finish register test.
```

```shell
./sht30 -t read --addr=0 --times=3

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
sht30: temperature is 29.13C.
sht30: humidity is 27.53%.
sht30: temperature is 29.65C.
sht30: humidity is 27.32%.
sht30: temperature is 29.79C.
sht30: humidity is 26.81%.
sht30: set rate 1Hz.
sht30: temperature is 29.85C.
sht30: humidity is 26.40%.
sht30: temperature is 29.82C.
sht30: humidity is 26.19%.
sht30: temperature is 30.00C.
sht30: humidity is 26.09%.
sht30: set rate 2Hz.
sht30: temperature is 29.93C.
sht30: humidity is 26.09%.
sht30: temperature is 30.02C.
sht30: humidity is 26.05%.
sht30: temperature is 29.96C.
sht30: humidity is 26.00%.
sht30: set rate 4Hz.
sht30: temperature is 29.90C.
sht30: humidity is 25.89%.
sht30: temperature is 29.93C.
sht30: humidity is 26.05%.
sht30: temperature is 29.99C.
sht30: humidity is 25.94%.
sht30: set rate 10Hz.
sht30: temperature is 29.93C.
sht30: humidity is 25.95%.
sht30: temperature is 30.06C.
sht30: humidity is 25.98%.
sht30: temperature is 29.93C.
sht30: humidity is 25.98%.
sht30: set medium repeatability.
sht30: set rate 0.5Hz.
sht30: temperature is 30.02C.
sht30: humidity is 25.99%.
sht30: temperature is 29.96C.
sht30: humidity is 26.00%.
sht30: temperature is 30.03C.
sht30: humidity is 26.26%.
sht30: set rate 1Hz.
sht30: temperature is 30.09C.
sht30: humidity is 26.33%.
sht30: temperature is 30.03C.
sht30: humidity is 26.28%.
sht30: temperature is 30.04C.
sht30: humidity is 26.05%.
sht30: set rate 2Hz.
sht30: temperature is 30.06C.
sht30: humidity is 25.99%.
sht30: temperature is 30.06C.
sht30: humidity is 25.86%.
sht30: temperature is 30.00C.
sht30: humidity is 25.91%.
sht30: set rate 4Hz.
sht30: temperature is 30.09C.
sht30: humidity is 25.95%.
sht30: temperature is 30.07C.
sht30: humidity is 25.89%.
sht30: temperature is 30.09C.
sht30: humidity is 25.90%.
sht30: set rate 10Hz.
sht30: temperature is 30.07C.
sht30: humidity is 25.84%.
sht30: temperature is 30.04C.
sht30: humidity is 25.93%.
sht30: temperature is 30.06C.
sht30: humidity is 25.90%.
sht30: set high repeatability.
sht30: set rate 0.5Hz.
sht30: temperature is 30.06C.
sht30: humidity is 25.95%.
sht30: temperature is 30.07C.
sht30: humidity is 25.95%.
sht30: temperature is 30.07C.
sht30: humidity is 25.95%.
sht30: set rate 1Hz.
sht30: temperature is 30.10C.
sht30: humidity is 26.03%.
sht30: temperature is 30.10C.
sht30: humidity is 25.89%.
sht30: temperature is 30.12C.
sht30: humidity is 25.86%.
sht30: set rate 2Hz.
sht30: temperature is 30.13C.
sht30: humidity is 25.89%.
sht30: temperature is 30.12C.
sht30: humidity is 25.85%.
sht30: temperature is 30.13C.
sht30: humidity is 25.80%.
sht30: set rate 4Hz.
sht30: temperature is 30.14C.
sht30: humidity is 25.62%.
sht30: temperature is 30.12C.
sht30: humidity is 25.75%.
sht30: temperature is 30.12C.
sht30: humidity is 25.78%.
sht30: set rate 10Hz.
sht30: temperature is 30.14C.
sht30: humidity is 25.89%.
sht30: temperature is 30.14C.
sht30: humidity is 25.94%.
sht30: temperature is 30.16C.
sht30: humidity is 25.97%.
sht30: single read.
sht30: set low repeatability.
sht30: temperature is 30.17C.
sht30: humidity is 26.02%.
sht30: temperature is 30.17C.
sht30: humidity is 25.88%.
sht30: temperature is 30.10C.
sht30: humidity is 25.95%.
sht30: set medium repeatability.
sht30: temperature is 30.16C.
sht30: humidity is 25.86%.
sht30: temperature is 30.16C.
sht30: humidity is 25.89%.
sht30: temperature is 30.17C.
sht30: humidity is 25.88%.
sht30: set high repeatability.
sht30: temperature is 30.16C.
sht30: humidity is 25.89%.
sht30: temperature is 30.16C.
sht30: humidity is 25.91%.
sht30: temperature is 30.17C.
sht30: humidity is 25.91%.
sht30: disable clock stretching.
sht30: temperature is 30.16C.
sht30: humidity is 25.92%.
sht30: temperature is 30.20C.
sht30: humidity is 25.94%.
sht30: temperature is 30.17C.
sht30: humidity is 25.86%.
sht30: finish read test.
```

```shell
./sht30 -t alert --addr=0 --timeout=10000 --high-limit-temp=30.0 --high-limit-humi=50.0 --low-limit-temp=25.0 --low-limit-humi=30.0

sht30: chip is Sensirion SHT30.
sht30: manufacturer is Sensirion.
sht30: interface is IIC.
sht30: driver version is 2.0.
sht30: min supply voltage is 2.4V.
sht30: max supply voltage is 5.5V.
sht30: max current is 1.50mA.
sht30: max temperature is 125.0C.
sht30: min temperature is -40.0C.
sht30: start alert test.
sht30: high limit temperature is 30.00C.
sht30: high limit humidity is 50.00%.
sht30: low limit temperature is 25.00C.
sht30: low limit humidity is 30.00%.
sht30: irq alert pending status.
sht30: irq humidity alert.
sht30: irq temperature alert.
sht30: finish alert test.
```

```shell
./sht30 -e read --addr=0 --times=3

sht30: 1/3.
sht30: temperature is 29.59C.
sht30: humidity is 25.88%.
sht30: 2/3.
sht30: temperature is 29.44C.
sht30: humidity is 26.00%.
sht30: 3/3.
sht30: temperature is 29.35C.
sht30: humidity is 26.11%.
```

```shell
./sht30 -e shot --addr=0 --times=3

sht30: 1/3.
sht30: temperature is 29.14C.
sht30: humidity is 26.40%.
sht30: 2/3.
sht30: temperature is 29.13C.
sht30: humidity is 26.43%.
sht30: 3/3.
sht30: temperature is 29.13C.
sht30: humidity is 26.47%.
```

```shell
./sht30 -e alert --addr=0 --timeout=10000 --high-limit-temp=30.0 --high-limit-humi=50.0 --low-limit-temp=25.0 --low-limit-humi=30.0

sht30: high limit temperature is 30.00C.
sht30: high limit humidity is 50.00%.
sht30: low limit temperature is 25.00C.
sht30: low limit humidity is 30.00%.
sht30: irq alert pending status.
sht30: irq humidity alert.
sht30: irq temperature alert.
sht30: finish.
```

```shell
./sht30 -e sn --addr=0

sht30: serial number is 0x10 0xE2 0x41 0x1F.
```

```shell
./sht30 -h

Usage:
  sht30 (-i | --information)
  sht30 (-h | --help)
  sht30 (-p | --port)
  sht30 (-t reg | --test=reg) [--addr=<0 | 1>]
  sht30 (-t read | --test=read) [--addr=<0 | 1>] [--times=<num>]
  sht30 (-t alert | --test=alert) [--addr=<0 | 1>] [--timeout=<ms>] [--high-limit-temp=<degree>] [--high-limit-humi=<percentage>]
        [--low-limit-temp=<degree>] [--low-limit-humi=<percentage>]
  sht30 (-e read | --example=read) [--addr=<0 | 1>] [--times=<num>]
  sht30 (-e shot | --example=shot) [--addr=<0 | 1>] [--times=<num>]
  sht30 (-e alert | --example=alert) [--addr=<0 | 1>] [--timeout=<ms>] [--high-limit-temp=<degree>] [--high-limit-humi=<percentage>]
        [--low-limit-temp=<degree>] [--low-limit-humi=<percentage>]

Options:
      --addr=<0 | 1>    Set the addr pin.([default: 0])
  -e <read | shot | alert | sn>, --example=<read | shot | alert | sn>
                        Run the driver example.
      --low-limit-temp  Low limit temperature in degress.([default: 25.0])
      --low-limit-humi  Low limit humidity in percentage.([default: 30.0])
  -h, --help            Show the help.
      --high-limit-temp High limit temperature in degress.([default: 30.0])
      --high-limit-humi High limit humidity in percentage.([default: 50.0])
  -i, --information     Show the chip information.
  -p, --port            Display the pin connections of the current board.
  -t <reg | read | alert>, --test=<reg | read | alert>
                        Run the driver test.
      --times=<num>     Set the running times.([default: 3])
      --timeout=<ms>    Set timeout in ms.([default: 10000])
```

