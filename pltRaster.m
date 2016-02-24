%****************************************
% Reads spikes data and plots raster
% Author : Madhavun Candadai Vasu
%****************************************

nNeurons = 10;
simTime = 1000;

ras = csvread('izhiSpikes.csv');

figure;
h = plot(ras(:,1),ras(:,2),'.');
title('3,4');
xlim([1,simTime]);
ylim([1,nNeurons]);
%saveas(h,'./izhi_sincos.png');