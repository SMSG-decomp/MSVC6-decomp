c2_symbol * __fastcall cse_hash_call_or_intrinsic(c2_tuple *t)

{
  uint16_t type;
  c2_operand *pcVar1;
  uint32_t op;
  c2_symbol *pcVar2;
  int iVar3;
  c2_operand *pcVar4;
  c2_operand **ppcVar5;
  
  pcVar1 = t->src;
  if (t->kind == '\x0e') {
    pcVar4 = pcVar1->next;
    g_expr_operand_scratch[0] = pcVar1;
  }
  else {
    g_expr_operand_scratch[0] = operand_new_intconst(0x1004,(uint)(t->u20).intrinsic.id,0);
    pcVar4 = pcVar1;
  }
  iVar3 = 1;
  if (pcVar4 != (c2_operand *)0x0) {
    ppcVar5 = g_expr_operand_scratch + 1;
    do {
      if ((pcVar4->flags & 0x20) == 0) {
        if (0x10799647 < (int)ppcVar5) {
          ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\hash.c",0x2be);
        }
        if (pcVar4->kind == '\v') {
          *ppcVar5 = pcVar4;
        }
        else {
          *ppcVar5 = pcVar4->sym->def->src;
        }
        pcVar4 = pcVar4->next;
        iVar3 = iVar3 + 1;
        ppcVar5 = ppcVar5 + 1;
      }
    } while (pcVar4 != (c2_operand *)0x0);
  }
  type = t->type;
  op = t->op;
  g_expr_operand_scratch[iVar3] = (c2_operand *)0x0;
  pcVar2 = (c2_symbol *)cse_find_or_insert(op,type);
  return pcVar2;
}

