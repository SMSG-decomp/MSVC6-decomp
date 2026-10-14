int __fastcall sizeopt_dead_high_bits(c2_tuple *t)

{
  ushort uVar1;
  ushort uVar2;
  c2_operand *op;
  c2_symbol *pcVar3;
  uint32_t uVar4;
  uint uVar5;
  
  uVar1 = t->type;
  if ((uVar1 & 0xfff) < 5) {
    uVar4 = t->op;
    if ((uVar4 == 0x15f) && (uVar2 = t->src->type, (uVar1 & 0xfff) < (uVar2 & 0xfff))) {
      return ((uVar2 & 0xfff) - (uVar1 & 0xfff)) * 8;
    }
    if (((t->src != (c2_operand *)0x0) && (op = t->src->next, op != (c2_operand *)0x0)) &&
       (op->kind == '\a')) {
      if (uVar4 == 0x172) {
        uVar4 = operand_known_leading_zero_bits(op);
        return uVar4 + (4 - (uVar1 & 0xfff)) * 8;
      }
      if (((uVar4 == 0x177) && ((1 << (t->dst->kind & 0x1f) & 6U) != 0)) &&
         (pcVar3 = t->dst->sym, pcVar3->def != (c2_tuple *)0x0)) {
        uVar5 = (uint)(pcVar3->u30).globopt.killed;
        if ((int)(op->u18).lo < (int)uVar5) {
          return uVar5 - (op->u18).lo;
        }
      }
    }
  }
  return 0;
}

