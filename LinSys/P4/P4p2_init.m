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

K_1 = L_1/J_p;
K_2 = L_3/J_e;
K_3 = -(L_4*L_2)/(J_t*L_3);

%%%%%%%%%%% Calculated from transfer function (zeta = 1)
w_0 = 3.0; % Chosen by observation
k_pp = w_0^2*J_p/L_1;
k_pd = 2*w_0*J_p/L_1;

k_rp = -2;
%%%%%%%%Matrices
A_sys = [0 1 0 0 0 0; 0 0 0 0 0 0; 0 0 0 1 0 0; 0 0 0 0 0 0; 0 0 0 0 0 1; K_3 0 0 0 0 0];
A_reg = [0 1 0; 0 0 0; 0 0 0];
%display(A);
B_sys = [0 0; 0 K_1; 0 0; K_2 0; 0 0; 0 0];
B_reg = [0 0; 0 K_1; K_2 0];
C_sys = [1 0 0 0 0 0; 0 0 1 0 0 0; 0 0 0 0 1 0];
C_reg = C_sys(1:2,1:3);
Q = [80 0 0 0 0 0; 0 12.5 0 0 0 0; 0 0 20 0 0 0; 0 0 0 0 0 0; 0 0 0 0 0 0; 0 0 0 0 0 0];
Q_reg = Q(1:3,1:3);
R = [1 0; 0 1];

K_reg = lqr(A_reg, B_reg, Q_reg, R);
%K_reg = K_sys(1:2, 1:3);
display(K_reg);
P = -(C_reg*((A_reg-B_reg*K_reg)^(-1))*B_reg)^(-1);

%%%%%%%% Placing poles for estimator (Placing in an arc)
systemPoles = eig(A_reg-B_reg*K_reg);

r0 = max(abs(systemPoles)); % Longest distance from origo for systempoles (Pole farthest away)

fr = 11.5; % How many times the arc is going to be bigger than r0
phi = pi/8; % angle between each pole-par
r = r0*fr; % Radius of the arc
spread = -phi:(phi/(2.5)):phi; %

poles = -r*exp(1i*spread);


L = transpose(place(transpose(A_sys),transpose(C_sys),poles));
display(L);

%plot(real(systemPoles), imag(systemPoles), 'sb', real(poles), imag(poles), 'rx');
%grid on;
%axis equal;


%%%%%%%% Plotting
% plot(elev_rate.time, elev_rate.signals.values, 'g');
% hold on;
% plot(elev_rate_est.time, elev_rate_est.signals.values, 'r');
% hold on;
% xlabel('Time [s]');
% ylabel('[Rad/s]')
% legend('Elevation rate measured', 'Elevation rate estimator');
% grid on;
% grid on;

 
% plot(pitch_est.time, pitch_est.signals.values, 'r');
% hold on;
% plot(pitch.time, pitch.signals.values, 'g--');
% hold on;
% ylabel('[Rad/s]');
% xlabel('Time [s]');
% legend('Pitch angle estimator', 'Pitch angle measured');
% grid on;

plot(pitch_rate_est.time, pitch_rate_est.signals.values, 'r');
hold on;
plot(pitch_rate.time, pitch_rate.signals.values, 'g--');
hold on;
ylabel('[Rad/s]');
xlabel('Time [s]');
legend('Pitch rate estimator', 'Pitch angle measured');
grid on;

% t = linspace(0, 2*pi, 1000);
% axes('position', [.65 .175 .25 .25]);
% box on;
% indexOfInterest = (t < 8.32) & (t > 8.26);
% plot(t(indexOfInterest), pitch.values(indexOfInterest));
% axis tight;

