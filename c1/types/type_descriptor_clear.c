void __fastcall type_descriptor_clear(c1_type *type)

{
  type->code = 0;
  type->flags = 0;
  type->base = (c1_type *)0x0;
  (type->extra).sym = (c1_symbol *)0x0;
  type->debug_index = 0;
  return;
}

