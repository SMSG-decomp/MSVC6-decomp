int __fastcall eliminate_tail_recursion(c2_function *fn)

{
  c2_block **ppcVar1;
  c2_edge *pcVar2;
  uint uVar3;
  uint uVar4;
  
  if ((((fn->struct_return == (c2_fe_symbol *)0x0) && ((fn->flags & 0x40) == 0)) &&
      ((g_opt_eh_enabled != 0 || ((fn->flags & 0x10000) == 0)))) &&
     ((fn->fsym->attrs & 0x1000) == 0)) {
    pcVar2 = fn->cfg->last->preds;
    uVar4 = 0;
    while (pcVar2 != (c2_edge *)0x0) {
      ppcVar1 = &pcVar2->from;
      pcVar2 = pcVar2->next_pred;
      uVar3 = tail_recursion_try_block(fn,*ppcVar1);
      uVar4 = uVar4 | uVar3;
    }
    return uVar4 & 1;
  }
  return 0;
}

