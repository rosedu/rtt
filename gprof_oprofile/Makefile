BASENAME = profiling
HIGHLIGHT = code
PDF = $(addsuffix .pdf, $(BASENAME))
TEX = $(addsuffix .tex, $(BASENAME))
PDFLATEX = pdflatex
EXTRA_EXTENSIONS = .pdf .aux .log .nav .out .snm .toc
CLEAN_FILES = $(addprefix $(BASENAME), $(EXTRA_EXTENSIONS))

.PHONY: clean all

all: $(PDF)

$(PDF): $(TEX) $(HIGHLIGHT)/Makefile oprofile.pdf gprof.pdf
	#make -C $(HIGHLIGHT)
	$(PDFLATEX) $<
	$(PDFLATEX) $<	# Twice, so TOC is also updated

oprofile.pdf: oprofile.eps
	epstopdf $<
gprof.pdf: gprof.eps
	epstopdf $<

clean:
	-make -C $(HIGHLIGHT) clean
	-rm -f $(CLEAN_FILES) *~
