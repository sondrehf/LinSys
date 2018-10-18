% x and y data 
x = [0; 5; 10; 10.1; 10.25; 10.5; 11.34; 22.83; 43; 119; 257]; 
y = 2*exp(-1/8*x)+1/3*exp(-2*x)+0.2*rand(length(x),1); 
figure 
plot(x,y) 
hold on

% fit an exponential function to data 
f1 = fit(x,y,'exp2'); 
plot(f1)

% set major axes legend, title, and labels 
title('How far does the apple fall?') 
xlabel('Distance from tree') 
legend('Experimental Data','Multi-Exponential Fit')

% zoomPlot to highlight a portion of the major plot 
[p,z] = zoomPlot(x,y,[5 50],[0.33 0.35 0.3 0.55],[1 3]); 
hold on 
plot(f1) 
legend hide

% Forgot to add a title/label/legend to the original plot? 
p.YLabel.String = 'Apples';
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
    plot([xbounds(1) x1], [max(y(index)) y2], 'k'); % Line to vertex 1
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
plot(x,y)
axis([xbounds(1) xbounds(2) min(y(index)) max(y(index))]);
end