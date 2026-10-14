void __fastcall vb_merge_entry_zero_stores(c2_function *fn)

{
  uint8_t uVar1;
  ushort uVar2;
  c2_symbol *pcVar3;
  c2_tuple *t;
  uint uVar4;
  int iVar5;
  int stosd_bytes;
  c2_operand *pcVar6;
  c2_const_operand *pcVar7;
  c2_tuple *pcVar8;
  c2_operand *pcVar9;
  c2_operand *pcVar10;
  c2_operand *pcVar11;
  int32_t high_offset;
  int32_t ndwords;
  c2_tuple *pcVar12;
  code *insert_fn_00;
  c2_tuple *anchor;
  c2_operand *index;
  int zero_store_bytes;
  int32_t low_offset;
  uint32_t record_floor;
  c2_insert_fn *insert_fn;
  
  high_offset = 0;
  if ((((g_opt_favor_speed == 0) && ((fn->flags & 0x10) == 0)) &&
      (uVar4 = fn->fsym->attrs & 0x1c, uVar4 != 4)) &&
     ((uVar4 != 0x14 && (pcVar8 = fn->cfg->first->head, pcVar8 != (c2_tuple *)0x0)))) {
    while ((pcVar8->flags & 1) == 0) {
      pcVar8 = pcVar8->next;
      if (pcVar8 == (c2_tuple *)0x0) {
        return;
      }
    }
    if (pcVar8 != (c2_tuple *)0x0) {
      uVar2 = pcVar8->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      anchor = pcVar8->prev;
      if (g_frame_eh_record == (c2_fe_symbol *)0x0) {
        record_floor = 0;
      }
      else {
        record_floor = -g_frame_eh_record->size;
      }
      zero_store_bytes = 0;
      low_offset = 0;
      pcVar12 = pcVar8;
      if (pcVar8->kind == '\f') {
        do {
          pcVar6 = pcVar12->src;
          for (pcVar9 = pcVar6; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
            if ((pcVar9->kind == '\x02') || (pcVar9->kind == '\x06')) goto LAB_1077b994;
          }
          pcVar9 = pcVar12->dst;
          for (pcVar10 = pcVar9; pcVar10 != (c2_operand *)0x0; pcVar10 = pcVar10->next) {
            if ((pcVar10->kind == '\x06') ||
               ((pcVar10->kind == '\x02' && (pcVar10->sym->cls != '\x04')))) goto LAB_1077b994;
          }
          if ((pcVar12->op == 1) && (pcVar9->kind == '\x02')) {
            pcVar3 = pcVar9->sym->storage;
            if (((uint)pcVar3->fe->offset < record_floor) &&
               (((uVar1 = pcVar6->kind, uVar1 == '\a' && ((pcVar6->u18).reg == (c2_symbol *)0x0)) ||
                ((uVar1 == '\x01' &&
                 (((pcVar6->sym->cls == '\r' &&
                   (pcVar6 = (pcVar6->sym->u28).const_operand, pcVar6->kind == '\a')) &&
                  ((pcVar6->u18).reg == (c2_symbol *)0x0)))))))) {
              if (uVar1 == '\x01') {
                zero_store_bytes = zero_store_bytes + 3;
              }
              else {
                zero_store_bytes = zero_store_bytes + 4;
              }
              if ((pcVar12->type & 0xfff) == 2) {
                zero_store_bytes = zero_store_bytes + 1;
              }
              iVar5 = pcVar3->fe->offset;
              if (pcVar9->sym->offset + iVar5 < -0x80) {
                zero_store_bytes = zero_store_bytes + 3;
              }
              if (low_offset == 0) {
                high_offset = pcVar3->size + iVar5;
                low_offset = iVar5;
              }
              else {
                if (iVar5 < low_offset) {
                  low_offset = iVar5;
                }
                uVar4 = iVar5 + pcVar3->size;
                if (high_offset < (int)uVar4) {
                  high_offset = uVar4;
                }
              }
            }
          }
          pcVar12 = pcVar12->next;
        } while (pcVar12->kind == '\f');
LAB_1077b994:
        if (low_offset != 0) {
          uVar4 = low_offset & 0xfffffffc;
          if (high_offset != (high_offset & 0xfffffffcU)) {
            high_offset = (high_offset & 0xfffffffcU) + 4;
          }
          iVar5 = (high_offset - uVar4) + ((int)(high_offset - uVar4) >> 0x1f & 3U);
          stosd_bytes = 10;
          ndwords = iVar5 >> 2;
          if (0x7f < ndwords) {
            stosd_bytes = 0xd;
          }
          if ((int)uVar4 < -0x80) {
            stosd_bytes = stosd_bytes + 3;
          }
          if (stosd_bytes < zero_store_bytes) {
            while (t = pcVar8, t != pcVar12) {
              pcVar8 = t->next;
              if (((t->op == 1) && (t->dst->kind == '\x02')) &&
                 ((uint)t->dst->sym->storage->fe->offset < record_floor)) {
                pcVar6 = t->src;
                if (((pcVar6->kind == '\a') && ((pcVar6->u18).reg == (c2_symbol *)0x0)) ||
                   ((pcVar6->kind == '\x01' &&
                    (((pcVar6->sym->cls == '\r' &&
                      (pcVar6 = (pcVar6->sym->u28).const_operand, pcVar6->kind == '\a')) &&
                     ((pcVar6->u18).reg == (c2_symbol *)0x0)))))) {
                  tuple_unlink_free(t);
                }
              }
            }
            pcVar6 = operand_new_temp(0x1004);
            insert_fn = tuple_insert_after;
            g_reg_symbols[1].flags5 = g_reg_symbols[1].flags5 | 0x10;
            (pcVar6->u18).reg = g_reg_symbols + 1;
            pcVar7 = operand_new_intconst(0x1004,0,0);
            pcVar8 = tuple_new(1,0x1004,pcVar6,pcVar7,insert_fn,anchor);
            pcVar9 = operand_new_temp(0x1004);
            g_reg_symbols[2].flags5 = g_reg_symbols[2].flags5 | 0x10;
            insert_fn = tuple_insert_after;
            (pcVar9->u18).reg = g_reg_symbols + 2;
            pcVar7 = operand_new_intconst(0x1004,ndwords,iVar5 >> 0x1f);
            pcVar8 = tuple_new(1,0x1004,pcVar9,pcVar7,insert_fn,pcVar8);
            pcVar10 = operand_new_temp(0x1004);
            g_reg_symbols[8].flags5 = g_reg_symbols[8].flags5 | 0x10;
            index = (c2_operand *)0x0;
            (pcVar10->u18).reg = g_reg_symbols + 8;
            pcVar11 = operand_new_hardreg(6,0x1004);
            pcVar11 = operand_new_addr(0x14c,0x1004,(c2_symbol *)0x0,uVar4,pcVar11,index);
            pcVar8 = tuple_new(0x12,0x1004,pcVar10,pcVar11,tuple_insert_after,pcVar8);
            insert_fn_00 = tuple_insert_after;
            pcVar11 = operand_new_hardreg(2,0x1004);
            pcVar8 = tuple_new_binary(0x111,0x1004,pcVar11,pcVar6,pcVar9,insert_fn_00,pcVar8);
            tuple_append_src(pcVar8,pcVar10);
            pcVar6 = operand_new_hardreg(8,0x1004);
            tuple_append_dst(pcVar8,pcVar6);
          }
        }
      }
    }
  }
  return;
}

