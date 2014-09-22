#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-exp16_pic24fj128ga010_spi_epd_2.0_v110_g1.mk)" "nbproject/Makefile-local-exp16_pic24fj128ga010_spi_epd_2.0_v110_g1.mk"
include nbproject/Makefile-local-exp16_pic24fj128ga010_spi_epd_2.0_v110_g1.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=exp16_pic24fj128ga010_spi_epd_2.0_v110_g1
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../../../bsp/exp16/pic24fj128ga010_pim/adc.c ../../../../../bsp/exp16/pic24fj128ga010_pim/timer_1ms.c ../src/demo_screen_for_2_inch/epd_demo1.c ../src/demo_screen_for_2_inch/epd_demo2.c ../src/demo_screen_for_2_inch/epd_demo3.c ../src/demo_screen_for_2_inch/epd_demo4.c ../src/demo_screen_for_2_inch/epd_demo_home.c ../../../../../framework/driver/eeprom_spi/src/drv_nvm_eeprom_spi_25lc256.c ../src/gfx/drv_gfx_pdi_e_paper.c ../../../../../framework/driver/spi/src/drv_spi_16bit.c ../../../../../framework/gfx/src/gfx_gol.c ../../../../../framework/gfx/src/gfx_gol_button.c ../../../../../framework/gfx/src/gfx_gol_picture.c ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c ../../../../../framework/gfx/src/gfx_gol_static_text.c ../../../../../framework/gfx/src/gfx_primitive.c ../../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c ../../../../../framework/driver/touch_screen/src/drv_touch_screen.c ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c ../src/Pervasive_Displays_small_EPD/EPD_controller.c ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c ../src/Pervasive_Displays_small_EPD/drv_serial_ram_mchp23k256.c ../src/resources/image_resources_epd_2.0_inch_demo.S ../src/resources/image_resources_epd_2.0_inch_demo_reference.c ../src/resources/font_resources_epd_demo.S ../src/resources/font_resources_epd_demo_reference.c ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1/system.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/485330153/adc.o ${OBJECTDIR}/_ext/485330153/timer_1ms.o ${OBJECTDIR}/_ext/1599848702/epd_demo1.o ${OBJECTDIR}/_ext/1599848702/epd_demo2.o ${OBJECTDIR}/_ext/1599848702/epd_demo3.o ${OBJECTDIR}/_ext/1599848702/epd_demo4.o ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o ${OBJECTDIR}/_ext/526778074/system.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/485330153/adc.o.d ${OBJECTDIR}/_ext/485330153/timer_1ms.o.d ${OBJECTDIR}/_ext/1599848702/epd_demo1.o.d ${OBJECTDIR}/_ext/1599848702/epd_demo2.o.d ${OBJECTDIR}/_ext/1599848702/epd_demo3.o.d ${OBJECTDIR}/_ext/1599848702/epd_demo4.o.d ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o.d ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o.d ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o.d ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o.d ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o.d ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d ${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o.d ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.d ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o.d ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.d ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o.d ${OBJECTDIR}/_ext/526778074/system.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/485330153/adc.o ${OBJECTDIR}/_ext/485330153/timer_1ms.o ${OBJECTDIR}/_ext/1599848702/epd_demo1.o ${OBJECTDIR}/_ext/1599848702/epd_demo2.o ${OBJECTDIR}/_ext/1599848702/epd_demo3.o ${OBJECTDIR}/_ext/1599848702/epd_demo4.o ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o ${OBJECTDIR}/_ext/526778074/system.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../../../../../bsp/exp16/pic24fj128ga010_pim/adc.c ../../../../../bsp/exp16/pic24fj128ga010_pim/timer_1ms.c ../src/demo_screen_for_2_inch/epd_demo1.c ../src/demo_screen_for_2_inch/epd_demo2.c ../src/demo_screen_for_2_inch/epd_demo3.c ../src/demo_screen_for_2_inch/epd_demo4.c ../src/demo_screen_for_2_inch/epd_demo_home.c ../../../../../framework/driver/eeprom_spi/src/drv_nvm_eeprom_spi_25lc256.c ../src/gfx/drv_gfx_pdi_e_paper.c ../../../../../framework/driver/spi/src/drv_spi_16bit.c ../../../../../framework/gfx/src/gfx_gol.c ../../../../../framework/gfx/src/gfx_gol_button.c ../../../../../framework/gfx/src/gfx_gol_picture.c ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c ../../../../../framework/gfx/src/gfx_gol_static_text.c ../../../../../framework/gfx/src/gfx_primitive.c ../../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c ../../../../../framework/driver/touch_screen/src/drv_touch_screen.c ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c ../src/Pervasive_Displays_small_EPD/EPD_controller.c ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c ../src/Pervasive_Displays_small_EPD/drv_serial_ram_mchp23k256.c ../src/resources/image_resources_epd_2.0_inch_demo.S ../src/resources/image_resources_epd_2.0_inch_demo_reference.c ../src/resources/font_resources_epd_demo.S ../src/resources/font_resources_epd_demo_reference.c ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1/system.c ../src/main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-exp16_pic24fj128ga010_spi_epd_2.0_v110_g1.mk dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA010
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/485330153/adc.o: ../../../../../bsp/exp16/pic24fj128ga010_pim/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/485330153 
	@${RM} ${OBJECTDIR}/_ext/485330153/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/485330153/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../bsp/exp16/pic24fj128ga010_pim/adc.c  -o ${OBJECTDIR}/_ext/485330153/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/485330153/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/485330153/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/485330153/timer_1ms.o: ../../../../../bsp/exp16/pic24fj128ga010_pim/timer_1ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/485330153 
	@${RM} ${OBJECTDIR}/_ext/485330153/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/_ext/485330153/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../bsp/exp16/pic24fj128ga010_pim/timer_1ms.c  -o ${OBJECTDIR}/_ext/485330153/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/485330153/timer_1ms.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/485330153/timer_1ms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo1.o: ../src/demo_screen_for_2_inch/epd_demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo1.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo2.o: ../src/demo_screen_for_2_inch/epd_demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo2.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo3.o: ../src/demo_screen_for_2_inch/epd_demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo3.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo4.o: ../src/demo_screen_for_2_inch/epd_demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo4.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo_home.o: ../src/demo_screen_for_2_inch/epd_demo_home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo_home.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo_home.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo_home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o: ../../../../../framework/driver/eeprom_spi/src/drv_nvm_eeprom_spi_25lc256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/574415913 
	@${RM} ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o.d 
	@${RM} ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/eeprom_spi/src/drv_nvm_eeprom_spi_25lc256.c  -o ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o: ../src/gfx/drv_gfx_pdi_e_paper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o.d 
	@${RM} ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gfx/drv_gfx_pdi_e_paper.c  -o ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o: ../../../../../framework/driver/spi/src/drv_spi_16bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1385053818 
	@${RM} ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/spi/src/drv_spi_16bit.c  -o ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol.o: ../../../../../framework/gfx/src/gfx_gol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o: ../../../../../framework/gfx/src/gfx_gol_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_button.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o: ../../../../../framework/gfx/src/gfx_gol_picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_picture.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o: ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o: ../../../../../framework/gfx/src/gfx_gol_static_text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_static_text.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_primitive.o: ../../../../../framework/gfx/src/gfx_primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_primitive.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o: ../../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2136820584 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c  -o ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o: ../../../../../framework/driver/touch_screen/src/drv_touch_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2136820584 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/touch_screen/src/drv_touch_screen.c  -o ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o: ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1702581813 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  -o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o: ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1672105619 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  -o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_controller.o: ../src/Pervasive_Displays_small_EPD/EPD_controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_controller.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o: ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o: ../src/Pervasive_Displays_small_EPD/drv_serial_ram_mchp23k256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/drv_serial_ram_mchp23k256.c  -o ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o: ../src/resources/image_resources_epd_2.0_inch_demo_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/resources/image_resources_epd_2.0_inch_demo_reference.c  -o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o: ../src/resources/font_resources_epd_demo_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/resources/font_resources_epd_demo_reference.c  -o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/526778074/system.o: ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/526778074 
	@${RM} ${OBJECTDIR}/_ext/526778074/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/526778074/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1/system.c  -o ${OBJECTDIR}/_ext/526778074/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/526778074/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/526778074/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/485330153/adc.o: ../../../../../bsp/exp16/pic24fj128ga010_pim/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/485330153 
	@${RM} ${OBJECTDIR}/_ext/485330153/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/485330153/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../bsp/exp16/pic24fj128ga010_pim/adc.c  -o ${OBJECTDIR}/_ext/485330153/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/485330153/adc.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/485330153/adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/485330153/timer_1ms.o: ../../../../../bsp/exp16/pic24fj128ga010_pim/timer_1ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/485330153 
	@${RM} ${OBJECTDIR}/_ext/485330153/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/_ext/485330153/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../bsp/exp16/pic24fj128ga010_pim/timer_1ms.c  -o ${OBJECTDIR}/_ext/485330153/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/485330153/timer_1ms.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/485330153/timer_1ms.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo1.o: ../src/demo_screen_for_2_inch/epd_demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo1.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo1.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo2.o: ../src/demo_screen_for_2_inch/epd_demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo2.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo2.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo3.o: ../src/demo_screen_for_2_inch/epd_demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo3.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo3.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo4.o: ../src/demo_screen_for_2_inch/epd_demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo4.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo4.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1599848702/epd_demo_home.o: ../src/demo_screen_for_2_inch/epd_demo_home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1599848702 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o.d 
	@${RM} ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/demo_screen_for_2_inch/epd_demo_home.c  -o ${OBJECTDIR}/_ext/1599848702/epd_demo_home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1599848702/epd_demo_home.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1599848702/epd_demo_home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o: ../../../../../framework/driver/eeprom_spi/src/drv_nvm_eeprom_spi_25lc256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/574415913 
	@${RM} ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o.d 
	@${RM} ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/eeprom_spi/src/drv_nvm_eeprom_spi_25lc256.c  -o ${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/574415913/drv_nvm_eeprom_spi_25lc256.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o: ../src/gfx/drv_gfx_pdi_e_paper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o.d 
	@${RM} ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gfx/drv_gfx_pdi_e_paper.c  -o ${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/drv_gfx_pdi_e_paper.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o: ../../../../../framework/driver/spi/src/drv_spi_16bit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1385053818 
	@${RM} ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/spi/src/drv_spi_16bit.c  -o ${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1385053818/drv_spi_16bit.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol.o: ../../../../../framework/gfx/src/gfx_gol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o: ../../../../../framework/gfx/src/gfx_gol_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_button.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o: ../../../../../framework/gfx/src/gfx_gol_picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_picture.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o: ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o: ../../../../../framework/gfx/src/gfx_gol_static_text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_static_text.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_primitive.o: ../../../../../framework/gfx/src/gfx_primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_primitive.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o: ../../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2136820584 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/touch_screen/src/drv_touch_resistive_adc.c  -o ${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2136820584/drv_touch_resistive_adc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o: ../../../../../framework/driver/touch_screen/src/drv_touch_screen.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/2136820584 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o.d 
	@${RM} ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/driver/touch_screen/src/drv_touch_screen.c  -o ${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/2136820584/drv_touch_screen.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o: ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1702581813 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  -o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o: ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1672105619 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  -o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_controller.o: ../src/Pervasive_Displays_small_EPD/EPD_controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_controller.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o: ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o: ../src/Pervasive_Displays_small_EPD/drv_serial_ram_mchp23k256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/drv_serial_ram_mchp23k256.c  -o ${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/drv_serial_ram_mchp23k256.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o: ../src/resources/image_resources_epd_2.0_inch_demo_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/resources/image_resources_epd_2.0_inch_demo_reference.c  -o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo_reference.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o: ../src/resources/font_resources_epd_demo_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/resources/font_resources_epd_demo_reference.c  -o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo_reference.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/526778074/system.o: ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/526778074 
	@${RM} ${OBJECTDIR}/_ext/526778074/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/526778074/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1/system.c  -o ${OBJECTDIR}/_ext/526778074/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/526778074/system.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/526778074/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/demo_screen_for_2_inch" -I"../src" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../../../../../framework" -I"../src/gfx" -I"../../../../../bsp/exp16/pic24fj128ga010_pim" -I"../src/resources" -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o: ../src/resources/image_resources_epd_2.0_inch_demo.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/resources/image_resources_epd_2.0_inch_demo.S  -o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -I"../src" -I"../../../../../framework" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../src/gfx" -I"../src/resources" -Wa,-MD,"${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.d" "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o: ../src/resources/font_resources_epd_demo.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/resources/font_resources_epd_demo.S  -o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -I"../src" -I"../../../../../framework" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../src/gfx" -I"../src/resources" -Wa,-MD,"${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.d" "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o: ../src/resources/image_resources_epd_2.0_inch_demo.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/resources/image_resources_epd_2.0_inch_demo.S  -o ${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.d"  -omf=elf -I"../src" -I"../../../../../framework" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../src/gfx" -I"../src/resources" -Wa,-MD,"${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.d" "${OBJECTDIR}/_ext/1358156373/image_resources_epd_2.0_inch_demo.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o: ../src/resources/font_resources_epd_demo.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1358156373 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/resources/font_resources_epd_demo.S  -o ${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.d"  -omf=elf -I"../src" -I"../../../../../framework" -I"../src/system_config/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1" -I"../src/gfx" -I"../src/resources" -Wa,-MD,"${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.d" "${OBJECTDIR}/_ext/1358156373/font_resources_epd_demo.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1
	${RM} -r dist/exp16_pic24fj128ga010_spi_epd_2.0_v110_g1

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
