.PHONY: all
all:
	@mkdir -pv build
	@cd build && cmake -GNinja ..
	@cd build && ninja

.PHONY: clean
clean:
	@rm -rfv build

.PHONY: test
test: all
	@cd build && ./unittest 