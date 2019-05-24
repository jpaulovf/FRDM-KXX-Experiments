# KL25 Internal Flash example

## Test project to perform R/W operations on KL25Z internal flash

---

This code was based on the one in [MCU On Eclipse's](https://mcuoneclipse.com/2014/05/31/configuration-data-using-the-internal-flash-instead-of-an-external-eeprom/) blog.

I used the KDS IDE with Processor Expert. You can import the project into your workspace to compile the code.

The board I used to test this code is the FRDM-KL25Z. In order to run the test, you will need an USB cable to communicate with the OpenSDA serial port on the board. The baud rate is 115200. I recommend using a terminal that supports colored strings, such as putty (Linux) or TeraTerm (Windows). 
