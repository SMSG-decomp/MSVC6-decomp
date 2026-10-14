int __fastcall operands_same_location(c2_operand *opnd,c2_operand *b)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_operand *pcVar3;
  c2_tuple *pcVar4;
  uint32_t uVar5;
  c2_live_range *pcVar6;
  c2_live_range *pcVar7;
  int iVar8;
  c2_symbol *pcVar9;
  int local_c;
  
  if (opnd == b) {
    return 1;
  }
  uVar1 = opnd->kind;
  if (uVar1 == '\x01') {
    pcVar6 = (opnd->u18).range;
    if (pcVar6->kind != '\x02') {
      if (b->kind != '\x01') {
        return 0;
      }
      pcVar7 = (b->u18).range;
      if (pcVar6->self != pcVar7->self) {
        return 0;
      }
      if (pcVar7->refcount < pcVar6->refcount) {
        return 0;
      }
      if ((int)(pcVar6->allowed->pad_05 + pcVar6->refcount + -5) <
          (int)(pcVar7->allowed->pad_05 + pcVar7->refcount + -5)) {
        return 0;
      }
      return 1;
    }
  }
  else if (uVar1 != '\x02') {
    if (uVar1 != '\x06') {
      return 0;
    }
    if (b->kind != '\x06') {
      return 0;
    }
    if (opnd->tag != b->tag) {
      return 0;
    }
    if (g_alias_symbol_class_count <= opnd->tag) {
      if ((opnd->index == (c2_operand *)0x0) && (b->index == (c2_operand *)0x0)) {
        pcVar2 = opnd->base;
        local_c = opnd->disp;
        pcVar3 = b->base;
        iVar8 = b->disp;
        if ((((1 << (pcVar2->kind & 0x1f) & 6U) == 0) ||
            (pcVar4 = pcVar2->sym->def, pcVar4 == (c2_tuple *)0x0)) ||
           ((pcVar2->kind == 1 && (((pcVar2->u18).reg)->cls == '\x01')))) {
          pcVar9 = pcVar2->sym;
        }
        else {
          uVar5 = pcVar4->op;
          pcVar9 = (c2_symbol *)0x0;
          if ((uVar5 != 0x16d) && (uVar5 != 0x16e)) {
            return 0;
          }
          for (pcVar2 = pcVar4->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
            uVar1 = pcVar2->kind;
            if ((uVar1 == '\x02') || (uVar1 == '\x01')) {
              if (pcVar9 != (c2_symbol *)0x0) {
                return 0;
              }
              pcVar9 = pcVar2->sym;
            }
            else {
              if (uVar1 != '\a') {
                return 0;
              }
              if (uVar5 == 0x16d) {
                local_c = local_c + (pcVar2->u18).lo;
              }
              else {
                local_c = local_c - (pcVar2->u18).lo;
              }
            }
          }
        }
        if ((pcVar9->flags5 & 8) != 0) {
          if (((1 << (pcVar3->kind & 0x1f) & 6U) == 0) ||
             (pcVar4 = pcVar3->sym->def, pcVar4 == (c2_tuple *)0x0)) {
            pcVar9 = pcVar3->sym;
          }
          else {
            uVar5 = pcVar4->op;
            pcVar9 = (c2_symbol *)0x0;
            if ((uVar5 != 0x16d) && (uVar5 != 0x16e)) {
              return 0;
            }
            for (pcVar2 = pcVar4->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
              uVar1 = pcVar2->kind;
              if ((uVar1 == '\x02') || (uVar1 == '\x01')) {
                if (pcVar9 != (c2_symbol *)0x0) {
                  return 0;
                }
                pcVar9 = pcVar2->sym;
              }
              else {
                if (uVar1 != '\a') {
                  return 0;
                }
                if (uVar5 == 0x16d) {
                  iVar8 = iVar8 + (pcVar2->u18).lo;
                }
                else {
                  iVar8 = iVar8 - (pcVar2->u18).lo;
                }
              }
            }
          }
          if ((pcVar9->flags5 & 8) != 0) {
            if ((local_c <= iVar8) &&
               ((int)((b->type & 0xfff) + iVar8) <= (int)((opnd->type & 0xfff) + local_c))) {
              return 1;
            }
          }
        }
      }
      return 0;
    }
    return 0;
  }
  if ((b->kind != '\x02') && ((b->kind != '\x01' || (((b->u18).reg)->cls != '\x02')))) {
    return 0;
  }
  iVar8 = symbol_contains(opnd->sym,b->sym);
  return iVar8;
}

