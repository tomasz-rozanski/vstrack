@echo off
cl main.c /Fe: vstrack-release /nologo /link user32.lib psapi.lib 