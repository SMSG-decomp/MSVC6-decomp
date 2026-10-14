void __fastcall retie_register_chain(c2_operand *op,c2_operand *to)

{
  uint uVar1;
  c2_symbol *pcVar2;
  
  pcVar2 = (op->u18).reg;
  if (pcVar2->cls != '\x01') {
    for (; op != (c2_operand *)0x0; op = op->next) {
      if ((op->kind == '\x01') && ((op->u18).reg == pcVar2)) {
        op->u18 = to->u18;
        rebind_def_to_register(op,to,pcVar2);
      }
    }
    return;
  }
  uVar1 = op->sym->offset;
  pcVar2 = reg_find_subreg(pcVar2,(to->type & 0xfff) << 3,(uVar1 & (3 < (int)uVar1) - 1) * 8);
  (to->u18).reg = pcVar2;
  return;
}

