% FOR HELICOPTER NR 1-2
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert h�sten 2006 av Jostein Bakkeheim
% Oppdatert h�sten 2008 av Arnfinn Aas Eielsen
% Oppdatert h�sten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.40; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.65; % Motor mass [kg]
k_f = -((m_c*l_c-2*m_p*l_h)*g)/(l_h*5.5); % Calculated k_f where V_s^* is measured to 5.5 at e = 0 and gain_y is multiplied by 10

%%%%%%%%%%% Gathered constants from mathematical modeling (P1)
L_1 = l_p*k_f; 
L_2 = (l_c*m_c-2*m_p*l_h)*g; 
L_3 = l_h*k_f;
L_4 = -L_3; 

J_p = 2*m_p*l_p*l_p;
J_e = m_c*l_c*l_c+2*m_p*l_h*l_h;
J_t = m_c*l_c*l_c+2*m_p*(l_h*l_h+l_p*l_p);

%%%%%%%%%%% Calculated from transfer function (zeta = 1)
w_0 = 3.0; % Chosen by observation
k_pp = w_0^2*J_p/L_1;
k_pd = 2*w_0*J_p/L_1;

k_rp = -2;

%%%%%%%%Matrices NOTE: Needed to change the voltage constant
A_bar = [0 1 0 0 0; 0 0 0 0 0; 0 0 0 0 0; 1 0 0 0 0; 0 0 1 0 0];
A = A_bar(1:3, 1:3);
display(A);
B_bar = [0 0; 0 L_1/J_p; L_3/J_e 0; 0 0; 0 0];
B = B_bar(1:3, 1:2);
display(B);
D = [0 0; 0 0; 0 0; -1 0; 0 -1];
display(D);
C = [1 0 0; 0 0 1];

Q = [75 0 0 0 0; 0 20 0 0 0; 0 0 50 0 0; 0 0 0 100 0; 0 0 0 0 5];

display(Q);
R = [1 0; 0 5];
I = [1 0; 0 1];
K_bar = lqr(A_bar, B_bar, Q, R);
K = K_bar(1:2, 1:3);
display(K);
P = (-C*(A-B*K)^(-1)*B)^(-1);
display(P);