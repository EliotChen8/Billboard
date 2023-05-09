<div class="cover" style="page-break-after:always;font-family:方正公文仿宋;width:100%;height:100%;border:none;margin: 0 auto;text-align:center;">
</br></br></br></br></br></br></br></br>
    <div style="width:73%;margin: 0 auto;height:0;padding-bottom:30%;">
        <img src="/Users/tianyangchen/Library/Application Support/typora-user-images/image-20230402010328769.png" alt="校徽" style="width:300%;"/>
	</div>
    <span style="font-family:华文黑体;Bold;text-align:center;font-size:28pt;margin: 10pt auto;line-height:30pt;">电子科学创新实验课程报告</span>
</br></br>
    <p style="text-align:center;font-size:17pt;margin: 0 auto"> STM32 部分第一次作业 </p>
    </br></br></br></br></br></br>
    <table style="border:none;text-align:center;width:66%;font-family:仿宋;font-size:14px; margin: 0 auto;">
    <tbody style="font-family:方正公文仿宋;font-size:13pt;">
    	<tr style="font-weight:normal;"> 
    		<td style="width:10%;text-align:right;">题　　目</td>
    		<td style="width:2%">：</td> 
    		<td style="width:50%;font-weight:normal;border-bottom: 1px solid;text-align:center;font-family:华文仿宋"> STM32 部分第一次作业 </td>     </tr>
        <div style="display: flex; flex-direction: column; justify-content: center; align-items: center; width: 100%; height: 100%; margin: 0 auto; text-align: center;">
            </br>
    <tr style="font-weight:normal;"> 
    		<td style="width:10%;text-align:right;">姓　　名</td>
    		<td style="width:2%">：</td> 
    		<td style="width:50%;font-weight:normal;border-bottom: 1px solid;text-align:center;font-family:华文仿宋"> 陈天阳 </td>     </tr>
        <tr style="font-weight:normal;"> 
    		<td style="width:10%;text-align:right;">学　　号</td>
    		<td style="width:2%">：</td> 
    		<td style="width:50%;font-weight:normal;border-bottom: 1px solid;text-align:center;font-family:华文仿宋">12111524</td></tr>
        <tr style="font-weight:normal;"> 
    		<td style="width:10%;text-align:right;">系　　别</td>
    		<td style="width:2%">：</td> 
    		<td style="width:50%;font-weight:normal;border-bottom: 1px solid;text-align:center;font-family:华文仿宋"> 电子与电气工程系 </td>     </tr>
        <tr style="font-weight:normal;"> 
    		<td style="width:10%;text-align:right;">专　　业</td>
    		<td style="width:2%">：</td> 
    		<td style="width:50%;font-weight:normal;border-bottom: 1px solid;text-align:center;font-family:华文仿宋">通信工程</td>     </tr>
        <tr style="font-weight:normal;"> 
    		<td style="width:10%;text-align:right;">指导老师</td>
    		<td style="width:2%">：</td> 
    		<td style="width:50%;font-weight:normal;border-bottom: 1px solid;text-align:center;font-family:华文仿宋">王小静</td>     </tr>
</div> 
    </tbody>              
    </table>
</br></br></br>
</div>

<!-- 导出PDF时会在这里分页 -->


# Contents

*You could click the hyperlink in the table of contents to navigate to the corresponding section.*

[TOC]

<!-- 导出PDF时会在这里分页 -->

## Review

### Course Revision

The main topics covered during Weeks 9-11 of the course included an introduction and overview of STM32, the evolution of code, and a detailed examination of firmware libraries. 

The following mindmap is my summary of the knowledge acquired during these three weeks of class.

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506225046028.png" alt="image-20230506225046028" style="zoom:11%;" />

The original image and engineering files of this mindmap are open sourced on my GitHub repository.

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230505232332766.png" alt="image-20230505232332766" style="zoom:30%;" />

