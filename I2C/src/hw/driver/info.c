/*
 * info.c
 *
 * Created: 2023-11-18 오전 11:53:01
 *  Author: jymen
 */ 


 #include "info.h"
 #include "cli.h"


 #ifdef _USE_HW_INFO


 void cliInfo(cli_args_t *args);

 
 bool infoInit(void)
 {
	 cliAdd("info", cliInfo);

	 return true;
 }

 void cliInfo(cli_args_t *args)
 {
	 bool ret = false;

	 if (args->argc == 1 && args->isStr(0, "fuse") == true)
	 {
		 cliPrintf_P(PSTR("\nFUSE.WDTCFG      \t : 0x%08X\n"), FUSE.WDTCFG);
		 cliPrintf_P(PSTR("     WINDOW[3:0] \t : 0x%X\n"), (FUSE.WDTCFG >> FUSE_WINDOW_gp) & FUSE_WINDOW_gm);
		 cliPrintf_P(PSTR("     PERIOD[3:0] \t : 0x%X\n"), (FUSE.WDTCFG >> FUSE_PERIOD_gp) & FUSE_PERIOD_gm);

		 uint16_t reg;

		 // FUSE.BODCFG
		 //
		 cliPrintf_P(PSTR("\nFUSE.BODCFG      \t : 0x%08X\n"), FUSE.BODCFG);

		 const char * PROGMEM lvl_tbl[] = {PSTR("1.9V"), PSTR("2.45V"), PSTR("2.70V"), PSTR("2.85V")};
		 const char * PROGMEM sampfreq_tbl[] = {PSTR("128Hz"), PSTR("32Hz")};
		 const char * PROGMEM active_tbl[] = {PSTR("DISABLE"), PSTR("ENABLE"), PSTR("SAMPLE"), PSTR("ENABLEWAIT")};
		 const char * PROGMEM sleep_tbl[] = {PSTR("DISABLE"), PSTR("ENABLE"), PSTR("SAMPLE"), PSTR("Reserved")};

		 reg = (FUSE.BODCFG & FUSE_LVL_gm) >> FUSE_LVL_gp;
		 cliPrintf_P(PSTR("     LVL         \t : ")); cliPrintf_P(lvl_tbl[reg]); cliPrintf_P(PSTR("\n"));
		 reg = (FUSE.BODCFG & FUSE_SAMPFREQ_bm) >> FUSE_SAMPFREQ_bp;
		 cliPrintf_P(PSTR("     SAMPFREQ    \t : ")); cliPrintf_P(sampfreq_tbl[reg]); cliPrintf_P(PSTR("\n"));
		 reg = (FUSE.BODCFG & FUSE_ACTIVE_gm) >> FUSE_ACTIVE_gp;
		 cliPrintf_P(PSTR("     ACTIVE      \t : ")); cliPrintf_P(active_tbl[reg]); cliPrintf_P(PSTR("\n"));
		 reg = (FUSE.BODCFG & FUSE_SLEEP_gm) >> FUSE_SLEEP_gp;
		 cliPrintf_P(PSTR("     SLEEP       \t : ")); cliPrintf_P(sleep_tbl[reg]); cliPrintf_P(PSTR("\n"));


		 // FUSE.OSCCFG
		 //
		 cliPrintf_P(PSTR("\nFUSE.OSCCFG     \t : 0x%08X\n"), FUSE.OSCCFG);

		 const char * PROGMEM clksel_tbl[] = {PSTR("OSCHF"), PSTR("OSC32K")};

		 reg = (FUSE.OSCCFG & FUSE_FREQSEL_gm) >> FUSE_FREQSEL_gp;
		 cliPrintf_P(PSTR("     CLKSEL     \t : ")); cliPrintf_P(clksel_tbl[reg]); cliPrintf_P(PSTR("\n"));


		 // FUSE.SYSCFG0
		 //
		 cliPrintf_P(PSTR("\nFUSE.SYSCFG0    \t : 0x%08X\n"), FUSE.SYSCFG0);
		 const char * PROGMEM rstpincfg_tbl[] = {PSTR("INPUT PF6 configured as general input pin"),
			 PSTR("- "),
			 PSTR("RESET External Reset enabled on PF6"),
		 PSTR("- ")};
		 const char * PROGMEM eesave_tbl[] = {PSTR("EEPROM erased during Chip Erase"), PSTR("EEPROM not erased under Chip Erase")};

		 reg = (FUSE.SYSCFG0 & FUSE_RSTPINCFG_gm) >> FUSE_RSTPINCFG_gp;
		 cliPrintf_P(PSTR("     RSTPINCFG  \t : ")); cliPrintf_P(rstpincfg_tbl[reg]); cliPrintf_P(PSTR("\n"));
		 reg = (FUSE.SYSCFG0 & FUSE_EESAVE_bm) >> FUSE_EESAVE_bp;
		 cliPrintf_P(PSTR("     EESAVE     \t : ")); cliPrintf_P(eesave_tbl[reg]); cliPrintf_P(PSTR("\n"));


		 // FUSE.SYSCFG0
		 //
		 cliPrintf_P(PSTR("\nFUSE.SYSCFG1    \t : 0x%08X\n"), FUSE.SYSCFG1);

		 const char * PROGMEM sut_tbl[] = {PSTR("0 ms"), PSTR("1 ms"), PSTR("2 ms"), PSTR("4 ms"),
		 PSTR("8 ms"), PSTR("16 ms"), PSTR("32 ms"), PSTR("64 ms")};

		 reg = (FUSE.SYSCFG1 & FUSE_SUT_gm) >> FUSE_SUT_gp;
		 cliPrintf_P(PSTR("     SUT          \t : ")); cliPrintf_P(sut_tbl[reg]); cliPrintf_P(PSTR("\n"));


		 // FUSE.BOOTSIZE
		 //
		 cliPrintf_P(PSTR("\nFUSE.BOOTEND   \t : 0x%08X\n"), FUSE.BOOTEND);
		 cliPrintf_P(PSTR("     BOOTEND     \t : %d KB\n"), FUSE.BOOTEND*512/1024);

		 // FUSE.CODESIZE
		 //
		 cliPrintf_P(PSTR("\nFUSE.APPEND   \t : 0x%08X\n"), FUSE.APPEND);
		 cliPrintf_P(PSTR("     APPEND     \t : %d KB\n"), FUSE.APPEND*512/1024);

		 ret = true;
	 }

	 if (ret != true)
	 {
		 cliPrintf_P(PSTR("info fuse\n"));
	 }
 }

 #endif
 