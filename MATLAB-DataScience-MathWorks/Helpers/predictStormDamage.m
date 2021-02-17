function damage = predictStormDamage(location,eventtype,dur,date)
% PREDICTSTORMDAMAGE Predict damage cost, based on machine learning model
%
% Example:
% eventtype = "Tornado";
% location = "MASSACHUSETTS";
% dur = 1;
% damage = predictStormDamage(location,eventtype,dur)
%
% Copyright 2020 The MathWorks, Inc.
%

% Prep inputs 
if nargin < 4
    date = datetime("now");
end

[location,eventtype] = convertCharsToStrings(location,eventtype);
location = upper(location); % model requires uppercase

% Organize for machine learning
testData = table;
testData.weathercats = categorical(eventtype);
testData.state = categorical(location);
testData.storm_duration = dur;
testData.Time = date; 
[testData.yy,testData.MM,testData.dd] = ymd(testData.Time);

% Load model and persist for future function calls
persistent trainedModel;

if isempty(trainedModel)
    mdl = load("MLModel.mat");
    trainedModel = mdl.trainedModel;
end

% Make prediction
damage = trainedModel.predictFcn(testData); 

end