<center style="font-size:8pt;">https://github.com/EliotChen8/Billboard/tree/main/2023_SP/EE317%20电子科学创新实验/STM32/HW1</center>



### Requirements

This report is required to contain the following content:

1. **Introduction and Preparation:**
   1. The introduction to STM32;
   2. Modify LED from PB5 to PC13.
2. **Register to Firmware Library:**
   1. Configure PC13 as a pull-up input pin by 2 method refer to the example above:
      1. Firmware library programming;
      2. Register Programming.
3. **Firmware Library:**
   1. Write out the assignment process of each step in the function GPIO_Init (GPIOB, & GPIO_InitStructure);
   2. Sort out the file structure of the official Firmware Library as page27 (mind mapping is recommended).

<!-- 下面一行是翻页代码 -->

<div STYLE="page-break-after: always;"></div>

## Questions and Answers

### Week 9: Introduction and Preparation

#### The *introduction* to STM32

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506012217581.png" alt="image-20230506012217581" style="zoom:33%;" />

**Overview and Developing Environment**

The STM32 is a type of microcontroller **(M)** that is manufactured by STMicroelectronics **(ST)**. It is based on a 32-bit architecture **(32)**, and is designed as a System-on-Chip (SoC).

The STM32 SoC is comprised of several subtopics, including the Cortex-M3 core, which includes a Debug System, Bus, Peripherals, Memory, Clock and Reset, and Input/Output (I/O) components. Additionally, the STM32 SoC includes Direct Memory Access (DMA), Flash memory, Static Random Access Memory (SRAM), and other miscellaneous components.

To use the STM32, a programmer must be familiar with several programming concepts, including the use of the C programming language. This includes an understanding of naming conventions, variables and assignment, data types, format output, type casting, constants, and auto type conversion. Additionally, the programmer must be familiar with programming constructs, such as loops and conditional statements.

To compile code for STM32, the programmer may use the Microcontroller Development Kit (MDK), such as Keil5, which is provided by ARM. It is important to note that the Keil may generate errors, but the programmer should not panic as these errors can be resolved. Additionally, programmer like us must be familiar with the appropriate chip package and need to use keygen to generate a license key, which comes with wonderful music as well.

**Important Learning Materials**

To effectively learn about the STM32 microcontroller, several important learning materials are necessary.

1. The datasheet is a crucial resource that provides an overview of the microcontroller, including its pins, memory mapping, and electrical characteristics. This document is essential for understanding the basic features and capabilities of the STM32;

2. The reference manual is another important resource that provides detailed information on how to configure registers and utilize other advanced features of the microcontroller. It is recommended to refer to the reference manual when programming the STM32;
3. The definitive guide provides an in-depth understanding of the STM32 microcontroller. It covers topics such as the architecture, programming, and advanced features of the microcontroller. This book is highly recommended for those seeking a comprehensive understanding of the STM32;
4. The schematic diagram is a hardware design document that illustrates the layout and connections of the microcontroller and other components on a circuit board. This document is necessary for understanding the physical connections and circuit design of the microcontroller. The following figure shows the hardware design of the circuit board that is going to be focused in this lesson.

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506005129919.png" alt="image-20230506005129919" style="zoom:15%;" />

**Hello World Project: Lighting a LED**

To execute the "Hello World" project of lighting a LED, several steps need to be taken.

1. Prepare the software project by open a well prepared project in the Keil and configure the necessary settings;
2. Prepare the hardware by connecting the PC to the STM32 using the ST-Link debugger and providing power to the microcontroller. It is important to ensure that the connections are correct and the power supply is within the allowable range for the microcontroller;
3. Download the program into the microcontroller using the ST-Link debugger:
   1. Installing the ST-Link driver and configuring the debugger settings to enable communication with the microcontroller;
   2. The target files need to be rebuilt and then downloaded to the flash memory of the microcontroller. 
4. Finally, the result can be observed by checking whether the LED is lit, indicating that the program has successfully executed. 

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/ce145d302ea6279603abb14889950a9f.jpeg" alt="ce145d302ea6279603abb14889950a9f" style="zoom:16%;" />

