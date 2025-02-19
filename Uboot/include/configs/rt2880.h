/*
 * (C) Copyright 2003
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * This file contains the configuration parameters for the RT2880 board.
 */

#ifndef __CONFIG_H
#define __CONFIG_H


#if 0
#define DEBUG				1
#endif

//#define ET_DEBUG

#define CONFIG_RT2880_ETH		1	/* Enable built-in 10/100 Ethernet */

#define CONFIG_MIPS32		1	/* MIPS 4Kc CPU core	*/
//CONFIG_INCA_IP
#if defined (RT3052_FPGA_BOARD) || defined (RT3352_FPGA_BOARD) || \
    defined (RT2883_FPGA_BOARD) || defined (RT3883_FPGA_BOARD) || \
    defined (RT5350_FPGA_BOARD) || defined (RT6855_FPGA_BOARD) || \
    defined (RT6352_FPGA_BOARD) || defined (RT71100_FPGA_BOARD) || \
    defined (RT6855A_FPGA_BOARD)
#define FPGA_BOARD_CLOCK_RATE 40000000
#else
#define FPGA_BOARD_CLOCK_RATE 25000000
#endif
#define PALMCHIP_CLOCK_DIVISOR 16
#define FPGA_BOARD_CLOCK_DIVISOR 32

/* allowed values: 100000000, 133000000, and 150000000 */
#if 1 /* for CFG_HZ only */

#ifdef RT2880_ASIC_BOARD
#define CPU_CLOCK_RATE	266666666 /* default: 150 MHz clock for the MIPS core */
#elif defined (RT3052_ASIC_BOARD)
#define CPU_CLOCK_RATE	384000000 
#elif defined (RT3352_ASIC_BOARD)
#define CPU_CLOCK_RATE	400000000 
#elif defined (RT6855_ASIC_BOARD) || defined (RT6855A_ASIC_BOARD)
#define CPU_CLOCK_RATE	500000000 
#elif defined (RT6352_ASIC_BOARD)
#define CPU_CLOCK_RATE	600000000 
#elif defined (RT71100_ASIC_BOARD)
#define CPU_CLOCK_RATE	400000000 
#elif defined (RT2883_ASIC_BOARD)
#define CPU_CLOCK_RATE	400000000 
#elif defined (RT3883_ASIC_BOARD)
#define CPU_CLOCK_RATE	500000000 
#elif defined (RT5350_ASIC_BOARD)
#define CPU_CLOCK_RATE	360000000 
#else
#define CPU_CLOCK_RATE	FPGA_BOARD_CLOCK_RATE /* default: 150 MHz clock for the MIPS core */
#endif

#endif

#define SERIAL_CLOCK_DIVISOR 16

#define CONFIG_BOOTDELAY 5 /* autoboot after 30 seconds	*/

#define CONFIG_WEBGPIO	0	/* use gpio 0 to trigger webpage	*/

#define CONFIG_BAUDRATE  57600

#define CONFIG_SERVERIP 192.168.1.240
#define CONFIG_IPADDR 192.168.1.1
#define CONFIG_NETCONSOLE 192.168.1.240
#define CONFIG_ETHADDR "00:AA:BB:CC:DD:10"
/* valid baudrates */
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

#define	CONFIG_TIMESTAMP		/* Print image info with timestamp */

#undef	CONFIG_BOOTARGS

#define	CONFIG_EXTRA_ENV_SETTINGS					\
	"ramargs=setenv bootargs root=/dev/ram rw\0"			\
	"addip=setenv bootargs $(bootargs) "				\
		"ip=$(ipaddr):$(serverip):$(gatewayip):$(netmask)"	\
		":$(hostname):$(netdev):off\0"				\
	"addmisc=setenv bootargs $(bootargs) "				\
		"console=ttyS0,$(baudrate) "				\
		"ethaddr=$(ethaddr) "					\
		"panic=1\0"						\
	"flash_self=run ramargs addip addmisc;"				\
		"bootm $(kernel_addr) $(ramdisk_addr)\0"		\
	"kernel_addr=BFC40000\0"					\
	"u-boot=u-boot.bin\0"				\
	"load=tftp 8A100000 $(u-boot)\0"				\
	"u_b=protect off 1:0-1;era 1:0-1;"				\
		"cp.b 8A100000 BC400000 $(filesize)\0"			\
	"loadfs=tftp 8A100000 root.cramfs\0"				\
	"u_fs=era bc540000 bc83ffff;"				\
		"cp.b 8A100000 BC540000 $(filesize)\0"			\
	"test_tftp=tftp 8A100000 root.cramfs;run test_tftp\0"				\
	""
