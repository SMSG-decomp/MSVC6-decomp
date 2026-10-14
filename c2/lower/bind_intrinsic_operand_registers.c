void __fastcall bind_intrinsic_operand_registers(c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *op;
  c2_intrinsic_fixed_regs *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  pcVar2 = g_intrinsic_fixed_reg_table;
  do {
    if (pcVar2->id == (uint)(t->u20).intrinsic.id) {
      iVar3 = 0;
      for (op = t->src; op != (c2_operand *)0x0; op = op->next) {
        uVar1 = op->kind;
        if ((((uVar1 != '\v') && (uVar1 != '\n')) && ((op->flags & 0x20) == 0)) &&
           ((uVar1 != '\x01' || (op->sym->cls != '\x01')))) {
          operand_set_subreg_of(op,g_reg_symbols + g_intrinsic_fixed_reg_table[iVar4].regs[iVar3]);
          operand_set_subreg_of
                    (op->sym->def->dst,
                     g_reg_symbols + g_intrinsic_fixed_reg_table[iVar4].regs[iVar3]);
        }
        iVar3 = iVar3 + 1;
      }
      return;
    }
    pcVar2 = pcVar2 + 1;
    iVar4 = iVar4 + 1;
  } while ((int)pcVar2 < 0x107a338c);
  return;
}