**Programming mode and Code Analysis**

Programming mode refers to the two ways of programming a microcontroller, namely register programming and firmware library programming. Register programming is a process-oriented approach where individual registers of a microcontroller are directly manipulated, while firmware library programming is an object-oriented approach where the microcontroller peripherals are accessed through high-level function calls that abstract the low-level register operations.

Code analysis is an important step in the programming process that involves analyzing the code to ensure that it meets its intended purpose. This includes examining the schematic diagram to understand the connections and signal flow of the system, as well as analyzing the code to ensure that the I/O ports are set correctly. This involves enabling the clock, initializing the peripherals, setting the output port, setting the output mode to push-pull, and configuring the frequency. Finally, controlling the output data register (ODR) is necessary to set the port's output level.

#### Modify LED from PB5 to PC13

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506010901638.png" alt="image-20230506010901638" style="zoom:30%;" />

Modify LED from PB5 to PC13 needs following steps:

1. **Determine the address of the GPIOC port clock and the bit number of IOPC, and enable the GPIOC port clock:**

   In the reference manual, the address of the GPIOC port clock can be identified. 

   <img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506023913201.png" alt="image-20230506023913201" style="zoom:32%;" />

   Additionally, the boundary address of the reset and clock control RCC can be determined by consulting the memory map in the reference manual. 

   <img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/f323da87da2334f7f0e97d702a340b59.png" alt="f323da87da2334f7f0e97d702a340b59" style="zoom:32%;" />

   Based on this information, the GPIOC port clock can be enabled.

   ```c
   int main (void)
   {
   // enable GPIOC port clock
   *( unsigned int * )0x40021018 |= ( (1) << 4 );
   ```

2. **Output Settings:**

   First, we need to determine the address of the output port. As our target port, PC13, is in the high byte, we refer to the CRH address. The port address is the base address plus the offset address: 0x04 + 0x40011000 = 0x40011004.

   <img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506025726436.png" alt="image-20230506025726436" style="zoom:44%;" />

   Next, we set the output mode to push-pull output with a speed of 10MHz, which corresponds to the binary code 0001 at bits 23, 22, 21, and 20. This is equivalent to the hexadecimal value of 0x00100000.

   <img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/6355ec27a3874e140bb233db6d3ec906.jpeg" alt="6355ec27a3874e140bb233db6d3ec906" style="zoom:40%;" />

   Based on the above analysis, we can now set the port output.

   ```c
   // Configure the IO port PC13 as output, push-pull, and speed of 10MHz
   // Clear the corresponding bits in GPIOC's configuration register to set the output mode to push-pull and the output speed to 10MHz.
   *(unsigned int*)0x40011004 &= 0xFF0FFFFF; 
   // 0xFF0FFFFF represents the binary value of 11111111000000001111111111111111 in hexadecimal notation, which clears the 20th bit in the configuration register.
   // The & operator performs a bitwise AND operation with the current value in the configuration register.
   // The first step is to clear the corresponding bit to set the output mode to push-pull.
    
   // Set the corresponding bit in GPIOC's configuration register to set the output mode to push-pull.
   // 0x00100000 represents the binary value of 00000000000100000000000000000000 in hexadecimal notation, which sets the 20th bit in the configuration register.
   // The | operator performs a bitwise OR operation with the current value in the configuration register.
   *(unsigned int*)0x40011004 |= 0x00100000;
   ```

3. **Control ODR register:**

   To light up the LED, we need to set the output port to low level. To achieve this, we first need to find the circuit diagram for the LED on the target port. 

   <img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506030344617.png" alt="image-20230506030344617" style="zoom:15%;" />

From the diagram, we can see that a low-level signal is needed to light up the LED. We then refer to the GPIO output configuration table and find that the ODR register can be used to control the output level of the port.

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506031214485.png" alt="image-20230506031214485" style="zoom:40%;" />

