void __fastcall assign_source_operand_registers(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_symbol *temp;
  uint uVar2;
  c2_register_descriptor *reg;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  
  pcVar1 = t->src;
  do {
    if (pcVar1 == (c2_operand *)0x0) {
      return;
    }
    if (((pcVar1->kind == '\x01') && (pcVar3 = pcVar1->sym, pcVar3->cls == '\x03')) &&
       (pcVar3->def != (c2_tuple *)0x0)) {
      temp = (pcVar1->u18).reg;
      if (temp->cls == '\x01') {
        uVar2 = temp->storage->id;
        if (uVar2 < 9) {
LAB_10733d7e:
          g_register_holders[uVar2] = (c2_symbol *)0x0;
        }
      }
      else {
        reg = find_register_holding_temp(temp);
        pcVar3 = reg_find_subreg(reg,(pcVar1->type & 0xfff) << 3,
                                 (pcVar3->offset & (3 < pcVar3->offset) - 1) * 8);
        (pcVar1->u18).reg = pcVar3;
        pcVar4 = find_dst_reg_operand(temp,t);
        if (pcVar4 == (c2_operand *)0x0) {
          uVar2 = reg->id;
          goto LAB_10733d7e;
        }
      }
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

