### 1. Board

#### 1.1 Board Info

Board Name: Raspberry Pi 4B.

IIC Pin: SCL/SDA GPIO3/GPIO2.

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
sht30: get status test.
sht30: check status 0x8070.
sht30: clear status test.
sht30: check clear status ok.
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
sht30: temperature is 28.24C.
sht30: humidity is 25.53%.
sht30: temperature is 29.19C.
sht30: humidity is 25.28%.
sht30: temperature is 29.47C.
sht30: humidity is 24.69%.
sht30: set rate 1Hz.
sht30: temperature is 29.63C.
sht30: humidity is 24.14%.
sht30: temperature is 29.74C.
sht30: humidity is 23.92%.
sht30: temperature is 29.74C.
sht30: humidity is 23.86%.
sht30: set rate 2Hz.
sht30: temperature is 29.82C.
sht30: humidity is 23.68%.
sht30: temperature is 29.91C.
sht30: humidity is 23.61%.
sht30: temperature is 29.93C.
sht30: humidity is 23.69%.
sht30: set rate 4Hz.
sht30: temperature is 29.87C.
sht30: humidity is 23.80%.
sht30: temperature is 29.93C.
sht30: humidity is 23.66%.
sht30: temperature is 29.99C.
sht30: humidity is 23.52%.
sht30: set rate 10Hz.
sht30: temperature is 29.91C.
sht30: humidity is 23.59%.
sht30: temperature is 30.02C.
sht30: humidity is 23.62%.
sht30: temperature is 29.89C.
sht30: humidity is 23.58%.
sht30: set medium repeatability.
sht30: set rate 0.5Hz.
sht30: temperature is 29.99C.
sht30: humidity is 23.61%.
sht30: temperature is 30.01C.
sht30: humidity is 23.57%.
sht30: temperature is 30.07C.
sht30: humidity is 23.46%.
sht30: set rate 1Hz.
sht30: temperature is 30.12C.
sht30: humidity is 23.43%.
sht30: temperature is 30.09C.
sht30: humidity is 23.35%.
sht30: temperature is 30.15C.
sht30: humidity is 23.45%.
sht30: set rate 2Hz.
sht30: temperature is 30.19C.
sht30: humidity is 23.38%.
sht30: temperature is 30.19C.
sht30: humidity is 23.33%.
sht30: temperature is 30.19C.
sht30: humidity is 23.32%.
sht30: set rate 4Hz.
sht30: temperature is 30.19C.
sht30: humidity is 23.20%.
sht30: temperature is 30.16C.
sht30: humidity is 23.22%.
sht30: temperature is 30.22C.
sht30: humidity is 23.11%.
sht30: set rate 10Hz.
sht30: temperature is 30.23C.
sht30: humidity is 23.22%.
sht30: temperature is 30.23C.
sht30: humidity is 23.26%.
sht30: temperature is 30.23C.
sht30: humidity is 23.21%.
sht30: set high repeatability.
sht30: set rate 0.5Hz.
sht30: temperature is 30.25C.
sht30: humidity is 23.08%.
sht30: temperature is 30.25C.
sht30: humidity is 23.19%.
sht30: temperature is 30.29C.
sht30: humidity is 23.14%.
sht30: set rate 1Hz.
sht30: temperature is 30.32C.
sht30: humidity is 23.20%.
sht30: temperature is 30.33C.
sht30: humidity is 23.08%.
sht30: temperature is 30.36C.
sht30: humidity is 23.02%.
sht30: set rate 2Hz.
sht30: temperature is 30.42C.
sht30: humidity is 23.01%.
sht30: temperature is 30.36C.
sht30: humidity is 22.97%.
sht30: temperature is 30.37C.
sht30: humidity is 22.97%.
sht30: set rate 4Hz.
sht30: temperature is 30.36C.
sht30: humidity is 22.89%.
sht30: temperature is 30.37C.
sht30: humidity is 23.04%.
sht30: temperature is 30.39C.
sht30: humidity is 23.02%.
sht30: set rate 10Hz.
sht30: temperature is 30.36C.
sht30: humidity is 22.90%.
sht30: temperature is 30.39C.
sht30: humidity is 22.97%.
sht30: temperature is 30.42C.
sht30: humidity is 23.01%.
sht30: single read.
sht30: set low repeatability.
sht30: temperature is 30.42C.
sht30: humidity is 23.01%.
sht30: temperature is 30.40C.
sht30: humidity is 23.07%.
sht30: temperature is 30.40C.
sht30: humidity is 23.07%.
sht30: set medium repeatability.
sht30: temperature is 30.39C.
sht30: humidity is 22.99%.
sht30: temperature is 30.40C.
sht30: humidity is 22.99%.
sht30: temperature is 30.40C.
sht30: humidity is 23.05%.
sht30: set high repeatability.
sht30: temperature is 30.44C.
sht30: humidity is 23.11%.
sht30: temperature is 30.43C.
sht30: humidity is 22.96%.
sht30: temperature is 30.44C.
sht30: humidity is 22.99%.
sht30: disable clock stretching.
sht30: temperature is 30.42C.
sht30: humidity is 23.02%.
sht30: temperature is 30.44C.
sht30: humidity is 22.99%.
sht30: temperature is 30.46C.
sht30: humidity is 22.96%.
sht30: finish read test.
```

```shell
./sht30 -e read --addr=0 --times=3

sht30: 1/3.
sht30: temperature is 30.16C.
sht30: humidity is 22.74%.
sht30: 2/3.
sht30: temperature is 29.91C.
sht30: humidity is 22.93%.
sht30: 3/3.
sht30: temperature is 29.72C.
sht30: humidity is 23.19%.
```

```shell
./sht30 -e shot --addr=0 --times=3

sht30: 1/3.
sht30: temperature is 28.75C.
sht30: humidity is 24.78%.
sht30: 2/3.
sht30: temperature is 28.74C.
sht30: humidity is 24.88%.
sht30: 3/3.
sht30: temperature is 28.72C.
sht30: humidity is 24.90%.
```

```shell
./sht30 -h

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