The address of the ODR register for the target port can be obtained by adding the offset address of the ODR register (0x0C) to the base address of the port (0x40011000). Thus, the address of the ODR register for the target port is 0x40010C0C.

To turn on the LED, we need to set the 13th bit of the ODR register to 0. However, we must first set the 13th bit to 1, and then take the complement of the value before assigning it to the register. Otherwise, all bits of the register will be set to 0. To turn off the LED, we need to set the 13th bit to 1.

In summary, the implementation code is as follows:

```c
// Control ODR register
*(unsigned int*)0x40010C0C &= ~(1<<13); //Turn on LED 

void SystemInit(void)
{
// The function body is empty to trick the compiler into not generating errors. 
}
```

At this point, we have completed the modification of the LED from PB5 to PC13.



### Week 10: Register to Firmware Library

#### Configure PC13 as a pull-up input pin by 2 methods

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506190353952.png" alt="image-20230506190353952" style="zoom:20%;" />

##### Firmware library programming

Firmware library programming differs in structure from register programming. Benefiting from the declarations in header files, which improve the code's readability. During programming, it is necessary to declare the mapping corresponding to the address in the header file to facilitate subsequent programming.

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506193036774.png" alt="image-20230506193036774" style="zoom:30%;" />

Based on the header file, we design the main program, and the code implementation required for this problem is as follows:

```c
// First, initialize GPIO
GPIO_InitTypeDef GPIO_InitStructure;
// Initialize pin 13
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13; // Configured as input mode
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; // Configuration rate (can be omitted in input mode)
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; // Finally, use the Init function to implement the final code
GPIO_Init(GPIOC, &GPIO_InitStructure);
```

##### Register Programming

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506194945419.png" alt="image-20230506194945419" style="zoom:33%;" />

When configuring pull-up/pull-down output, it is necessary to configure ODR as pseudo pull-up/pull-down output.

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506194546561.png" alt="image-20230506194546561" style="zoom:33%;" />

For pull-up input and input mode = 1000, which corresponds to bits 23, 22, 21, and 20, the hexadecimal value is 0x800000.

Generally, the code should be:

```c
// Clear the four bits that control GPIO pin 13 on GPIOC
GPIOC->CRH &= 0xFF0FFFFF;

// Set the four bits to "0010", which corresponds to output mode, push-pull
GPIOC->CRH |= 0x00800000;

// Set bit 13 of the output data register to "1"
GPIOC->ODR |= 0x00002000;
```



### Week 11: Firmware Library

#### Write out the assignment process of each step in the function GPIO_Init

By referring to the official firmware library provided in the course, we can search for keywords to reach the function introduction interface. From the introduction interface, we can determine that the GPIO_Init function is a peripheral initialization function in the firmware library for microcontroller programming. It is utilized to configure the GPIO (General Purpose Input Output) peripheral of the microcontroller based on the specified parameters in the GPIO_InitStruct. The GPIO peripheral is selected using the GPIOx parameter, where x can be A to G to select the corresponding GPIO peripheral. The configuration information for the GPIO peripheral is contained in a structure of type GPIO_InitTypeDef, which is pointed to by the GPIO_InitStruct parameter. This structure contains various configuration parameters for the GPIO peripheral, such as the pin number, mode, speed, and pull-up/pull-down configuration. The function does not return anything (void).

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506215457530.png" alt="image-20230506215457530" style="zoom:23%;" />

Click on the link to jump to the starting position of the function in the code file.

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506215617786.png" alt="image-20230506215617786" style="zoom:17%;" />

Adding comments to the code.

