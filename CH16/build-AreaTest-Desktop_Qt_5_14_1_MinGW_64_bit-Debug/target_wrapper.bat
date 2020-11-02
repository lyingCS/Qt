@echo off
SetLocal EnableDelayedExpansion
(set PATH=E:\Qt\Qt5.14.1\5.14.1\mingw73_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=E:\Qt\Qt5.14.1\5.14.1\mingw73_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=E:\Qt\Qt5.14.1\5.14.1\mingw73_64\plugins
)
%*
EndLocal
