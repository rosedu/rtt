TEXFILES = sample.tex sample-preproc.tex stupid-example.tex stupid-example-preproc.tex win-lin.tex true-debug.tex c-cpp.tex string.tex concat.tex diag.tex

ifeq (3, $(shell highlight --version | head -2 | tail -1 | rev | cut -d ' ' -f 1 | rev | cut -d '.' -f 1))
	GENERIC_HIGHLIGHT_OPTS = -O latex -l -f -t 8 -K tiny -c highlight.sty
	C_HIGHLIGHT_OPTS = -O latex -l -f -t 8 -K footnotesize -c highlight.sty
	MK_HIGHLIGHT_OPTS = -O latex -l -f -t 8 -K footnotesize -S Make -c highlight.sty
	BASH_HIGHLIGHT_OPTS = -O latex -l -f -t 8 -K footnotesize -S Bash -c highlight.sty
else
	GENERIC_HIGHLIGHT_OPTS = -L -l -f -t 8 -K tiny -c highlight.sty
	C_HIGHLIGHT_OPTS = -L -l -f -t 8 -K footnotesize -c highlight.sty
	MK_HIGHLIGHT_OPTS = -L -l -f -t 8 -K footnotesize -S Make -c highlight.sty
	BASH_HIGHLIGHT_OPTS = -L -l -f -t 8 -K footnotesize -S Bash -c highlight.sty
endif

all: $(TEXFILES)

sample.tex: sample.c
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

sample-preproc.tex: sample.i
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

stupid-example.tex: stupid_example.c
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

stupid-example-preproc.tex: stupid_example.i
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

win-lin.tex: win_lin.c
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

true-debug.tex: true_debug.h
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

c-cpp.tex: mix_header.h
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

string.tex: string.c
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

concat.tex: concat.c
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

diag.tex: diag.c
	highlight $(GENERIC_HIGHLIGHT_OPTS) -i $< -o $@

.PHONY: clean
clean:
	rm -f $(TEXFILES) highlight.sty *~
