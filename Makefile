CC = clang
CFLAGS = -Wall -Wextra -g
BUILD_DIR = build

build_test_arrays: tests/test_arrays.c src/array.c src/types.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I src -o $(BUILD_DIR)/test_arrays $^

build_test_queues_arr1p: tests/test_queues_arr1p.c src/queue_arr1p.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I src -o $(BUILD_DIR)/test_queues_arr1p $^

build_test_queues_arr2p: tests/test_queues_arr2p.c src/queue_arr2p.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I src -o $(BUILD_DIR)/test_queues_arr2p $^

run_test_arrays: $(BUILD_DIR)/test_arrays
	./$(BUILD_DIR)/test_arrays

run_test_queues_arr1p: $(BUILD_DIR)/test_queues_arr1p
	./$(BUILD_DIR)/test_queues_arr1p

run_test_queues_arr2p: $(BUILD_DIR)/test_queues_arr2p
	./$(BUILD_DIR)/test_queues_arr2p

run_test_queues_arr1p_leaks: $(BUILD_DIR)/test_queues_arr1p
	sudo leaks --atExit -- ./$(BUILD_DIR)/test_queues_arr1p

run_test_queues_arr2p_leaks: $(BUILD_DIR)/test_queues_arr2p
	sudo leaks --atExit -- ./$(BUILD_DIR)/test_queues_arr2p

clean:
	rm -rf $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)