@echo off
rem !!!Don't move this file
rem usage: run.bat <BUILD_CFG>
rem    BUILD_CFG could be Debug,Release,MinSizeRel,RelWithDebInfo

set myDir=%~dp0
set cacheFile=%myDir%run.bat.txt

echo Entering run.bat directory: %myDir%

cd /d %myDir%

set APP_NAME=Boomlings
set BUILD_DIR=build
set BUILD_CFG=%1

rem Determine which build config to run
if not defined BUILD_CFG if exist %cacheFile% set /p BUILD_CFG=< %cacheFile%
if not defined BUILD_CFG set /p BUILD_CFG=Please input Build config(Debug,Release,MinSizeRel,RelWithDebInfo):
if not defined BUILD_CFG set BUILD_CFG=Debug

rem Save run config to run.bat.txt
echo %BUILD_CFG%>%cacheFile%

start /D %myDir%Content %BUILD_DIR%/bin/%APP_NAME%/%BUILD_CFG%/%APP_NAME%.exe
