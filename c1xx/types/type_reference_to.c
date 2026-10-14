c1_type * __thiscall type_reference_to(c1_type *type,char variant_4000)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  local_10.debug_index = 0;
  local_10.code = (-(ushort)(variant_4000 != '\0') & 0x4000) + 0x82;
  local_10.flags = 0;
  local_10.base = type->base;
  local_10.extra.cls = (c1_symbol *)0x0;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

