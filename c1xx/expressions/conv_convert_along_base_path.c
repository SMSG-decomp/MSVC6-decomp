c1_node * __thiscall conv_convert_along_base_path(c1_conversion *conv,c1_node *obj)

{
  c1_type *pcVar1;
  uint uVar2;
  c1_node *pcVar3;
  c1_type *pcVar4;
  c1_type *extraout_EDX;
  c1_type *extraout_EDX_00;
  
  pcVar1 = conv->overload_set->type;
  pcVar4 = *(c1_type **)pcVar1;
  if (pcVar4 == pcVar1->base) {
    if ((conv->flags4e & 8) != 0) {
      uVar2 = sym_list_has_flagged_scope_entry((int)conv->overload_set);
      pcVar4 = extraout_EDX;
      if ((char)uVar2 != '\0') {
        pcVar3 = conv_check_virtual_base_conversion(conv);
        return pcVar3;
      }
    }
  }
  else {
    diag_error(0x252,(uint)conv->op,conv->source,conv->target);
    pcVar4 = extraout_EDX_00;
  }
  if ((conv->mode < 4) || (9 < conv->mode)) {
    uVar2 = 100;
  }
  else {
    uVar2 = (uint)conv->op;
  }
  pcVar3 = expr_access_checked_member
                     (uVar2,obj,conv->overload_set,
                      CONCAT31((int3)((uint)pcVar4 >> 8),(byte)~conv->flags4e >> 3) & 0xffffff01,
                      conv->target);
  return pcVar3;
}

