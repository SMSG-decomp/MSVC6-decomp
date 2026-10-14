void __fastcall split_insert_spill_stores(c2_function *fn,c2_ra_split_block *blocks)

{
  ushort uVar1;
  c2_block *b;
  uint mask;
  c2_loop *piece;
  c2_tuple *pcVar2;
  c2_symbol *storage;
  c2_register_descriptor *pcVar3;
  byte bVar4;
  c2_operand *pcVar5;
  int iVar6;
  c2_live_range *pcVar7;
  c2_tuple *anchor;
  uint uVar8;
  uint local_24;
  c2_bitset *local_20;
  c2_bitset *local_1c;
  
  do {
    if (blocks == (c2_ra_split_block *)0x0) {
      return;
    }
    b = blocks->block;
    local_20 = b->set28;
    local_1c = b->set50;
    local_24 = ~(uint)local_20;
    anchor = b->end;
    if (b->end != b->head) {
      do {
        pcVar2 = anchor->prev;
        if ((anchor->flags & 1) == 0) {
          if (anchor->kind == '\x1b') {
            pcVar5 = anchor->dst;
            local_20 = (c2_bitset *)((uint)local_20 & ~(uint)pcVar5);
            local_24 = local_24 | (uint)pcVar5;
            local_1c = (c2_bitset *)((uint)local_1c | (uint)pcVar5);
          }
        }
        else {
          for (pcVar5 = anchor->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            if (((pcVar5->kind == '\x01') && (storage = (pcVar5->u18).reg, storage->cls == '\x02'))
               && ((storage->flags5 & 2) != 0)) {
              mask._0_2_ = storage->type;
              mask._2_2_ = storage->x12;
              if (((pcVar5->rank != 0) && ((storage->flags5 & 0x10) == 0)) &&
                 (((uint)local_1c & mask) != 0)) {
                uVar1 = anchor->line;
                pcVar5->rank = 0;
                if (uVar1 != 0) {
                  g_current_line_abs = fn->line_base + (uint)uVar1;
                  g_cur_line = uVar1;
                }
                iVar6 = insert_live_range_spill_store(pcVar5->sym,storage,anchor);
                iVar6 = *(int *)(iVar6 + 0x18);
                if ((local_24 & mask) == 0) {
                  bVar4 = *(byte *)(iVar6 + 0x11) | 0x40;
                }
                else {
                  bVar4 = *(byte *)(iVar6 + 0x11) & 0xbf;
                }
                *(byte *)(iVar6 + 0x11) = bVar4;
                if (((uint)local_20 & mask) == 0) {
                  bVar4 = bVar4 | 0x10;
                }
                else {
                  bVar4 = bVar4 & 0xef;
                }
                *(byte *)(iVar6 + 0x11) = bVar4;
              }
              uVar8 = ~mask;
              local_1c = (c2_bitset *)((uint)local_1c & uVar8);
              piece = b->loop;
              if ((piece != (c2_loop *)0x0) &&
                 (iVar6 = split_piece_regs_all_in(piece,mask), iVar6 == 0)) {
                split_mark_symbol_in_chain(piece,pcVar5->sym);
              }
              if ((pcVar5->flags & 0xf) == 0) {
                if (((uint)local_20 & mask) == 0) {
                  if (anchor->op == 0x163) {
                    local_24 = local_24 | mask;
                    tuple_unlink_free(anchor);
                    goto LAB_1072479c;
                  }
                  if (((pcVar5->rank == 0) && ((pcVar5->type & 0xf000) != 0x4000)) &&
                     (((pcVar5->sym->type ^ pcVar5->type) & 0xfff) == 0)) {
                    local_24 = local_24 | mask;
                    if ((pcVar5->flags11 & 0x80) != 0) {
                      add_reference_saving(anchor,(c2_live_range *)storage,b);
                    }
                    uVar1 = anchor->line;
                    if (uVar1 != 0) {
                      g_current_line_abs = fn->line_base + (uint)uVar1;
                      g_cur_line = uVar1;
                    }
                    pcVar5 = split_reload_spilled_def(anchor,pcVar5);
                    goto LAB_107247e0;
                  }
                }
                else {
                  local_20 = (c2_bitset *)((uint)local_20 & uVar8);
                }
                if ((mask & local_24) == 0) {
                  local_24 = local_24 | mask;
                  bVar4 = pcVar5->flags11 | 0x40;
                }
                else {
                  bVar4 = pcVar5->flags11 & 0xbf;
                }
                pcVar5->flags11 = bVar4;
              }
              else if ((local_24 & mask) == 0) {
                pcVar5->flags11 = pcVar5->flags11 | 0x40;
                local_20 = (c2_bitset *)((uint)local_20 & uVar8);
              }
              else {
                pcVar5->flags11 = pcVar5->flags11 & 0xbf;
                local_20 = (c2_bitset *)((uint)local_20 & uVar8);
              }
            }
LAB_107247e0:
          }
          for (pcVar5 = anchor->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
            if (pcVar5->kind == '\x01') {
              pcVar7 = (pcVar5->u18).range;
              if ((pcVar7->kind == '\x02') && ((pcVar7->flags5 & 2) != 0)) {
                pcVar3 = pcVar7->colour;
                if ((local_24 & (uint)pcVar3) == 0) {
                  bVar4 = pcVar5->flags11 | 0x40;
                }
                else {
                  bVar4 = pcVar5->flags11 & 0xbf;
                }
                pcVar5->flags11 = bVar4;
                if ((bVar4 & 0x10) != 0) {
                  local_1c = (c2_bitset *)((uint)local_1c & ~(uint)pcVar3);
                }
                if ((((uint)local_20 & (uint)pcVar3) == 0) &&
                   (iVar6 = operand_list_has_same_reg(pcVar5), iVar6 == 0)) {
                  local_20 = (c2_bitset *)((uint)local_20 | (uint)pcVar3);
                  pcVar5->flags11 = pcVar5->flags11 | 0x10;
                }
                else {
                  pcVar5->flags11 = pcVar5->flags11 & 0xef;
                }
              }
            }
            else if ((pcVar5->kind == '\x02') && (pcVar5->rank != 0)) {
              pcVar7 = live_range_from_id(pcVar5->rank);
              pcVar3 = pcVar7->colour;
              if (pcVar3 != (c2_register_descriptor *)0x0) {
                pcVar5->rank = 0;
                local_1c = (c2_bitset *)((uint)local_1c | (uint)pcVar3);
              }
            }
          }
        }
LAB_1072479c:
        anchor = pcVar2;
      } while (pcVar2 != b->head);
    }
    blocks = blocks->next;
  } while( true );
}

