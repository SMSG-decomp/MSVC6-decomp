c2_symbol * __fastcall split_local_temp_at_pressure_point(c2_function *fn,int reg_class,c2_tuple *t)

{
  uint8_t uVar1;
  byte bVar2;
  uint16_t type;
  ushort uVar3;
  ushort type_00;
  c2_symbol *sym;
  c2_symbol *pcVar4;
  c2_bitset *bs;
  uint32_t uVar5;
  c2_operand *pcVar6;
  c2_tuple *pcVar7;
  c2_tuple *pcVar8;
  c2_symbol *pcVar9;
  c2_symbol *pcVar10;
  ushort type_01;
  c2_operand *pcVar11;
  c2_operand *local_10;
  c2_tuple *local_8;
  
  local_8 = (c2_tuple *)0x0;
  local_10 = (c2_operand *)0x0;
  bs = bitset_new(6);
  for (pcVar11 = t->src; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
    if ((pcVar11->kind == '\x01') && (((pcVar11->u18).reg)->cls == '\x03')) {
      bitset_set(bs,((pcVar11->u18).reg)->id);
    }
  }
  pcVar8 = t->prev;
  pcVar11 = (c2_operand *)0x0;
  uVar1 = pcVar8->kind;
  while (uVar1 != '\x19') {
    if ((pcVar8->flags & 1) != 0) {
      for (pcVar11 = pcVar8->dst; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
        if ((((pcVar11->kind == '\x01') && (((pcVar11->u18).reg)->cls == '\x03')) &&
            (g_type_class[pcVar11->type >> 0xc] == reg_class)) &&
           (uVar5 = bitset_test(bs,((pcVar11->u18).reg)->id), uVar5 == 0)) {
          local_10 = pcVar11;
          local_8 = pcVar8;
        }
      }
      for (pcVar11 = pcVar8->src; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
        if ((pcVar11->kind == '\x01') && (((pcVar11->u18).reg)->cls == '\x03')) {
          bitset_set(bs,((pcVar11->u18).reg)->id);
        }
      }
    }
    pcVar8 = pcVar8->prev;
    uVar1 = pcVar8->kind;
  }
  bitset_free(bs);
  sym = (local_10->u18).reg;
  for (pcVar8 = t->next; pcVar8 != (c2_tuple *)0x0; pcVar8 = pcVar8->next) {
    if ((pcVar8->flags & 1) != 0) {
      for (pcVar11 = pcVar8->src; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
        if ((pcVar11->kind == '\x01') && ((pcVar11->u18).reg == sym)) goto LAB_1078e916;
      }
    }
  }
LAB_1078e916:
  type = local_10->type;
  pcVar6 = operand_new_temp_sym(type);
  uVar3 = local_8->line;
  if (uVar3 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar3;
    g_cur_line = uVar3;
  }
  pcVar7 = tuple_new(1,type,pcVar6,local_10,tuple_insert_after,local_8);
  pcVar7->src->flags11 = pcVar7->src->flags11 | 0x10;
  uVar3 = pcVar8->line;
  if (uVar3 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar3;
    g_cur_line = uVar3;
  }
  pcVar8 = tuple_new_unary_temp(1,type,pcVar6,tuple_insert_before,pcVar8);
  pcVar6 = pcVar8->dst;
  bVar2 = sym->flags5;
  pcVar8 = pcVar8->next;
  pcVar6->flags11 = pcVar6->flags11 | 0x10;
  pcVar4 = pcVar6->sym;
  pcVar11->sym = pcVar4;
  pcVar4->flags5 = (pcVar4->flags5 ^ bVar2) & 0x7f ^ bVar2;
  do {
    if (pcVar8 == (c2_tuple *)0x0) {
      return sym;
    }
    if ((pcVar8->flags & 1) != 0) {
      for (pcVar11 = pcVar8->src; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
        if ((pcVar11->kind == '\x01') && ((pcVar11->u18).reg == sym)) {
          pcVar9 = pcVar11->sym;
          if (pcVar9->storage == sym->storage) {
            if (pcVar9 != sym) {
              if ((sym->size + sym->offset <= pcVar9->offset) ||
                 (pcVar9->size + pcVar9->offset <= sym->offset)) goto LAB_1078eacb;
            }
            pcVar6 = find_dst_symbol_ref(sym->def,sym);
            uVar3 = pcVar6->type;
            type_00 = pcVar11->type;
            type_01 = uVar3;
            if ((uVar3 & 0xfff) <= (type_00 & 0xfff)) {
              type_01 = type_00;
            }
            pcVar9 = symbol_new_temp(type_01);
            pcVar10 = symbol_get_part(pcVar9,type_00,type_00 & 0xfff,0);
            pcVar11->sym = pcVar10;
            pcVar10 = symbol_get_part(pcVar9,uVar3,uVar3 & 0xfff,0);
            pcVar6->sym = pcVar10;
            if (pcVar9->storage->part_next == (c2_symbol *)0x0) {
              pcVar9->def = sym->def;
            }
            else {
              symbol_mark_overlapping_parts(pcVar9,sym->def);
            }
          }
LAB_1078eacb:
          (pcVar11->u18).reg = pcVar4;
          if ((pcVar11->flags11 & 0x10) != 0) {
            return sym;
          }
        }
      }
      for (pcVar11 = pcVar8->dst; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
        if ((pcVar11->kind == '\x01') && ((pcVar11->u18).reg == sym)) {
          (pcVar11->u18).reg = pcVar4;
        }
      }
    }
    pcVar8 = pcVar8->next;
  } while( true );
}

