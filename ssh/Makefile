BASENAME = ssh
PDF = $(addsuffix .pdf, $(BASENAME))
TEX = $(addsuffix .tex, $(BASENAME))
PDFLATEX = pdflatex
EXTRA_EXTENSIONS = .pdf .aux .log .nav .out .snm .toc
CLEAN_FILES = $(addprefix $(BASENAME), $(EXTRA_EXTENSIONS))
PDF_VIEWER = evince

.PHONY: clean all

all: $(PDF)

$(PDF): $(TEX)
	$(PDFLATEX) $<
	$(PDFLATEX) $<	# Twice, so TOC is also updated

view:$(PDF)
	$(PDF_VIEWER) $<

clean:
	-rm -f $(CLEAN_FILES) *~
