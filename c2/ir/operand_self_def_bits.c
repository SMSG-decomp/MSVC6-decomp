uint32_t __fastcall operand_self_def_bits(c2_operand *op)

{
  c2_symbol *pcVar1;
  
  if ((op->kind != 0) && (op->kind < 3)) {
    if (op->sym->def == (c2_tuple *)0x0) {
      return 0xffffffff;
    }
    pcVar1 = op->sym->storage;
    if (pcVar1->def->dst->sym == pcVar1) {
      return (uint)(pcVar1->u30).globopt.live;
    }
  }
  return 0;
}

