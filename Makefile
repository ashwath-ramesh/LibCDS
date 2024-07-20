CC = clang
CFLAGS = -Wall -Wextra -g
BUILD_DIR = build

build_test_arrays: tests/test_arrays.c src/array.c src/types.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I src -o $(BUILD_DIR)/test_arrays $^

build_test_queues: tests/test_queues.c src/queue_arr1p.c src/types.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I src -o $(BUILD_DIR)/test_queues $^

run_test_arrays: $(BUILD_DIR)/test_arrays
	./$(BUILD_DIR)/test_arrays

run_test_queues: $(BUILD_DIR)/test_queues
	./$(BUILD_DIR)/test_queues

run_test_queues_leaks: $(BUILD_DIR)/test_queues
	sudo leaks --atExit -- ./$(BUILD_DIR)/test_queues

clean:
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)