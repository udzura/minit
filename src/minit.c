/*
** minit.c - Minit class
**
** Copyright (c) Uchio Kondo 2019
**
** See Copyright Notice in LICENSE
*/

#include <mruby.h>
#include <mruby/data.h>

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_minit_data;

static const struct mrb_data_type mrb_minit_data_type = {
  "mrb_minit_data", mrb_free,
};

static mrb_value mrb_minit_init(mrb_state *mrb, mrb_value self)
{
  mrb_minit_data *data;
  char *str;
  int len;

  data = (mrb_minit_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_minit_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_minit_data *)mrb_malloc(mrb, sizeof(mrb_minit_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}

static mrb_value mrb_minit_hello(mrb_state *mrb, mrb_value self)
{
  mrb_minit_data *data = DATA_PTR(self);

  return mrb_str_new(mrb, data->str, data->len);
}

static mrb_value mrb_minit_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_minit_gem_init(mrb_state *mrb)
{
  struct RClass *minit;
  // minit = mrb_define_class(mrb, "Minit", mrb->object_class);
  minit = mrb_define_module(mrb, "Minit");
  mrb_define_module_function(mrb, minit, "initialize", mrb_minit_init, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, minit, "hello", mrb_minit_hello, MRB_ARGS_NONE());
  mrb_define_module_function(mrb, minit, "hi", mrb_minit_hi, MRB_ARGS_NONE());
  DONE;
}

void mrb_minit_gem_final(mrb_state *mrb)
{
}
