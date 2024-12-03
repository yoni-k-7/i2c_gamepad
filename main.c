#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
 
#define I2C_BUS "/dev/i2c-2" // I2C bus 2
#define DEVICE_ADDR 0x30     // Device address
#define READ_REG 0x68        // Register to read
#define WRITE_REG 0x69       // Register to write
#define WRITE_VALUE 0xAB     // Value to write
 
int main() {
    int fd;
    char buf[2];
 
    // Open the I2C bus
    if ((fd = open(I2C_BUS, O_RDWR)) < 0) {
        perror("Failed to open the I2C bus");
        return 1;
    }
 
    // Set the I2C slave address
    if (ioctl(fd, I2C_SLAVE, DEVICE_ADDR) < 0) {
        perror("Failed to set I2C slave address");
        close(fd);
        return 1;
    }
 
    // Write to the register
    buf[0] = WRITE_REG; // Register to write
    buf[1] = WRITE_VALUE; // Value to write
    if (write(fd, buf, 2) != 2) {
        perror("Failed to write to the I2C device");
        close(fd);
        return 1;
    }
    printf("Wrote 0x%02X to register 0x%02X\n", WRITE_VALUE, WRITE_REG);
 
    // Read from the register
    buf[0] = READ_REG; // Register to read
    if (write(fd, buf, 1) != 1) {
        perror("Failed to select register for reading");
        close(fd);
        return 1;
    }
 
    if (read(fd, buf, 1) != 1) {
        perror("Failed to read from the I2C device");
        close(fd);
        return 1;
    }
    printf("Read 0x%02X from register 0x%02X\n", buf[0], READ_REG);
 
    // Close the I2C bus
    close(fd);
    return 0;
}
 
 