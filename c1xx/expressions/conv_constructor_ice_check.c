char __thiscall conv_constructor_ice_check(c1_conversion *conv,c1_conversion *seq)

{
  c1_node *pcVar1;
  c1_symbol *pcVar2;
  
  pcVar1 = conv->expr->link;
  if ((((pcVar1 != (c1_node *)0x0) && (g_token_class[pcVar1->op] == '`')) &&
      ((conv->target->code & 0x200) != 0)) &&
     (((pcVar2 = (seq->via).function, pcVar2 != (c1_symbol *)0x0 ||
       (pcVar2 = (c1_symbol *)
                 class_find_member_function_matching
                           (conv->target,(int)g_name_ctor,sym_is_copy_constructor),
       pcVar2 != (c1_symbol *)0x0)) &&
      (((*(byte *)((int)&pcVar2->tail + 8) & 0x20) == 0 ||
       ((*(byte *)((int)&pcVar2->tail + 9) & 0x10) == 0)))))) {
    return '\x01';
  }
  return '\0';
}