#define CONFIG_BOOTCOMMAND	"tftp" //"run flash_self"


#include <cmd_confdefs.h>

/*
 * Miscellaneous configurable options
 */
#define	CFG_LONGHELP				/* undef to save memory      */

#if defined (RT2880_FPGA_BOARD) || defined (RT2880_ASIC_BOARD) 
#define	CFG_PROMPT		"RT2880 # "
#elif defined (RT2883_FPGA_BOARD) || defined (RT2883_ASIC_BOARD) 
#define	CFG_PROMPT		"RT2883 # "
#elif defined (RT3052_FPGA_BOARD) || defined (RT3052_ASIC_BOARD) 
#define	CFG_PROMPT		"RT3052 # "
#elif defined (RT3352_FPGA_BOARD) || defined (RT3352_ASIC_BOARD) 
#define	CFG_PROMPT		"RT3352 # "
#elif defined (RT3883_FPGA_BOARD) || defined (RT3883_ASIC_BOARD) 
#define	CFG_PROMPT		"RT3883 # "
#elif defined (RT5350_FPGA_BOARD) || defined (RT5350_ASIC_BOARD) 
#define	CFG_PROMPT		"RT5350 # "
#elif defined (RT6855_FPGA_BOARD) || defined (RT6855_ASIC_BOARD) 
#define	CFG_PROMPT		"RT6855 # "
#elif defined (RT6855A_FPGA_BOARD) || defined (RT6855A_ASIC_BOARD) 
#define	CFG_PROMPT		"RT6855A # "
#elif defined (RT6352_FPGA_BOARD) || defined (RT6352_ASIC_BOARD) 
#define	CFG_PROMPT		"RT6352 # "
#elif defined (RT71100_FPGA_BOARD) || defined (RT71100_ASIC_BOARD) 
#define	CFG_PROMPT		"RT71100 # "
#else
#define	CFG_PROMPT		"RTxxxx # "
#endif
#define	CFG_CBSIZE		256		/* Console I/O Buffer Size   */
#define	CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16)  /* Print Buffer Size */
#define	CFG_MAXARGS		16		/* max number of command args*/

#define CFG_MALLOC_LEN		256*1024

#define CFG_BOOTPARAMS_LEN	128*1024

#define CFG_HZ			CPU_CLOCK_RATE/2

#if defined (RT2880_FPGA_BOARD) || defined (RT2880_ASIC_BOARD)
#define CFG_SDRAM_BASE		0x8A000000
#else
#define CFG_SDRAM_BASE		0x80000000
#endif


/* 
 * for TEST 
 */
#define CFG_CONSOLE_INFO_QUIET	

#if defined (RT2880_FPGA_BOARD) || defined (RT2880_ASIC_BOARD)
#define	CFG_LOAD_ADDR		0x8A100000	/* default load address	*/
#define CFG_HTTP_DL_ADDR	0x8A300000

#define CFG_MEMTEST_START	0x8A100000
#define CFG_MEMTEST_END		0x8A400000
#else
#define	CFG_LOAD_ADDR		0x80100000	/* default load address	*/
#define CFG_HTTP_DL_ADDR	0x80300000
#if defined(RT6855A_FPGA_BOARD) || defined(RT6855A_ASIC_BOARD)
#define CFG_SPINAND_LOAD_ADDR	0x80c00000
#else
#define CFG_SPINAND_LOAD_ADDR 0x80300000
#endif

#define CFG_MEMTEST_START	0x80100000
#define CFG_MEMTEST_END		0x80400000
#endif


