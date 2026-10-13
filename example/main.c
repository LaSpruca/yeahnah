#include "../yeahnah/include/core.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

const uint8_t *str__0 = "Hello, world!\n";

const YNType stdlib__String__field__ptr_type_ptr = {
    .type = USIZE, .field = {.primitave = NULL}};
const YNField stdlib__String__field__ptr = {
    .name = "ptr",
    .type = {.type = PTR,
             .field = {.ptr = &stdlib__String__field__ptr_type_ptr}}};
const YNField stdlib__String__field__len = {
    .name = "len", .type = {.type = USIZE, .field = {.primitave = NULL}}};
const YNStruct stdlib__String = {.name = "stdlib.String",
                                 .meta = {.len = 0, .meta = {}},
                                 .fields = {.len = 2, .fields = {}}};

struct stdlib__String {
  const uint8_t *ptr;
  size_t len;
};

struct stdlib__String
stdlib__String__from_parts(YNContext *ctx, const uint8_t *text, size_t size) {
  struct stdlib__String str = {
      .ptr = text,
      .len = size,
  };

  return str;
}

void stdlib__printf(YNContext *ctx, struct stdlib__String args) {
  write(STDOUT_FILENO, args.ptr, args.len);
}

void example__main(YNContext *ctx) {
  struct stdlib__String temp0 = stdlib__String__from_parts(ctx, str__0, 14);
  stdlib__printf(ctx, temp0);
}

YNAllocator DEFAULT_ALLOCTAR = {
    .alloc = &malloc,
};

YNContext DEFAULT_CTX = {
    .alloc = &DEFAULT_ALLOCTAR,
};

int main() {
  example__main(&DEFAULT_CTX);
  return 0;
}
