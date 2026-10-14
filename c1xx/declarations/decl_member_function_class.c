c1_symbol * __fastcall decl_member_function_class(c1_decl_record *rec)

{
  c1_symbol *pcVar1;
  byte bVar2;
  
  pcVar1 = (c1_symbol *)rec->qualifier;
  if (((pcVar1 == (c1_symbol *)0x0) && (pcVar1 = rec->sym, pcVar1 == (c1_symbol *)0x0)) ||
     ((pcVar1->kind & 0x1f) != 0x12)) {
    if (((-1 < g_class_depth) && (g_prototype_scope_depth == 0)) && ((rec->spec[0] & 0x400) == 0)) {
      if (-1 < g_class_depth) {
        return g_class_def_stack[g_class_depth].cls;
      }
      return (c1_symbol *)0x0;
    }
  }
  else {
    if (pcVar1->type == (c1_type *)0x0) {
      pcVar1 = class_current_definition();
    }
    else {
      pcVar1 = *(c1_symbol **)(**(int **)pcVar1->type + 8);
    }
    if ((pcVar1 != (c1_symbol *)0x0) && (bVar2 = pcVar1->kind & 0x1f, bVar2 != 0x19)) {
      if (bVar2 == 4) {
        return pcVar1;
      }
      return g_scope_vector->entries[(short)pcVar1->key_ref];
    }
  }
  return (c1_symbol *)0x0;
}

