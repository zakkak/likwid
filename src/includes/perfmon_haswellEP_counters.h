/*
 * =======================================================================================
 *
 *      Filename:  perfmon_haswellEP_counters.h
 *
 *      Description:  Counter Header File of perfmon module for Intel Haswell EP/EN/EX.
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:   Jan Treibig (jt), jan.treibig@gmail.com
 *                Thomas Roehl (tr), thomas.roehl@googlemail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2015 RRZE, University Erlangen-Nuremberg
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_HASWELL_EP 187
#define NUM_COUNTERS_CORE_HASWELL_EP 8
#define NUM_COUNTERS_UNCORE_HASWELL_EP 111

#define HAS_EP_VALID_OPTIONS_FIXED EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_COUNT_KERNEL_MASK
#define HAS_EP_VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK|EVENT_OPTION_INVERT_MASK| \
            EVENT_OPTION_ANYTHREAD_MASK|EVENT_OPTION_IN_TRANS_MASK|EVENT_OPTION_THRESHOLD_MASK
#define HAS_EP_VALID_OPTIONS_CBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_TID_MASK
#define HAS_EP_VALID_OPTIONS_UBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define HAS_EP_VALID_OPTIONS_SBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_TID_MASK
#define HAS_EP_VALID_OPTIONS_BBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define HAS_EP_VALID_OPTIONS_WBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK|\
            EVENT_OPTION_OCCUPANCY_MASK|EVENT_OPTION_OCCUPANCY_FILTER_MASK|EVENT_OPTION_OCCUPANCY_EDGE_MASK|\
            EVENT_OPTION_OCCUPANCY_INVERT_MASK
#define HAS_EP_VALID_OPTIONS_MBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define HAS_EP_VALID_OPTIONS_IBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define HAS_EP_VALID_OPTIONS_PBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define HAS_EP_VALID_OPTIONS_RBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK
#define HAS_EP_VALID_OPTIONS_QBOX EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK

static RegisterMap haswellEP_counter_map[NUM_COUNTERS_HASWELL_EP] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, HAS_EP_VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, HAS_EP_VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, HAS_EP_VALID_OPTIONS_PMC|EVENT_OPTION_IN_TRANS_ABORT_MASK},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, HAS_EP_VALID_OPTIONS_PMC},
    /* Temperature Sensor*/
    {"TMP0", PMC7, THERMAL, 0, IA32_THERM_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    /* RAPL counters */
    {"PWR0", PMC8, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR1", PMC9, POWER, 0, MSR_PP0_ENERGY_STATUS, 0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR2", PMC10, POWER, 0, MSR_PP1_ENERGY_STATUS,  0, 0, EVENT_OPTION_NONE_MASK},
    {"PWR3", PMC11, POWER, 0, MSR_DRAM_ENERGY_STATUS,  0, 0, EVENT_OPTION_NONE_MASK},
    {"CBOX0C0", PMC12, CBOX0, MSR_UNC_V3_C0_PMON_CTL0, MSR_UNC_V3_C0_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX0C1", PMC13, CBOX0, MSR_UNC_V3_C0_PMON_CTL1, MSR_UNC_V3_C0_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX0C2", PMC14, CBOX0, MSR_UNC_V3_C0_PMON_CTL2, MSR_UNC_V3_C0_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX0C3", PMC15, CBOX0, MSR_UNC_V3_C0_PMON_CTL3, MSR_UNC_V3_C0_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX1C0", PMC16, CBOX1, MSR_UNC_V3_C1_PMON_CTL0, MSR_UNC_V3_C1_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX1C1", PMC17, CBOX1, MSR_UNC_V3_C1_PMON_CTL1, MSR_UNC_V3_C1_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX1C2", PMC18, CBOX1, MSR_UNC_V3_C1_PMON_CTL2, MSR_UNC_V3_C1_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX1C3", PMC19, CBOX1, MSR_UNC_V3_C1_PMON_CTL3, MSR_UNC_V3_C1_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX2C0", PMC20, CBOX2, MSR_UNC_V3_C2_PMON_CTL0, MSR_UNC_V3_C2_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX2C1", PMC21, CBOX2, MSR_UNC_V3_C2_PMON_CTL1, MSR_UNC_V3_C2_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX2C2", PMC22, CBOX2, MSR_UNC_V3_C2_PMON_CTL2, MSR_UNC_V3_C2_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX2C3", PMC23, CBOX2, MSR_UNC_V3_C2_PMON_CTL3, MSR_UNC_V3_C2_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX3C0", PMC24, CBOX3, MSR_UNC_V3_C3_PMON_CTL0, MSR_UNC_V3_C3_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX3C1", PMC25, CBOX3, MSR_UNC_V3_C3_PMON_CTL1, MSR_UNC_V3_C3_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX3C2", PMC26, CBOX3, MSR_UNC_V3_C3_PMON_CTL2, MSR_UNC_V3_C3_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX3C3", PMC27, CBOX3, MSR_UNC_V3_C3_PMON_CTL3, MSR_UNC_V3_C3_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX4C0", PMC28, CBOX4, MSR_UNC_V3_C4_PMON_CTL0, MSR_UNC_V3_C4_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX4C1", PMC29, CBOX4, MSR_UNC_V3_C4_PMON_CTL1, MSR_UNC_V3_C4_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX4C2", PMC30, CBOX4, MSR_UNC_V3_C4_PMON_CTL2, MSR_UNC_V3_C4_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX4C3", PMC31, CBOX4, MSR_UNC_V3_C4_PMON_CTL3, MSR_UNC_V3_C4_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX5C0", PMC32, CBOX5, MSR_UNC_V3_C5_PMON_CTL0, MSR_UNC_V3_C5_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX5C1", PMC33, CBOX5, MSR_UNC_V3_C5_PMON_CTL1, MSR_UNC_V3_C5_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX5C2", PMC34, CBOX5, MSR_UNC_V3_C5_PMON_CTL2, MSR_UNC_V3_C5_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX5C3", PMC35, CBOX5, MSR_UNC_V3_C5_PMON_CTL3, MSR_UNC_V3_C5_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX6C0", PMC36, CBOX6, MSR_UNC_V3_C6_PMON_CTL0, MSR_UNC_V3_C6_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX6C1", PMC37, CBOX6, MSR_UNC_V3_C6_PMON_CTL1, MSR_UNC_V3_C6_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX6C2", PMC38, CBOX6, MSR_UNC_V3_C6_PMON_CTL2, MSR_UNC_V3_C6_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX6C3", PMC39, CBOX6, MSR_UNC_V3_C6_PMON_CTL3, MSR_UNC_V3_C6_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX7C0", PMC40, CBOX7, MSR_UNC_V3_C7_PMON_CTL0, MSR_UNC_V3_C7_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX7C1", PMC41, CBOX7, MSR_UNC_V3_C7_PMON_CTL1, MSR_UNC_V3_C7_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX7C2", PMC42, CBOX7, MSR_UNC_V3_C7_PMON_CTL2, MSR_UNC_V3_C7_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX7C3", PMC43, CBOX7, MSR_UNC_V3_C7_PMON_CTL3, MSR_UNC_V3_C7_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX8C0", PMC44, CBOX8, MSR_UNC_V3_C8_PMON_CTL0, MSR_UNC_V3_C8_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX8C1", PMC45, CBOX8, MSR_UNC_V3_C8_PMON_CTL1, MSR_UNC_V3_C8_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX8C2", PMC46, CBOX8, MSR_UNC_V3_C8_PMON_CTL2, MSR_UNC_V3_C8_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX8C3", PMC47, CBOX8, MSR_UNC_V3_C8_PMON_CTL3, MSR_UNC_V3_C8_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX9C0", PMC48, CBOX9, MSR_UNC_V3_C9_PMON_CTL0, MSR_UNC_V3_C9_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX9C1", PMC49, CBOX9, MSR_UNC_V3_C9_PMON_CTL1, MSR_UNC_V3_C9_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX9C2", PMC50, CBOX9, MSR_UNC_V3_C9_PMON_CTL2, MSR_UNC_V3_C9_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX9C3", PMC51, CBOX9, MSR_UNC_V3_C9_PMON_CTL3, MSR_UNC_V3_C9_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX10C0", PMC52, CBOX10, MSR_UNC_V3_C10_PMON_CTL0, MSR_UNC_V3_C10_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX10C1", PMC53, CBOX10, MSR_UNC_V3_C10_PMON_CTL1, MSR_UNC_V3_C10_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX10C2", PMC54, CBOX10, MSR_UNC_V3_C10_PMON_CTL2, MSR_UNC_V3_C10_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX10C3", PMC55, CBOX10, MSR_UNC_V3_C10_PMON_CTL3, MSR_UNC_V3_C10_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX11C0", PMC56, CBOX11, MSR_UNC_V3_C11_PMON_CTL0, MSR_UNC_V3_C11_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX11C1", PMC57, CBOX11, MSR_UNC_V3_C11_PMON_CTL1, MSR_UNC_V3_C11_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX11C2", PMC58, CBOX11, MSR_UNC_V3_C11_PMON_CTL2, MSR_UNC_V3_C11_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX11C3", PMC59, CBOX11, MSR_UNC_V3_C11_PMON_CTL3, MSR_UNC_V3_C11_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX12C0", PMC60, CBOX12, MSR_UNC_V3_C12_PMON_CTL0, MSR_UNC_V3_C12_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX12C1", PMC61, CBOX12, MSR_UNC_V3_C12_PMON_CTL1, MSR_UNC_V3_C12_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX12C2", PMC62, CBOX12, MSR_UNC_V3_C12_PMON_CTL2, MSR_UNC_V3_C12_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX12C3", PMC63, CBOX12, MSR_UNC_V3_C12_PMON_CTL3, MSR_UNC_V3_C12_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX13C0", PMC64, CBOX13, MSR_UNC_V3_C13_PMON_CTL0, MSR_UNC_V3_C13_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX13C1", PMC65, CBOX13, MSR_UNC_V3_C13_PMON_CTL1, MSR_UNC_V3_C13_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX13C2", PMC66, CBOX13, MSR_UNC_V3_C13_PMON_CTL2, MSR_UNC_V3_C13_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX13C3", PMC67, CBOX13, MSR_UNC_V3_C13_PMON_CTL3, MSR_UNC_V3_C13_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX14C0", PMC68, CBOX14, MSR_UNC_V3_C14_PMON_CTL0, MSR_UNC_V3_C14_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX14C1", PMC69, CBOX14, MSR_UNC_V3_C14_PMON_CTL1, MSR_UNC_V3_C14_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX14C2", PMC70, CBOX14, MSR_UNC_V3_C14_PMON_CTL2, MSR_UNC_V3_C14_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX14C3", PMC71, CBOX14, MSR_UNC_V3_C14_PMON_CTL3, MSR_UNC_V3_C14_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX15C0", PMC72, CBOX15, MSR_UNC_V3_C15_PMON_CTL0, MSR_UNC_V3_C15_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX15C1", PMC73, CBOX15, MSR_UNC_V3_C15_PMON_CTL1, MSR_UNC_V3_C15_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX15C2", PMC74, CBOX15, MSR_UNC_V3_C15_PMON_CTL2, MSR_UNC_V3_C15_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX15C3", PMC75, CBOX15, MSR_UNC_V3_C15_PMON_CTL3, MSR_UNC_V3_C15_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX16C0", PMC76, CBOX16, MSR_UNC_V3_C16_PMON_CTL0, MSR_UNC_V3_C16_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX16C1", PMC77, CBOX16, MSR_UNC_V3_C16_PMON_CTL1, MSR_UNC_V3_C16_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX16C2", PMC78, CBOX16, MSR_UNC_V3_C16_PMON_CTL2, MSR_UNC_V3_C16_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX16C3", PMC79, CBOX16, MSR_UNC_V3_C16_PMON_CTL3, MSR_UNC_V3_C16_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX17C0", PMC80, CBOX17, MSR_UNC_V3_C17_PMON_CTL0, MSR_UNC_V3_C17_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX17C1", PMC81, CBOX17, MSR_UNC_V3_C17_PMON_CTL1, MSR_UNC_V3_C17_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX17C2", PMC82, CBOX17, MSR_UNC_V3_C17_PMON_CTL2, MSR_UNC_V3_C17_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"CBOX17C3", PMC83, CBOX17, MSR_UNC_V3_C17_PMON_CTL3, MSR_UNC_V3_C17_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_CBOX},
    {"UBOX0", PMC84, UBOX, MSR_UNC_V3_U_PMON_CTL0, MSR_UNC_V3_U_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_UBOX},
    {"UBOX1", PMC85, UBOX, MSR_UNC_V3_U_PMON_CTL1, MSR_UNC_V3_U_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_UBOX},
    {"UBOXFIX", PMC86, UBOXFIX, MSR_UNC_V3_U_UCLK_FIXED_CTL, MSR_UNC_V3_U_UCLK_FIXED_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"SBOX0C0", PMC87, SBOX0, MSR_UNC_V3_S0_PMON_CTL_0, MSR_UNC_V3_S0_PMON_CTR_0, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX0C1", PMC88, SBOX0, MSR_UNC_V3_S0_PMON_CTL_1, MSR_UNC_V3_S0_PMON_CTR_1, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX0C2", PMC89, SBOX0, MSR_UNC_V3_S0_PMON_CTL_2, MSR_UNC_V3_S0_PMON_CTR_2, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX0C3", PMC90, SBOX0, MSR_UNC_V3_S0_PMON_CTL_3, MSR_UNC_V3_S0_PMON_CTR_3, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX1C0", PMC91, SBOX1, MSR_UNC_V3_S1_PMON_CTL_0, MSR_UNC_V3_S1_PMON_CTR_0, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX1C1", PMC92, SBOX1, MSR_UNC_V3_S1_PMON_CTL_1, MSR_UNC_V3_S1_PMON_CTR_1, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX1C2", PMC93, SBOX1, MSR_UNC_V3_S1_PMON_CTL_2, MSR_UNC_V3_S1_PMON_CTR_2, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX1C3", PMC94, SBOX1, MSR_UNC_V3_S1_PMON_CTL_3, MSR_UNC_V3_S1_PMON_CTR_3, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX2C0", PMC95, SBOX2, MSR_UNC_V3_S2_PMON_CTL_0, MSR_UNC_V3_S2_PMON_CTR_0, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX2C1", PMC96, SBOX2, MSR_UNC_V3_S2_PMON_CTL_1, MSR_UNC_V3_S2_PMON_CTR_1, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX2C2", PMC97, SBOX2, MSR_UNC_V3_S2_PMON_CTL_2, MSR_UNC_V3_S2_PMON_CTR_2, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX2C3", PMC98, SBOX2, MSR_UNC_V3_S2_PMON_CTL_3, MSR_UNC_V3_S2_PMON_CTR_3, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX3C0", PMC99, SBOX3, MSR_UNC_V3_S3_PMON_CTL_0, MSR_UNC_V3_S3_PMON_CTR_0, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX3C1", PMC100, SBOX3, MSR_UNC_V3_S3_PMON_CTL_1, MSR_UNC_V3_S3_PMON_CTR_1, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX3C2", PMC101, SBOX3, MSR_UNC_V3_S3_PMON_CTL_2, MSR_UNC_V3_S3_PMON_CTR_2, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"SBOX3C3", PMC102, SBOX3, MSR_UNC_V3_S3_PMON_CTL_3, MSR_UNC_V3_S3_PMON_CTR_3, 0, 0, HAS_EP_VALID_OPTIONS_SBOX},
    {"WBOX0", PMC103, WBOX, MSR_UNC_V3_PCU_PMON_CTL0, MSR_UNC_V3_PCU_PMON_CTR0, 0, 0, HAS_EP_VALID_OPTIONS_WBOX},
    {"WBOX1", PMC104, WBOX, MSR_UNC_V3_PCU_PMON_CTL1, MSR_UNC_V3_PCU_PMON_CTR1, 0, 0, HAS_EP_VALID_OPTIONS_WBOX},
    {"WBOX2", PMC105, WBOX, MSR_UNC_V3_PCU_PMON_CTL2, MSR_UNC_V3_PCU_PMON_CTR2, 0, 0, HAS_EP_VALID_OPTIONS_WBOX},
    {"WBOX3", PMC106, WBOX, MSR_UNC_V3_PCU_PMON_CTL3, MSR_UNC_V3_PCU_PMON_CTR3, 0, 0, HAS_EP_VALID_OPTIONS_WBOX},
    {"WBOX0FIX", PMC107, WBOX0FIX, 0, MSR_UNC_V3_PCU_CC6_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOX1FIX", PMC108, WBOX0FIX, 0, MSR_UNC_V3_PCU_CC3_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOX2FIX", PMC109, WBOX0FIX, 0, MSR_UNC_V3_PCU_PC2_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOX3FIX", PMC110, WBOX0FIX, 0, MSR_UNC_V3_PCU_PC3_CTR , 0, 0, EVENT_OPTION_NONE_MASK},
    {"BBOX0C0", PMC111, BBOX0, PCI_UNC_HA_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_0, HAS_EP_VALID_OPTIONS_BBOX},
    {"BBOX0C1", PMC112, BBOX0, PCI_UNC_HA_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_0, HAS_EP_VALID_OPTIONS_BBOX},
    {"BBOX0C2", PMC113, BBOX0, PCI_UNC_HA_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_0, HAS_EP_VALID_OPTIONS_BBOX},
    {"BBOX0C3", PMC114, BBOX0, PCI_UNC_HA_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_0, HAS_EP_VALID_OPTIONS_BBOX},
    {"BBOX1C0", PMC115, BBOX1, PCI_UNC_HA_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE_1, HAS_EP_VALID_OPTIONS_BBOX},
    {"BBOX1C1", PMC116, BBOX1, PCI_UNC_HA_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE_1, HAS_EP_VALID_OPTIONS_BBOX},
    {"BBOX1C2", PMC117, BBOX1, PCI_UNC_HA_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE_1, HAS_EP_VALID_OPTIONS_BBOX},
    {"BBOX1C3", PMC118, BBOX1, PCI_UNC_HA_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE_1, HAS_EP_VALID_OPTIONS_BBOX},
    {"MBOX0C0", PMC119, MBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0C1", PMC120, MBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0C2", PMC121, MBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0C3", PMC122, MBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC123, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX1C0", PMC124, MBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX1C1", PMC125, MBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX1C2", PMC126, MBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX1C3", PMC127, MBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC128, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX2C0", PMC129, MBOX2, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX2C1", PMC130, MBOX2, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX2C2", PMC131, MBOX2, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX2C3", PMC132, MBOX2, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC133, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX3C0", PMC134, MBOX3, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_0_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX3C1", PMC135, MBOX3, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_0_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX3C2", PMC136, MBOX3, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_0_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX3C3", PMC137, MBOX3, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_0_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC138, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX4C0", PMC139, MBOX4, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX4C1", PMC140, MBOX4, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX4C2", PMC141, MBOX4, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX4C3", PMC142, MBOX4, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_0, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC43, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX5C0", PMC144, MBOX5, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX5C1", PMC145, MBOX5, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX5C2", PMC146, MBOX5, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX5C3", PMC147, MBOX5, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_1, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC148, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX6C0", PMC149, MBOX6, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX6C1", PMC150, MBOX6, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX6C2", PMC151, MBOX6, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX6C3", PMC152, MBOX6, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_2, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC153, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX7C0", PMC154, MBOX7, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_1_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX7C1", PMC155, MBOX7, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_1_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX7C2", PMC156, MBOX7, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_1_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX7C3", PMC157, MBOX7, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_1_CH_3, HAS_EP_VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC158, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_0_CH_0, EVENT_OPTION_NONE_MASK},
    {"IBOX0C0", PMC159, IBOX0, PCI_UNC_IRP0_PMON_CTL_0, PCI_UNC_IRP0_PMON_CTR_0, 0, PCI_IRP_DEVICE, HAS_EP_VALID_OPTIONS_IBOX},
    {"IBOX0C1", PMC160, IBOX0, PCI_UNC_IRP0_PMON_CTL_1, PCI_UNC_IRP0_PMON_CTR_1, 0, PCI_IRP_DEVICE, HAS_EP_VALID_OPTIONS_IBOX},
    {"IBOX1C0", PMC161, IBOX1, PCI_UNC_IRP1_PMON_CTL_0, PCI_UNC_IRP1_PMON_CTR_0, 0, PCI_IRP_DEVICE, HAS_EP_VALID_OPTIONS_IBOX},
    {"IBOX1C1", PMC162, IBOX1, PCI_UNC_IRP1_PMON_CTL_1, PCI_UNC_IRP1_PMON_CTR_1, 0, PCI_IRP_DEVICE, HAS_EP_VALID_OPTIONS_IBOX},
    {"PBOX0", PMC163, PBOX, PCI_UNC_R2PCIE_PMON_CTL_0, PCI_UNC_R2PCIE_PMON_CTR_0_A, PCI_UNC_R2PCIE_PMON_CTR_0_B, PCI_R2PCIE_DEVICE, HAS_EP_VALID_OPTIONS_PBOX},
    {"PBOX1", PMC164, PBOX, PCI_UNC_R2PCIE_PMON_CTL_1, PCI_UNC_R2PCIE_PMON_CTR_1_A, PCI_UNC_R2PCIE_PMON_CTR_1_B, PCI_R2PCIE_DEVICE, HAS_EP_VALID_OPTIONS_PBOX},
    {"PBOX2", PMC165, PBOX, PCI_UNC_R2PCIE_PMON_CTL_2, PCI_UNC_R2PCIE_PMON_CTR_2_A, PCI_UNC_R2PCIE_PMON_CTR_2_B, PCI_R2PCIE_DEVICE, HAS_EP_VALID_OPTIONS_PBOX},
    {"PBOX3", PMC166, PBOX, PCI_UNC_R2PCIE_PMON_CTL_3, PCI_UNC_R2PCIE_PMON_CTR_3_A, PCI_UNC_R2PCIE_PMON_CTR_3_B, PCI_R2PCIE_DEVICE, HAS_EP_VALID_OPTIONS_PBOX},
    {"RBOX0C0", PMC167, RBOX0, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_0, HAS_EP_VALID_OPTIONS_RBOX},
    {"RBOX0C1", PMC168, RBOX0, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_0, HAS_EP_VALID_OPTIONS_RBOX},
    {"RBOX0C2", PMC169, RBOX0, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_0, HAS_EP_VALID_OPTIONS_RBOX},
    {"RBOX1C0", PMC170, RBOX1, PCI_UNC_R3QPI_PMON_CTL_0, PCI_UNC_R3QPI_PMON_CTR_0_A, PCI_UNC_R3QPI_PMON_CTR_0_B, PCI_R3QPI_DEVICE_LINK_1, HAS_EP_VALID_OPTIONS_RBOX},
    {"RBOX1C1", PMC171, RBOX1, PCI_UNC_R3QPI_PMON_CTL_1, PCI_UNC_R3QPI_PMON_CTR_1_A, PCI_UNC_R3QPI_PMON_CTR_1_B, PCI_R3QPI_DEVICE_LINK_1, HAS_EP_VALID_OPTIONS_RBOX},
    {"RBOX1C2", PMC172, RBOX1, PCI_UNC_R3QPI_PMON_CTL_2, PCI_UNC_R3QPI_PMON_CTR_2_A, PCI_UNC_R3QPI_PMON_CTR_2_B, PCI_R3QPI_DEVICE_LINK_1, HAS_EP_VALID_OPTIONS_RBOX},
    {"QBOX0C0", PMC173, QBOX0, PCI_UNC_V3_QPI_PMON_CTL_0, PCI_UNC_V3_QPI_PMON_CTR_0_A, PCI_UNC_V3_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_0, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX0C1", PMC174, QBOX0, PCI_UNC_V3_QPI_PMON_CTL_1, PCI_UNC_V3_QPI_PMON_CTR_1_A, PCI_UNC_V3_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_0, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX0C2", PMC175, QBOX0, PCI_UNC_V3_QPI_PMON_CTL_2, PCI_UNC_V3_QPI_PMON_CTR_2_A, PCI_UNC_V3_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_0, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX0C3", PMC176, QBOX0, PCI_UNC_V3_QPI_PMON_CTL_3, PCI_UNC_V3_QPI_PMON_CTR_3_A, PCI_UNC_V3_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_0, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX1C0", PMC177, QBOX1, PCI_UNC_V3_QPI_PMON_CTL_0, PCI_UNC_V3_QPI_PMON_CTR_0_A, PCI_UNC_V3_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_1, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX1C1", PMC178, QBOX1, PCI_UNC_V3_QPI_PMON_CTL_1, PCI_UNC_V3_QPI_PMON_CTR_1_A, PCI_UNC_V3_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_1, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX1C2", PMC179, QBOX1, PCI_UNC_V3_QPI_PMON_CTL_2, PCI_UNC_V3_QPI_PMON_CTR_2_A, PCI_UNC_V3_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_1, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX1C3", PMC180, QBOX1, PCI_UNC_V3_QPI_PMON_CTL_3, PCI_UNC_V3_QPI_PMON_CTR_3_A, PCI_UNC_V3_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_1, HAS_EP_VALID_OPTIONS_QBOX},
    {"QBOX0FIX0", PMC181, QBOX0FIX, 0x0, PCI_UNC_V3_QPI_RATE_STATUS, 0x0, PCI_QPI_MISC_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"QBOX0FIX1", PMC182, QBOX0FIX, 0x0, PCI_UNC_V3_QPI_LINK_IDLE, 0x0, PCI_QPI_MISC_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"QBOX0FIX2", PMC183, QBOX0FIX, 0x0, PCI_UNC_V3_QPI_LINK_LLR, 0x0, PCI_QPI_MISC_DEVICE_PORT_0, EVENT_OPTION_NONE_MASK},
    {"QBOX1FIX0", PMC184, QBOX1FIX, 0x0, PCI_UNC_V3_QPI_RATE_STATUS, 0x0, PCI_QPI_MISC_DEVICE_PORT_1, EVENT_OPTION_NONE_MASK},
    {"QBOX1FIX1", PMC185, QBOX1FIX, 0x0, PCI_UNC_V3_QPI_LINK_IDLE, 0x0, PCI_QPI_MISC_DEVICE_PORT_1, EVENT_OPTION_NONE_MASK},
    {"QBOX1FIX2", PMC186, QBOX1FIX, 0x0, PCI_UNC_V3_QPI_LINK_LLR, 0x0, PCI_QPI_MISC_DEVICE_PORT_1, EVENT_OPTION_NONE_MASK},
};


static BoxMap haswellEP_box_map[NUM_UNITS] = {
    [PMC] = {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, -1, 0, 0, 48},
    [THERMAL] = {0,0,0,-1,0,0,8},
    [FIXED] =  {MSR_PERF_GLOBAL_CTRL, MSR_PERF_GLOBAL_STATUS, MSR_PERF_GLOBAL_OVF_CTRL, -1, 0, 0, 48},
    [POWER] = {0,0,0,-1,0,0,32},
    [CBOX0] = {MSR_UNC_V3_C0_PMON_BOX_CTL, MSR_UNC_V3_C0_PMON_BOX_STATUS, MSR_UNC_V3_C0_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C0_PMON_BOX_FILTER0, MSR_UNC_V3_C0_PMON_BOX_FILTER1},
    [CBOX1] = {MSR_UNC_V3_C1_PMON_BOX_CTL, MSR_UNC_V3_C1_PMON_BOX_STATUS, MSR_UNC_V3_C1_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C1_PMON_BOX_FILTER0, MSR_UNC_V3_C1_PMON_BOX_FILTER1},
    [CBOX2] = {MSR_UNC_V3_C2_PMON_BOX_CTL, MSR_UNC_V3_C2_PMON_BOX_STATUS, MSR_UNC_V3_C2_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C2_PMON_BOX_FILTER0, MSR_UNC_V3_C2_PMON_BOX_FILTER1},
    [CBOX3] = {MSR_UNC_V3_C3_PMON_BOX_CTL, MSR_UNC_V3_C3_PMON_BOX_STATUS, MSR_UNC_V3_C3_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C3_PMON_BOX_FILTER0, MSR_UNC_V3_C3_PMON_BOX_FILTER1},
    [CBOX4] = {MSR_UNC_V3_C4_PMON_BOX_CTL, MSR_UNC_V3_C4_PMON_BOX_STATUS, MSR_UNC_V3_C4_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C4_PMON_BOX_FILTER0, MSR_UNC_V3_C4_PMON_BOX_FILTER1},
    [CBOX5] = {MSR_UNC_V3_C5_PMON_BOX_CTL, MSR_UNC_V3_C5_PMON_BOX_STATUS, MSR_UNC_V3_C5_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C5_PMON_BOX_FILTER0, MSR_UNC_V3_C5_PMON_BOX_FILTER1},
    [CBOX6] = {MSR_UNC_V3_C6_PMON_BOX_CTL, MSR_UNC_V3_C6_PMON_BOX_STATUS, MSR_UNC_V3_C6_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C6_PMON_BOX_FILTER0, MSR_UNC_V3_C6_PMON_BOX_FILTER1},
    [CBOX7] = {MSR_UNC_V3_C7_PMON_BOX_CTL, MSR_UNC_V3_C7_PMON_BOX_STATUS, MSR_UNC_V3_C7_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C7_PMON_BOX_FILTER0, MSR_UNC_V3_C7_PMON_BOX_FILTER1},
    [CBOX8] = {MSR_UNC_V3_C8_PMON_BOX_CTL, MSR_UNC_V3_C8_PMON_BOX_STATUS, MSR_UNC_V3_C8_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C8_PMON_BOX_FILTER0, MSR_UNC_V3_C8_PMON_BOX_FILTER1},
    [CBOX9] = {MSR_UNC_V3_C9_PMON_BOX_CTL, MSR_UNC_V3_C9_PMON_BOX_STATUS, MSR_UNC_V3_C9_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C9_PMON_BOX_FILTER0, MSR_UNC_V3_C9_PMON_BOX_FILTER1},
    [CBOX10] = {MSR_UNC_V3_C10_PMON_BOX_CTL, MSR_UNC_V3_C10_PMON_BOX_STATUS, MSR_UNC_V3_C10_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C10_PMON_BOX_FILTER0, MSR_UNC_V3_C10_PMON_BOX_FILTER1},
    [CBOX11] = {MSR_UNC_V3_C11_PMON_BOX_CTL, MSR_UNC_V3_C11_PMON_BOX_STATUS, MSR_UNC_V3_C11_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C11_PMON_BOX_FILTER0, MSR_UNC_V3_C11_PMON_BOX_FILTER1},
    [CBOX12] = {MSR_UNC_V3_C12_PMON_BOX_CTL, MSR_UNC_V3_C12_PMON_BOX_STATUS, MSR_UNC_V3_C12_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C12_PMON_BOX_FILTER0, MSR_UNC_V3_C12_PMON_BOX_FILTER1},
    [CBOX13] = {MSR_UNC_V3_C13_PMON_BOX_CTL, MSR_UNC_V3_C13_PMON_BOX_STATUS, MSR_UNC_V3_C13_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C13_PMON_BOX_FILTER0, MSR_UNC_V3_C13_PMON_BOX_FILTER1},
    [CBOX14] = {MSR_UNC_V3_C14_PMON_BOX_CTL, MSR_UNC_V3_C14_PMON_BOX_STATUS, MSR_UNC_V3_C14_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C14_PMON_BOX_FILTER0, MSR_UNC_V3_C14_PMON_BOX_FILTER1},
    [CBOX15] = {MSR_UNC_V3_C15_PMON_BOX_CTL, MSR_UNC_V3_C15_PMON_BOX_STATUS, MSR_UNC_V3_C15_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C15_PMON_BOX_FILTER0, MSR_UNC_V3_C15_PMON_BOX_FILTER1},
    [CBOX16] = {MSR_UNC_V3_C16_PMON_BOX_CTL, MSR_UNC_V3_C16_PMON_BOX_STATUS, MSR_UNC_V3_C16_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C16_PMON_BOX_FILTER0, MSR_UNC_V3_C16_PMON_BOX_FILTER1},
    [CBOX17] = {MSR_UNC_V3_C17_PMON_BOX_CTL, MSR_UNC_V3_C17_PMON_BOX_STATUS, MSR_UNC_V3_C17_PMON_BOX_STATUS, -1, 0, 0, 48, MSR_UNC_V3_C17_PMON_BOX_FILTER0, MSR_UNC_V3_C17_PMON_BOX_FILTER1},
    [UBOX] = {0, MSR_UNC_V3_U_PMON_BOX_STATUS, MSR_UNC_V3_U_PMON_BOX_STATUS, 1, 0, 0, 48},
    [UBOXFIX] = {0, MSR_UNC_V3_U_PMON_BOX_STATUS, MSR_UNC_V3_U_PMON_BOX_STATUS, 0, 0, 0, 48},
    [SBOX0] = {MSR_UNC_V3_S0_PMON_BOX_CTL, MSR_UNC_V3_S0_PMON_BOX_STATUS, MSR_UNC_V3_S0_PMON_BOX_STATUS, -1, 0, 0, 48},
    [SBOX1] = {MSR_UNC_V3_S1_PMON_BOX_CTL, MSR_UNC_V3_S1_PMON_BOX_STATUS, MSR_UNC_V3_S1_PMON_BOX_STATUS, -1, 0, 0, 48},
    [SBOX2] = {MSR_UNC_V3_S2_PMON_BOX_CTL, MSR_UNC_V3_S2_PMON_BOX_STATUS, MSR_UNC_V3_S2_PMON_BOX_STATUS, -1, 0, 0, 48},
    [SBOX3] = {MSR_UNC_V3_S3_PMON_BOX_CTL, MSR_UNC_V3_S3_PMON_BOX_STATUS, MSR_UNC_V3_S3_PMON_BOX_STATUS, -1, 0, 0, 48},
    [WBOX] = {MSR_UNC_V3_PCU_PMON_BOX_CTL, MSR_UNC_V3_PCU_PMON_BOX_STATUS,MSR_UNC_V3_PCU_PMON_BOX_STATUS, 2, 0, 0, 48, MSR_UNC_V3_PCU_PMON_BOX_FILTER},
    [WBOX0FIX] = {0,0,0,-1,0,0,64},
    [BBOX0] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 21, 1, PCI_HA_DEVICE_0, 48},
    [BBOX1] = {PCI_UNC_HA_PMON_BOX_CTL, PCI_UNC_HA_PMON_BOX_STATUS, PCI_UNC_HA_PMON_BOX_STATUS, 22, 1, PCI_HA_DEVICE_1, 48},
    [MBOX0] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX0FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_0_CH_0, 48},
    [MBOX1] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX1FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_0_CH_1, 48},
    [MBOX2] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX2FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_0_CH_2, 48},
    [MBOX3] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 23, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX3FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_0_CH_3, 48},
    [MBOX4] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 24, 1, PCI_IMC_DEVICE_1_CH_0, 48},
    [MBOX4FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_1_CH_0, 48},
    [MBOX5] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 24, 1, PCI_IMC_DEVICE_1_CH_1, 48},
    [MBOX5FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_1_CH_1, 48},
    [MBOX6] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 24, 1, PCI_IMC_DEVICE_1_CH_2, 48},
    [MBOX6FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_1_CH_2, 48},
    [MBOX7] = {PCI_UNC_MC_PMON_BOX_CTL, PCI_UNC_MC_PMON_BOX_STATUS, PCI_UNC_MC_PMON_BOX_STATUS, 24, 1, PCI_IMC_DEVICE_1_CH_3, 48},
    [MBOX7FIX] = {PCI_UNC_MC_PMON_BOX_CTL, 0, 0, 23, 1, PCI_IMC_DEVICE_1_CH_3, 48},
    [IBOX0] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, 34, 1, PCI_IRP_DEVICE, 48},
    [IBOX1] = {PCI_UNC_IRP_PMON_BOX_CTL, PCI_UNC_IRP_PMON_BOX_STATUS, PCI_UNC_IRP_PMON_BOX_STATUS, 34, 1, PCI_IRP_DEVICE, 48},
    [PBOX] = {PCI_UNC_R2PCIE_PMON_BOX_CTL, PCI_UNC_R2PCIE_PMON_BOX_STATUS, PCI_UNC_R2PCIE_PMON_BOX_STATUS, 29, 1, PCI_R2PCIE_DEVICE, 48},
    [RBOX0] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 27, 1, PCI_R3QPI_DEVICE_LINK_0, 44},
    [RBOX1] = {PCI_UNC_R3QPI_PMON_BOX_CTL, PCI_UNC_R3QPI_PMON_BOX_STATUS, PCI_UNC_R3QPI_PMON_BOX_STATUS, 28, 1, PCI_R3QPI_DEVICE_LINK_1, 44},
    [QBOX0] = {PCI_UNC_V3_QPI_PMON_BOX_CTL, PCI_UNC_V3_QPI_PMON_BOX_STATUS, PCI_UNC_V3_QPI_PMON_BOX_STATUS, 25, 1, PCI_QPI_DEVICE_PORT_0, 48},
    [QBOX1] = {PCI_UNC_V3_QPI_PMON_BOX_CTL, PCI_UNC_V3_QPI_PMON_BOX_STATUS, PCI_UNC_V3_QPI_PMON_BOX_STATUS, 26, 1, PCI_QPI_DEVICE_PORT_1, 48},
    [QBOX0FIX] = {0x0, 0x0, 0x0, -1, 1, PCI_QPI_MISC_DEVICE_PORT_0, 32},
    [QBOX1FIX] = {0x0, 0x0, 0x0, -1, 1, PCI_QPI_MISC_DEVICE_PORT_1, 32},
};

