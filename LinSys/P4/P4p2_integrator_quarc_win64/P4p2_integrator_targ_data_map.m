  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (P4p2_integrator_P)
    ;%
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.A_sys
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_P.B_sys
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% P4p2_integrator_P.C_sys
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 48;
	
	  ;% P4p2_integrator_P.Joystick_gain_x
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 66;
	
	  ;% P4p2_integrator_P.Joystick_gain_y
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 67;
	
	  ;% P4p2_integrator_P.K_reg
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 68;
	
	  ;% P4p2_integrator_P.L
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 78;
	
	  ;% P4p2_integrator_P.P
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 96;
	
	  ;% P4p2_integrator_P.HILInitialize_analog_input_maxi
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 100;
	
	  ;% P4p2_integrator_P.HILInitialize_analog_input_mini
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 101;
	
	  ;% P4p2_integrator_P.HILInitialize_analog_output_max
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 102;
	
	  ;% P4p2_integrator_P.HILInitialize_analog_output_min
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 103;
	
	  ;% P4p2_integrator_P.HILInitialize_final_analog_outp
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 104;
	
	  ;% P4p2_integrator_P.HILInitialize_final_pwm_outputs
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 105;
	
	  ;% P4p2_integrator_P.HILInitialize_initial_analog_ou
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 106;
	
	  ;% P4p2_integrator_P.HILInitialize_initial_pwm_outpu
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 107;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_frequency
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 108;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_leading_deadb
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 109;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_trailing_dead
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 110;
	
	  ;% P4p2_integrator_P.HILInitialize_set_other_outputs
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 111;
	
	  ;% P4p2_integrator_P.HILInitialize_set_other_outpu_g
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 112;
	
	  ;% P4p2_integrator_P.HILInitialize_set_other_outpu_f
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 113;
	
	  ;% P4p2_integrator_P.HILInitialize_set_other_outpu_m
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 114;
	
	  ;% P4p2_integrator_P.HILInitialize_watchdog_analog_o
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 115;
	
	  ;% P4p2_integrator_P.HILInitialize_watchdog_pwm_outp
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 116;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P4p2_integrator_P.HILInitialize_initial_encoder_c
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 4;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_alignment
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 5;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_configuration
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 6;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_modes
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 7;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_polarity
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 8;
	
	  ;% P4p2_integrator_P.HILInitialize_watchdog_digital_
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 8;
	
	  ;% P4p2_integrator_P.HILReadEncoderTimebase_channels
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 16;
	
	  ;% P4p2_integrator_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 19;
	
	  ;% P4p2_integrator_P.HILInitialize_encoder_channels
	  section.data(5).logicalSrcIdx = 37;
	  section.data(5).dtTransOffset = 21;
	
	  ;% P4p2_integrator_P.HILInitialize_pwm_channels
	  section.data(6).logicalSrcIdx = 38;
	  section.data(6).dtTransOffset = 29;
	
	  ;% P4p2_integrator_P.HILInitialize_quadrature
	  section.data(7).logicalSrcIdx = 39;
	  section.data(7).dtTransOffset = 37;
	
	  ;% P4p2_integrator_P.HILReadEncoderTimebase_samples_
	  section.data(8).logicalSrcIdx = 40;
	  section.data(8).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P4p2_integrator_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 2;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 44;
	  section.data(4).dtTransOffset = 3;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_inpu_f
	  section.data(5).logicalSrcIdx = 45;
	  section.data(5).dtTransOffset = 4;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 46;
	  section.data(6).dtTransOffset = 5;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_outp_g
	  section.data(7).logicalSrcIdx = 47;
	  section.data(7).dtTransOffset = 6;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_outp_h
	  section.data(8).logicalSrcIdx = 48;
	  section.data(8).dtTransOffset = 7;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_outp_j
	  section.data(9).logicalSrcIdx = 49;
	  section.data(9).dtTransOffset = 8;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_out_j0
	  section.data(10).logicalSrcIdx = 50;
	  section.data(10).dtTransOffset = 9;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_outp_m
	  section.data(11).logicalSrcIdx = 51;
	  section.data(11).dtTransOffset = 10;
	
	  ;% P4p2_integrator_P.HILInitialize_set_analog_outp_l
	  section.data(12).logicalSrcIdx = 52;
	  section.data(12).dtTransOffset = 11;
	
	  ;% P4p2_integrator_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 53;
	  section.data(13).dtTransOffset = 12;
	
	  ;% P4p2_integrator_P.HILInitialize_set_clock_frequ_b
	  section.data(14).logicalSrcIdx = 54;
	  section.data(14).dtTransOffset = 13;
	
	  ;% P4p2_integrator_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 55;
	  section.data(15).dtTransOffset = 14;
	
	  ;% P4p2_integrator_P.HILInitialize_set_clock_param_o
	  section.data(16).logicalSrcIdx = 56;
	  section.data(16).dtTransOffset = 15;
	
	  ;% P4p2_integrator_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 57;
	  section.data(17).dtTransOffset = 16;
	
	  ;% P4p2_integrator_P.HILInitialize_set_digital_out_k
	  section.data(18).logicalSrcIdx = 58;
	  section.data(18).dtTransOffset = 17;
	
	  ;% P4p2_integrator_P.HILInitialize_set_digital_out_b
	  section.data(19).logicalSrcIdx = 59;
	  section.data(19).dtTransOffset = 18;
	
	  ;% P4p2_integrator_P.HILInitialize_set_digital_out_o
	  section.data(20).logicalSrcIdx = 60;
	  section.data(20).dtTransOffset = 19;
	
	  ;% P4p2_integrator_P.HILInitialize_set_digital_out_c
	  section.data(21).logicalSrcIdx = 61;
	  section.data(21).dtTransOffset = 20;
	
	  ;% P4p2_integrator_P.HILInitialize_set_digital_ou_oj
	  section.data(22).logicalSrcIdx = 62;
	  section.data(22).dtTransOffset = 21;
	
	  ;% P4p2_integrator_P.HILInitialize_set_digital_out_j
	  section.data(23).logicalSrcIdx = 63;
	  section.data(23).dtTransOffset = 22;
	
	  ;% P4p2_integrator_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 64;
	  section.data(24).dtTransOffset = 23;
	
	  ;% P4p2_integrator_P.HILInitialize_set_encoder_cou_d
	  section.data(25).logicalSrcIdx = 65;
	  section.data(25).dtTransOffset = 24;
	
	  ;% P4p2_integrator_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 66;
	  section.data(26).dtTransOffset = 25;
	
	  ;% P4p2_integrator_P.HILInitialize_set_encoder_par_e
	  section.data(27).logicalSrcIdx = 67;
	  section.data(27).dtTransOffset = 26;
	
	  ;% P4p2_integrator_P.HILInitialize_set_other_outpu_l
	  section.data(28).logicalSrcIdx = 68;
	  section.data(28).dtTransOffset = 27;
	
	  ;% P4p2_integrator_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 69;
	  section.data(29).dtTransOffset = 28;
	
	  ;% P4p2_integrator_P.HILInitialize_set_pwm_outputs_b
	  section.data(30).logicalSrcIdx = 70;
	  section.data(30).dtTransOffset = 29;
	
	  ;% P4p2_integrator_P.HILInitialize_set_pwm_outputs_l
	  section.data(31).logicalSrcIdx = 71;
	  section.data(31).dtTransOffset = 30;
	
	  ;% P4p2_integrator_P.HILInitialize_set_pwm_outputs_c
	  section.data(32).logicalSrcIdx = 72;
	  section.data(32).dtTransOffset = 31;
	
	  ;% P4p2_integrator_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 73;
	  section.data(33).dtTransOffset = 32;
	
	  ;% P4p2_integrator_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 74;
	  section.data(34).dtTransOffset = 33;
	
	  ;% P4p2_integrator_P.HILInitialize_set_pwm_params__n
	  section.data(35).logicalSrcIdx = 75;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 46;
      section.data(46)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.RateTransitionx_X0
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_P.DeadZonex_Start
	  section.data(2).logicalSrcIdx = 77;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P4p2_integrator_P.DeadZonex_End
	  section.data(3).logicalSrcIdx = 78;
	  section.data(3).dtTransOffset = 2;
	
	  ;% P4p2_integrator_P.Gainx_Gain
	  section.data(4).logicalSrcIdx = 79;
	  section.data(4).dtTransOffset = 3;
	
	  ;% P4p2_integrator_P.Gain6_Gain
	  section.data(5).logicalSrcIdx = 80;
	  section.data(5).dtTransOffset = 4;
	
	  ;% P4p2_integrator_P.RateTransitiony_X0
	  section.data(6).logicalSrcIdx = 81;
	  section.data(6).dtTransOffset = 5;
	
	  ;% P4p2_integrator_P.DeadZoney_Start
	  section.data(7).logicalSrcIdx = 82;
	  section.data(7).dtTransOffset = 6;
	
	  ;% P4p2_integrator_P.DeadZoney_End
	  section.data(8).logicalSrcIdx = 83;
	  section.data(8).dtTransOffset = 7;
	
	  ;% P4p2_integrator_P.Gainy_Gain
	  section.data(9).logicalSrcIdx = 84;
	  section.data(9).dtTransOffset = 8;
	
	  ;% P4p2_integrator_P.Gain7_Gain
	  section.data(10).logicalSrcIdx = 85;
	  section.data(10).dtTransOffset = 9;
	
	  ;% P4p2_integrator_P.Integrator2_IC
	  section.data(11).logicalSrcIdx = 86;
	  section.data(11).dtTransOffset = 10;
	
	  ;% P4p2_integrator_P.Integrator1_IC
	  section.data(12).logicalSrcIdx = 87;
	  section.data(12).dtTransOffset = 11;
	
	  ;% P4p2_integrator_P.Integrator3_IC
	  section.data(13).logicalSrcIdx = 88;
	  section.data(13).dtTransOffset = 12;
	
	  ;% P4p2_integrator_P.Constant_Value
	  section.data(14).logicalSrcIdx = 89;
	  section.data(14).dtTransOffset = 13;
	
	  ;% P4p2_integrator_P.ElevationCounttorad_Gain
	  section.data(15).logicalSrcIdx = 90;
	  section.data(15).dtTransOffset = 14;
	
	  ;% P4p2_integrator_P.ElevationTransferFcn_A
	  section.data(16).logicalSrcIdx = 91;
	  section.data(16).dtTransOffset = 15;
	
	  ;% P4p2_integrator_P.ElevationTransferFcn_C
	  section.data(17).logicalSrcIdx = 92;
	  section.data(17).dtTransOffset = 16;
	
	  ;% P4p2_integrator_P.ElevationTransferFcn_D
	  section.data(18).logicalSrcIdx = 93;
	  section.data(18).dtTransOffset = 17;
	
	  ;% P4p2_integrator_P.Gain_Gain
	  section.data(19).logicalSrcIdx = 94;
	  section.data(19).dtTransOffset = 18;
	
	  ;% P4p2_integrator_P.Gain8_Gain
	  section.data(20).logicalSrcIdx = 95;
	  section.data(20).dtTransOffset = 19;
	
	  ;% P4p2_integrator_P.Integrator2_IC_i
	  section.data(21).logicalSrcIdx = 96;
	  section.data(21).dtTransOffset = 20;
	
	  ;% P4p2_integrator_P.PitchCounttorad_Gain
	  section.data(22).logicalSrcIdx = 97;
	  section.data(22).dtTransOffset = 21;
	
	  ;% P4p2_integrator_P.Gain_Gain_n
	  section.data(23).logicalSrcIdx = 98;
	  section.data(23).dtTransOffset = 22;
	
	  ;% P4p2_integrator_P.Gain1_Gain
	  section.data(24).logicalSrcIdx = 99;
	  section.data(24).dtTransOffset = 23;
	
	  ;% P4p2_integrator_P.PitchTransferFcn_A
	  section.data(25).logicalSrcIdx = 100;
	  section.data(25).dtTransOffset = 24;
	
	  ;% P4p2_integrator_P.PitchTransferFcn_C
	  section.data(26).logicalSrcIdx = 101;
	  section.data(26).dtTransOffset = 25;
	
	  ;% P4p2_integrator_P.PitchTransferFcn_D
	  section.data(27).logicalSrcIdx = 102;
	  section.data(27).dtTransOffset = 26;
	
	  ;% P4p2_integrator_P.Gain_Gain_l
	  section.data(28).logicalSrcIdx = 103;
	  section.data(28).dtTransOffset = 27;
	
	  ;% P4p2_integrator_P.Gain5_Gain
	  section.data(29).logicalSrcIdx = 104;
	  section.data(29).dtTransOffset = 28;
	
	  ;% P4p2_integrator_P.Gain_Gain_p
	  section.data(30).logicalSrcIdx = 105;
	  section.data(30).dtTransOffset = 29;
	
	  ;% P4p2_integrator_P.Gain10_Gain
	  section.data(31).logicalSrcIdx = 106;
	  section.data(31).dtTransOffset = 30;
	
	  ;% P4p2_integrator_P.Constant1_Value
	  section.data(32).logicalSrcIdx = 107;
	  section.data(32).dtTransOffset = 31;
	
	  ;% P4p2_integrator_P.Backgain_Gain
	  section.data(33).logicalSrcIdx = 108;
	  section.data(33).dtTransOffset = 32;
	
	  ;% P4p2_integrator_P.Frontgain_Gain
	  section.data(34).logicalSrcIdx = 109;
	  section.data(34).dtTransOffset = 33;
	
	  ;% P4p2_integrator_P.TravelCounttorad_Gain
	  section.data(35).logicalSrcIdx = 110;
	  section.data(35).dtTransOffset = 34;
	
	  ;% P4p2_integrator_P.Gain_Gain_a
	  section.data(36).logicalSrcIdx = 111;
	  section.data(36).dtTransOffset = 35;
	
	  ;% P4p2_integrator_P.TravelTransferFcn_A
	  section.data(37).logicalSrcIdx = 112;
	  section.data(37).dtTransOffset = 36;
	
	  ;% P4p2_integrator_P.TravelTransferFcn_C
	  section.data(38).logicalSrcIdx = 113;
	  section.data(38).dtTransOffset = 37;
	
	  ;% P4p2_integrator_P.TravelTransferFcn_D
	  section.data(39).logicalSrcIdx = 114;
	  section.data(39).dtTransOffset = 38;
	
	  ;% P4p2_integrator_P.Gain_Gain_e
	  section.data(40).logicalSrcIdx = 115;
	  section.data(40).dtTransOffset = 39;
	
	  ;% P4p2_integrator_P.Gain9_Gain
	  section.data(41).logicalSrcIdx = 116;
	  section.data(41).dtTransOffset = 40;
	
	  ;% P4p2_integrator_P.Gain3_Gain
	  section.data(42).logicalSrcIdx = 117;
	  section.data(42).dtTransOffset = 41;
	
	  ;% P4p2_integrator_P.FrontmotorSaturation_UpperSat
	  section.data(43).logicalSrcIdx = 118;
	  section.data(43).dtTransOffset = 42;
	
	  ;% P4p2_integrator_P.FrontmotorSaturation_LowerSat
	  section.data(44).logicalSrcIdx = 119;
	  section.data(44).dtTransOffset = 43;
	
	  ;% P4p2_integrator_P.BackmotorSaturation_UpperSat
	  section.data(45).logicalSrcIdx = 120;
	  section.data(45).dtTransOffset = 44;
	
	  ;% P4p2_integrator_P.BackmotorSaturation_LowerSat
	  section.data(46).logicalSrcIdx = 121;
	  section.data(46).dtTransOffset = 45;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 122;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.GameController_ControllerNumber
	  section.data(1).logicalSrcIdx = 123;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% P4p2_integrator_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 124;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_P.HILWriteAnalog_Active
	  section.data(2).logicalSrcIdx = 125;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P4p2_integrator_P.GameController_AutoCenter
	  section.data(3).logicalSrcIdx = 126;
	  section.data(3).dtTransOffset = 2;
	
	  ;% P4p2_integrator_P.GameController_Enabled
	  section.data(4).logicalSrcIdx = 127;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (P4p2_integrator_B)
    ;%
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% P4p2_integrator_B.HILReadEncoderTimebase_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_B.HILReadEncoderTimebase_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P4p2_integrator_B.RateTransitionx
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% P4p2_integrator_B.Joystick_gain_x
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% P4p2_integrator_B.Gain6
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% P4p2_integrator_B.RateTransitiony
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% P4p2_integrator_B.Joystick_gain_y
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% P4p2_integrator_B.Gain7
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% P4p2_integrator_B.Product
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% P4p2_integrator_B.Constant1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 10;
	
	  ;% P4p2_integrator_B.Integrator2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% P4p2_integrator_B.Integrator1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 26;
	
	  ;% P4p2_integrator_B.Integrator3
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 27;
	
	  ;% P4p2_integrator_B.Sum1
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 28;
	
	  ;% P4p2_integrator_B.Sum
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 30;
	
	  ;% P4p2_integrator_B.ElevationCounttorad
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 31;
	
	  ;% P4p2_integrator_B.Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 32;
	
	  ;% P4p2_integrator_B.Gain8
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 33;
	
	  ;% P4p2_integrator_B.Integrator2_j
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 34;
	
	  ;% P4p2_integrator_B.PitchCounttorad
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 35;
	
	  ;% P4p2_integrator_B.Gain_d
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 36;
	
	  ;% P4p2_integrator_B.Gain1
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 37;
	
	  ;% P4p2_integrator_B.Gain_a
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 38;
	
	  ;% P4p2_integrator_B.Gain5
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 39;
	
	  ;% P4p2_integrator_B.Gain_h
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 40;
	
	  ;% P4p2_integrator_B.Sum4
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 41;
	
	  ;% P4p2_integrator_B.Constant1_d
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 42;
	
	  ;% P4p2_integrator_B.A
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 43;
	
	  ;% P4p2_integrator_B.B
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 79;
	
	  ;% P4p2_integrator_B.C
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 91;
	
	  ;% P4p2_integrator_B.L
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 109;
	
	  ;% P4p2_integrator_B.TravelCounttorad
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 127;
	
	  ;% P4p2_integrator_B.Gain_l
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 128;
	
	  ;% P4p2_integrator_B.Gain_k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 129;
	
	  ;% P4p2_integrator_B.Sum5
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 130;
	
	  ;% P4p2_integrator_B.FrontmotorSaturation
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 136;
	
	  ;% P4p2_integrator_B.BackmotorSaturation
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 137;
	
	  ;% P4p2_integrator_B.GameController_o4
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 138;
	
	  ;% P4p2_integrator_B.GameController_o5
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 139;
	
	  ;% P4p2_integrator_B.Sum1_n
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 140;
	
	  ;% P4p2_integrator_B.Sum2
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 141;
	
	  ;% P4p2_integrator_B.Sum3
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 142;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (P4p2_integrator_DW)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% P4p2_integrator_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% P4p2_integrator_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% P4p2_integrator_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% P4p2_integrator_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% P4p2_integrator_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% P4p2_integrator_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% P4p2_integrator_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% P4p2_integrator_DW.RateTransitionx_Buffer0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% P4p2_integrator_DW.RateTransitiony_Buffer0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% P4p2_integrator_DW.HILWriteAnalog_Buffer
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 66;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P4p2_integrator_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P4p2_integrator_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P4p2_integrator_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% P4p2_integrator_DW.Voltage_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_DW.elrate_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% P4p2_integrator_DW.gamma_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% P4p2_integrator_DW.pitch_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% P4p2_integrator_DW.pitchrate_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% P4p2_integrator_DW.zheta_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
	  ;% P4p2_integrator_DW.Elevation_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 6;
	
	  ;% P4p2_integrator_DW.ElevationScopedegs_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 7;
	
	  ;% P4p2_integrator_DW.ElevationScopedeg_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 8;
	
	  ;% P4p2_integrator_DW.Pitch_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 9;
	
	  ;% P4p2_integrator_DW.PitchScopedeg_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 10;
	
	  ;% P4p2_integrator_DW.PtichrateScopedegs_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 11;
	
	  ;% P4p2_integrator_DW.Travel_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 12;
	
	  ;% P4p2_integrator_DW.TravelrateScopedegs_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 13;
	
	  ;% P4p2_integrator_DW.TravelScopedeg_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 14;
	
	  ;% P4p2_integrator_DW.HILWriteAnalog_PWORK
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 15;
	
	  ;% P4p2_integrator_DW.XScope_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 16;
	
	  ;% P4p2_integrator_DW.YScope_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 17;
	
	  ;% P4p2_integrator_DW.Scope1_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 18;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% P4p2_integrator_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% P4p2_integrator_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 3;
	
	  ;% P4p2_integrator_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 11;
	
	  ;% P4p2_integrator_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 19;
	
	  ;% P4p2_integrator_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 37;
	  section.data(5).dtTransOffset = 27;
	
	  ;% P4p2_integrator_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 38;
	  section.data(6).dtTransOffset = 35;
	
	  ;% P4p2_integrator_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 39;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% P4p2_integrator_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2795928446;
  targMap.checksum1 = 2249789079;
  targMap.checksum2 = 2723966071;
  targMap.checksum3 = 3237565163;