#define CFG_EMBEDED_SRAM_START 0xA0800000
#define CFG_EMBEDED_SRAM_FOR_RXRING0_DESC 0xA0800000
#define CFG_EMBEDED_SRAM_FOR_TXRING0_DESC 0xA0800100
#define CFG_EMBEDED_SRAM_FOR_TXRING1_DESC 0xA0800200
#define CFG_EMBEDED_SRAM_BUF_START 0xA0800300
#define CFG_EMBEDED_SRAM_SDP0_BUF_START 0xA0804000
#define CFG_EMBEDED_SRAM_END   0xA0807FFF

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CFG_MAX_FLASH_BANKS	1	/* max number of memory banks */
#define CFG_MAX_FLASH_SECT	(263)	/* max number of sectors on one chip */

#if defined (RT2880_FPGA_BOARD) || defined (RT2880_ASIC_BOARD)
#ifdef DUAL_IMAGE_SUPPORT
#define PHYS_FLASH_START	0xBC000000 /* Address for issuing flash command */
#if defined (ON_BOARD_2M_FLASH_COMPONENT)
#define PHYS_FLASH_1		0xBC000000 /* Image1 Bank #1 */
#define PHYS_FLASH2_1		0xBC100000 /* Image2 Bank #1 */
#elif defined (ON_BOARD_4M_FLASH_COMPONENT)
#define PHYS_FLASH_1		0xBC000000 /* Image1 Bank #1 */
#define PHYS_FLASH2_1		0xBC200000 /* Image2 Bank #1 */
#elif defined (ON_BOARD_8M_FLASH_COMPONENT)
#define PHYS_FLASH_1		0xBC400000 /* Image1 Bank #1 */
#define PHYS_FLASH_2		0xBC000000 /* Image1 Bank #2 */
#define PHYS_FLASH2_1		0xBC000000 /* Image2 Bank #1 */
#elif defined (ON_BOARD_16M_FLASH_COMPONENT)
#define PHYS_FLASH_1		0xBCC00000 /* Image1 Bank #1 */
#define PHYS_FLASH_2		0xBC000000 /* Image1 Bank #2 */
#define PHYS_FLASH2_1		0xBC400000 /* Image2 Bank #1 */
#define PHYS_FLASH2_2		0xBC800000 /* Image2 Bank #2 */
#endif 
#else //Non Dual Image
#ifdef ON_BOARD_8M_FLASH_COMPONENT
#define PHYS_FLASH_1		0xBC400000 /* Flash Bank #1 */
#else
#define PHYS_FLASH_1		0xBCC00000 /* Flash Bank #1 */
#endif
#define PHYS_FLASH_2		0xBC000000 /* Flash Bank #2 */
#if defined (ON_BOARD_8M_FLASH_COMPONENT) || defined (ON_BOARD_16M_FLASH_COMPONENT)
#define PHYS_FLASH_START	PHYS_FLASH_2 /* Address for issuing flash command */
#else
#define PHYS_FLASH_START	PHYS_FLASH_1 /* Address for issuing flash command */
#endif
#endif
#elif defined (RT2883_FPGA_BOARD) || defined (RT2883_ASIC_BOARD) || \
      defined (RT3883_FPGA_BOARD) || defined (RT3883_ASIC_BOARD) || \
      defined (RT3352_FPGA_BOARD) || defined (RT3352_ASIC_BOARD) || \
      defined (RT5350_FPGA_BOARD) || defined (RT5350_ASIC_BOARD) || \
      defined (RT6855_FPGA_BOARD) || defined (RT6855_ASIC_BOARD) || \
      defined (RT6352_FPGA_BOARD) || defined (RT6352_ASIC_BOARD) || \
      defined (RT71100_FPGA_BOARD) || defined (RT71100_ASIC_BOARD)
#define PHYS_FLASH_START	0xBC000000 /* Flash Bank #2 */
#define PHYS_FLASH_1		0xBC000000 /* Flash Bank #1 */
  #ifdef DUAL_IMAGE_SUPPORT
  #if defined (ON_BOARD_2M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBC100000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_4M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBC200000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_8M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBC400000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_16M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBC800000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_32M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBD000000 /* Flash Bank #2 */
  #endif
  #endif // DUAL_IMAGE_SUPPORT
