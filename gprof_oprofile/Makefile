BASENAME = profiling
HIGHLIGHT = code
PDF = $(addsuffix .pdf, $(BASENAME))
TEX = $(addsuffix .tex, $(BASENAME))
PDFLATEX = pdflatex
EXTRA_EXTENSIONS = .pdf .aux .log .nav .out .snm .toc
CLEAN_FILES = $(addprefix $(BASENAME), $(EXTRA_EXTENSIONS))

.PHONY: clean all

all: $(PDF)

$(PDF): $(TEX) oprofile.pdf gprof.pdf
	$(PDFLATEX) $<
	$(PDFLATEX) $<	# Twice, so TOC is also updated

oprofile.pdf: oprofile.eps
	epstopdf $<
gprof.pdf: gprof.eps
	epstopdf $<

clean:
	-rm -f $(CLEAN_FILES) *~
	-rm -f *.pdf
