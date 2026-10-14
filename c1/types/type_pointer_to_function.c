c1_type * __fastcall type_pointer_to_function(c1_type *function_type)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.debug_index = 0;
  local_10.extra.sym = (c1_symbol *)0x0;
  local_10.flags = (byte)function_type->flags & 0x1f;
  local_10.code = 0x4086;
  local_10.base = function_type;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

