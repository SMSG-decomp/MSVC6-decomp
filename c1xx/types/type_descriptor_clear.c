void __fastcall type_descriptor_clear(c1_type *t)

{
  t->code = 0;
  t->flags = 0;
  t->base = (c1_type *)0x0;
  (t->extra).cls = (c1_symbol *)0x0;
  t->debug_index = 0;
  return;
}

