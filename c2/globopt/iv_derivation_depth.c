int __fastcall iv_derivation_depth(c2_symbol *s,c2_symbol *iv,int depth)

{
  c2_copy_link *pcVar1;
  c2_symbol *s_00;
  c2_operand *op;
  int iVar2;
  int iVar3;
  
  op = tuple_iv_second_source((c2_tuple *)s,iv);
  iVar2 = iv_operand_is_variable(op);
  if (iVar2 == 0) {
    iVar3 = iv_has_non_plain_use(s);
    iVar2 = depth;
    if (iVar3 == 0) {
      iVar2 = -1;
    }
    for (pcVar1 = (s->u34).source_links; pcVar1 != (c2_copy_link *)0x0;
        pcVar1 = pcVar1->next_of_source) {
      s_00 = pcVar1->copy;
      iVar3 = iv_tuple_is_add_sub_of((c2_operand *)s_00,s);
      if ((iVar3 != 0) && (iVar3 = iv_derivation_depth(s_00,s,depth + 1), iVar2 < iVar3)) {
        iVar2 = iVar3;
      }
    }
    return iVar2;
  }
  return -1;
}

