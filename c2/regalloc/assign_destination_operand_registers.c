void __fastcall assign_destination_operand_registers(c2_tuple *t)

{
  c2_operand *op;
  c2_symbol *temp;
  uint uVar1;
  c2_symbol *pcVar2;
  byte bVar3;
  
  for (op = t->dst; op != (c2_operand *)0x0; op = op->next) {
    if (((op->kind == '\x01') && (pcVar2 = op->sym, pcVar2->cls == '\x03')) &&
       (pcVar2->def != (c2_tuple *)0x0)) {
      temp = (op->u18).reg;
      if (temp->cls == '\x01') {
        uVar1 = temp->storage->id;
        if (uVar1 < 9) {
          g_register_holders[uVar1] = pcVar2;
        }
      }
      else {
        pcVar2 = find_register_holding_temp(temp);
        if (pcVar2 == g_reg_symbols) {
          pcVar2 = select_local_register(op,t);
          bVar3 = op->flags11 | 0x10;
        }
        else {
          bVar3 = op->flags11 & 0xef;
        }
        op->flags11 = bVar3;
        uVar1 = op->sym->offset;
        pcVar2 = reg_find_subreg(pcVar2,(op->type & 0xfff) << 3,((3 < (int)uVar1) - 1 & uVar1) * 8);
        (op->u18).reg = pcVar2;
      }
    }
  }
  return;
}

