c1_type * __thiscall lookup_class_pointer_type(void *lookup,c1_u32 qualifiers)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  pcVar1 = *(c1_type **)(**(int **)((int)lookup + 8) + 4);
  if (qualifiers != 0) {
    local_10.code = pcVar1->code;
    local_10.flags = pcVar1->flags;
    local_10.base = pcVar1->base;
    local_10.extra.count = qualifiers;
    local_10.debug_index = pcVar1->debug_index;
    pcVar1 = type_intern(&local_10);
  }
  local_10.debug_index = 0;
  local_10.code = 0x80;
  local_10.flags = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = pcVar1;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

