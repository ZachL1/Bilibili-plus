function tests = Tests_WeatherEvents
% Tests for weather event prediction application
%
% Copyright 2020 The MathWorks, Inc.
tests = functiontests(localfunctions);
end

function testDefaultDate(testCase)
% Test with default date
eventtype = "Wildfire";
location = "VERMONT";
damage = predictStormDamage(location,eventtype,1);
% The output of the function is the damage cost
verifySize(testCase,damage,[1,1]);
end

function testDateInput(testCase)
% Test with non-default date
eventtype = "Tornado";
location = "MASSACHUSETTS";
date = datetime(2020,8,21);
damage = predictStormDamage(location,eventtype,1,date);

% The output of the function is the damage cost
verifyClass(testCase,damage,"double");
end

function testInputDataType(testCase)
% Test with lowercase char
eventtype = "Wildfire";
location = 'new york';
damage = predictStormDamage(location,eventtype,1);

% The output of the function is the damage cost
verifySize(testCase,damage,[1,1]);
end


function testModelOutput(testCase)
% Test model prediction is reasonable
eventtype = "Tornado";
location = "Ohio";
date = datetime(2020,8,21);
damage = predictStormDamage(location,eventtype,1,date);

% Test that the model predicts a postive value
verifyGreaterThanOrEqual(testCase,damage,0);
end




