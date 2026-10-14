uint32_t __fastcall operands_overlap(c2_operand *a,c2_operand *b)

{
  uint8_t uVar1;
  uint8_t uVar2;
  c2_symbol *pcVar3;
  uint uVar4;
  c2_symbol_cell *pcVar5;
  c2_symbol *pcVar6;
  int iVar7;
  uint32_t uVar8;
  c2_symbol *member_sym;
  c2_symbol *target_storage;
  uint *puVar9;
  int iVar10;
  int home_b;
  c2_symbol *a_reg;
  c2_symbol *b_reg;
  c2_symbol_cell *member_cell;
  
  if (b->kind == '\x01') {
    if (a->kind == '\x06') {
      member_sym = ((b->u18).reg)->storage;
      if (((a->base != (c2_operand *)0x0) && (((a->base->u18).reg)->storage == member_sym)) ||
         ((a->index != (c2_operand *)0x0 && (((a->index->u18).reg)->storage == member_sym)))) {
        return 1;
      }
    }
    return 0;
  }
  if (b == a) {
    return 1;
  }
  switch(b->kind) {
  case '\x01':
    b_reg = (b->u18).reg;
    if (b_reg->cls != '\x02') {
      if (a->kind == '\x01') {
        a_reg = (a->u18).reg;
        if (b_reg->storage != a_reg->storage) {
          return 0;
        }
        if (b_reg != a_reg) {
          if (a_reg->size + a_reg->offset <= b_reg->offset) {
            return 0;
          }
          if (b_reg->size + b_reg->offset <= a_reg->offset) {
            return 0;
          }
        }
        return 1;
      }
      if (a->kind != '\n') {
        return 0;
      }
      if (b_reg->cls != '\x01') {
        return 0;
      }
      uVar8 = bitset_test((c2_bitset *)a->sym,b_reg->storage->id);
      return uVar8;
    }
  case '\x02':
    switch(a->kind) {
    case '\x01':
      if (((a->u18).reg)->cls != '\x02') {
        return 0;
      }
    case '\x02':
      member_sym = a->sym;
      target_storage = b->sym;
      pcVar3 = member_sym->storage;
      pcVar6 = target_storage->storage;
      if (pcVar6 != pcVar3) {
        if (((g_frame_offsets_assigned != 0) &&
            (((uVar1 = target_storage->cls, uVar1 == '\x03' || (uVar1 == '\x04')) ||
             ((uVar1 == '\x05' || (uVar1 == '\x06')))))) &&
           ((((uVar2 = member_sym->cls, uVar2 == '\x03' || (uVar2 == '\x04')) || (uVar2 == '\x05'))
            || (uVar2 == '\x06')))) {
          if (uVar1 == '\x03') {
            home_b = (pcVar6->u28).frame_home;
          }
          else {
            home_b = pcVar6->fe->offset;
          }
          iVar10 = home_b + (target_storage->offset - pcVar6->offset);
          if (uVar2 == '\x03') {
            pcVar6 = (pcVar3->u28).free_next;
          }
          else {
            pcVar6 = (c2_symbol *)pcVar3->fe->offset;
          }
          iVar7 = (int)pcVar6 + (member_sym->offset - pcVar3->offset);
          if ((iVar10 < member_sym->size + iVar7) && (iVar7 < target_storage->size + iVar10)) {
            return 1;
          }
        }
        return 0;
      }
      if (target_storage != member_sym) {
        if (member_sym->size + member_sym->offset <= target_storage->offset) {
          return 0;
        }
        if (target_storage->size + target_storage->offset <= member_sym->offset) {
          return 0;
        }
      }
      return 1;
    default:
switchD_10702616_caseD_3:
      return 0;
    case '\x06':
      target_storage = b->sym;
      member_sym = (c2_symbol *)a->tag;
      if (g_frame_offsets_assigned == 0) {
        uVar8 = symbol_in_alias_class(target_storage,(uint32_t)member_sym);
        return uVar8;
      }
      break;
    case '\v':
      target_storage = b->sym;
      member_sym = a->sym;
      if (g_frame_offsets_assigned == 0) {
        uVar8 = symbol_in_alias_class(target_storage,(uint32_t)member_sym);
        return uVar8;
      }
    }
    break;
  default:
    goto switchD_10702616_caseD_3;
  case '\x06':
    switch(a->kind) {
    case '\x01':
      if (((a->u18).reg)->cls != '\x02') {
        return 0;
      }
    case '\x02':
      member_sym = (c2_symbol *)b->tag;
      target_storage = a->sym;
      if (g_frame_offsets_assigned == 0) {
        uVar8 = symbol_in_alias_class(target_storage,(uint32_t)member_sym);
        return uVar8;
      }
      break;
    default:
      goto switchD_10702616_caseD_3;
    case '\x06':
      uVar8 = alias_classes_intersect(b->tag,a->tag);
      return uVar8;
    case '\v':
      uVar8 = alias_classes_intersect(b->tag,(uint32_t)a->sym);
      return uVar8;
    }
    break;
  case '\n':
    if ((a->kind == '\x01') && (((a->u18).reg)->cls == '\x01')) {
      uVar8 = bitset_test((c2_bitset *)b->sym,((a->u18).reg)->storage->id);
      return uVar8;
    }
    if (a->kind != '\n') {
      return 0;
    }
    uVar8 = bitset_intersects((c2_bitset *)b->sym,(c2_bitset *)a->sym);
    return uVar8;
  case '\v':
    switch(a->kind) {
    case '\x01':
      if (((a->u18).reg)->cls != '\x02') {
        return 0;
      }
    case '\x02':
      member_sym = b->sym;
      target_storage = a->sym;
      if (g_frame_offsets_assigned == 0) {
        if (member_sym == (c2_symbol *)0x1) {
          return 1;
        }
        target_storage = target_storage->storage;
        if (g_alias_class_count <= member_sym) {
          member_sym = (c2_symbol *)
                       g_alias_secondary_records[(int)member_sym - g_alias_class_count].parent;
        }
        switch(target_storage->cls) {
        case '\x04':
        case '\x05':
          if ((target_storage->flags5 & 2) != 0) {
            if ((target_storage->flags5 & 4) == 0) {
              if ((g_alias_pointee_class_base <= member_sym) &&
                 (pcVar5 = g_alias_primary_table[(int)member_sym], pcVar5 != (c2_symbol_cell *)0x0))
              {
                do {
                  if (pcVar5->sym == target_storage) {
                    return 1;
                  }
                  pcVar5 = pcVar5->next;
                } while (pcVar5 != (c2_symbol_cell *)0x0);
                return 0;
              }
            }
            else {
              pcVar5 = g_alias_primary_table[(int)member_sym];
              if (pcVar5 != (c2_symbol_cell *)0x0) {
                do {
                  member_sym = pcVar5->sym;
                  if (member_sym->cls == '\f') {
                    for (member_cell = (member_sym->u30).members;
                        member_cell != (c2_symbol_cell *)0x0; member_cell = member_cell->next) {
                      if (member_cell->sym == target_storage) {
                        return 1;
                      }
                    }
                  }
                  else if (member_sym == target_storage) {
                    return 1;
                  }
                  pcVar5 = pcVar5->next;
                } while (pcVar5 != (c2_symbol_cell *)0x0);
                return 0;
              }
            }
          }
          break;
        case '\a':
        case '\b':
          if (((target_storage->flags5 & 4) == 0) || ((target_storage->flags5 & 2) != 0)) {
            for (pcVar5 = g_alias_primary_table[(int)member_sym]; pcVar5 != (c2_symbol_cell *)0x0;
                pcVar5 = pcVar5->next) {
              if (pcVar5->sym == target_storage) {
                return 1;
              }
              if (pcVar5->sym == g_alias_special_symbol) {
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
      uVar8 = alias_classes_intersect((uint32_t)b->sym,a->tag);
      return uVar8;
    case '\v':
      target_storage = a->sym;
      member_sym = b->sym;
      if (((member_sym == target_storage) || (member_sym == (c2_symbol *)0x1)) ||
         (target_storage == (c2_symbol *)0x1)) {
        return 1;
      }
      if (g_alias_class_count <= member_sym) {
        iVar10 = (int)member_sym - g_alias_class_count;
        member_sym = (c2_symbol *)g_alias_secondary_records[iVar10].parent;
        if (target_storage < g_alias_class_count) goto LAB_10702522;
        if ((member_sym ==
             (c2_symbol *)
             g_alias_secondary_records[(int)target_storage - g_alias_class_count].parent) &&
           (g_alias_field_overlap_test != 0)) {
          return 1 << ((byte)g_alias_secondary_records[(int)target_storage - g_alias_class_count].
                             bit & 0x1f) & g_alias_secondary_records[iVar10].overlap;
        }
      }
      if (g_alias_class_count <= target_storage) {
        target_storage =
             (c2_symbol *)
             g_alias_secondary_records[(int)target_storage - g_alias_class_count].parent;
      }
LAB_10702522:
      puVar9 = g_alias_class_symbol_sets[(int)target_storage]->words;
      uVar4 = (g_alias_class_symbol_sets[(int)member_sym]->nbits & 0xffffff) + 0x1f >> 5;
      if (uVar4 != 0) {
        iVar10 = (int)g_alias_class_symbol_sets[(int)member_sym]->words - (int)puVar9;
        do {
          if ((*puVar9 & *(uint *)(iVar10 + (int)puVar9)) != 0) {
            return 1;
          }
          puVar9 = puVar9 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      return 0;
    }
  }
  iVar10 = symbol_in_alias_class(target_storage,(uint32_t)member_sym);
  if (iVar10 != 0) {
    return 1;
  }
  uVar1 = target_storage->cls;
  if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) || (uVar1 == '\x06')) {
    for (pcVar5 = stack_slot_aliased_symbols(target_storage); pcVar5 != (c2_symbol_cell *)0x0;
        pcVar5 = pcVar5->next) {
      iVar10 = symbol_in_alias_class(pcVar5->sym,(uint32_t)member_sym);
      if (iVar10 != 0) {
        return 1;
      }
    }
  }
  return 0;
}

