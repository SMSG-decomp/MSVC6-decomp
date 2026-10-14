int __fastcall operands_may_alias_case_1_2(c2_operand *a,c2_operand *b)

{
  uint8_t uVar1;
  uint8_t uVar2;
  c2_symbol *pcVar3;
  c2_live_range *pcVar4;
  c2_live_range *pcVar5;
  uint32_t uVar6;
  int iVar7;
  c2_symbol_cell *pcVar8;
  c2_symbol *pcVar9;
  int iVar10;
  c2_symbol *pcVar11;
  c2_symbol *pcVar12;
  c2_symbol *pcVar13;
  
  pcVar4 = (a->u18).range;
  if (pcVar4->kind == '\x02') {
    switch(b->kind) {
    case '\x01':
      if (((b->u18).reg)->cls != '\x02') {
        return 0;
      }
    case '\x02':
      pcVar11 = b->sym;
      pcVar12 = a->sym;
      pcVar3 = pcVar11->storage;
      pcVar9 = pcVar12->storage;
      if (pcVar9 != pcVar3) {
        if (((g_frame_offsets_assigned != 0) &&
            (((uVar1 = pcVar12->cls, uVar1 == '\x03' || (uVar1 == '\x04')) ||
             ((uVar1 == '\x05' || (uVar1 == '\x06')))))) &&
           ((((uVar2 = pcVar11->cls, uVar2 == '\x03' || (uVar2 == '\x04')) || (uVar2 == '\x05')) ||
            (uVar2 == '\x06')))) {
          if (uVar1 == '\x03') {
            pcVar13 = (pcVar9->u28).free_next;
          }
          else {
            pcVar13 = (c2_symbol *)pcVar9->fe->offset;
          }
          iVar7 = (int)pcVar13 + (pcVar12->offset - pcVar9->offset);
          if (uVar2 == '\x03') {
            pcVar9 = (pcVar3->u28).free_next;
          }
          else {
            pcVar9 = (c2_symbol *)pcVar3->fe->offset;
          }
          iVar10 = (int)pcVar9 + (pcVar11->offset - pcVar3->offset);
          if ((iVar7 < pcVar11->size + iVar10) && (iVar10 < pcVar12->size + iVar7)) {
            return 1;
          }
        }
        return 0;
      }
      if (pcVar12 != pcVar11) {
        if (pcVar11->size + pcVar11->offset <= pcVar12->offset) {
          return 0;
        }
        if (pcVar12->size + pcVar12->offset <= pcVar11->offset) {
          return 0;
        }
      }
      return 1;
    default:
      goto switchD_10702616_caseD_3;
    case '\x06':
      pcVar11 = a->sym;
      pcVar12 = (c2_symbol *)b->tag;
      if (g_frame_offsets_assigned == 0) {
        iVar7 = symbol_in_alias_class(pcVar11,(uint32_t)pcVar12);
        return iVar7;
      }
      break;
    case '\v':
      pcVar11 = a->sym;
      pcVar12 = b->sym;
      if (g_frame_offsets_assigned == 0) {
        iVar7 = symbol_in_alias_class(pcVar11,(uint32_t)pcVar12);
        return iVar7;
      }
    }
    iVar7 = symbol_in_alias_class(pcVar11,(uint32_t)pcVar12);
    if (iVar7 != 0) {
      return 1;
    }
    uVar1 = pcVar11->cls;
    if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) || (uVar1 == '\x06')) {
      for (pcVar8 = stack_slot_aliased_symbols(pcVar11); pcVar8 != (c2_symbol_cell *)0x0;
          pcVar8 = pcVar8->next) {
        iVar7 = symbol_in_alias_class(pcVar8->sym,(uint32_t)pcVar12);
        if (iVar7 != 0) {
          return 1;
        }
      }
    }
    return 0;
  }
  if (b->kind == '\x01') {
    pcVar5 = (b->u18).range;
    if (pcVar4->self == pcVar5->self) {
      if (pcVar4 != pcVar5) {
        if ((int)(pcVar5->allowed->pad_05 + pcVar5->refcount + -5) <= pcVar4->refcount) {
          return 0;
        }
        if ((int)(pcVar4->allowed->pad_05 + pcVar4->refcount + -5) <= pcVar5->refcount) {
          return 0;
        }
      }
      return 1;
    }
  }
  else if ((b->kind == '\n') && (pcVar4->kind == '\x01')) {
    uVar6 = bitset_test((c2_bitset *)b->sym,pcVar4->self->id);
    return uVar6;
  }
switchD_10702616_caseD_3:
  return 0;
}

