% FOR HELICOPTER NR 1-2
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.


% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
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
k_f = -((m_c*l_c-2*m_p*l_h)*g)/(l_h*5.5); % Calculated k_f where V_s^*
%is measured to 5.5 at e = 0 and gain_y is multiplied by 10

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
% x1 = elev_rate.time;
% y1 = elev_rate.signals.values;
% f = plot(x1, y1, 'b');
% xlabel('Time [s]')
% ylabel('Elevation [Rad]')
% title('Elevation Angle Estimated vs Elevation Angle Measured')
% axis([64.5 78 -pi/4 pi/4.3])
% hold on;
% 
% x = elev_rate_est.time; 
% y = elev_rate_est.signals.values;
% 
% hold on;
% xlabel('Time [s]');
% ylabel('[Rad/s]')
% legend('Elevation Angle rate measured', 'Elevation Angle rate estimator');
% f1 = plot(x,y, 'r');
% hold on;
% ylabel('Elevation Angle [Rad]');
% xlabel('Time [s]');
% legend('Elevation Angle estimator', 'Elevation Angle measured');
% grid on;
% [p,z] = zoomPlot(x1,y1,[71.75 72],[0.63 0.14 0.25 0.25],[2, 4]); 
% legend([f1, f], 'Elevation Angle Estimated', 'Elevation Angle Measured');
% set(gca,'xtick',[])
% set(gca,'ytick',[])
% hold on 
% plot(x, y, 'r');
% hold on;
% legend('off')
 
% x1 = pitch_est.time;
% y1 = pitch_est.signals.values;
% f = plot(x1, y1, 'b');
% xlabel('Time [s]')
% ylabel('Pitch [Rad]')
% title('Pitch Angle Estimated vs Pitch Angle Measured')
% axis([26 32 -pi/4.5 pi/4.5])
% hold on;
% 
% x = pitch.time;
% y = pitch.signals.values;
% f1 = plot(x,y, 'r');
% hold on;
% ylabel('Pitch Angle [Rad]');
% xlabel('Time [s]');
% legend('Pitch Angle estimator', 'Pitch Angle measured');
% grid on;
% [p,z] = zoomPlot(x1,y1,[26.9 27.20],[0.6 0.15 0.25 0.25],[2, 4]); 
% legend([f1, f], 'Pitch Angle Estimated', 'Pitch Angle Measured');
% set(gca,'xtick',[])
% set(gca,'ytick',[])
% hold on 
% plot(x, y, 'r');
% hold on;
% legend('off')

%plot(pitch_rate.time, pitch_rate.signals.values, 'r');
y1 = pitch_rate.signals.values;
x1 = pitch_rate.time;
f = plot(x1, y1, 'b')
xlabel('Time [s]')
ylabel('Pitch Rate [Rad/s]')
title('Pitch Rate Estimated vs Pitch Rate Measured')
axis([23 33.5 -pi/1.2 pi/1.25])
hold on;
y = pitch_rate_est.signals.values;
x = pitch_rate_est.time;
f1 = plot(x,y, 'r');
legend('boxoff') 
set(legend,'FontSize',11)
[p,z] = zoomPlot(x1,y1,[26.9 27.25],[0.17 0.63 0.25 0.25],[3, 4]); 
legend([f1, f], 'Pitch Rate Estimated', 'Pitch Rate Measured');
set(gca,'xtick',[])
set(gca,'ytick',[])
hold on 
plot(x, y, 'r');
hold on;
legend('off')






%% zoomPlot     add inlaid plot to current figure
%       [p,z]   = zoomPlot(x,y,xbounds,pos,vertex) where: 
%       x,y     = vectors being plotted
%       xbounds = [x1 x2] specifies the zoom indices, where x1 is the 
%               first x value displayed in the zoom plot and x2 is the last.
%       pos     = [left, bottom, width, height] specifies the location and
%               size of the side of the zoom box, relative to the lower-left
%               corner of the Figure window, in normalized units where (0,0)
%               is the lower-left corner and (1.0,1.0) is the upper-right.
% {opt} vertex  = toggles connecting lines corresponding to vertices, where 1 
%               corresponds to the top left vertex and continuing clockwise, 
%               4 corresponds to the bottom right vertex. All 4 vertices can 
%               be included.
% {opt} p       = axes handle for larger plot
% {opt} z       = axes handle for zoom plot
% 
% Note: place title, labels, and legend BEFORE placing zoom plot,
%     otherwise zoomPlot returns the handle of the original axes (p).
%     Change title using p.Title.String = 'insert title here'
% 
% Kelsey Bower (kelsey.bower@case.edu) 10/20/15
 
function [p z] = zoomPlot(x,y,xbounds,pos,varargin)
% Please retain the following:
% 
% Original Author: 
% Kelsey Bower, kelsey.bower@case.edu
if nargin > 5
    printf('Too many arguments. zoomPlot(x,y,xbounds,pos,vertex)\n')
elseif nargin < 5
    vertex = [1 4];
elseif nargin == 5
    vertex = varargin{1};
end
% Get current axis position and limits
p = gca;
% Calculate x,y points of zoomPlot
x1 = (pos(1)-p.Position(1))/p.Position(3)*diff(p.XLim)+p.XLim(1);
x2 = (pos(1)+pos(3)-p.Position(1))/p.Position(3)*diff(p.XLim)+(p.XLim(1));
y1 = (pos(2)-p.Position(2))/p.Position(4)*diff(p.YLim)+p.YLim(1);
y2 = ((pos(2)+pos(4)-p.Position(2))/p.Position(4))*diff(p.YLim)+p.YLim(1);
% Plot lines connecting zoomPlot to original plot points
index = find(x>=xbounds(1) & x<=xbounds(2)); % Find indexes of points in zoomPlot
rectangle('Position',[xbounds(1) min(y(index)) diff(xbounds) max(y(index))-min(y(index))]);
hold on
if any(vertex==1)
    a = plot([xbounds(1) x1], [max(y(index)) y2], 'k'); % Line to vertex 1 
    legend('off');
end
if any(vertex==2)
    plot([xbounds(2) x2], [max(y(index)) y2], 'k'); % Line to vertex 2
end
if any(vertex==3)
    plot([xbounds(2) x2], [min(y(index)) y1], 'k'); % Line to vertex 4
end
if any(vertex==4)
    plot([xbounds(1) x1], [min(y(index)) y1], 'k'); % Line to vertex 3
end
% Plot zoomPlot and change axis
z = axes('position',pos);
box on 

plot(x,y, 'b')
b = gca; 
axis([xbounds(1) xbounds(2) min(y(index)) max(y(index))]);
legend('off');



end
