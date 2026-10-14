int __fastcall retarget_value_chain_register(c2_tuple *t,c2_symbol *from,c2_symbol *to)

{
  c2_tuple *pcVar1;
  uint uVar2;
  c2_operand *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  c2_symbol *pcVar6;
  uint32_t uVar7;
  
  pcVar3 = find_dst_reg_operand(from,t);
  if (pcVar3 != (c2_operand *)0x0) {
    return 0;
  }
  pcVar3 = t->src;
  pcVar1 = pcVar3->sym->def;
  if (((pcVar1->type & 0xfff) != 1) || (to->id < 5)) {
    pcVar4 = find_src_reg_operand(from,pcVar1);
    while( true ) {
      if (pcVar4 == (c2_operand *)0x0) {
        pcVar1 = pcVar1->next;
        do {
          if (pcVar1 == t) {
            while (pcVar3 != (c2_operand *)0x0) {
              pcVar6 = pcVar3->sym;
              uVar2 = pcVar6->offset;
              pcVar5 = reg_find_subreg(to,(pcVar3->type & 0xfff) << 3,
                                       (uVar2 & (3 < (int)uVar2) - 1) * 8);
              pcVar1 = pcVar6->def;
              (pcVar3->u18).reg = pcVar5;
              pcVar3 = find_dst_reg_operand(from,pcVar1);
              uVar2 = pcVar3->sym->offset;
              pcVar6 = reg_find_subreg(to,(pcVar3->type & 0xfff) << 3,
                                       (uVar2 & (3 < (int)uVar2) - 1) * 8);
              (pcVar3->u18).reg = pcVar6;
              pcVar3 = find_src_reg_operand(from,pcVar1);
            }
            return 1;
          }
          if ((pcVar1->flags & 1) != 0) {
            for (pcVar4 = pcVar1->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
              if ((pcVar4->kind == '\x01') && (((pcVar4->u18).reg)->storage == to)) {
                return 0;
              }
            }
            for (pcVar4 = pcVar1->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
              if (pcVar4->kind == '\x01') {
                if (((pcVar4->u18).reg)->storage == to) {
                  return 0;
                }
              }
              else if ((pcVar4->kind == '\n') &&
                      (uVar7 = bitset_test((c2_bitset *)pcVar4->sym,to->id), uVar7 != 0)) {
                return 0;
              }
            }
          }
          pcVar1 = pcVar1->next;
        } while( true );
      }
      if (((((pcVar4->type & 0xfff) == 1) && (4 < to->id)) ||
          (((pcVar1->type ^ pcVar4->type) & 0xfff) != 0)) ||
         ((pcVar1 = pcVar4->sym->def, (pcVar1->type & 0xfff) == 1 && (4 < to->id)))) break;
      pcVar4 = find_src_reg_operand(from,pcVar1);
    }
  }
  return 0;
}

