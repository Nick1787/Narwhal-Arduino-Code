/*
 *        File: config.h
 *      Author: Nick Dodds <Nick1787@gmail.com>
 * Description: Configuration Options
 * ----------------------------------------------------------------
 *    Revision:
 *		01032015 - NRD - Initial Version
 *      08242019 - GAI - Added version date
 * ----------------------------------------------------------------
 */

#ifndef __config_h
#define __config_h

// Main Code version
#define VERSION 1.04
#define VERSIONDATE "08/24/2019"    // Update with version roll, keep same number of characters
#define SERIAL_VERBOSE 3			// 0 = Disabled, 1 = Enabled with Basic events, 2= Enabled with detailed events (i.e. ecoder values), 2= Enabled with debugging details (i.e. Page Item Count, etc.).

#ifndef A
#define A(x)  x,((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#endif

#endif
