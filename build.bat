@echo off
cl main.c /Fe: vstrack /nologo /Zi /link user32.lib psapi.lib Wtsapi32.lib Advapi32.lib