#ifndef TM4C123GH6PM_REGISTERS
#define TM4C123GH6PM_REGISTERS

#include "std_types.h"

/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_DATA_REG       (*((volatile uint32 *)0x400043FC))
#define GPIO_PORTA_DIR_REG        (*((volatile uint32 *)0x40004400))
#define GPIO_PORTA_AFSEL_REG      (*((volatile uint32 *)0x40004420))
#define GPIO_PORTA_PUR_REG        (*((volatile uint32 *)0x40004510))
#define GPIO_PORTA_PDR_REG        (*((volatile uint32 *)0x40004514))
#define GPIO_PORTA_DEN_REG        (*((volatile uint32 *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       (*((volatile uint32 *)0x40004520))
#define GPIO_PORTA_CR_REG         (*((volatile uint32 *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      (*((volatile uint32 *)0x40004528))
#define GPIO_PORTA_PCTL_REG       (*((volatile uint32 *)0x4000452C))

/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         (*((volatile uint32 *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile uint32 *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile uint32 *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile uint32 *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile uint32 *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile uint32 *)0x4000441C))

/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       (*((volatile uint32 *)0x400053FC))
#define GPIO_PORTB_DIR_REG        (*((volatile uint32 *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      (*((volatile uint32 *)0x40005420))
#define GPIO_PORTB_PUR_REG        (*((volatile uint32 *)0x40005510))
#define GPIO_PORTB_PDR_REG        (*((volatile uint32 *)0x40005514))
#define GPIO_PORTB_DEN_REG        (*((volatile uint32 *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       (*((volatile uint32 *)0x40005520))
#define GPIO_PORTB_CR_REG         (*((volatile uint32 *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      (*((volatile uint32 *)0x40005528))
#define GPIO_PORTB_PCTL_REG       (*((volatile uint32 *)0x4000552C))

/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         (*((volatile uint32 *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile uint32 *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile uint32 *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile uint32 *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile uint32 *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile uint32 *)0x4000541C))

/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG       (*((volatile uint32 *)0x400063FC))
#define GPIO_PORTC_DIR_REG        (*((volatile uint32 *)0x40006400))
#define GPIO_PORTC_AFSEL_REG      (*((volatile uint32 *)0x40006420))
#define GPIO_PORTC_PUR_REG        (*((volatile uint32 *)0x40006510))
#define GPIO_PORTC_PDR_REG        (*((volatile uint32 *)0x40006514))
#define GPIO_PORTC_DEN_REG        (*((volatile uint32 *)0x4000651C))
#define GPIO_PORTC_LOCK_REG       (*((volatile uint32 *)0x40006520))
#define GPIO_PORTC_CR_REG         (*((volatile uint32 *)0x40006524))
#define GPIO_PORTC_AMSEL_REG      (*((volatile uint32 *)0x40006528))
#define GPIO_PORTC_PCTL_REG       (*((volatile uint32 *)0x4000652C))

/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         (*((volatile uint32 *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile uint32 *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile uint32 *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile uint32 *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile uint32 *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile uint32 *)0x4000641C))

