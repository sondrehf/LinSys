/*
 * P4p2_private.h
 *
 * Code generation for model "P4p2".
 *
 * Model version              : 1.107
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Oct 18 15:40:33 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_P4p2_private_h_
#define RTW_HEADER_P4p2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
void P4p2_output0(void);
void P4p2_update0(void);
void P4p2_output2(void);
void P4p2_update2(void);               /* private model entry point functions */
extern void P4p2_derivatives(void);

#endif                                 /* RTW_HEADER_P4p2_private_h_ */