#elif defined (RT3052_FPGA_BOARD) || defined (RT3052_ASIC_BOARD)
  // RT3052_MP2 and 32M_FLASH
  #define PHYS_FLASH_START	0xBF000000 /* Address for issuing flash command */
  #define PHYS_FLASH_1		0xBF000000 /* Flash Bank #1 */
  #ifdef DUAL_IMAGE_SUPPORT
  #if defined (ON_BOARD_2M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBF100000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_4M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBF200000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_8M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBF400000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_16M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBF800000 /* Flash Bank #2 */
  #elif defined (ON_BOARD_32M_FLASH_COMPONENT)
  #define PHYS_FLASH2_1		0xBB000000 /* Flash Bank #2 */
  #undef CFG_MAX_FLASH_BANKS
  #define CFG_MAX_FLASH_BANKS	2
  #endif
  //#define PHYS_FLASH_2		0xBF000000 /* Flash Bank #2 */
  #else // Non Dual Image
  #ifdef ON_BOARD_32M_FLASH_COMPONENT
  #define PHYS_FLASH2_START	0xBB000000 /* Flash Bank #2 */
  #define PHYS_FLASH_2		0xBB000000 /* Flash Bank #2 */
  #undef CFG_MAX_FLASH_BANKS
  #define CFG_MAX_FLASH_BANKS	2
  #endif
 #endif
#elif defined (RT6855A_FPGA_BOARD) || defined (RT6855A_ASIC_BOARD)
#define PHYS_FLASH_1		0xB0000000
#endif // defined (RT2880_FPGA_BOARD) || defined (RT2880_ASIC_BOARD)

/* The following #defines are needed to get flash environment right */
#define	CFG_MONITOR_BASE	TEXT_BASE

#define	CFG_MONITOR_LEN		(192 << 10)

#define CFG_INIT_SP_OFFSET	0x400000

#define CFG_FLASH_BASE		PHYS_FLASH_1
#ifdef DUAL_IMAGE_SUPPORT
#define CFG_FLASH2_BASE		PHYS_FLASH2_1
#endif

/* timeout values are in ticks */
#define CFG_FLASH_ERASE_TOUT	(15UL * CFG_HZ) /* Timeout for Flash Erase */
#define CFG_FLASH_WRITE_TOUT	(5 * CFG_HZ) /* Timeout for Flash Write */
#define CFG_ETH_AN_TOUT	(5 * CFG_HZ) /* Timeout for Flash Write */
#define CFG_ETH_LINK_UP_TOUT	(5 * CFG_HZ) /* Timeout for Flash Write */
#define CFG_FLASH_STATE_DISPLAY_TOUT  (2 * CFG_HZ) /* Timeout for Flash Write */

#if defined (ON_BOARD_32M_FLASH_COMPONENT) && !defined (DUAL_IMAGE_SUPPORT)
#define CFG_BOOTLOADER_SIZE	0x40000
#define CFG_CONFIG_SIZE		0x20000
#define CFG_FACTORY_SIZE	0x20000
#define CFG_ENV_ADDR		(PHYS_FLASH_2 + 0x1000000 - CFG_BOOTLOADER_SIZE)
#define CFG_FACTORY_ADDR	(PHYS_FLASH_2 + 0x1000000 - CFG_FACTORY_SIZE)
#define CFG_KERN_ADDR		(CFG_FLASH_BASE + CFG_BOOTLOADER_SIZE)
#define CFG_KERN2_ADDR		(CFG_FLASH2_BASE + CFG_BOOTLOADER_SIZE)
#else
#define CFG_BOOTLOADER_SIZE	0x30000
#define CFG_CONFIG_SIZE		0x10000
#define CFG_FACTORY_SIZE	0x10000

#define CFG_ENV_ADDR		(CFG_FLASH_BASE + CFG_BOOTLOADER_SIZE)
#define CFG_FACTORY_ADDR	(CFG_FLASH_BASE + CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE)
#define CFG_KERN_ADDR		(CFG_FLASH_BASE + (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#ifdef DUAL_IMAGE_SUPPORT
#define CFG_KERN2_ADDR		(CFG_FLASH2_BASE + (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#endif
#endif

