c1_type * __fastcall type_intern_pointer_to(c1_type *array_type)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.base = array_type->base;
  local_10.debug_index = 0;
  local_10.code = 0x82;
  local_10.flags = 0;
  local_10.extra.sym = (c1_symbol *)0x0;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

