SRC=kalman_filter.c kalman_filter.h test_kalman_filter.c
BIN=test_kalman_filter

$(BIN):$(SRC)
	gcc -g $(SRC) -o $@

.PHONY:
	
clean:
	-rm -f *.o $(BIN) tags
run:
	./$(BIN) > result.txt