#define CFG_ENV_SECT_SIZE	CFG_CONFIG_SIZE
#define CFG_ENV_SIZE		0x1000

#if defined (DUAL_IMAGE_SUPPORT)
#if defined (ON_BOARD_2M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x100000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#elif defined (ON_BOARD_4M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x200000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#elif defined (ON_BOARD_8M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x400000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#elif defined (ON_BOARD_16M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x800000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#endif
#define CFG_KERN2_SIZE		CFG_KERN_SIZE
#else // Non Dual Image
#if defined (ON_BOARD_2M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x200000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#elif defined (ON_BOARD_4M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x400000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#elif defined (ON_BOARD_8M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x800000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#elif defined (ON_BOARD_16M_FLASH_COMPONENT)
#define CFG_KERN_SIZE		(0x1000000 - (CFG_BOOTLOADER_SIZE + CFG_CONFIG_SIZE + CFG_FACTORY_SIZE))
#endif
#endif

#define CONFIG_FLASH_16BIT

#define CONFIG_NR_DRAM_BANKS	1

#define CONFIG_NET_MULTI
#define CFG_RX_ETH_BUFFER		60

//#define CFG_JFFS2_FIRST_BANK	1
//#define CFG_JFFS2_NUM_BANKS		1

/*-----------------------------------------------------------------------
 * Cache Configuration
 */
#define CFG_DCACHE_SIZE		(16*1024)
#define CFG_ICACHE_SIZE		(16*1024)
#define CFG_CACHELINE_SIZE	16


#define CONFIG_LZMA		1


#define RT2880_REGS_BASE			0xA0000000


/*
 * System Controller	(0x00300000)
 *   Offset
 *   0x10  -- SYSCFG		System Configuration Register
 *   0x30  -- CLKCFG1		Clock Configuration Register
 *   0x34  -- RSTCTRL		Reset Control Register
 *   0x38  -- RSTSTAT		Reset Status Register 
 *   0x60  -- GPIOMODE		GPIO Mode Control Register 
 */
#define RT2880_SYS_CNTL_BASE			(RALINK_SYSCTL_BASE)
#if defined (RT6855A_FPGA_BOARD) || defined (RT6855A_ASIC_BOARD)
#define RT2880_SYSCFG_REG                       (RT2880_SYS_CNTL_BASE+0x8c)
#define RT2880_RSTCTRL_REG                      (RT2880_SYS_CNTL_BASE+0x834)
#define RT2880_RSTSTAT_REG                      (RT2880_SYS_CNTL_BASE+0x38)
#define RT2880_GPIOMODE_REG                     (RT2880_SYS_CNTL_BASE+0x860)
#else
#define RT2880_SYSCFG_REG			(RT2880_SYS_CNTL_BASE+0x10)
#define RT2880_SYSCFG1_REG			(RT2880_SYS_CNTL_BASE+0x14)
#define RT2880_CLKCFG1_REG			(RT2880_SYS_CNTL_BASE+0x30)
#define RT2880_RSTCTRL_REG			(RT2880_SYS_CNTL_BASE+0x34)
#define RT2880_RSTSTAT_REG			(RT2880_SYS_CNTL_BASE+0x38)
#define RT2880_GPIOMODE_REG			(RT2880_SYS_CNTL_BASE+0x60)
#endif

#define RT2880_PRGIO_ADDR       (RALINK_SYSCTL_BASE + 0x600) // Programmable I/O
#define RT2880_REG_PIOINT       (RT2880_PRGIO_ADDR + 0)
#define RT2880_REG_PIOEDGE      (RT2880_PRGIO_ADDR + 0x04)
#define RT2880_REG_PIORENA      (RT2880_PRGIO_ADDR + 0x08)
#define RT2880_REG_PIOFENA      (RT2880_PRGIO_ADDR + 0x0C)
#define RT2880_REG_PIODATA      (RT2880_PRGIO_ADDR + 0x20)
#define RT2880_REG_PIODIR       (RT2880_PRGIO_ADDR + 0x24)

#define RALINK_REG(x)		(*((volatile u32 *)(x)))	
#if defined (RT6855A_FPGA_BOARD) || defined (RT6855A_ASIC_BOARD)
#define ra_inb(offset)		(*(volatile unsigned char *)(offset))
#define ra_inw(offset)		(*(volatile unsigned short *)(offset))
#define ra_inl(offset)		(*(volatile unsigned long *)(offset))

