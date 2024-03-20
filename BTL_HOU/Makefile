.PHONY: target clean
CC:= g++
CFLAGS:= -I./inc
JSFLAGS := -ljsoncpp


target:
	$(CC) -c src/AppController.cpp 		  	  -o   obj/AppController.o   	$(CFLAGS)
	$(CC) -c src/container.cpp 	      	      -o   obj/container.o 		$(CFLAGS)
	$(CC) -c src/dienthoai.cpp  	      	  -o   obj/dienthoai.o  	$(CFLAGS)
	$(CC) -c src/engine.cpp      	  		  -o   obj/engine.o  	$(CFLAGS)
	$(CC) -c src/hoadon.cpp      	  		  -o   obj/hoadon.o   	$(CFLAGS)
	$(CC) -c src/main.cpp  		          		  -o   obj/main.o  				$(CFLAGS)
	$(CC) -o app obj/main.o \
	         obj/AppController.o \
			 obj/container.o \
			 obj/dienthoai.o \
			 obj/engine.o \
			 obj/hoadon.o  $(JSFLAGS)
			 
clean:
	rm app obj/*.o