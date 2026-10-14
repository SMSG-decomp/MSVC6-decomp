c1_type * __thiscall type_replace_in_chain(c1_type *type,c1_type *layer,c1_type *replacement)

{
  c1_type *pcVar1;
  c1_type local_10;
  
  if (type == layer) {
    return replacement;
  }
  local_10.base = type_replace_in_chain(type->base,layer,replacement);
  if (type->base != local_10.base) {
    local_10.code = type->code;
    local_10.flags = type->flags;
    local_10.debug_index = type->debug_index;
    local_10.extra = type->extra;
    pcVar1 = type_intern(&local_10);
    return pcVar1;
  }
  return type;
}

