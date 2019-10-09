CFLAGS = -Wall -O0 -g

case1:
	gcc $(CFLAGS) case1.c -o case1
case2: $(OBJECTS)
	gcc $(CFLAGS) case2.c -o case2
case3: $(OBJECTS)
	gcc $(CFLAGS) case3.c -o case3
