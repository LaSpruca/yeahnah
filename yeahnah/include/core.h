#include <stddef.h>
#include <stdint.h>

typedef struct YNMetaList YNMetaList;

typedef struct YNField YNField;
typedef struct YNFieldList YNFieldList;

typedef struct YNType YNType;
typedef struct YNStruct YNStruct;
typedef struct YNFunction YNFunction;

typedef struct YNContext YNContext;
typedef struct YNAllocator YNAllocator;

enum YNTypeDesc {
  U8,
  U16,
  U32,
  U64,
  I8,
  I16,
  I32,
  I64,
  BOOL,
  USIZE,
  ISIZE,
  PTR,

  STRUCT,
  FUNCTION,
};

struct YNType {
  enum YNTypeDesc type;
  union {
    const YNStruct *ynstruct;
    const YNFunction *ynfunction;
    const YNType *ptr;
    void *primitave;
  } field;
};

struct YNMetaList {
  int len;
  const char **meta;
};

struct YNField {
  const char *name;

  YNMetaList meta;
  YNType type;
};

struct YNFieldList {
  int len;
  const YNField *fields;
};

struct YNStruct {
  const char *name;
  YNMetaList meta;
  YNFieldList fields;
};

struct YNFunction {};

struct YNAllocator {
  void *(*alloc)(size_t bytes);
};
struct YNContext {
  YNAllocator *alloc;
};
