TEXFILES = sample.tex sample-preproc.tex stupid-example.tex stupid-example-preproc.tex win-lin.tex true-debug.tex c-cpp.tex string.tex concat.tex diag.tex
HIGHLIGHT_OPTS = -L -l -f -t 8 -K tiny -c highlight.sty

all: $(TEXFILES)

sample.tex: sample.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

sample-preproc.tex: sample.i
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

stupid-example.tex: stupid_example.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

stupid-example-preproc.tex: stupid_example.i
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

win-lin.tex: win_lin.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

true-debug.tex: true_debug.h
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

c-cpp.tex: mix_header.h
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

string.tex: string.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

concat.tex: concat.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

diag.tex: diag.c
	highlight $(HIGHLIGHT_OPTS) -i $< -o $@

.PHONY: clean
clean:
	rm -f $(TEXFILES) highlight.sty *~