/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG       (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTD_DIR_REG        (*((volatile uint32 *)0x40007400))
#define GPIO_PORTD_AFSEL_REG      (*((volatile uint32 *)0x40007420))
#define GPIO_PORTD_PUR_REG        (*((volatile uint32 *)0x40007510))
#define GPIO_PORTD_PDR_REG        (*((volatile uint32 *)0x40007514))
#define GPIO_PORTD_DEN_REG        (*((volatile uint32 *)0x4000751C))
#define GPIO_PORTD_LOCK_REG       (*((volatile uint32 *)0x40007520))
#define GPIO_PORTD_CR_REG         (*((volatile uint32 *)0x40007524))
#define GPIO_PORTD_AMSEL_REG      (*((volatile uint32 *)0x40007528))
#define GPIO_PORTD_PCTL_REG       (*((volatile uint32 *)0x4000752C))

/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         (*((volatile uint32 *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile uint32 *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile uint32 *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile uint32 *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile uint32 *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile uint32 *)0x4000741C))

/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG       (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTE_DIR_REG        (*((volatile uint32 *)0x40024400))
#define GPIO_PORTE_AFSEL_REG      (*((volatile uint32 *)0x40024420))
#define GPIO_PORTE_PUR_REG        (*((volatile uint32 *)0x40024510))
#define GPIO_PORTE_PDR_REG        (*((volatile uint32 *)0x40024514))
#define GPIO_PORTE_DEN_REG        (*((volatile uint32 *)0x4002451C))
#define GPIO_PORTE_LOCK_REG       (*((volatile uint32 *)0x40024520))
#define GPIO_PORTE_CR_REG         (*((volatile uint32 *)0x40024524))
#define GPIO_PORTE_AMSEL_REG      (*((volatile uint32 *)0x40024528))
#define GPIO_PORTE_PCTL_REG       (*((volatile uint32 *)0x4002452C))

/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         (*((volatile uint32 *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile uint32 *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile uint32 *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile uint32 *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile uint32 *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile uint32 *)0x4002441C))

/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       (*((volatile uint32 *)0x400253FC))
#define GPIO_PORTF_DIR_REG        (*((volatile uint32 *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      (*((volatile uint32 *)0x40025420))
#define GPIO_PORTF_PUR_REG        (*((volatile uint32 *)0x40025510))
#define GPIO_PORTF_PDR_REG        (*((volatile uint32 *)0x40025514))
#define GPIO_PORTF_DEN_REG        (*((volatile uint32 *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       (*((volatile uint32 *)0x40025520))
#define GPIO_PORTF_CR_REG         (*((volatile uint32 *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      (*((volatile uint32 *)0x40025528))
#define GPIO_PORTF_PCTL_REG       (*((volatile uint32 *)0x4002552C))

/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG         (*((volatile uint32 *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile uint32 *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile uint32 *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile uint32 *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile uint32 *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile uint32 *)0x4002541C))

/*****************************************************************************
Systick Timer Registers
*****************************************************************************/
#define SYSTICK_CTRL_REG          (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile uint32 *)0xE000E018))

/*****************************************************************************
NVIC Registers
*****************************************************************************/
#define NVIC_PRI0_REG             (*((volatile uint32 *)0xE000E400))
#define NVIC_PRI1_REG             (*((volatile uint32 *)0xE000E404))
#define NVIC_PRI2_REG             (*((volatile uint32 *)0xE000E408))
#define NVIC_PRI3_REG             (*((volatile uint32 *)0xE000E40C))
#define NVIC_PRI4_REG             (*((volatile uint32 *)0xE000E410))
#define NVIC_PRI5_REG             (*((volatile uint32 *)0xE000E414))
#define NVIC_PRI6_REG             (*((volatile uint32 *)0xE000E418))
#define NVIC_PRI7_REG             (*((volatile uint32 *)0xE000E41C))
#define NVIC_PRI8_REG             (*((volatile uint32 *)0xE000E420))
#define NVIC_PRI9_REG             (*((volatile uint32 *)0xE000E424))
#define NVIC_PRI10_REG            (*((volatile uint32 *)0xE000E428))
#define NVIC_PRI11_REG            (*((volatile uint32 *)0xE000E42C))
#define NVIC_PRI12_REG            (*((volatile uint32 *)0xE000E430))
#define NVIC_PRI13_REG            (*((volatile uint32 *)0xE000E434))
#define NVIC_PRI14_REG            (*((volatile uint32 *)0xE000E438))
#define NVIC_PRI15_REG            (*((volatile uint32 *)0xE000E43C))
#define NVIC_PRI16_REG            (*((volatile uint32 *)0xE000E440))
#define NVIC_PRI17_REG            (*((volatile uint32 *)0xE000E444))
#define NVIC_PRI18_REG            (*((volatile uint32 *)0xE000E448))
#define NVIC_PRI19_REG            (*((volatile uint32 *)0xE000E44C))
#define NVIC_PRI20_REG            (*((volatile uint32 *)0xE000E450))
#define NVIC_PRI21_REG            (*((volatile uint32 *)0xE000E454))
#define NVIC_PRI22_REG            (*((volatile uint32 *)0xE000E458))
#define NVIC_PRI23_REG            (*((volatile uint32 *)0xE000E45C))
#define NVIC_PRI24_REG            (*((volatile uint32 *)0xE000E460))
#define NVIC_PRI25_REG            (*((volatile uint32 *)0xE000E464))
#define NVIC_PRI26_REG            (*((volatile uint32 *)0xE000E468))
#define NVIC_PRI27_REG            (*((volatile uint32 *)0xE000E46C))
#define NVIC_PRI28_REG            (*((volatile uint32 *)0xE000E470))
#define NVIC_PRI29_REG            (*((volatile uint32 *)0xE000E474))
#define NVIC_PRI30_REG            (*((volatile uint32 *)0xE000E478))
#define NVIC_PRI31_REG            (*((volatile uint32 *)0xE000E47C))
#define NVIC_PRI32_REG            (*((volatile uint32 *)0xE000E480))
#define NVIC_PRI33_REG            (*((volatile uint32 *)0xE000E484))
#define NVIC_PRI34_REG            (*((volatile uint32 *)0xE000E488))

#define NVIC_EN0_REG              (*((volatile uint32 *)0xE000E100))
#define NVIC_EN1_REG              (*((volatile uint32 *)0xE000E104))
#define NVIC_EN2_REG              (*((volatile uint32 *)0xE000E108))
#define NVIC_EN3_REG              (*((volatile uint32 *)0xE000E10C))
#define NVIC_EN4_REG              (*((volatile uint32 *)0xE000E110))
#define NVIC_DIS0_REG             (*((volatile uint32 *)0xE000E180))
#define NVIC_DIS1_REG             (*((volatile uint32 *)0xE000E184))
#define NVIC_DIS2_REG             (*((volatile uint32 *)0xE000E188))
#define NVIC_DIS3_REG             (*((volatile uint32 *)0xE000E18C))
#define NVIC_DIS4_REG             (*((volatile uint32 *)0xE000E190))

/*****************************************************************************
System Control Block Registers
*****************************************************************************/
#define NVIC_SYSTEM_PRI1_REG      (*((volatile uint32 *)0xE000ED18))
#define NVIC_SYSTEM_PRI2_REG      (*((volatile uint32 *)0xE000ED1C))
#define NVIC_SYSTEM_PRI3_REG      (*((volatile uint32 *)0xE000ED20))
#define NVIC_SYSTEM_SYSHNDCTRL    (*((volatile uint32 *)0xE000ED24))
#define NVIC_SYSTEM_INTCTRL       (*((volatile uint32 *)0xE000ED04))
#define NVIC_SYSTEM_CFGCTRL       (*((volatile uint32 *)0xE000ED14))

/*****************************************************************************
MPU Registers
*****************************************************************************/
#define MPU_TYPE_REG              (*((volatile uint32 *)0xE000ED90))
#define MPU_CTRL_REG              (*((volatile uint32 *)0xE000ED94))
#define MPU_NUMBER_REG            (*((volatile uint32 *)0xE000ED98))
#define MPU_BASE_REG              (*((volatile uint32 *)0xE000ED9C))
#define MPU_ATTR_REG              (*((volatile uint32 *)0xE000EDA0))
#define MPU_BASE1_REG             (*((volatile uint32 *)0xE000EDA4))
#define MPU_ATTR1_REG             (*((volatile uint32 *)0xE000EDA8))
#define MPU_BASE2_REG             (*((volatile uint32 *)0xE000EDAC))
#define MPU_ATTR2_REG             (*((volatile uint32 *)0xE000EDB0))
#define MPU_BASE3_REG             (*((volatile uint32 *)0xE000EDB4))
#define MPU_ATTR3_REG             (*((volatile uint32 *)0xE000EDB8))

/*****************************************************************************
System Control Registers
*****************************************************************************/
#define SYSCTL_DID0_REG           (*((volatile uint32 *)0x400FE000))
#define SYSCTL_DID1_REG           (*((volatile uint32 *)0x400FE004))
#define SYSCTL_DC0_REG            (*((volatile uint32 *)0x400FE008))
#define SYSCTL_DC1_REG            (*((volatile uint32 *)0x400FE010))
#define SYSCTL_DC2_REG            (*((volatile uint32 *)0x400FE014))
#define SYSCTL_DC3_REG            (*((volatile uint32 *)0x400FE018))
#define SYSCTL_DC4_REG            (*((volatile uint32 *)0x400FE01C))
#define SYSCTL_DC5_REG            (*((volatile uint32 *)0x400FE020))
#define SYSCTL_DC6_REG            (*((volatile uint32 *)0x400FE024))
#define SYSCTL_DC7_REG            (*((volatile uint32 *)0x400FE028))
#define SYSCTL_DC8_REG            (*((volatile uint32 *)0x400FE02C))
#define SYSCTL_PBORCTL_REG        (*((volatile uint32 *)0x400FE030))
#define SYSCTL_SRCR0_REG          (*((volatile uint32 *)0x400FE040))
#define SYSCTL_SRCR1_REG          (*((volatile uint32 *)0x400FE044))
#define SYSCTL_SRCR2_REG          (*((volatile uint32 *)0x400FE048))
#define SYSCTL_RIS_REG            (*((volatile uint32 *)0x400FE050))
#define SYSCTL_IMC_REG            (*((volatile uint32 *)0x400FE054))
#define SYSCTL_MISC_REG           (*((volatile uint32 *)0x400FE058))
#define SYSCTL_RESC_REG           (*((volatile uint32 *)0x400FE05C))
#define SYSCTL_RCC_REG            (*((volatile uint32 *)0x400FE060))
#define SYSCTL_GPIOHBCTL_REG      (*((volatile uint32 *)0x400FE06C))
#define SYSCTL_RCC2_REG           (*((volatile uint32 *)0x400FE070))
#define SYSCTL_MOSCCTL_REG        (*((volatile uint32 *)0x400FE07C))
#define SYSCTL_RCGC0_REG          (*((volatile uint32 *)0x400FE100))
#define SYSCTL_RCGC1_REG          (*((volatile uint32 *)0x400FE104))
#define SYSCTL_RCGC2_REG          (*((volatile uint32 *)0x400FE108))
#define SYSCTL_SCGC0_REG          (*((volatile uint32 *)0x400FE110))
#define SYSCTL_SCGC1_REG          (*((volatile uint32 *)0x400FE114))
#define SYSCTL_SCGC2_REG          (*((volatile uint32 *)0x400FE118))
#define SYSCTL_DCGC0_REG          (*((volatile uint32 *)0x400FE120))
#define SYSCTL_DCGC1_REG          (*((volatile uint32 *)0x400FE124))
#define SYSCTL_DCGC2_REG          (*((volatile uint32 *)0x400FE128))
#define SYSCTL_DSLPCLKCFG_REG     (*((volatile uint32 *)0x400FE144))
#define SYSCTL_SYSPROP_REG        (*((volatile uint32 *)0x400FE14C))
#define SYSCTL_PIOSCCAL_REG       (*((volatile uint32 *)0x400FE150))
#define SYSCTL_PIOSCSTAT_REG      (*((volatile uint32 *)0x400FE154))
#define SYSCTL_PLLFREQ0_REG       (*((volatile uint32 *)0x400FE160))
#define SYSCTL_PLLFREQ1_REG       (*((volatile uint32 *)0x400FE164))
#define SYSCTL_PLLSTAT_REG        (*((volatile uint32 *)0x400FE168))
#define SYSCTL_DC9_REG            (*((volatile uint32 *)0x400FE190))
#define SYSCTL_NVMSTAT_REG        (*((volatile uint32 *)0x400FE1A0))
#define SYSCTL_PPWD_REG           (*((volatile uint32 *)0x400FE300))
#define SYSCTL_PPTIMER_REG        (*((volatile uint32 *)0x400FE304))
#define SYSCTL_PPGPIO_REG         (*((volatile uint32 *)0x400FE308))
#define SYSCTL_PPDMA_REG          (*((volatile uint32 *)0x400FE30C))
#define SYSCTL_PPHIB_REG          (*((volatile uint32 *)0x400FE314))
#define SYSCTL_PPUART_REG         (*((volatile uint32 *)0x400FE318))
#define SYSCTL_PPSSI_REG          (*((volatile uint32 *)0x400FE31C))
#define SYSCTL_PPI2C_REG          (*((volatile uint32 *)0x400FE320))
#define SYSCTL_PPUSB_REG          (*((volatile uint32 *)0x400FE328))
#define SYSCTL_PPCAN_REG          (*((volatile uint32 *)0x400FE334))
#define SYSCTL_PPADC_REG          (*((volatile uint32 *)0x400FE338))
#define SYSCTL_PPACMP_REG         (*((volatile uint32 *)0x400FE33C))
#define SYSCTL_PPPWM_REG          (*((volatile uint32 *)0x400FE340))
#define SYSCTL_PPQEI_REG          (*((volatile uint32 *)0x400FE344))
#define SYSCTL_PPEEPROM_REG       (*((volatile uint32 *)0x400FE358))
#define SYSCTL_PPWTIMER_REG       (*((volatile uint32 *)0x400FE35C))
#define SYSCTL_SRWD_REG           (*((volatile uint32 *)0x400FE500))
#define SYSCTL_SRTIMER_REG        (*((volatile uint32 *)0x400FE504))
#define SYSCTL_SRGPIO_REG         (*((volatile uint32 *)0x400FE508))
#define SYSCTL_SRDMA_REG          (*((volatile uint32 *)0x400FE50C))
#define SYSCTL_SRHIB_REG          (*((volatile uint32 *)0x400FE514))
#define SYSCTL_SRUART_REG         (*((volatile uint32 *)0x400FE518))
#define SYSCTL_SRSSI_REG          (*((volatile uint32 *)0x400FE51C))
#define SYSCTL_SRI2C_REG          (*((volatile uint32 *)0x400FE520))
#define SYSCTL_SRUSB_REG          (*((volatile uint32 *)0x400FE528))
#define SYSCTL_SRCAN_REG          (*((volatile uint32 *)0x400FE534))
#define SYSCTL_SRADC_REG          (*((volatile uint32 *)0x400FE538))
#define SYSCTL_SRACMP_REG         (*((volatile uint32 *)0x400FE53C))
#define SYSCTL_SRPWM_REG          (*((volatile uint32 *)0x400FE540))
#define SYSCTL_SRQEI_REG          (*((volatile uint32 *)0x400FE544))
#define SYSCTL_SREEPROM_REG       (*((volatile uint32 *)0x400FE558))
#define SYSCTL_SRWTIMER_REG       (*((volatile uint32 *)0x400FE55C))
#define SYSCTL_RCGCWD_REG         (*((volatile uint32 *)0x400FE600))
#define SYSCTL_RCGCTIMER_REG      (*((volatile uint32 *)0x400FE604))
#define SYSCTL_RCGCGPIO_REG       (*((volatile uint32 *)0x400FE608))
#define SYSCTL_RCGCDMA_REG        (*((volatile uint32 *)0x400FE60C))
#define SYSCTL_RCGCHIB_REG        (*((volatile uint32 *)0x400FE614))
#define SYSCTL_RCGCUART_REG       (*((volatile uint32 *)0x400FE618))
#define SYSCTL_RCGCSSI_REG        (*((volatile uint32 *)0x400FE61C))
#define SYSCTL_RCGCI2C_REG        (*((volatile uint32 *)0x400FE620))
#define SYSCTL_RCGCUSB_REG        (*((volatile uint32 *)0x400FE628))
#define SYSCTL_RCGCCAN_REG        (*((volatile uint32 *)0x400FE634))
#define SYSCTL_RCGCADC_REG        (*((volatile uint32 *)0x400FE638))
#define SYSCTL_RCGCACMP_REG       (*((volatile uint32 *)0x400FE63C))
#define SYSCTL_RCGCPWM_REG        (*((volatile uint32 *)0x400FE640))
#define SYSCTL_RCGCQEI_REG        (*((volatile uint32 *)0x400FE644))
#define SYSCTL_RCGCEEPROM_REG     (*((volatile uint32 *)0x400FE658))
#define SYSCTL_RCGCWTIMER_REG     (*((volatile uint32 *)0x400FE65C))
#define SYSCTL_SCGCWD_REG         (*((volatile uint32 *)0x400FE700))
#define SYSCTL_SCGCTIMER_REG      (*((volatile uint32 *)0x400FE704))
#define SYSCTL_SCGCGPIO_REG       (*((volatile uint32 *)0x400FE708))
#define SYSCTL_SCGCDMA_REG        (*((volatile uint32 *)0x400FE70C))
#define SYSCTL_SCGCHIB_REG        (*((volatile uint32 *)0x400FE714))
#define SYSCTL_SCGCUART_REG       (*((volatile uint32 *)0x400FE718))
#define SYSCTL_SCGCSSI_REG        (*((volatile uint32 *)0x400FE71C))
#define SYSCTL_SCGCI2C_REG        (*((volatile uint32 *)0x400FE720))
#define SYSCTL_SCGCUSB_REG        (*((volatile uint32 *)0x400FE728))
#define SYSCTL_SCGCCAN_REG        (*((volatile uint32 *)0x400FE734))
#define SYSCTL_SCGCADC_REG        (*((volatile uint32 *)0x400FE738))
#define SYSCTL_SCGCACMP_REG       (*((volatile uint32 *)0x400FE73C))
#define SYSCTL_SCGCPWM_REG        (*((volatile uint32 *)0x400FE740))
#define SYSCTL_SCGCQEI_REG        (*((volatile uint32 *)0x400FE744))
#define SYSCTL_SCGCEEPROM_REG     (*((volatile uint32 *)0x400FE758))
#define SYSCTL_SCGCWTIMER_REG     (*((volatile uint32 *)0x400FE75C))
#define SYSCTL_DCGCWD_REG         (*((volatile uint32 *)0x400FE800))
#define SYSCTL_DCGCTIMER_REG      (*((volatile uint32 *)0x400FE804))
#define SYSCTL_DCGCGPIO_REG       (*((volatile uint32 *)0x400FE808))
#define SYSCTL_DCGCDMA_REG        (*((volatile uint32 *)0x400FE80C))
#define SYSCTL_DCGCHIB_REG        (*((volatile uint32 *)0x400FE814))
#define SYSCTL_DCGCUART_REG       (*((volatile uint32 *)0x400FE818))
#define SYSCTL_DCGCSSI_REG        (*((volatile uint32 *)0x400FE81C))
#define SYSCTL_DCGCI2C_REG        (*((volatile uint32 *)0x400FE820))
#define SYSCTL_DCGCUSB_REG        (*((volatile uint32 *)0x400FE828))
#define SYSCTL_DCGCCAN_REG        (*((volatile uint32 *)0x400FE834))
#define SYSCTL_DCGCADC_REG        (*((volatile uint32 *)0x400FE838))
#define SYSCTL_DCGCACMP_REG       (*((volatile uint32 *)0x400FE83C))
#define SYSCTL_DCGCPWM_REG        (*((volatile uint32 *)0x400FE840))
#define SYSCTL_DCGCQEI_REG        (*((volatile uint32 *)0x400FE844))
#define SYSCTL_DCGCEEPROM_REG     (*((volatile uint32 *)0x400FE858))
#define SYSCTL_DCGCWTIMER_REG     (*((volatile uint32 *)0x400FE85C))
#define SYSCTL_PRWD_REG           (*((volatile uint32 *)0x400FEA00))
#define SYSCTL_PRTIMER_REG        (*((volatile uint32 *)0x400FEA04))
#define SYSCTL_PRGPIO_REG         (*((volatile uint32 *)0x400FEA08))
#define SYSCTL_PRDMA_REG          (*((volatile uint32 *)0x400FEA0C))
#define SYSCTL_PRHIB_REG          (*((volatile uint32 *)0x400FEA14))
#define SYSCTL_PRUART_REG         (*((volatile uint32 *)0x400FEA18))
#define SYSCTL_PRSSI_REG          (*((volatile uint32 *)0x400FEA1C))
#define SYSCTL_PRI2C_REG          (*((volatile uint32 *)0x400FEA20))
#define SYSCTL_PRUSB_REG          (*((volatile uint32 *)0x400FEA28))
#define SYSCTL_PRCAN_REG          (*((volatile uint32 *)0x400FEA34))
#define SYSCTL_PRADC_REG          (*((volatile uint32 *)0x400FEA38))
#define SYSCTL_PRACMP_REG         (*((volatile uint32 *)0x400FEA3C))
#define SYSCTL_PRPWM_REG          (*((volatile uint32 *)0x400FEA40))
#define SYSCTL_PRQEI_REG          (*((volatile uint32 *)0x400FEA44))
#define SYSCTL_PREEPROM_REG       (*((volatile uint32 *)0x400FEA58))
#define SYSCTL_PRWTIMER_REG       (*((volatile uint32 *)0x400FEA5C))

/*****************************************************************************
UART0 Registers
*****************************************************************************/
#define UART0_DR_REG              (*((volatile uint32 *)0x4000C000))
#define UART0_RSR_REG             (*((volatile uint32 *)0x4000C004))
#define UART0_ECR_REG             (*((volatile uint32 *)0x4000C004))
#define UART0_FR_REG              (*((volatile uint32 *)0x4000C018))
#define UART0_ILPR_REG            (*((volatile uint32 *)0x4000C020))
#define UART0_IBRD_REG            (*((volatile uint32 *)0x4000C024))
#define UART0_FBRD_REG            (*((volatile uint32 *)0x4000C028))
#define UART0_LCRH_REG            (*((volatile uint32 *)0x4000C02C))
#define UART0_CTL_REG             (*((volatile uint32 *)0x4000C030))
#define UART0_IFLS_REG            (*((volatile uint32 *)0x4000C034))
#define UART0_IM_REG              (*((volatile uint32 *)0x4000C038))
#define UART0_RIS_REG             (*((volatile uint32 *)0x4000C03C))
#define UART0_MIS_REG             (*((volatile uint32 *)0x4000C040))
#define UART0_ICR_REG             (*((volatile uint32 *)0x4000C044))
#define UART0_DMACTL_REG          (*((volatile uint32 *)0x4000C048))
#define UART0_9BITADDR_REG        (*((volatile uint32 *)0x4000C0A4))
#define UART0_9BITAMASK_REG       (*((volatile uint32 *)0x4000C0A8))
#define UART0_PP_REG              (*((volatile uint32 *)0x4000CFC0))
#define UART0_CC_REG              (*((volatile uint32 *)0x4000CFC8))

/*****************************************************************************
Micro Direct Memory Access Registers (UDMA)
*****************************************************************************/
#define UDMA_STAT_REG             (*((volatile uint32 *)0x400FF000))
#define UDMA_CFG_REG              (*((volatile uint32 *)0x400FF004))
#define UDMA_CTLBASE_REG          (*((volatile uint32 *)0x400FF008))
#define UDMA_ALTBASE_REG          (*((volatile uint32 *)0x400FF00C))
#define UDMA_WAITSTAT_REG         (*((volatile uint32 *)0x400FF010))
#define UDMA_SWREQ_REG            (*((volatile uint32 *)0x400FF014))
#define UDMA_USEBURSTSET_REG      (*((volatile uint32 *)0x400FF018))
#define UDMA_USEBURSTCLR_R      (*((volatile uint32 *)0x400FF01C))
#define UDMA_REQMASKSET_REG       (*((volatile uint32 *)0x400FF020))
#define UDMA_REQMASKCLR_REG       (*((volatile uint32 *)0x400FF024))
#define UDMA_ENASET_REG           (*((volatile uint32 *)0x400FF028))
#define UDMA_ENACLR_REG           (*((volatile uint32 *)0x400FF02C))
#define UDMA_ALTSET_REG           (*((volatile uint32 *)0x400FF030))
#define UDMA_ALTCLR_REG           (*((volatile uint32 *)0x400FF034))
#define UDMA_PRIOSET_REG          (*((volatile uint32 *)0x400FF038))
#define UDMA_PRIOCLR_REG          (*((volatile uint32 *)0x400FF03C))
#define UDMA_ERRCLR_REG           (*((volatile uint32 *)0x400FF04C))
#define UDMA_CHASGN_REG           (*((volatile uint32 *)0x400FF500))
#define UDMA_CHIS_REG             (*((volatile uint32 *)0x400FF504))
#define UDMA_CHMAP0_REG           (*((volatile uint32 *)0x400FF510))
#define UDMA_CHMAP1_REG           (*((volatile uint32 *)0x400FF514))
#define UDMA_CHMAP2_REG           (*((volatile uint32 *)0x400FF518))
#define UDMA_CHMAP3_REG           (*((volatile uint32 *)0x400FF51C))

/*****************************************************************************
Flash Registers
*****************************************************************************/
#define FLASH_FMA_REG             (*((volatile uint32 *)0x400FD000))
#define FLASH_FMD_REG             (*((volatile uint32 *)0x400FD004))
#define FLASH_FMC_REG             (*((volatile uint32 *)0x400FD008))
#define FLASH_FCRIS_REG           (*((volatile uint32 *)0x400FD00C))
#define FLASH_FCIM_REG            (*((volatile uint32 *)0x400FD010))
#define FLASH_FCMISC_REG          (*((volatile uint32 *)0x400FD014))
#define FLASH_FMC2_REG            (*((volatile uint32 *)0x400FD020))
#define FLASH_FWBVAL_REG          (*((volatile uint32 *)0x400FD030))
#define FLASH_FWBN_REG            (*((volatile uint32 *)0x400FD100))
#define FLASH_FSIZE_REG           (*((volatile uint32 *)0x400FDFC0))
#define FLASH_SSIZE_REG           (*((volatile uint32 *)0x400FDFC4))
#define FLASH_ROMSWMAP_REG        (*((volatile uint32 *)0x400FDFCC))
#define FLASH_RMCTL_REG           (*((volatile uint32 *)0x400FE0F0))
#define FLASH_BOOTCFG_REG         (*((volatile uint32 *)0x400FE1D0))
#define FLASH_USERREG0_REG        (*((volatile uint32 *)0x400FE1E0))
#define FLASH_USERREG1_REG        (*((volatile uint32 *)0x400FE1E4))
#define FLASH_USERREG2_REG        (*((volatile uint32 *)0x400FE1E8))
#define FLASH_USERREG3_REG        (*((volatile uint32 *)0x400FE1EC))
#define FLASH_FMPRE0_REG          (*((volatile uint32 *)0x400FE200))
#define FLASH_FMPRE1_REG          (*((volatile uint32 *)0x400FE204))
#define FLASH_FMPRE2_REG          (*((volatile uint32 *)0x400FE208))
#define FLASH_FMPRE3_REG          (*((volatile uint32 *)0x400FE20C))
#define FLASH_FMPPE0_REG          (*((volatile uint32 *)0x400FE400))
#define FLASH_FMPPE1_REG          (*((volatile uint32 *)0x400FE404))
#define FLASH_FMPPE2_REG          (*((volatile uint32 *)0x400FE408))
#define FLASH_FMPPE3_REG          (*((volatile uint32 *)0x400FE40C))

/*****************************************************************************
Timer Registers (WTIMER0)
*****************************************************************************/
#define WTIMER0_CFG_REG           (*((volatile uint32 *)0x40036000))
#define WTIMER0_TAMR_REG          (*((volatile uint32 *)0x40036004))
#define WTIMER0_TBMR_REG          (*((volatile uint32 *)0x40036008))
#define WTIMER0_CTL_REG           (*((volatile uint32 *)0x4003600C))
#define WTIMER0_TAILR_REG         (*((volatile uint32 *)0x40036028))
#define WTIMER0_TBILR_REG         (*((volatile uint32 *)0x4003602C))
#define WTIMER0_TAPR_REG          (*((volatile uint32 *)0x40036038))
#define WTIMER0_TBPR_REG          (*((volatile uint32 *)0x4003603C))
#define WTIMER0_TAR_REG           (*((volatile uint32 *)0x40036048))
#define WTIMER0_TBR_REG           (*((volatile uint32 *)0x4003604C))

/*****************************************************************************
ADC0 Registers
*****************************************************************************/
#define ADC0_ACTSS_REG            (*((volatile uint32 *)0x40038000))
#define ADC0_EMUX_REG             (*((volatile uint32 *)0x40038014))
#define ADC0_TSSEL_REG            (*((volatile uint32 *)0x4003801C))
#define ADC0_SSMUX0_REG           (*((volatile uint32 *)0x40038040))
#define ADC0_SSMUX1_REG           (*((volatile uint32 *)0x40038060))
#define ADC0_SSMUX2_REG           (*((volatile uint32 *)0x40038080))
#define ADC0_SSMUX3_REG           (*((volatile uint32 *)0x400380A0))
#define ADC0_SSCTL0_REG           (*((volatile uint32 *)0x40038044))
#define ADC0_SSCTL1_REG           (*((volatile uint32 *)0x40038064))
#define ADC0_SSCTL2_REG           (*((volatile uint32 *)0x40038084))
#define ADC0_SSCTL3_REG           (*((volatile uint32 *)0x400380A4))
#define ADC0_SSFIFO3_REG          (*((volatile uint32 *)0x400380A8))
#define ADC0_SSFSTAT3_REG         (*((volatile uint32 *)0x400380AC))
#define ADC0_RIS_REG              (*((volatile uint32 *)0x40038004))
#define ADC0_ISC_REG              (*((volatile uint32 *)0x4003800C))
#define ADC0_PSSI_REG             (*((volatile uint32 *)0x40038028))
/*****************************************************************************
ADC1 Registers
*****************************************************************************/
#define ADC1_ACTSS_REG            (*((volatile uint32 *)0x40039000))
#define ADC1_EMUX_REG             (*((volatile uint32 *)0x40039014))
#define ADC1_TSSEL_REG            (*((volatile uint32 *)0x4003901C))
#define ADC1_SSMUX0_REG           (*((volatile uint32 *)0x40039040))
#define ADC1_SSMUX1_REG           (*((volatile uint32 *)0x40039060))
#define ADC1_SSMUX2_REG           (*((volatile uint32 *)0x40039080))
#define ADC1_SSMUX3_REG           (*((volatile uint32 *)0x400390A0))
#define ADC1_SSCTL0_REG           (*((volatile uint32 *)0x40039044))
#define ADC1_SSCTL1_REG           (*((volatile uint32 *)0x40039064))
#define ADC1_SSCTL2_REG           (*((volatile uint32 *)0x40039084))
#define ADC1_SSCTL3_REG           (*((volatile uint32 *)0x400390A4))
#define ADC1_SSFIFO3_REG          (*((volatile uint32 *)0x400390A8))
#define ADC1_SSFSTAT3_REG         (*((volatile uint32 *)0x400390AC))
#define ADC1_RIS_REG              (*((volatile uint32 *)0x40039004))
#define ADC1_ISC_REG              (*((volatile uint32 *)0x4003900C))
#define ADC1_PSSI_REG             (*((volatile uint32 *)0x40039028))
#endif
