#include <stdio.h>


#define OPT(type) \
  typedef type (*opt_add_ ## type)(type, type); \
  typedef type (*opt_sub_ ## type)(type, type); \
  typedef type (*opt_mul_ ## type)(type, type); \
  typedef type (*opt_div_ ## type)(type, type); \
  \
  typedef struct opt_##type { \
    opt_add_ ## type add; \
    opt_sub_ ## type sub; \
    opt_mul_ ## type mul; \
    opt_div_ ## type div; \
  } opt_ ## type;

typedef int (*opt_add)(int, int);
typedef int (*opt_sub)(int, int);
typedef int (*opt_mul)(int, int);
typedef int (*opt_div)(int, int);

typedef struct opt_t {
  opt_add add;
  opt_sub sub;
  opt_mul mul;
  opt_div div;
} opt_t;


int add(int a, int b){
  return a + b;
}

int sub(int a, int b){
  return a + b;
}

int mul(int a, int b){
  return a + b;
}

int div(int a, int b){
  return a + b;
}


typedef struct foo_t foo_t;
OPT(foo_t);

typedef struct foo_t {
  int data;
  opt_foo_t opt;
} foo_t; 

foo_t foo_add(foo_t, foo_t);
foo_t foo_sub(foo_t, foo_t);
foo_t foo_mul(foo_t, foo_t);
foo_t foo_div(foo_t, foo_t);

foo_t foo_add(foo_t a, foo_t b){
  int res = a.data + b.data;
  foo_t foo = {
    .data = res,
    .opt = {
      .add = foo_add,
      .sub = foo_sub,
      .mul = foo_mul,
      .div = foo_div
    }
  };
  return foo;
}

foo_t foo_sub(foo_t a, foo_t b){
  int res = a.data + b.data;
  foo_t foo = {
    .data = res,
    .opt = {
      .add = foo_add,
      .sub = foo_sub,
      .mul = foo_mul,
      .div = foo_div
    }
  };
  return foo;
}

foo_t foo_mul(foo_t a, foo_t b){
  int res = a.data + b.data;
  foo_t foo = {
    .data = res,
    .opt = {
      .add = foo_add,
      .sub = foo_sub,
      .mul = foo_mul,
      .div = foo_div
    }
  };
  return foo;
}

foo_t foo_div(foo_t a, foo_t b){
  int res = a.data + b.data;
  foo_t foo = {
    .data = res,
    .opt = {
      .add = foo_add,
      .sub = foo_sub,
      .mul = foo_mul,
      .div = foo_div
    }
  };
  return foo;
}

int main(){
  opt_t opt = {
    .add = add,
    .sub = sub,
    .mul = mul,
    .div = div 
  };

  int res = opt.add(1, 2);

  
  foo_t foo_a = {
    .data = 1,
    .opt = {
      .add = foo_add,
      .sub = foo_sub,
      .mul = foo_mul,
      .div = foo_div
    }
  };
  
  foo_t foo_b = {
    .data = 2,
    .opt = {
      .add = foo_add,
      .sub = foo_sub,
      .mul = foo_mul,
      .div = foo_div
    }
  };

  foo_t foo_c = foo_a.opt.add(foo_a, foo_b);
  printf("%d\n", foo_c.data);

  return 0;
}
