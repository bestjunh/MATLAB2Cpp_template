clc;clear;close all;
nfft = 1024;
nshift = nfft/4;
fs = 16000;
nol = nfft-nshift;


mat = audioread('S:\githubclone\OverIVA_RLS_VAD\output\vad.wav');
cxx = audioread('../output/speaker4_1_output.wav');
[~,nch] = size(cxx);

tmpc = cxx(nfft-nshift+1:end,:);
tmpm = mat(1:length(tmpc),:);

for ch = 1:nch
figure;
subplot(2,1,1)
spectrogram(tmpc(:,ch),nfft,nol,nfft,fs,'yaxis');colormap jet;title('C++');caxis([-150 -70]);
subplot(2,1,2)
spectrogram(tmpm(:,ch),nfft,nol,nfft,fs,'yaxis');colormap jet;title('MATLAB');caxis([-150 -70]);    
end


for ch = 1:nch
    figure;plot(tmpc(:,ch)-tmpm(:,ch))
end

autoArrangeFigures(2,nch,1);