int __fastcall operand_def_is_aligned_imul(c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_operand *pcVar2;
  
  if (((((1 << (t->src->kind & 0x1f) & 6U) != 0) &&
       (pcVar1 = t->src->sym->def, pcVar1 != (c2_tuple *)0x0)) && (pcVar1->op == 0xc1)) &&
     ((pcVar2 = pcVar1->src->next, pcVar2->kind == '\a' && (((pcVar2->u18).lo & 3) == 0)))) {
    return 1;
  }
  return 0;
}

