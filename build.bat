@echo off
cl main.c /Fe: vstrack /nologo /Zi /link user32.lib psapi.lib 