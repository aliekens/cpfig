all: demo.pdf tiefighter.pdf

tiefighter.pdf: tiefighter.fig
	fig2dev -L pdf tiefighter.fig tiefighter.pdf

tiefighter.fig: tiefighter
	./tiefighter > tiefighter.fig

tiefighter: tiefighter.cpp
	g++ tiefighter.cpp -L/usr/local/lib -lcpfig -o tiefighter

demo.pdf: demo.fig
	fig2dev -L pdf demo.fig demo.pdf

demo.fig: demo
	./demo > demo.fig

demo: demo.cpp
	g++ demo.cpp -L/usr/local/lib -lcpfig -o demo

clean:
	rm -rf *~ 
	rm -rf demo demo.fig demo.pdf
	rm -rf tiefighter tiefighter.fig tiefighter.pdf
