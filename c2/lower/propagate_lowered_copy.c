void __fastcall propagate_lowered_copy(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  uint32_t uVar3;
  c2_operand *use;
  int iVar4;
  int iVar5;
  c2_operand *pcVar6;
  
  if ((((t->op == 1) && (pcVar6 = t->dst, pcVar6->kind == '\x01')) && (pcVar6->sym->cls == '\x03'))
     && (pcVar6->sym->def != (c2_tuple *)0x0)) {
    pcVar1 = t->src;
    if ((((pcVar1->kind == '\x01') && (pcVar1->sym->cls == '\x03')) &&
        ((pcVar1->sym->def != (c2_tuple *)0x0 && (((pcVar1->u18).reg)->cls == '\x01')))) &&
       ((uVar3 = temp_operand_piece_mismatch(pcVar6), uVar3 == 0 ||
        ((pcVar6->u18).reg == (pcVar1->u18).reg)))) {
      for (pcVar2 = t->next; pcVar2 != (c2_tuple *)0x0; pcVar2 = pcVar2->next) {
        if (((pcVar2->flags & 1) != 0) && (pcVar2->op != 0x19e)) {
          use = find_src_symbol_ref(pcVar2,pcVar6->sym);
          if (use != (c2_operand *)0x0) {
            pcVar6 = pcVar2->dst;
            if (((((pcVar6 == (c2_operand *)0x0) || (pcVar6->kind != '\x01')) ||
                 (pcVar6->sym->cls != '\x03')) ||
                ((pcVar6->sym->def == (c2_tuple *)0x0 ||
                 (uVar3 = temp_operand_piece_mismatch(pcVar6), uVar3 == 0)))) &&
               (iVar4 = try_substitute_operand(pcVar2,use,pcVar1,tuple_replace_src), iVar4 != 0)) {
              t->op = 0x145;
            }
            break;
          }
          use = find_src_overlapping_reg(pcVar2,(pcVar1->u18).reg);
          if ((use != (c2_operand *)0x0) ||
             (use = find_dst_clobbering_reg(pcVar2,(pcVar1->u18).reg), use != (c2_operand *)0x0))
          break;
        }
      }
    }
    iVar4 = copy_has_single_operands(t);
    if (iVar4 != 0) {
      pcVar6 = t->dst;
      uVar3 = temp_operand_piece_mismatch(pcVar6);
      if (((uVar3 == 0) &&
          (((pcVar1 = t->src, pcVar1->kind != '\a' ||
            ((pcVar1->u18).reg != (c2_symbol *)0x0 || pcVar1->tag != 0)) &&
           (pcVar2 = t->next, (pcVar2->flags & 1) != 0)))) &&
         ((iVar4 = src_position_of_symbol(pcVar2,pcVar6->sym), iVar4 != 0 &&
          (iVar5 = operand_fits_instruction(pcVar2,iVar4,pcVar1), iVar5 != 0)))) {
        if (iVar4 == 1) {
          pcVar6 = pcVar2->src;
        }
        else {
          pcVar6 = pcVar2->src->next;
        }
        iVar4 = try_substitute_operand(pcVar2,pcVar6,pcVar1,tuple_replace_src);
        if (iVar4 != 0) {
          t->op = 0x145;
        }
      }
    }
  }
  return;
}

