clc;clear;close all;

% Check input output data with no process

frame = 1024;
shift = frame/4;
nfft = frame;
fs = 16000;
nol = frame-shift;

win = hanning(nfft,'periodic');
win = win./sqrt(sum(win.^2)/shift);

[raw_matlab,fs1] = audioread('../input/F01_22GC010A_BUS.wav');
[raw_cpp,fs2] = audioread('../output/F01_22GC010A_BUS_output.wav');
nch = size(raw_cpp,2);


for ch = 1:nch
    figure;
    subplot(3,1,1);plot(raw_matlab(:,ch));title('Matlab');
    subplot(3,1,2);plot(raw_cpp(:,ch));title('C');
    tmpc = raw_cpp(frame-shift+1:end,ch);
    tmpm = raw_matlab(1:length(tmpc),ch);
    subplot(3,1,3);plot(tmpm-tmpc);title('Matlab-C');
end

autoArrangeFigures()