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
ifeq "$(wildcard nbproject/Makefile-local-EPD_2.7inch_V230_G2.mk)" "nbproject/Makefile-local-EPD_2.7inch_V230_G2.mk"
include nbproject/Makefile-local-EPD_2.7inch_V230_G2.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=EPD_2.7inch_V230_G2
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
SOURCEFILES_QUOTED_IF_SPACED=../../../Microchip/Common/TimeDelay.c "../src/Demo Screen for 1.44 inch/EPD_Demo1.c" "../src/Demo Screen for 1.44 inch/EPD_Demo2.c" "../src/Demo Screen for 1.44 inch/EPD_Demo3.c" "../src/Demo Screen for 1.44 inch/EPD_Demo4.c" "../src/Demo Screen for 1.44 inch/EPD_Demo_Home.c" "../src/Demo Screen for 2 inch/EPD_Demo1.c" "../src/Demo Screen for 2 inch/EPD_Demo2.c" "../src/Demo Screen for 2 inch/EPD_Demo3.c" "../src/Demo Screen for 2 inch/EPD_Demo4.c" "../src/Demo Screen for 2 inch/EPD_Demo_Home.c" "../src/Demo Screen for 2.7 inch/EPD_Demo1.c" "../src/Demo Screen for 2.7 inch/EPD_Demo2.c" "../src/Demo Screen for 2.7 inch/EPD_Demo3.c" "../src/Demo Screen for 2.7 inch/EPD_Demo4.c" "../src/Demo Screen for 2.7 inch/EPD_Demo_Home.c" "../src/gfx/PDI e-paper display_driver.c" ../../../Microchip/Graphics/Button.c ../../../Microchip/Graphics/GOL.c ../../../Microchip/Graphics/GOLSchemeDefault.c ../../../Microchip/Graphics/Picture.c ../../../Microchip/Graphics/Primitive.c ../../../Microchip/Graphics/Slider.c ../../../Microchip/Graphics/StaticText.c ../../../../../framework/gfx/src/gfx_gol.c ../../../../../framework/gfx/src/gfx_gol_button.c ../../../../../framework/gfx/src/gfx_gol_picture.c ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c ../../../../../framework/gfx/src/gfx_gol_static_text.c ../../../../../framework/gfx/src/gfx_primitive.c ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c ../src/Pervasive_Displays_small_EPD/EPD_controller.c ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c ../src/Pervasive_Displays_small_EPD/EPD_hardware_gpio.c ../src/Pervasive_Displays_small_EPD/SpiRAM.c ../src/gfx/resources_epd_demo.S ../src/gfx/resources_epd_demo_reference.c ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.7_v110_g1/system.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1860783399/TimeDelay.o ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o" ${OBJECTDIR}/_ext/803622919/Button.o ${OBJECTDIR}/_ext/803622919/GOL.o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ${OBJECTDIR}/_ext/803622919/Picture.o ${OBJECTDIR}/_ext/803622919/Primitive.o ${OBJECTDIR}/_ext/803622919/Slider.o ${OBJECTDIR}/_ext/803622919/StaticText.o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o ${OBJECTDIR}/_ext/1846579039/SpiRAM.o ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o ${OBJECTDIR}/_ext/294057427/system.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o.d ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o.d ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o.d ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o.d ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o.d ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o.d ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o.d ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o.d ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o.d ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o.d ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o.d ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o.d ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o.d ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o.d ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o.d "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o.d" ${OBJECTDIR}/_ext/803622919/Button.o.d ${OBJECTDIR}/_ext/803622919/GOL.o.d ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d ${OBJECTDIR}/_ext/803622919/Picture.o.d ${OBJECTDIR}/_ext/803622919/Primitive.o.d ${OBJECTDIR}/_ext/803622919/Slider.o.d ${OBJECTDIR}/_ext/803622919/StaticText.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d ${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o.d ${OBJECTDIR}/_ext/1846579039/SpiRAM.o.d ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.d ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o.d ${OBJECTDIR}/_ext/294057427/system.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1860783399/TimeDelay.o ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o ${OBJECTDIR}/_ext/659856255/PDI\ e-paper\ display_driver.o ${OBJECTDIR}/_ext/803622919/Button.o ${OBJECTDIR}/_ext/803622919/GOL.o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o ${OBJECTDIR}/_ext/803622919/Picture.o ${OBJECTDIR}/_ext/803622919/Primitive.o ${OBJECTDIR}/_ext/803622919/Slider.o ${OBJECTDIR}/_ext/803622919/StaticText.o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o ${OBJECTDIR}/_ext/1846579039/SpiRAM.o ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o ${OBJECTDIR}/_ext/294057427/system.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../../../Microchip/Common/TimeDelay.c ../src/Demo Screen for 1.44 inch/EPD_Demo1.c ../src/Demo Screen for 1.44 inch/EPD_Demo2.c ../src/Demo Screen for 1.44 inch/EPD_Demo3.c ../src/Demo Screen for 1.44 inch/EPD_Demo4.c ../src/Demo Screen for 1.44 inch/EPD_Demo_Home.c ../src/Demo Screen for 2 inch/EPD_Demo1.c ../src/Demo Screen for 2 inch/EPD_Demo2.c ../src/Demo Screen for 2 inch/EPD_Demo3.c ../src/Demo Screen for 2 inch/EPD_Demo4.c ../src/Demo Screen for 2 inch/EPD_Demo_Home.c ../src/Demo Screen for 2.7 inch/EPD_Demo1.c ../src/Demo Screen for 2.7 inch/EPD_Demo2.c ../src/Demo Screen for 2.7 inch/EPD_Demo3.c ../src/Demo Screen for 2.7 inch/EPD_Demo4.c ../src/Demo Screen for 2.7 inch/EPD_Demo_Home.c ../src/gfx/PDI e-paper display_driver.c ../../../Microchip/Graphics/Button.c ../../../Microchip/Graphics/GOL.c ../../../Microchip/Graphics/GOLSchemeDefault.c ../../../Microchip/Graphics/Picture.c ../../../Microchip/Graphics/Primitive.c ../../../Microchip/Graphics/Slider.c ../../../Microchip/Graphics/StaticText.c ../../../../../framework/gfx/src/gfx_gol.c ../../../../../framework/gfx/src/gfx_gol_button.c ../../../../../framework/gfx/src/gfx_gol_picture.c ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c ../../../../../framework/gfx/src/gfx_gol_static_text.c ../../../../../framework/gfx/src/gfx_primitive.c ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c ../src/Pervasive_Displays_small_EPD/EPD_controller.c ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c ../src/Pervasive_Displays_small_EPD/EPD_hardware_gpio.c ../src/Pervasive_Displays_small_EPD/SpiRAM.c ../src/gfx/resources_epd_demo.S ../src/gfx/resources_epd_demo_reference.c ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.7_v110_g1/system.c ../src/main.c


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
	${MAKE}  -f nbproject/Makefile-EPD_2.7inch_V230_G2.mk dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA010
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1860783399/TimeDelay.o: ../../../Microchip/Common/TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1860783399 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Common/TimeDelay.c  -o ${OBJECTDIR}/_ext/1860783399/TimeDelay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo1.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo1.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo2.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo2.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo3.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo3.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo4.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo4.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo_Home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo_Home.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo1.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo2.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo3.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo4.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo_Home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo_Home.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo1.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo1.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo2.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo2.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo3.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo3.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo3.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo4.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo4.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo4.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo_Home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo_Home.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659856255/PDI\ e-paper\ display_driver.o: ../src/gfx/PDI\ e-paper\ display_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/PDI\ e-paper\ display_driver.o.d 
	@${RM} "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/gfx/PDI e-paper display_driver.c"  -o "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Button.o: ../../../Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Button.c  -o ${OBJECTDIR}/_ext/803622919/Button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Button.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/GOL.o: ../../../Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/GOL.c  -o ${OBJECTDIR}/_ext/803622919/GOL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/GOL.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o: ../../../Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/GOLSchemeDefault.c  -o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Picture.o: ../../../Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Picture.c  -o ${OBJECTDIR}/_ext/803622919/Picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Picture.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Primitive.o: ../../../Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Primitive.c  -o ${OBJECTDIR}/_ext/803622919/Primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Primitive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Slider.o: ../../../Microchip/Graphics/Slider.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Slider.c  -o ${OBJECTDIR}/_ext/803622919/Slider.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Slider.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Slider.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/StaticText.o: ../../../Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/StaticText.c  -o ${OBJECTDIR}/_ext/803622919/StaticText.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/StaticText.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/StaticText.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol.o: ../../../../../framework/gfx/src/gfx_gol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o: ../../../../../framework/gfx/src/gfx_gol_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_button.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o: ../../../../../framework/gfx/src/gfx_gol_picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_picture.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o: ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o: ../../../../../framework/gfx/src/gfx_gol_static_text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_static_text.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_primitive.o: ../../../../../framework/gfx/src/gfx_primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_primitive.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o: ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1702581813 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  -o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o: ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1672105619 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  -o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_controller.o: ../src/Pervasive_Displays_small_EPD/EPD_controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_controller.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o: ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o: ../src/Pervasive_Displays_small_EPD/EPD_hardware_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_hardware_gpio.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/SpiRAM.o: ../src/Pervasive_Displays_small_EPD/SpiRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/SpiRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/SpiRAM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/SpiRAM.c  -o ${OBJECTDIR}/_ext/1846579039/SpiRAM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/SpiRAM.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/SpiRAM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o: ../src/gfx/resources_epd_demo_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gfx/resources_epd_demo_reference.c  -o ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/294057427/system.o: ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.7_v110_g1/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/294057427 
	@${RM} ${OBJECTDIR}/_ext/294057427/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/294057427/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.7_v110_g1/system.c  -o ${OBJECTDIR}/_ext/294057427/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/294057427/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/294057427/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1    -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1860783399/TimeDelay.o: ../../../Microchip/Common/TimeDelay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1860783399 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1860783399/TimeDelay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Common/TimeDelay.c  -o ${OBJECTDIR}/_ext/1860783399/TimeDelay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1860783399/TimeDelay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo1.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo1.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo1.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo2.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo2.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo2.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo3.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo3.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo3.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo4.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo4.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo4.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o: ../src/Demo\ Screen\ for\ 1.44\ inch/EPD_Demo_Home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/566230139 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o.d 
	@${RM} ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 1.44 inch/EPD_Demo_Home.c"  -o ${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/566230139/EPD_Demo_Home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo1.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo2.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo3.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo4.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o: ../src/Demo\ Screen\ for\ 2\ inch/EPD_Demo_Home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1830399008 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o.d 
	@${RM} ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2 inch/EPD_Demo_Home.c"  -o ${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1830399008/EPD_Demo_Home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo1.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo1.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo1.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo2.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo2.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo2.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo3.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo3.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo3.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo3.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo3.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo4.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo4.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo4.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo4.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo4.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o: ../src/Demo\ Screen\ for\ 2.7\ inch/EPD_Demo_Home.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/408667767 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o.d 
	@${RM} ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/Demo Screen for 2.7 inch/EPD_Demo_Home.c"  -o ${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/408667767/EPD_Demo_Home.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659856255/PDI\ e-paper\ display_driver.o: ../src/gfx/PDI\ e-paper\ display_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/PDI\ e-paper\ display_driver.o.d 
	@${RM} "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o" 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../src/gfx/PDI e-paper display_driver.c"  -o "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o"  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/PDI e-paper display_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Button.o: ../../../Microchip/Graphics/Button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Button.c  -o ${OBJECTDIR}/_ext/803622919/Button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Button.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/GOL.o: ../../../Microchip/Graphics/GOL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOL.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/GOL.c  -o ${OBJECTDIR}/_ext/803622919/GOL.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/GOL.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOL.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o: ../../../Microchip/Graphics/GOLSchemeDefault.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/GOLSchemeDefault.c  -o ${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/GOLSchemeDefault.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Picture.o: ../../../Microchip/Graphics/Picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Picture.c  -o ${OBJECTDIR}/_ext/803622919/Picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Picture.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Primitive.o: ../../../Microchip/Graphics/Primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Primitive.c  -o ${OBJECTDIR}/_ext/803622919/Primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Primitive.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/Slider.o: ../../../Microchip/Graphics/Slider.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/Slider.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/Slider.c  -o ${OBJECTDIR}/_ext/803622919/Slider.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/Slider.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/Slider.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/803622919/StaticText.o: ../../../Microchip/Graphics/StaticText.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/803622919 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o.d 
	@${RM} ${OBJECTDIR}/_ext/803622919/StaticText.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../Microchip/Graphics/StaticText.c  -o ${OBJECTDIR}/_ext/803622919/StaticText.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/803622919/StaticText.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/803622919/StaticText.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol.o: ../../../../../framework/gfx/src/gfx_gol.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o: ../../../../../framework/gfx/src/gfx_gol_button.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_button.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_button.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o: ../../../../../framework/gfx/src/gfx_gol_picture.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_picture.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_picture.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o: ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_scroll_bar.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_scroll_bar.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o: ../../../../../framework/gfx/src/gfx_gol_static_text.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_gol_static_text.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_gol_static_text.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1127269358/gfx_primitive.o: ../../../../../framework/gfx/src/gfx_primitive.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1127269358 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d 
	@${RM} ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../../../../framework/gfx/src/gfx_primitive.c  -o ${OBJECTDIR}/_ext/1127269358/gfx_primitive.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1127269358/gfx_primitive.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o: ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1702581813 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V110_G1/EPD_COG_process_V110_G1.c  -o ${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1702581813/EPD_COG_process_V110_G1.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o: ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1672105619 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/COG/V230_G2/EPD_COG_process_V230_G2.c  -o ${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1672105619/EPD_COG_process_V230_G2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_controller.o: ../src/Pervasive_Displays_small_EPD/EPD_controller.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_controller.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_controller.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_controller.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_controller.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o: ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_hardware_driver.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_hardware_driver.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o: ../src/Pervasive_Displays_small_EPD/EPD_hardware_gpio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/EPD_hardware_gpio.c  -o ${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/EPD_hardware_gpio.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1846579039/SpiRAM.o: ../src/Pervasive_Displays_small_EPD/SpiRAM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1846579039 
	@${RM} ${OBJECTDIR}/_ext/1846579039/SpiRAM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1846579039/SpiRAM.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/Pervasive_Displays_small_EPD/SpiRAM.c  -o ${OBJECTDIR}/_ext/1846579039/SpiRAM.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1846579039/SpiRAM.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1846579039/SpiRAM.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o: ../src/gfx/resources_epd_demo_reference.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o.d 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gfx/resources_epd_demo_reference.c  -o ${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/resources_epd_demo_reference.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/294057427/system.o: ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.7_v110_g1/system.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/294057427 
	@${RM} ${OBJECTDIR}/_ext/294057427/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/294057427/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/system_config/exp16_pic24fj128ga010_spi_epd_2.7_v110_g1/system.c  -o ${OBJECTDIR}/_ext/294057427/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/294057427/system.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/294057427/system.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1360937237 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -mlarge-code -O1 -I"../src/Pervasive_Displays_small_EPD" -I"../src/gfx" -I"../src/Demo Screen for 2 inch" -I"../src" -I".." -I"../../../Microchip/Include" -DUSE_EPD_Type=EPD_270 -DCOG_V230_G2 -msmart-io=1 -msfr-warn=off
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
${OBJECTDIR}/_ext/659856255/resources_epd_demo.o: ../src/gfx/resources_epd_demo.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/gfx/resources_epd_demo.S  -o ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.d"  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -Wa,-MD,"${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.asm.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.d" "${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/659856255/resources_epd_demo.o: ../src/gfx/resources_epd_demo.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/659856255 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.d 
	@${RM} ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  ../src/gfx/resources_epd_demo.S  -o ${OBJECTDIR}/_ext/659856255/resources_epd_demo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.d"  -omf=elf -Wa,-MD,"${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.asm.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.d" "${OBJECTDIR}/_ext/659856255/resources_epd_demo.o.asm.d"  -t $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/pic24f_pdi_epd_pictail_plus.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
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
	${RM} -r build/EPD_2.7inch_V230_G2
	${RM} -r dist/EPD_2.7inch_V230_G2

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
