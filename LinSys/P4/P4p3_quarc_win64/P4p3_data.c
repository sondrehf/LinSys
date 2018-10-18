/*
 * P4p3_data.c
 *
 * Code generation for model "P4p3".
 *
 * Model version              : 1.106
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Oct 18 17:35:07 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "P4p3.h"
#include "P4p3_private.h"

/* Block parameters (auto storage) */
P_P4p3_T P4p3_P = {
  /*  Variable: A_sys
   * Referenced by: '<S2>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, -0.96672205235453113, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 },

  /*  Variable: B_sys
   * Referenced by: '<S2>/B'
   */
  { 0.0, 0.0, 0.0, 0.18377899062058986, 0.0, 0.0, 0.0, 1.0691127054763427, 0.0,
    0.0, 0.0, 0.0 },

  /*  Variable: C_sys
   * Referenced by: '<S2>/C'
   */
  { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },
  1.0,                                 /* Variable: Joystick_gain_x
                                        * Referenced by: '<S4>/Joystick_gain_x'
                                        */
  -1.0,                                /* Variable: Joystick_gain_y
                                        * Referenced by: '<S4>/Joystick_gain_y'
                                        */

  /*  Variable: K_reg
   * Referenced by: '<S5>/Constant1'
   */
  { -1.2161753311261108E-15, 0.00915341383006734, -1.1983479379826285E-14,
    0.13089455392740545, 2.8627235727305025, -1.3942496927992893E-20,
    1.8673079195590975E-16, 0.0003162277660168387, 0.70710678118654857,
    1.7468272962655334E-20 },

  /*  Variable: L
   * Referenced by: '<S2>/L'
   */
  { 35.500827393884, 49.382796633829656, 6.9541388322068913, 12.87784533305455,
    -0.83399734199938613, -8.3703257214682854, -187.74324834815272,
    -176.26801620356369, 0.0037194272170073817, 0.0025662050551003013,
    13.904881070029072, 74.3690881337435 },

  /*  Variable: P
   * Referenced by: '<S5>/Constant'
   */
  { -1.2161753311261106E-15, 0.00915341383006734, 2.8627235727305025,
    -1.3942496927992893E-20 },
  10.0,                                /* Mask Parameter: HILInitialize_analog_input_maxi
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_input_mini
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_output_max
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_output_min
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_analog_ou
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  24305.934065934067,                  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_analog_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<S3>/HIL Read Encoder Timebase'
                                        */

  /*  Mask Parameter: HILInitialize_hardware_clocks
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_analog_output_cha
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILReadEncoderTimebase_channels
   * Referenced by: '<S3>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /*  Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S3>/HIL Write Analog'
   */
  { 0U, 1U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  500U,                                /* Mask Parameter: HILReadEncoderTimebase_samples_
                                        * Referenced by: '<S3>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_h
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_out_j0
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_ou_oj
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_d
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__n
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Rate Transition: x'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<S4>/Dead Zone: x'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S4>/Dead Zone: x'
                                        */
  1.1111111111111112,                  /* Expression: 10/9
                                        * Referenced by: '<S4>/Gain: x'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Rate Transition: y'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<S4>/Dead Zone: y'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S4>/Dead Zone: y'
                                        */
  1.1111111111111112,                  /* Expression: 10/9
                                        * Referenced by: '<S4>/Gain: y'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  270.0,                               /* Expression: 270
                                        * Referenced by: '<S3>/Constant'
                                        */
  -0.0015339807878856412,              /* Expression: -2 * pi /4096
                                        * Referenced by: '<S3>/Elevation: Count to rad'
                                        */
  -50.0,                               /* Computed Parameter: ElevationTransferFcn_A
                                        * Referenced by: '<S3>/Elevation: Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: ElevationTransferFcn_C
                                        * Referenced by: '<S3>/Elevation: Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: ElevationTransferFcn_D
                                        * Referenced by: '<S3>/Elevation: Transfer Fcn'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S7>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi /4096
                                        * Referenced by: '<S3>/Pitch: Count to rad'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain1'
                                        */
  -50.0,                               /* Computed Parameter: PitchTransferFcn_A
                                        * Referenced by: '<S3>/Pitch: Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: PitchTransferFcn_C
                                        * Referenced by: '<S3>/Pitch: Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: PitchTransferFcn_D
                                        * Referenced by: '<S3>/Pitch: Transfer Fcn'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S9>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain5'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  6.1,                                 /* Expression: 6.1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Back gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Front gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S6>/Gain'
                                        */
  0.00076699039394282058,              /* Expression: 2*pi/8192
                                        * Referenced by: '<S3>/Travel: Count to rad'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S10>/Gain'
                                        */
  -50.0,                               /* Computed Parameter: TravelTransferFcn_A
                                        * Referenced by: '<S3>/Travel: Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: TravelTransferFcn_C
                                        * Referenced by: '<S3>/Travel: Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: TravelTransferFcn_D
                                        * Referenced by: '<S3>/Travel: Transfer Fcn'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S11>/Gain'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain9'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain2'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<Root>/Gain3'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Front motor: Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S3>/Front motor: Saturation'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S3>/Back motor: Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S3>/Back motor: Saturation'
                                        */
  12U,                                 /* Computed Parameter: GameController_BufferSize
                                        * Referenced by: '<S4>/Game Controller'
                                        */
  1U,                                  /* Computed Parameter: GameController_ControllerNumber
                                        * Referenced by: '<S4>/Game Controller'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<S3>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S3>/HIL Write Analog'
                                        */
  0,                                   /* Computed Parameter: GameController_AutoCenter
                                        * Referenced by: '<S4>/Game Controller'
                                        */
  1                                    /* Computed Parameter: GameController_Enabled
                                        * Referenced by: '<S4>/Game Controller'
                                        */
};