static PciDevice haswellEP_pci_devices[MAX_NUM_PCI_DEVICES] = {
 [MSR_DEV] = {NONE, "", "MSR", ""},
 [PCI_R3QPI_DEVICE_LINK_0] = {R3QPI, "0b.1", "PCI_R3QPI_DEVICE_LINK_0", "RBOX0", 0x2F36},
 [PCI_R3QPI_DEVICE_LINK_1] = {R3QPI, "0b.2", "PCI_R3QPI_DEVICE_LINK_1", "RBOX1", 0x2F37},
 [PCI_R2PCIE_DEVICE] = {R2PCIE, "10.1", "PCI_R2PCIE_DEVICE", "PBOX0", 0x2F34},
 [PCI_IMC_DEVICE_0_CH_0] = {IMC, "14.0", "PCI_IMC_DEVICE_0_CH_0", "MBOX0", 0x2FB4},
 [PCI_IMC_DEVICE_0_CH_1] = {IMC, "14.1", "PCI_IMC_DEVICE_0_CH_1", "MBOX1", 0x2FB5},
 [PCI_IMC_DEVICE_0_CH_2] = {IMC, "15.0", "PCI_IMC_DEVICE_0_CH_2", "MBOX2", 0x2FB0},
 [PCI_IMC_DEVICE_0_CH_3] = {IMC, "15.1", "PCI_IMC_DEVICE_0_CH_3", "MBOX3", 0x2FB1},
 [PCI_HA_DEVICE_0] = {HA, "12.1", "PCI_HA_DEVICE_0", "BBOX0", 0x2F30},
 [PCI_HA_DEVICE_1] = {HA, "12.5", "PCI_HA_DEVICE_1", "BBOX1", 0x2F38},
 [PCI_IMC_DEVICE_1_CH_0] = {IMC, "17.0", "PCI_IMC_DEVICE_1_CH_0", "MBOX4", 0x2FD4},
 [PCI_IMC_DEVICE_1_CH_1] = {IMC, "17.1", "PCI_IMC_DEVICE_1_CH_1", "MBOX5", 0x2FD5},
 [PCI_IMC_DEVICE_1_CH_2] = {IMC, "18.0", "PCI_IMC_DEVICE_1_CH_2", "MBOX6", 0x2FD0},
 [PCI_IMC_DEVICE_1_CH_3] = {IMC, "18.1", "PCI_IMC_DEVICE_1_CH_3", "MBOX7", 0x2FD1},
 [PCI_IRP_DEVICE] = {IRP, "05.6", "PCI_IRP_DEVICE", "IBOX", 0x2F39},
 [PCI_QPI_DEVICE_PORT_0] = {QPI, "08.2", "PCI_QPI_DEVICE_PORT_0", "QBOX0", 0x2F32},
 [PCI_QPI_DEVICE_PORT_1] = {QPI, "09.2", "PCI_QPI_DEVICE_PORT_1", "QBOX1", 0x2F33},
 [PCI_QPI_MASK_DEVICE_PORT_0] = {QPI, "08.6", "PCI_QPI_MASK_DEVICE_PORT_0", NULL, 0x2F86},
 [PCI_QPI_MASK_DEVICE_PORT_1] = {QPI, "09.6", "PCI_QPI_MASK_DEVICE_PORT_1", NULL, 0x2F96},
 [PCI_QPI_MISC_DEVICE_PORT_0] = {QPI, "08.0", "PCI_QPI_MISC_DEVICE_PORT_0", "QBOX0FIX", 0x2F80},
 [PCI_QPI_MISC_DEVICE_PORT_1] = {QPI, "08.0", "PCI_QPI_MISC_DEVICE_PORT_1", "QBOX1FIX", 0x2F80},
};

