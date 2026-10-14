int __fastcall operands_may_alias(c2_operand *a,c2_operand *b)

{
  uint8_t uVar1;
  uint8_t uVar2;
  c2_symbol *pcVar3;
  uint uVar4;
  uint32_t uVar5;
  c2_symbol_cell *pcVar6;
  c2_symbol *pcVar7;
  int iVar8;
  int iVar9;
  c2_symbol *member;
  c2_symbol *b_storage;
  uint *puVar10;
  int32_t a_frame_base;
  c2_symbol_cell *group_cell;
  c2_symbol *b_reg;
  c2_symbol *a_reg;
  
  if (a == b) {
    return 1;
  }
  switch(a->kind) {
  case '\x01':
    a_reg = (a->u18).reg;
    if (a_reg->cls != '\x02') {
      if (b->kind == '\x01') {
        b_reg = (b->u18).reg;
        if (a_reg->storage != b_reg->storage) {
          return 0;
        }
        if (a_reg != b_reg) {
          if (b_reg->size + b_reg->offset <= a_reg->offset) {
            return 0;
          }
          if (a_reg->size + a_reg->offset <= b_reg->offset) {
            return 0;
          }
        }
        return 1;
      }
      if (b->kind != '\n') {
        return 0;
      }
      if (a_reg->cls != '\x01') {
        return 0;
      }
      uVar5 = bitset_test((c2_bitset *)b->sym,a_reg->storage->id);
      return uVar5;
    }
  case '\x02':
    switch(b->kind) {
    case '\x01':
      if (((b->u18).reg)->cls != '\x02') {
        return 0;
      }
    case '\x02':
      member = b->sym;
      b_storage = a->sym;
      pcVar3 = member->storage;
      pcVar7 = b_storage->storage;
      if (pcVar7 != pcVar3) {
        if (((g_frame_offsets_assigned != 0) &&
            (((uVar1 = b_storage->cls, uVar1 == '\x03' || (uVar1 == '\x04')) ||
             ((uVar1 == '\x05' || (uVar1 == '\x06')))))) &&
           ((((uVar2 = member->cls, uVar2 == '\x03' || (uVar2 == '\x04')) || (uVar2 == '\x05')) ||
            (uVar2 == '\x06')))) {
          if (uVar1 == '\x03') {
            a_frame_base = (pcVar7->u28).frame_home;
          }
          else {
            a_frame_base = pcVar7->fe->offset;
          }
          iVar9 = a_frame_base + (b_storage->offset - pcVar7->offset);
          if (uVar2 == '\x03') {
            pcVar7 = (pcVar3->u28).free_next;
          }
          else {
            pcVar7 = (c2_symbol *)pcVar3->fe->offset;
          }
          iVar8 = (int)pcVar7 + (member->offset - pcVar3->offset);
          if ((iVar9 < member->size + iVar8) && (iVar8 < b_storage->size + iVar9)) {
            return 1;
          }
        }
        return 0;
      }
      if (b_storage != member) {
        if (member->size + member->offset <= b_storage->offset) {
          return 0;
        }
        if (b_storage->size + b_storage->offset <= member->offset) {
          return 0;
        }
      }
      return 1;
    default:
switchD_10702616_caseD_3:
      return 0;
    case '\x06':
      b_storage = a->sym;
      member = (c2_symbol *)b->tag;
      if (g_frame_offsets_assigned == 0) {
        iVar9 = symbol_in_alias_class(b_storage,(uint32_t)member);
        return iVar9;
      }
      break;
    case '\v':
      b_storage = a->sym;
      member = b->sym;
      if (g_frame_offsets_assigned == 0) {
        iVar9 = symbol_in_alias_class(b_storage,(uint32_t)member);
        return iVar9;
      }
    }
    break;
  default:
    goto switchD_10702616_caseD_3;
  case '\x06':
    switch(b->kind) {
    case '\x01':
      if (((b->u18).reg)->cls != '\x02') {
        return 0;
      }
    case '\x02':
      member = (c2_symbol *)a->tag;
      b_storage = b->sym;
      if (g_frame_offsets_assigned == 0) {
        iVar9 = symbol_in_alias_class(b_storage,(uint32_t)member);
        return iVar9;
      }
      break;
    default:
      goto switchD_10702616_caseD_3;
    case '\x06':
      uVar5 = alias_classes_intersect(a->tag,b->tag);
      return uVar5;
    case '\v':
      uVar5 = alias_classes_intersect(a->tag,(uint32_t)b->sym);
      return uVar5;
    }
    break;
  case '\n':
    if ((b->kind == '\x01') && (((b->u18).reg)->cls == '\x01')) {
      uVar5 = bitset_test((c2_bitset *)a->sym,((b->u18).reg)->storage->id);
      return uVar5;
    }
    if (b->kind != '\n') {
      return 0;
    }
    iVar9 = bitset_intersects((c2_bitset *)a->sym,(c2_bitset *)b->sym);
    return iVar9;
  case '\v':
    switch(b->kind) {
    case '\x01':
      if (((b->u18).reg)->cls != '\x02') {
        return 0;
      }
    case '\x02':
      member = a->sym;
      b_storage = b->sym;
      if (g_frame_offsets_assigned == 0) {
        if (member == (c2_symbol *)0x1) {
          return 1;
        }
        b_storage = b_storage->storage;
        if (g_alias_class_count <= member) {
          member = (c2_symbol *)g_alias_secondary_records[(int)member - g_alias_class_count].parent;
        }
        switch(b_storage->cls) {
        case '\x04':
        case '\x05':
          if ((b_storage->flags5 & 2) != 0) {
            if ((b_storage->flags5 & 4) == 0) {
              if ((g_alias_pointee_class_base <= member) &&
                 (pcVar6 = g_alias_primary_table[(int)member], pcVar6 != (c2_symbol_cell *)0x0)) {
                do {
                  if (pcVar6->sym == b_storage) {
                    return 1;
                  }
                  pcVar6 = pcVar6->next;
                } while (pcVar6 != (c2_symbol_cell *)0x0);
                return 0;
              }
            }
            else {
              pcVar6 = g_alias_primary_table[(int)member];
              if (pcVar6 != (c2_symbol_cell *)0x0) {
                do {
                  member = pcVar6->sym;
                  if (member->cls == '\f') {
                    for (group_cell = (member->u30).members; group_cell != (c2_symbol_cell *)0x0;
                        group_cell = group_cell->next) {
                      if (group_cell->sym == b_storage) {
                        return 1;
                      }
                    }
                  }
                  else if (member == b_storage) {
                    return 1;
                  }
                  pcVar6 = pcVar6->next;
                } while (pcVar6 != (c2_symbol_cell *)0x0);
                return 0;
              }
            }
          }
          break;
        case '\a':
        case '\b':
          if (((b_storage->flags5 & 4) == 0) || ((b_storage->flags5 & 2) != 0)) {
            for (pcVar6 = g_alias_primary_table[(int)member]; pcVar6 != (c2_symbol_cell *)0x0;
                pcVar6 = pcVar6->next) {
              if (pcVar6->sym == b_storage) {
                return 1;
              }
              if (pcVar6->sym == g_alias_special_symbol) {
                return 1;
              }
            }
          }
        }
        return 0;
      }
      break;
    default:
      goto switchD_10702616_caseD_3;
    case '\x06':
      uVar5 = alias_classes_intersect((uint32_t)a->sym,b->tag);
      return uVar5;
    case '\v':
      b_storage = b->sym;
      member = a->sym;
      if (((member == b_storage) || (member == (c2_symbol *)0x1)) || (b_storage == (c2_symbol *)0x1)
         ) {
        return 1;
      }
      if (g_alias_class_count <= member) {
        iVar9 = (int)member - g_alias_class_count;
        member = (c2_symbol *)g_alias_secondary_records[iVar9].parent;
        if (b_storage < g_alias_class_count) goto LAB_10702522;
        if ((member == (c2_symbol *)
                       g_alias_secondary_records[(int)b_storage - g_alias_class_count].parent) &&
           (g_alias_field_overlap_test != 0)) {
          return 1 << ((byte)g_alias_secondary_records[(int)b_storage - g_alias_class_count].bit &
                      0x1f) & g_alias_secondary_records[iVar9].overlap;
        }
      }
      if (g_alias_class_count <= b_storage) {
        b_storage = (c2_symbol *)
                    g_alias_secondary_records[(int)b_storage - g_alias_class_count].parent;
      }
LAB_10702522:
      puVar10 = g_alias_class_symbol_sets[(int)b_storage]->words;
      uVar4 = (g_alias_class_symbol_sets[(int)member]->nbits & 0xffffff) + 0x1f >> 5;
      if (uVar4 != 0) {
        iVar9 = (int)g_alias_class_symbol_sets[(int)member]->words - (int)puVar10;
        do {
          if ((*puVar10 & *(uint *)(iVar9 + (int)puVar10)) != 0) {
            return 1;
          }
          puVar10 = puVar10 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      return 0;
    }
  }
  iVar9 = symbol_in_alias_class(b_storage,(uint32_t)member);
  if (iVar9 != 0) {
    return 1;
  }
  uVar1 = b_storage->cls;
  if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) || (uVar1 == '\x06')) {
    for (pcVar6 = stack_slot_aliased_symbols(b_storage); pcVar6 != (c2_symbol_cell *)0x0;
        pcVar6 = pcVar6->next) {
      iVar9 = symbol_in_alias_class(pcVar6->sym,(uint32_t)member);
      if (iVar9 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

