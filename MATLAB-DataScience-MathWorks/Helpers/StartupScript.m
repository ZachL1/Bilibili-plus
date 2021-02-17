% Add data files to path if the directory exists
if exist("StormData","dir") == 7    
    addpath("StormData")
else
    warning("StormData not found. See getStormEventData.mlx to download data")
end