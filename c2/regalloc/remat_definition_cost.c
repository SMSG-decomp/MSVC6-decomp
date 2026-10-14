int __fastcall remat_definition_cost(c2_tuple *t)

{
  c2_operand *pcVar1;
  int iVar2;
  int iVar3;
  
  if (g_opt_favor_speed != 0) {
    return 1;
  }
  pcVar1 = t->src;
  iVar3 = 2;
  if (pcVar1->op == 0x14e) {
    return 3;
  }
  if (((pcVar1->base_sym == (c2_symbol *)0x0) && (iVar2 = pcVar1->disp, -0x81 < iVar2)) &&
     (iVar2 < 0x80)) {
    if (iVar2 != 0) {
      iVar3 = 3;
    }
  }
  else {
    iVar3 = 6;
  }
  if (pcVar1->index != (c2_operand *)0x0) {
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

