c1_type * __thiscall type_member_function_pointer_for_set(c1_type *function_type,c1_symbol *set)

{
  c1_type *pcVar1;
  c1_type cStack_10;
  
  cStack_10.extra = (c1_type_extra)((c1_type_extra *)(**(int **)set->type + 8))->cls;
  if (((cStack_10.extra.cls)->kind & 0x1f) != 4) {
    cStack_10.extra =
         *(c1_type_extra *)(g_scope_vector->entries + (short)(cStack_10.extra.cls)->key_ref);
  }
  cStack_10.flags = (byte)function_type->flags & 0x1f;
  cStack_10.debug_index = 0;
  cStack_10.code = 0x8e;
  cStack_10.base = function_type;
  pcVar1 = type_intern(&cStack_10);
  return pcVar1;
}

