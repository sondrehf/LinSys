/*
 * P4p2_integrator.c
 *
 * Code generation for model "P4p2_integrator".
 *
 * Model version              : 1.103
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Oct 18 16:43:31 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "P4p2_integrator.h"
#include "P4p2_integrator_private.h"
#include "P4p2_integrator_dt.h"

/* Block signals (auto storage) */
B_P4p2_integrator_T P4p2_integrator_B;

/* Continuous states */
X_P4p2_integrator_T P4p2_integrator_X;

/* Block states (auto storage) */
DW_P4p2_integrator_T P4p2_integrator_DW;

/* Real-time model */
RT_MODEL_P4p2_integrator_T P4p2_integrator_M_;
RT_MODEL_P4p2_integrator_T *const P4p2_integrator_M = &P4p2_integrator_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(P4p2_integrator_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(P4p2_integrator_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (P4p2_integrator_M->Timing.TaskCounters.TID[1] == 0) {
    P4p2_integrator_M->Timing.RateInteraction.TID1_2 =
      (P4p2_integrator_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    P4p2_integrator_M->Timing.perTaskSampleHits[5] =
      P4p2_integrator_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (P4p2_integrator_M->Timing.TaskCounters.TID[2])++;
  if ((P4p2_integrator_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    P4p2_integrator_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  P4p2_integrator_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void P4p2_integrator_output0(void)     /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_Backgain;
  real_T rtb_Gain3;
  int32_T i;
  real_T tmp[5];
  real_T tmp_0[6];
  real_T tmp_1[6];
  real_T tmp_2[6];
  real_T tmp_3[6];
  real_T tmp_4[3];
  real_T tmp_5[3];
  int32_T i_0;
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* set solver stop time */
    if (!(P4p2_integrator_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&P4p2_integrator_M->solverInfo,
                            ((P4p2_integrator_M->Timing.clockTickH0 + 1) *
        P4p2_integrator_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&P4p2_integrator_M->solverInfo,
                            ((P4p2_integrator_M->Timing.clockTick0 + 1) *
        P4p2_integrator_M->Timing.stepSize0 +
        P4p2_integrator_M->Timing.clockTickH0 *
        P4p2_integrator_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(P4p2_integrator_M)) {
    P4p2_integrator_M->Timing.t[0] = rtsiGetT(&P4p2_integrator_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: P4p2_integrator/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (P4p2_integrator_DW.HILReadEncoderTimebase_Task, 1,
         &P4p2_integrator_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
      } else {
        P4p2_integrator_B.HILReadEncoderTimebase_o1 =
          P4p2_integrator_DW.HILReadEncoderTimebase_Buffer[0];
        P4p2_integrator_B.HILReadEncoderTimebase_o2 =
          P4p2_integrator_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          P4p2_integrator_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* RateTransition: '<S4>/Rate Transition: x' */
    if (P4p2_integrator_M->Timing.RateInteraction.TID1_2) {
      P4p2_integrator_B.RateTransitionx =
        P4p2_integrator_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (P4p2_integrator_B.RateTransitionx > P4p2_integrator_P.DeadZonex_End) {
      unnamed_idx_0 = P4p2_integrator_B.RateTransitionx -
        P4p2_integrator_P.DeadZonex_End;
    } else if (P4p2_integrator_B.RateTransitionx >=
               P4p2_integrator_P.DeadZonex_Start) {
      unnamed_idx_0 = 0.0;
    } else {
      unnamed_idx_0 = P4p2_integrator_B.RateTransitionx -
        P4p2_integrator_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    P4p2_integrator_B.Joystick_gain_x = P4p2_integrator_P.Gainx_Gain *
      unnamed_idx_0 * P4p2_integrator_P.Joystick_gain_x;

    /* Gain: '<Root>/Gain6' */
    P4p2_integrator_B.Gain6 = P4p2_integrator_P.Gain6_Gain *
      P4p2_integrator_B.Joystick_gain_x;

    /* RateTransition: '<S4>/Rate Transition: y' */
    if (P4p2_integrator_M->Timing.RateInteraction.TID1_2) {
      P4p2_integrator_B.RateTransitiony =
        P4p2_integrator_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: y' */

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (P4p2_integrator_B.RateTransitiony > P4p2_integrator_P.DeadZoney_End) {
      unnamed_idx_0 = P4p2_integrator_B.RateTransitiony -
        P4p2_integrator_P.DeadZoney_End;
    } else if (P4p2_integrator_B.RateTransitiony >=
               P4p2_integrator_P.DeadZoney_Start) {
      unnamed_idx_0 = 0.0;
    } else {
      unnamed_idx_0 = P4p2_integrator_B.RateTransitiony -
        P4p2_integrator_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    P4p2_integrator_B.Joystick_gain_y = P4p2_integrator_P.Gainy_Gain *
      unnamed_idx_0 * P4p2_integrator_P.Joystick_gain_y;

    /* Gain: '<Root>/Gain7' */
    P4p2_integrator_B.Gain7 = P4p2_integrator_P.Gain7_Gain *
      P4p2_integrator_B.Joystick_gain_y;

    /* Product: '<S5>/Product' incorporates:
     *  Constant: '<S5>/Constant'
     *  SignalConversion: '<S5>/TmpSignal ConversionAtProductInport2'
     */
    P4p2_integrator_B.Product[0] = 0.0;
    P4p2_integrator_B.Product[0] += P4p2_integrator_P.P[0] *
      P4p2_integrator_B.Gain6;
    P4p2_integrator_B.Product[0] += P4p2_integrator_P.P[2] *
      P4p2_integrator_B.Gain7;
    P4p2_integrator_B.Product[1] = 0.0;
    P4p2_integrator_B.Product[1] += P4p2_integrator_P.P[1] *
      P4p2_integrator_B.Gain6;
    P4p2_integrator_B.Product[1] += P4p2_integrator_P.P[3] *
      P4p2_integrator_B.Gain7;

    /* Constant: '<S5>/Constant1' */
    memcpy(&P4p2_integrator_B.Constant1[0], &P4p2_integrator_P.K_reg[0], 10U *
           sizeof(real_T));
  }

  /* Integrator: '<S2>/Integrator2' */
  for (i = 0; i < 6; i++) {
    P4p2_integrator_B.Integrator2[i] = P4p2_integrator_X.Integrator2_CSTATE[i];
  }

  /* End of Integrator: '<S2>/Integrator2' */

  /* Integrator: '<Root>/Integrator1' */
  P4p2_integrator_B.Integrator1 = P4p2_integrator_X.Integrator1_CSTATE;

  /* Integrator: '<Root>/Integrator3' */
  P4p2_integrator_B.Integrator3 = P4p2_integrator_X.Integrator3_CSTATE;

  /* SignalConversion: '<S5>/TmpSignal ConversionAtProduct2Inport2' incorporates:
   *  Product: '<S5>/Product2'
   */
  tmp[0] = P4p2_integrator_B.Integrator2[0];
  tmp[1] = P4p2_integrator_B.Integrator2[1];
  tmp[2] = P4p2_integrator_B.Integrator2[3];
  tmp[3] = P4p2_integrator_B.Integrator1;
  tmp[4] = P4p2_integrator_B.Integrator3;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Product: '<S5>/Product2'
   */
  for (i = 0; i < 2; i++) {
    unnamed_idx_0 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      unnamed_idx_0 += P4p2_integrator_B.Constant1[(i_0 << 1) + i] * tmp[i_0];
    }

    P4p2_integrator_B.Sum1[i] = P4p2_integrator_B.Product[i] - unnamed_idx_0;
  }

  /* End of Sum: '<S5>/Sum1' */
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    P4p2_integrator_B.Sum = rtb_HILReadEncoderTimebase_o3 +
      P4p2_integrator_P.Constant_Value;

    /* Gain: '<S3>/Elevation: Count to rad' */
    P4p2_integrator_B.ElevationCounttorad =
      P4p2_integrator_P.ElevationCounttorad_Gain * P4p2_integrator_B.Sum;
  }

  /* Gain: '<S7>/Gain' incorporates:
   *  TransferFcn: '<S3>/Elevation: Transfer Fcn'
   */
  P4p2_integrator_B.Gain = (P4p2_integrator_P.ElevationTransferFcn_C *
    P4p2_integrator_X.ElevationTransferFcn_CSTATE +
    P4p2_integrator_P.ElevationTransferFcn_D *
    P4p2_integrator_B.ElevationCounttorad) * P4p2_integrator_P.Gain_Gain;

  /* Gain: '<Root>/Gain8' */
  P4p2_integrator_B.Gain8 = P4p2_integrator_P.Gain8_Gain *
    P4p2_integrator_B.Gain;
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
  }

  /* Integrator: '<Root>/Integrator2' */
  P4p2_integrator_B.Integrator2_j = P4p2_integrator_X.Integrator2_CSTATE_d;
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* Gain: '<S3>/Pitch: Count to rad' */
    P4p2_integrator_B.PitchCounttorad = P4p2_integrator_P.PitchCounttorad_Gain *
      P4p2_integrator_B.HILReadEncoderTimebase_o2;

    /* Gain: '<S8>/Gain' */
    P4p2_integrator_B.Gain_d = P4p2_integrator_P.Gain_Gain_n *
      P4p2_integrator_B.PitchCounttorad;

    /* Gain: '<Root>/Gain1' */
    P4p2_integrator_B.Gain1 = P4p2_integrator_P.Gain1_Gain *
      P4p2_integrator_B.Gain_d;
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  TransferFcn: '<S3>/Pitch: Transfer Fcn'
   */
  P4p2_integrator_B.Gain_a = (P4p2_integrator_P.PitchTransferFcn_C *
    P4p2_integrator_X.PitchTransferFcn_CSTATE +
    P4p2_integrator_P.PitchTransferFcn_D * P4p2_integrator_B.PitchCounttorad) *
    P4p2_integrator_P.Gain_Gain_l;

  /* Gain: '<Root>/Gain5' */
  P4p2_integrator_B.Gain5 = P4p2_integrator_P.Gain5_Gain *
    P4p2_integrator_B.Gain_a;
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* Gain: '<S6>/Gain' */
    P4p2_integrator_B.Gain_h = P4p2_integrator_P.Gain_Gain_p *
      P4p2_integrator_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum4' incorporates:
     *  Gain: '<Root>/Gain10'
     */
    P4p2_integrator_B.Sum4 = P4p2_integrator_P.Gain10_Gain *
      P4p2_integrator_B.Gain_h - P4p2_integrator_B.Gain7;

    /* Constant: '<Root>/Constant1' */
    P4p2_integrator_B.Constant1_d = P4p2_integrator_P.Constant1_Value;
  }

  /* Sum: '<Root>/Sum' */
  rtb_Backgain = P4p2_integrator_B.Constant1_d + P4p2_integrator_B.Sum1[0];
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* Constant: '<S2>/A' */
    memcpy(&P4p2_integrator_B.A[0], &P4p2_integrator_P.A_sys[0], 36U * sizeof
           (real_T));

    /* Constant: '<S2>/B' */
    memcpy(&P4p2_integrator_B.B[0], &P4p2_integrator_P.B_sys[0], 12U * sizeof
           (real_T));
    for (i = 0; i < 18; i++) {
      /* Constant: '<S2>/C' */
      P4p2_integrator_B.C[i] = P4p2_integrator_P.C_sys[i];

      /* Constant: '<S2>/L' */
      P4p2_integrator_B.L[i] = P4p2_integrator_P.L[i];
    }

    /* Gain: '<S3>/Travel: Count to rad' */
    P4p2_integrator_B.TravelCounttorad = P4p2_integrator_P.TravelCounttorad_Gain
      * P4p2_integrator_B.HILReadEncoderTimebase_o1;

    /* Gain: '<S10>/Gain' */
    P4p2_integrator_B.Gain_l = P4p2_integrator_P.Gain_Gain_a *
      P4p2_integrator_B.TravelCounttorad;
  }

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S3>/Travel: Transfer Fcn'
   */
  P4p2_integrator_B.Gain_k = (P4p2_integrator_P.TravelTransferFcn_C *
    P4p2_integrator_X.TravelTransferFcn_CSTATE +
    P4p2_integrator_P.TravelTransferFcn_D * P4p2_integrator_B.TravelCounttorad) *
    P4p2_integrator_P.Gain_Gain_e;

  /* Gain: '<Root>/Gain9' incorporates:
   *  Product: '<S2>/Bu'
   *  Product: '<S2>/y'
   *  Sum: '<S2>/Sum3'
   */
  tmp_2[0] = P4p2_integrator_B.Gain_d;
  tmp_2[1] = P4p2_integrator_B.Gain_a;
  tmp_2[2] = P4p2_integrator_B.Gain_h;
  tmp_2[3] = P4p2_integrator_B.Gain;
  tmp_2[4] = P4p2_integrator_B.Gain_l;
  tmp_2[5] = P4p2_integrator_B.Gain_k;
  for (i = 0; i < 6; i++) {
    /* Product: '<S2>/Bu' incorporates:
     *  Sum: '<S2>/Sum3'
     */
    tmp_0[i] = 0.0;
    tmp_0[i] += P4p2_integrator_B.B[i] * P4p2_integrator_B.Sum1[0];
    tmp_0[i] += P4p2_integrator_B.B[i + 6] * P4p2_integrator_B.Sum1[1];

    /* Product: '<S2>/Ax_hat' incorporates:
     *  Product: '<S2>/Bu'
     *  Sum: '<S2>/Sum3'
     */
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_1[i] += P4p2_integrator_B.A[6 * i_0 + i] *
        P4p2_integrator_B.Integrator2[i_0];
    }

    /* End of Product: '<S2>/Ax_hat' */
    tmp_3[i] = P4p2_integrator_P.Gain9_Gain * tmp_2[i];
  }

  /* End of Gain: '<Root>/Gain9' */

  /* Product: '<S2>/y' incorporates:
   *  Sum: '<S2>/Sum4'
   */
  for (i = 0; i < 3; i++) {
    tmp_4[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_4[i] += P4p2_integrator_B.C[3 * i_0 + i] * tmp_3[i_0];
    }
  }

  /* Product: '<S2>/y_hat' incorporates:
   *  Sum: '<S2>/Sum4'
   */
  for (i = 0; i < 3; i++) {
    tmp_5[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_5[i] += P4p2_integrator_B.C[3 * i_0 + i] *
        P4p2_integrator_B.Integrator2[i_0];
    }
  }

  /* End of Product: '<S2>/y_hat' */

  /* Sum: '<S2>/Sum4' incorporates:
   *  Product: '<S2>/L(y-y_hat)'
   */
  unnamed_idx_0 = tmp_4[0] - tmp_5[0];
  unnamed_idx_1 = tmp_4[1] - tmp_5[1];
  unnamed_idx_2 = tmp_4[2] - tmp_5[2];

  /* Sum: '<S2>/Sum5' incorporates:
   *  Product: '<S2>/L(y-y_hat)'
   *  Sum: '<S2>/Sum3'
   */
  for (i = 0; i < 6; i++) {
    P4p2_integrator_B.Sum5[i] = ((P4p2_integrator_B.L[i + 6] * unnamed_idx_1 +
      P4p2_integrator_B.L[i] * unnamed_idx_0) + P4p2_integrator_B.L[i + 12] *
      unnamed_idx_2) + (tmp_0[i] + tmp_1[i]);
  }

  /* End of Sum: '<S2>/Sum5' */
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* Gain: '<Root>/Gain3' */
    rtb_Gain3 = P4p2_integrator_P.Gain3_Gain * P4p2_integrator_B.Gain_d;
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  unnamed_idx_0 = (P4p2_integrator_B.Sum1[1] + rtb_Backgain) *
    P4p2_integrator_P.Frontgain_Gain;

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (unnamed_idx_0 > P4p2_integrator_P.FrontmotorSaturation_UpperSat) {
    P4p2_integrator_B.FrontmotorSaturation =
      P4p2_integrator_P.FrontmotorSaturation_UpperSat;
  } else if (unnamed_idx_0 < P4p2_integrator_P.FrontmotorSaturation_LowerSat) {
    P4p2_integrator_B.FrontmotorSaturation =
      P4p2_integrator_P.FrontmotorSaturation_LowerSat;
  } else {
    P4p2_integrator_B.FrontmotorSaturation = unnamed_idx_0;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  unnamed_idx_0 = (rtb_Backgain - P4p2_integrator_B.Sum1[1]) *
    P4p2_integrator_P.Backgain_Gain;

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (unnamed_idx_0 > P4p2_integrator_P.BackmotorSaturation_UpperSat) {
    P4p2_integrator_B.BackmotorSaturation =
      P4p2_integrator_P.BackmotorSaturation_UpperSat;
  } else if (unnamed_idx_0 < P4p2_integrator_P.BackmotorSaturation_LowerSat) {
    P4p2_integrator_B.BackmotorSaturation =
      P4p2_integrator_P.BackmotorSaturation_LowerSat;
  } else {
    P4p2_integrator_B.BackmotorSaturation = unnamed_idx_0;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: P4p2_integrator/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      P4p2_integrator_DW.HILWriteAnalog_Buffer[0] =
        P4p2_integrator_B.FrontmotorSaturation;
      P4p2_integrator_DW.HILWriteAnalog_Buffer[1] =
        P4p2_integrator_B.BackmotorSaturation;
      result = hil_write_analog(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILWriteAnalog_channels, 2,
        &P4p2_integrator_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
      }
    }
  }

  /* Sum: '<Root>/Sum1' */
  P4p2_integrator_B.Sum1_n = P4p2_integrator_B.Integrator2[0] -
    P4p2_integrator_B.Gain6;

  /* Sum: '<Root>/Sum2' */
  P4p2_integrator_B.Sum2 = P4p2_integrator_B.Integrator2[3] -
    P4p2_integrator_B.Gain7;
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    /* Sum: '<Root>/Sum3' */
    P4p2_integrator_B.Sum3 = rtb_Gain3 - P4p2_integrator_B.Gain6;
  }
}

/* Model update function for TID0 */
void P4p2_integrator_update0(void)     /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(P4p2_integrator_M)) {
    rt_ertODEUpdateContinuousStates(&P4p2_integrator_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++P4p2_integrator_M->Timing.clockTick0)) {
    ++P4p2_integrator_M->Timing.clockTickH0;
  }

  P4p2_integrator_M->Timing.t[0] = rtsiGetSolverStopTime
    (&P4p2_integrator_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++P4p2_integrator_M->Timing.clockTick1)) {
    ++P4p2_integrator_M->Timing.clockTickH1;
  }

  P4p2_integrator_M->Timing.t[1] = P4p2_integrator_M->Timing.clockTick1 *
    P4p2_integrator_M->Timing.stepSize1 + P4p2_integrator_M->Timing.clockTickH1 *
    P4p2_integrator_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void P4p2_integrator_derivatives(void)
{
  int32_T i;
  XDot_P4p2_integrator_T *_rtXdot;
  _rtXdot = ((XDot_P4p2_integrator_T *) P4p2_integrator_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S2>/Integrator2' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator2_CSTATE[i] = P4p2_integrator_B.Sum5[i];
  }

  /* End of Derivatives for Integrator: '<S2>/Integrator2' */

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = P4p2_integrator_B.Sum1_n;

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = P4p2_integrator_B.Sum2;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    P4p2_integrator_P.ElevationTransferFcn_A *
    P4p2_integrator_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += P4p2_integrator_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_d = P4p2_integrator_B.Sum3;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += P4p2_integrator_P.PitchTransferFcn_A *
    P4p2_integrator_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += P4p2_integrator_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += P4p2_integrator_P.TravelTransferFcn_A *
    P4p2_integrator_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += P4p2_integrator_B.TravelCounttorad;
}

/* Model output function for TID2 */
void P4p2_integrator_output2(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: P4p2_integrator/Joystick/Game Controller (game_controller_block) */
  {
    if (P4p2_integrator_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(P4p2_integrator_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        P4p2_integrator_B.GameController_o4 = state.x;
        P4p2_integrator_B.GameController_o5 = state.y;
      }
    } else {
      P4p2_integrator_B.GameController_o4 = 0;
      P4p2_integrator_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void P4p2_integrator_update2(void)     /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  P4p2_integrator_DW.RateTransitionx_Buffer0 =
    P4p2_integrator_B.GameController_o4;

  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  P4p2_integrator_DW.RateTransitiony_Buffer0 =
    P4p2_integrator_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++P4p2_integrator_M->Timing.clockTick2)) {
    ++P4p2_integrator_M->Timing.clockTickH2;
  }

  P4p2_integrator_M->Timing.t[2] = P4p2_integrator_M->Timing.clockTick2 *
    P4p2_integrator_M->Timing.stepSize2 + P4p2_integrator_M->Timing.clockTickH2 *
    P4p2_integrator_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void P4p2_integrator_output(int_T tid)
{
  switch (tid) {
   case 0 :
    P4p2_integrator_output0();
    break;

   case 2 :
    P4p2_integrator_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void P4p2_integrator_update(int_T tid)
{
  switch (tid) {
   case 0 :
    P4p2_integrator_update0();
    break;

   case 2 :
    P4p2_integrator_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void P4p2_integrator_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: P4p2_integrator/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &P4p2_integrator_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(P4p2_integrator_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(P4p2_integrator_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
      return;
    }

    if ((P4p2_integrator_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_analog_inpu_f && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &P4p2_integrator_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = P4p2_integrator_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &P4p2_integrator_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = P4p2_integrator_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILInitialize_analog_input_chan, 8U,
        &P4p2_integrator_DW.HILInitialize_AIMinimums[0],
        &P4p2_integrator_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if ((P4p2_integrator_P.HILInitialize_set_analog_output && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_analog_outp_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &P4p2_integrator_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = P4p2_integrator_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &P4p2_integrator_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = P4p2_integrator_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (P4p2_integrator_DW.HILInitialize_Card,
         P4p2_integrator_P.HILInitialize_analog_output_cha, 8U,
         &P4p2_integrator_DW.HILInitialize_AOMinimums[0],
         &P4p2_integrator_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if ((P4p2_integrator_P.HILInitialize_set_analog_outp_h && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &P4p2_integrator_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = P4p2_integrator_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILInitialize_analog_output_cha, 8U,
        &P4p2_integrator_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if (P4p2_integrator_P.HILInitialize_set_analog_outp_l) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &P4p2_integrator_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = P4p2_integrator_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (P4p2_integrator_DW.HILInitialize_Card,
         P4p2_integrator_P.HILInitialize_analog_output_cha, 8U,
         &P4p2_integrator_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if ((P4p2_integrator_P.HILInitialize_set_encoder_param && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_encoder_par_e && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &P4p2_integrator_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = P4p2_integrator_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (P4p2_integrator_DW.HILInitialize_Card,
         P4p2_integrator_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &P4p2_integrator_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if ((P4p2_integrator_P.HILInitialize_set_encoder_count && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_encoder_cou_d && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &P4p2_integrator_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            P4p2_integrator_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILInitialize_encoder_channels, 8U,
        &P4p2_integrator_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if ((P4p2_integrator_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_pwm_params__n && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &P4p2_integrator_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = P4p2_integrator_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &P4p2_integrator_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          P4p2_integrator_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &P4p2_integrator_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            P4p2_integrator_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            P4p2_integrator_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = P4p2_integrator_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            P4p2_integrator_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            P4p2_integrator_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              P4p2_integrator_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(P4p2_integrator_DW.HILInitialize_Card,
          &P4p2_integrator_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes, &P4p2_integrator_DW.HILInitialize_POSortedFreqs
          [0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(P4p2_integrator_DW.HILInitialize_Card,
          &P4p2_integrator_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &P4p2_integrator_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &P4p2_integrator_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            P4p2_integrator_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &P4p2_integrator_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = P4p2_integrator_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &P4p2_integrator_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = P4p2_integrator_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &P4p2_integrator_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &P4p2_integrator_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &P4p2_integrator_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &P4p2_integrator_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            P4p2_integrator_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &P4p2_integrator_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = P4p2_integrator_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILInitialize_pwm_channels, 8U,
        &P4p2_integrator_DW.HILInitialize_POSortedFreqs[0],
        &P4p2_integrator_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if ((P4p2_integrator_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_pwm_outputs_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &P4p2_integrator_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = P4p2_integrator_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(P4p2_integrator_DW.HILInitialize_Card,
        P4p2_integrator_P.HILInitialize_pwm_channels, 8U,
        &P4p2_integrator_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }

    if (P4p2_integrator_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &P4p2_integrator_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = P4p2_integrator_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (P4p2_integrator_DW.HILInitialize_Card,
         P4p2_integrator_P.HILInitialize_pwm_channels, 8U,
         &P4p2_integrator_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: P4p2_integrator/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (P4p2_integrator_DW.HILInitialize_Card,
       P4p2_integrator_P.HILReadEncoderTimebase_samples_,
       P4p2_integrator_P.HILReadEncoderTimebase_channels, 3,
       &P4p2_integrator_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S4>/Rate Transition: x' */
  P4p2_integrator_B.RateTransitionx = P4p2_integrator_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S4>/Rate Transition: y' */
  P4p2_integrator_B.RateTransitiony = P4p2_integrator_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: P4p2_integrator/Joystick/Game Controller (game_controller_block) */
  {
    if (P4p2_integrator_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (P4p2_integrator_P.GameController_ControllerNumber,
         P4p2_integrator_P.GameController_BufferSize, deadzone, saturation,
         P4p2_integrator_P.GameController_AutoCenter, 0, 1.0,
         &P4p2_integrator_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
    P4p2_integrator_DW.RateTransitionx_Buffer0 =
      P4p2_integrator_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
    P4p2_integrator_DW.RateTransitiony_Buffer0 =
      P4p2_integrator_P.RateTransitiony_X0;

    /* InitializeConditions for Integrator: '<S2>/Integrator2' */
    for (i = 0; i < 6; i++) {
      P4p2_integrator_X.Integrator2_CSTATE[i] = P4p2_integrator_P.Integrator2_IC;
    }

    /* End of InitializeConditions for Integrator: '<S2>/Integrator2' */

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    P4p2_integrator_X.Integrator1_CSTATE = P4p2_integrator_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<Root>/Integrator3' */
    P4p2_integrator_X.Integrator3_CSTATE = P4p2_integrator_P.Integrator3_IC;

    /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
    P4p2_integrator_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<Root>/Integrator2' */
    P4p2_integrator_X.Integrator2_CSTATE_d = P4p2_integrator_P.Integrator2_IC_i;

    /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
    P4p2_integrator_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
    P4p2_integrator_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void P4p2_integrator_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: P4p2_integrator/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(P4p2_integrator_DW.HILInitialize_Card);
    hil_monitor_stop_all(P4p2_integrator_DW.HILInitialize_Card);
    is_switching = false;
    if ((P4p2_integrator_P.HILInitialize_set_analog_outp_m && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_analog_out_j0 && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &P4p2_integrator_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = P4p2_integrator_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((P4p2_integrator_P.HILInitialize_set_pwm_outputs_c && !is_switching) ||
        (P4p2_integrator_P.HILInitialize_set_pwm_outputs_l && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &P4p2_integrator_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = P4p2_integrator_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(P4p2_integrator_DW.HILInitialize_Card
                         , P4p2_integrator_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , P4p2_integrator_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &P4p2_integrator_DW.HILInitialize_AOVoltages[0]
                         , &P4p2_integrator_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(P4p2_integrator_DW.HILInitialize_Card,
            P4p2_integrator_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &P4p2_integrator_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(P4p2_integrator_DW.HILInitialize_Card,
            P4p2_integrator_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &P4p2_integrator_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(P4p2_integrator_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(P4p2_integrator_DW.HILInitialize_Card);
    hil_monitor_delete_all(P4p2_integrator_DW.HILInitialize_Card);
    hil_close(P4p2_integrator_DW.HILInitialize_Card);
    P4p2_integrator_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: P4p2_integrator/Joystick/Game Controller (game_controller_block) */
  {
    if (P4p2_integrator_P.GameController_Enabled) {
      game_controller_close(P4p2_integrator_DW.GameController_Controller);
      P4p2_integrator_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  P4p2_integrator_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  P4p2_integrator_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  P4p2_integrator_initialize();
}

void MdlTerminate(void)
{
  P4p2_integrator_terminate();
}

/* Registration function */
RT_MODEL_P4p2_integrator_T *P4p2_integrator(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)P4p2_integrator_M, 0,
                sizeof(RT_MODEL_P4p2_integrator_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&P4p2_integrator_M->solverInfo,
                          &P4p2_integrator_M->Timing.simTimeStep);
    rtsiSetTPtr(&P4p2_integrator_M->solverInfo, &rtmGetTPtr(P4p2_integrator_M));
    rtsiSetStepSizePtr(&P4p2_integrator_M->solverInfo,
                       &P4p2_integrator_M->Timing.stepSize0);
    rtsiSetdXPtr(&P4p2_integrator_M->solverInfo,
                 &P4p2_integrator_M->ModelData.derivs);
    rtsiSetContStatesPtr(&P4p2_integrator_M->solverInfo, (real_T **)
                         &P4p2_integrator_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&P4p2_integrator_M->solverInfo,
      &P4p2_integrator_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&P4p2_integrator_M->solverInfo, (&rtmGetErrorStatus
      (P4p2_integrator_M)));
    rtsiSetRTModelPtr(&P4p2_integrator_M->solverInfo, P4p2_integrator_M);
  }

  rtsiSetSimTimeStep(&P4p2_integrator_M->solverInfo, MAJOR_TIME_STEP);
  P4p2_integrator_M->ModelData.intgData.f[0] = P4p2_integrator_M->
    ModelData.odeF[0];
  P4p2_integrator_M->ModelData.contStates = ((real_T *) &P4p2_integrator_X);
  rtsiSetSolverData(&P4p2_integrator_M->solverInfo, (void *)
                    &P4p2_integrator_M->ModelData.intgData);
  rtsiSetSolverName(&P4p2_integrator_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = P4p2_integrator_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    P4p2_integrator_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    P4p2_integrator_M->Timing.sampleTimes =
      (&P4p2_integrator_M->Timing.sampleTimesArray[0]);
    P4p2_integrator_M->Timing.offsetTimes =
      (&P4p2_integrator_M->Timing.offsetTimesArray[0]);

    /* task periods */
    P4p2_integrator_M->Timing.sampleTimes[0] = (0.0);
    P4p2_integrator_M->Timing.sampleTimes[1] = (0.002);
    P4p2_integrator_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    P4p2_integrator_M->Timing.offsetTimes[0] = (0.0);
    P4p2_integrator_M->Timing.offsetTimes[1] = (0.0);
    P4p2_integrator_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(P4p2_integrator_M, &P4p2_integrator_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = P4p2_integrator_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      P4p2_integrator_M->Timing.perTaskSampleHitsArray;
    P4p2_integrator_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    P4p2_integrator_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(P4p2_integrator_M, -1);
  P4p2_integrator_M->Timing.stepSize0 = 0.002;
  P4p2_integrator_M->Timing.stepSize1 = 0.002;
  P4p2_integrator_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  P4p2_integrator_M->Sizes.checksums[0] = (2795928446U);
  P4p2_integrator_M->Sizes.checksums[1] = (2249789079U);
  P4p2_integrator_M->Sizes.checksums[2] = (2723966071U);
  P4p2_integrator_M->Sizes.checksums[3] = (3237565163U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    P4p2_integrator_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(P4p2_integrator_M->extModeInfo,
      &P4p2_integrator_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(P4p2_integrator_M->extModeInfo,
                        P4p2_integrator_M->Sizes.checksums);
    rteiSetTPtr(P4p2_integrator_M->extModeInfo, rtmGetTPtr(P4p2_integrator_M));
  }

  P4p2_integrator_M->solverInfoPtr = (&P4p2_integrator_M->solverInfo);
  P4p2_integrator_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&P4p2_integrator_M->solverInfo, 0.002);
  rtsiSetSolverMode(&P4p2_integrator_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  P4p2_integrator_M->ModelData.blockIO = ((void *) &P4p2_integrator_B);

  {
    int_T i;
    for (i = 0; i < 10; i++) {
      P4p2_integrator_B.Constant1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      P4p2_integrator_B.Integrator2[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      P4p2_integrator_B.A[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      P4p2_integrator_B.B[i] = 0.0;
    }

    for (i = 0; i < 18; i++) {
      P4p2_integrator_B.C[i] = 0.0;
    }

    for (i = 0; i < 18; i++) {
      P4p2_integrator_B.L[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      P4p2_integrator_B.Sum5[i] = 0.0;
    }

    P4p2_integrator_B.HILReadEncoderTimebase_o1 = 0.0;
    P4p2_integrator_B.HILReadEncoderTimebase_o2 = 0.0;
    P4p2_integrator_B.RateTransitionx = 0.0;
    P4p2_integrator_B.Joystick_gain_x = 0.0;
    P4p2_integrator_B.Gain6 = 0.0;
    P4p2_integrator_B.RateTransitiony = 0.0;
    P4p2_integrator_B.Joystick_gain_y = 0.0;
    P4p2_integrator_B.Gain7 = 0.0;
    P4p2_integrator_B.Product[0] = 0.0;
    P4p2_integrator_B.Product[1] = 0.0;
    P4p2_integrator_B.Integrator1 = 0.0;
    P4p2_integrator_B.Integrator3 = 0.0;
    P4p2_integrator_B.Sum1[0] = 0.0;
    P4p2_integrator_B.Sum1[1] = 0.0;
    P4p2_integrator_B.Sum = 0.0;
    P4p2_integrator_B.ElevationCounttorad = 0.0;
    P4p2_integrator_B.Gain = 0.0;
    P4p2_integrator_B.Gain8 = 0.0;
    P4p2_integrator_B.Integrator2_j = 0.0;
    P4p2_integrator_B.PitchCounttorad = 0.0;
    P4p2_integrator_B.Gain_d = 0.0;
    P4p2_integrator_B.Gain1 = 0.0;
    P4p2_integrator_B.Gain_a = 0.0;
    P4p2_integrator_B.Gain5 = 0.0;
    P4p2_integrator_B.Gain_h = 0.0;
    P4p2_integrator_B.Sum4 = 0.0;
    P4p2_integrator_B.Constant1_d = 0.0;
    P4p2_integrator_B.TravelCounttorad = 0.0;
    P4p2_integrator_B.Gain_l = 0.0;
    P4p2_integrator_B.Gain_k = 0.0;
    P4p2_integrator_B.FrontmotorSaturation = 0.0;
    P4p2_integrator_B.BackmotorSaturation = 0.0;
    P4p2_integrator_B.GameController_o4 = 0.0;
    P4p2_integrator_B.GameController_o5 = 0.0;
    P4p2_integrator_B.Sum1_n = 0.0;
    P4p2_integrator_B.Sum2 = 0.0;
    P4p2_integrator_B.Sum3 = 0.0;
  }

  /* parameters */
  P4p2_integrator_M->ModelData.defaultParam = ((real_T *)&P4p2_integrator_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &P4p2_integrator_X;
    P4p2_integrator_M->ModelData.contStates = (x);
    (void) memset((void *)&P4p2_integrator_X, 0,
                  sizeof(X_P4p2_integrator_T));
  }

  /* states (dwork) */
  P4p2_integrator_M->ModelData.dwork = ((void *) &P4p2_integrator_DW);
  (void) memset((void *)&P4p2_integrator_DW, 0,
                sizeof(DW_P4p2_integrator_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      P4p2_integrator_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  P4p2_integrator_DW.RateTransitionx_Buffer0 = 0.0;
  P4p2_integrator_DW.RateTransitiony_Buffer0 = 0.0;
  P4p2_integrator_DW.HILWriteAnalog_Buffer[0] = 0.0;
  P4p2_integrator_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    P4p2_integrator_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  P4p2_integrator_M->Sizes.numContStates = (12);/* Number of continuous states */
  P4p2_integrator_M->Sizes.numY = (0); /* Number of model outputs */
  P4p2_integrator_M->Sizes.numU = (0); /* Number of model inputs */
  P4p2_integrator_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  P4p2_integrator_M->Sizes.numSampTimes = (3);/* Number of sample times */
  P4p2_integrator_M->Sizes.numBlocks = (87);/* Number of blocks */
  P4p2_integrator_M->Sizes.numBlockIO = (42);/* Number of block outputs */
  P4p2_integrator_M->Sizes.numBlockPrms = (253);/* Sum of parameter "widths" */
  return P4p2_integrator_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