#define ra_outb(offset,val)	(*(volatile unsigned char *)(offset) = val)
#define ra_outw(offset,val)	(*(volatile unsigned short *)(offset) = val)
#define ra_outl(offset,val)	(*(volatile unsigned long *)(offset) = val)

#define ra_and(addr, value) ra_outl(addr, (ra_inl(addr) & (value)))
#define ra_or(addr, value) ra_outl(addr, (ra_inl(addr) | (value)))
#endif
#define RT2880_WDRST            (1<<1)
#define RT2880_SWSYSRST         (1<<2)
#define RT2880_SWCPURST         (1<<3)


#define RT2880_UPHY0_CLK_EN		(1<<18)
#define RT2880_UPHY1_CLK_EN		(1<<20)


/*
* for USB
*/
#ifdef RALINK_USB
#define CONFIG_USB_OHCI		1
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	2
#define CONFIG_SYS_USB_OHCI_REGS_BASE		0x101C1000
#define CONFIG_SYS_USB_OHCI_SLOT_NAME		"rt3680"
#define CONFIG_USB_EHCI		1
#define CONFIG_USB_STORAGE    1
#define CONFIG_DOS_PARTITION
#define LITTLEENDIAN
#define CONFIG_CRC32_VERIFY
#endif /* RALINK_USB */

#endif	/* __CONFIG_H */

/*
 * Web Failsafe configuration
 */

#undef CONFIG_LOADADDR
#define CONFIG_LOADADDR			0x80100000

#define WEBFAILSAFE_UPLOAD_RAM_ADDRESS					0x80300000
#define WEBFAILSAFE_UPLOAD_UBOOT_ADDRESS				CFG_FLASH_BASE

// Firmware partition offset
#if defined(CONFIG_FOR_8DEVICES_CARAMBOLA2)
	#define WEBFAILSAFE_UPLOAD_KERNEL_ADDRESS			WEBFAILSAFE_UPLOAD_UBOOT_ADDRESS + 0x50000
#else
	#define WEBFAILSAFE_UPLOAD_KERNEL_ADDRESS			WEBFAILSAFE_UPLOAD_UBOOT_ADDRESS + 0x20000
#endif

// U-Boot partition size
#if defined(CONFIG_FOR_8DEVICES_CARAMBOLA2)
	#define WEBFAILSAFE_UPLOAD_UBOOT_SIZE_IN_BYTES		(256 * 1024)
#else
	#define WEBFAILSAFE_UPLOAD_UBOOT_SIZE_IN_BYTES		(64 * 1024)
#endif

// ART partition size
#define WEBFAILSAFE_UPLOAD_ART_SIZE_IN_BYTES			(64 * 1024)

// max. firmware size <= (FLASH_SIZE -  WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES)
#if defined(CONFIG_FOR_8DEVICES_CARAMBOLA2)
	// Carambola 2: 256k(U-Boot),64k(U-Boot env),64k(ART)
	#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES	(384 * 1024)
#else
	// TP-Link: 64k(U-Boot),64k(MAC/model/WPS pin block),64k(ART)
	#define WEBFAILSAFE_UPLOAD_LIMITED_AREA_IN_BYTES	(192 * 1024)
#endif

// progress state info
#define WEBFAILSAFE_PROGRESS_START				0
#define WEBFAILSAFE_PROGRESS_TIMEOUT			1
#define WEBFAILSAFE_PROGRESS_UPLOAD_READY		2
#define WEBFAILSAFE_PROGRESS_UPGRADE_READY		3
#define WEBFAILSAFE_PROGRESS_UPGRADE_FAILED		4

// update type
#define WEBFAILSAFE_UPGRADE_TYPE_FIRMWARE		0
#define WEBFAILSAFE_UPGRADE_TYPE_UBOOT			1
#define WEBFAILSAFE_UPGRADE_TYPE_ART			2

/*-----------------------------------------------------------------------*/
#define milisecdelay(_x)			udelay((_x) * 1000)
