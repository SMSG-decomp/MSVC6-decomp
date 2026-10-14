c1_node * __thiscall conv_build_member_pointer_along_base_path(c1_conversion *conv,c1_node *dest)

{
  byte bVar1;
  c1_type *pcVar2;
  char cVar3;
  uint uVar4;
  c1_node *value;
  
  pcVar2 = conv->overload_set->type;
  if (*(c1_type **)pcVar2 == pcVar2->base) {
    if ((conv->flags4e & 8) == 0) {
      uVar4 = sym_list_has_flagged_scope_entry((int)conv->overload_set);
      if ((char)uVar4 != '\0') {
        diag_error(0x1b8,(uint)conv->op,conv->source,conv->target);
        return conv->expr;
      }
    }
    if (g_token_class[conv->op] == 'd') {
      cVar3 = access_check_member_path(conv->overload_set);
      if (cVar3 == '\0') {
        bVar1 = conv->op;
        if ((bVar1 == 200) || (((byte)g_compile_flags_c8 & 1) == 0)) {
          diag_error(0xf3,(uint)bVar1,conv->source,conv->target);
        }
        else {
          diag_warning(3,0xf3,(uint)bVar1,conv->source,conv->target);
        }
      }
    }
    else {
      access_check_member(conv->overload_set);
    }
  }
  else {
    diag_error(0x252,(uint)conv->op,conv->source,conv->target);
  }
  value = pm_convert_along_base_path
                    (conv->expr,conv->target,conv->overload_set,conv->flags4e >> 3 & 1);
  if (dest != (c1_node *)0x0) {
    value = conv_store_converted_value(conv,dest,value);
  }
  return value;
}

