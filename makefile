main.obj: main.c
	cl /c /nologo /DDEBUG /Zi main.c
vst.exe: main.obj
	@cl main.c /Fe: vst /DDEBUG /nologo /Zi /link user32.lib psapi.lib Wtsapi32.lib Advapi32.lib
	@echo Bulding and linking...

