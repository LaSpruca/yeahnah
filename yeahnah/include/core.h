#pragma once

#include <cwchar>
#include <stddef.h>
#include <stdint.h>

typedef struct YNMetaList YNMetaList;

typedef struct YNGenericParamList YNGenericParamList;
typedef struct YNGenericParam YNGenericParam;
typedef struct YNGenericArgList YNGenericArgList;
typedef struct YNGenericArg YNGenericArg;

typedef struct YNTraitConstraints YNTraitConstraints;
typedef struct YNType YNType;
typedef struct YNEnum YNEnum;
typedef struct YNEnumMember YNEnumMember;
typedef struct YNUnion YNUnion;
typedef struct YNUnionType YNUnionType;
typedef struct YNStruct YNStruct;
typedef struct YNStructType YNStructType;
typedef struct YNField YNField;
typedef struct YNFieldList YNFieldList;
typedef struct YNFunction YNFunction;
typedef struct YNFunctionType YNFunctionType;
typedef struct YNFnParamList YNFnParamList;
typedef struct YNFnParam YNFnParam;

typedef struct YNTrait YNTrait;

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
  ENUM,
  UNION,
  FUNCTION,
};

struct YNTraitConstraints {
  int constrations_len;
  YNTrait *constraints;
};

struct YNGenericParam {
  const char *name;
  YNTraitConstraints constraints;
};

struct YNGenericParamList {
  int params_len;
  YNGenericParam *params;
};

struct YNTrait {
  const char *name;
  YNGenericParamList generic_params;
  YNTraitConstraints constraints;
};

struct YNStructType {
  YNStruct *ynstruct;
  YNGenericArgList *arg_list;
};

struct YNUnionType {
  YNUnion *ynunion;
  YNGenericArgList *arg_list;
};

struct YNFunctionType {
  YNFunction *ynfunction;
  YNGenericArgList *arg_list;
};

struct YNType {
  enum YNTypeDesc type;

  union {
    const YNStructType ynstruct;
    const YNUnionType ynunion;
    const YNType *ptr;
    const YNEnum *ynenum;
    const YNFunctionType *ynfunction;
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

struct YNFnParamList {
  int args_len;
  const YNFnParam *args;
};

struct YNFnParam {
  const char *name;
  YNMetaList meta;
  YNType type;
};

struct YNFunction {
  const char *name;
  YNMetaList meta;
  YNType return_type;
  YNFnParamList args;
};

struct YNEnum {
  YNMetaList meta;

  int members_len;
  YNEnumMember *members;
};

struct YNEnumMember {
  YNMetaList meta;
  char *annotation;
};

struct YNUnion {
  const char *name;
  YNMetaList meta;
  YNFieldList fields;
};

struct YNAllocator {
  void *(*alloc)(size_t bytes);
  void *(*realloc)(size_t bytes);
};

struct YNContext {
  YNAllocator *alloc;
};
