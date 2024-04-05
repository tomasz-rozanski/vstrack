@echo off
cls
cl.exe main.c /Fe: vstrack /DDEBUG /nologo /Zi /link user32.lib psapi.lib Wtsapi32.lib Advapi32.lib
