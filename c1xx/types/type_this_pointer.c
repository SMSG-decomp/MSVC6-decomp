c1_type * __cdecl type_this_pointer(c1_symbol *cls,c1_u16 pointer_flags,ushort cv)

{
  c1_type *pcVar1;
  c1_type local_10;
  undefined2 type_code;
  undefined2 type_flags;
  
  if (cls == (c1_symbol *)0x0) {
    pcVar1 = type_strip_cv_qualifiers(g_class_def_stack[g_class_depth].type);
  }
  else {
    pcVar1 = cls->type;
  }
  if ((pcVar1->flags & cv) != cv) {
    type_code = pcVar1->code;
    type_flags = pcVar1->flags;
    local_10.flags = type_flags | cv;
    local_10.code = type_code;
    local_10.base = pcVar1->base;
    local_10.extra = pcVar1->extra;
    local_10.debug_index = pcVar1->debug_index;
    pcVar1 = type_intern(&local_10);
  }
  local_10.debug_index = 0;
  local_10.flags = pointer_flags;
  local_10.code = 0x82;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = pcVar1;
  pcVar1 = type_intern(&local_10);
  return pcVar1;
}