```c
/*------------------- GPIO Mode Configuration -----------------*/

// Set GPIO mode configuration for a specific pin or set of pins
// The low 4 bits of input mode parameters are temporarily stored in 'currentmode'
currentmode = ((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x0F);

// Check bit 4, where 1 is output and 0 is input. Determine if it is output or input.
if ((((uint32_t)GPIO_InitStruct->GPIO_Mode) & ((uint32_t)0x10)) != 0x00)
{ 
  assert_param(IS_GPIO_SPEED(GPIO_InitStruct->GPIO_Speed));
  // For output mode, set the speed
  currentmode |= (uint32_t)GPIO_InitStruct->GPIO_Speed;
}


/*------------------- GPIO CRL Configuration -----------------*/

// Configure GPIO CRL for a specific pin or set of pins
if (((uint32_t)GPIO_InitStruct->GPIO_Pin & ((uint32_t)0x00FF)) != 0x00)
{
  // Backup register value
  tmpreg = GPIOx->CRL;
  // Iterate through pins starting from pin0, find the corresponding pin pair
  for (pinpos = 0x00; pinpos < 0x08; pinpos++)
  {
    // Left shift 1 by pinpos
    pos = ((uint32_t)0x01) << pinpos;
    // Bitwise AND of pos and input parameter for comparison
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;
    // If they are the same, the pin has been found
    if (currentpin == pos)
    {
      // Left shift by 2, equivalent to multiplying by 4
      pos = pinpos << 2;
      // Clear the 4 bits corresponding to the pin and leave the others unchanged
      pinmask = ((uint32_t)0x0F) << pos;
      tmpreg &= ~pinmask;
      // Write the pin mode into the cleared bits
      tmpreg |= (currentmode << pos);

      // Check if it is a pull-down output
      if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
      {
        // Pull-down output, default to 0
        GPIOx->BRR = (((uint32_t)0x01) << pinpos);
      }
      else
      {
        // Check if it is a pull-up output mode
        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
        {
          // Pull-up output, default to 1
          GPIOx->BSRR = (((uint32_t)0x01) << pinpos);
        }
      }
    }
  }
  // Write the processed temporary value into the register
  GPIOx->CRL = tmpreg;
}


/*------------------- GPIO CRH Configuration -----------------*/

  if (GPIO_InitStruct->GPIO_Pin > 0x00FF)
  {
    tmpreg = GPIOx->CRH;
    for (pinpos = 0x00; pinpos < 0x08; pinpos++)
    {
      pos = (((uint32_t)0x01) << (pinpos + 0x08));

      currentpin = ((GPIO_InitStruct->GPIO_Pin) & pos);
      if (currentpin == pos)
      {
        // Calculate the position of the corresponding control bits in the CRH register
        pos = pinpos << 2;

        // Clear the bits corresponding to the pin being configured
        pinmask = ((uint32_t)0x0F) << pos;
        tmpreg &= ~pinmask;

        // Write the pin mode configuration to the CRH register
        tmpreg |= (currentmode << pos);

        // Set the pin output type to Open-Drain if the GPIO mode is set to output with Pull-down
        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPD)
        {
          GPIOx->BRR = (((uint32_t)0x01) << (pinpos + 0x08));
        }

        // Set the pin output type to Push-Pull if the GPIO mode is set to output with Pull-up
        if (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_IPU)
        {
          GPIOx->BSRR = (((uint32_t)0x01) << (pinpos + 0x08));
        }
      }
    }
    // Write the processed value back to the CRH register
    GPIOx->CRH = tmpreg;
  }
```

It can be concluded that during GPIO configuration, the first step is to determine whether it is an input or output mode. If it is an output mode, the output speed needs to be configured. Then, by traversing the pins, it is determined whether the pins are in the range of 0-7 or 8-15, and once the pins are matched, the initialization configuration is completed.

<div STYLE="page-break-after: always;"></div>

#### Sort out the file structure of the official Firmware Library

After analysis, the structure of the official firmware library files is shown below:
*Due to personal proficiency in using XMind to draw mind maps, this software will continue to be used for drawing, please pardon the inconvenience*

<img src="/Users/tianyangchen/Data/2023/SP/EE317电子创新实验/STM32/HW1/HW1Image/image-20230506231931967.png" alt="image-20230506231931967" style="zoom:39%;" />

