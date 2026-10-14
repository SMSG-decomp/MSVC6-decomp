void __fastcall ra_eliminate_register_copy(c2_list_cell *copies)

{
  byte bVar1;
  c2_tuple *pcVar2;
  c2_list_cell *pcVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  c2_tuple *walk;
  int iVar8;
  c2_operand *scan_opnd;
  uint32_t uVar9;
  int32_t iVar10;
  char cVar11;
  c2_symbol *pcVar12;
  c2_operand *pcVar13;
  c2_operand *pcVar14;
  byte bVar15;
  c2_symbol *temp_reg;
  c2_tuple *t;
  c2_operand *last_match;
  byte local_29;
  c2_operand *dst_opnd;
  c2_tuple *back;
  c2_operand *src_opnd;
  c2_tuple *copy;
  c2_symbol *other_reg;
  
joined_r0x10723565:
  if (copies == (c2_list_cell *)0x0) {
    return;
  }
  copy = (copies->u04).tuple;
  if (copy != (c2_tuple *)0x0) {
    pcVar13 = copy->dst;
    temp_reg = (pcVar13->u18).reg;
    if (temp_reg->cls == '\x03') {
      scan_opnd = copy->src;
      pcVar12 = scan_opnd->sym;
      bVar6 = false;
      pcVar14 = scan_opnd;
    }
    else {
      temp_reg = (copy->src->u18).reg;
      if (temp_reg->cls != '\x03') {
        (copies->u04).tuple = (c2_tuple *)0x0;
        goto LAB_10723748;
      }
      pcVar12 = pcVar13->sym;
      bVar6 = true;
      scan_opnd = pcVar13;
      pcVar14 = copy->src;
    }
    other_reg = (scan_opnd->u18).reg;
    if (((temp_reg->flags5 & 0x80) == 0) || ((other_reg->flags5 & 0x80) != 0)) {
      if ((copy->type & 0xfff) == 1) {
        if (((pcVar12->u34).lcse_values == (c2_operand *)0x0) ||
           (pcVar12->offset == ((pcVar12->u34).lcse_values)->disp)) {
          if (bVar6) {
            iVar8 = pcVar14->sym->offset;
            if ((iVar8 < 4) && (iVar8 != 0)) goto LAB_10723748;
          }
          else {
            iVar8 = pcVar13->sym->offset;
            if (iVar8 < 4) goto LAB_107235ca;
          }
LAB_107235d0:
          uVar9 = bitset_test(g_ra_offset_byte_ranges,temp_reg->id);
          if (uVar9 == 0) {
LAB_107237ec:
            walk = copy;
            if (!bVar6) {
              walk = find_next_use_of_symbol_2(copy,pcVar13->sym);
            }
LAB_1072361f:
            for (back = walk->prev; back != (c2_tuple *)0x0; back = back->prev) {
              if ((back->flags & 1) != 0) {
                for (dst_opnd = back->dst; dst_opnd != (c2_operand *)0x0; dst_opnd = dst_opnd->next)
                {
                  if ((dst_opnd->kind == '\x01') && ((dst_opnd->u18).reg == temp_reg))
                  goto LAB_10723656;
                  iVar8 = operands_may_alias(dst_opnd,scan_opnd);
                  if (iVar8 != 0) {
                    dst_opnd = (c2_operand *)0x0;
                    goto LAB_10723748;
                  }
                }
              }
            }
LAB_10723656:
            if (dst_opnd != (c2_operand *)0x0) {
              if (temp_reg->storage->part_next == (c2_symbol *)0x0) {
                temp_reg->def = (c2_tuple *)0x0;
              }
              else {
                symbol_mark_overlapping_parts(temp_reg,(c2_tuple *)0x0);
              }
              bVar4 = false;
              temp_reg->defs = (c2_list_cell *)0x0;
              temp_reg->uses = (c2_list_cell *)0x0;
              bVar7 = false;
              t = copy;
              do {
                do {
                  do {
                    if (bVar6) {
                      t = t->prev;
                    }
                    else {
                      t = t->next;
                    }
                  } while ((t->flags & 1) == 0);
                  for (src_opnd = t->src; src_opnd != (c2_operand *)0x0; src_opnd = src_opnd->next)
                  {
                    if ((src_opnd->kind == '\x01') && ((src_opnd->u18).reg == temp_reg)) {
                      src_opnd->flags = src_opnd->flags & 0xf0;
                      (src_opnd->u18).reg = other_reg;
                      if ((bVar4) || (bVar6)) {
                        src_opnd->sym = temp_reg;
                      }
                      else {
                        bVar4 = true;
                        src_opnd->sym = pcVar12;
                      }
                      if ((!bVar6) && ((src_opnd->flags11 & 0x10) != 0)) {
                        if ((scan_opnd->flags11 & 0x10) != 0) goto LAB_1072387b;
                        bVar15 = src_opnd->flags11 & 0xef;
                        pcVar2 = t->prev;
                        src_opnd->flags11 = bVar15;
                        goto joined_r0x107239c7;
                      }
                      src_opnd->flags11 = src_opnd->flags11 | 0x10;
                    }
                  }
                } while (t->dst == (c2_operand *)0x0);
                local_29 = 1;
                dst_opnd = t->dst;
                do {
                  pcVar13 = dst_opnd->next;
                  if ((dst_opnd->kind == '\x01') && ((dst_opnd->u18).reg == temp_reg)) {
                    dst_opnd->flags = dst_opnd->flags & 0xf0;
                    iVar8 = operand_is_not_first_dst(t,dst_opnd);
                    if (iVar8 == 0) {
                      (dst_opnd->u18).reg = other_reg;
                      bVar7 = true;
                      if ((bVar4) || (!bVar6)) {
                        dst_opnd->sym = temp_reg;
                        dst_opnd->rank = 1;
                        if (bVar6) goto LAB_10723735;
                      }
                      else {
                        dst_opnd->sym = pcVar12;
                        bVar5 = true;
                        uVar9 = copy->dst->rank;
                        dst_opnd->rank = uVar9;
                        bVar4 = bVar5;
                        if (bVar6) {
                          bVar4 = true;
                          if (((uVar9 == 0) &&
                              (pcVar2 = copy->next, bVar4 = bVar5, pcVar2->op == 0x164)) &&
                             (t->next != copy)) {
                            tuple_unlink(pcVar2);
                            tuple_insert_after(t,pcVar2);
                          }
LAB_10723735:
                          if ((dst_opnd->flags11 & 0x10) != 0) goto LAB_1072373f;
                        }
                      }
                      cVar11 = '\0';
                      for (pcVar14 = t->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next)
                      {
                        if ((pcVar14->kind == '\x01') && ((pcVar14->u18).reg == other_reg)) {
                          dst_opnd->flags = (cVar11 + 1U ^ dst_opnd->flags) & 0xf ^ dst_opnd->flags;
                          pcVar14->flags = (pcVar14->flags ^ local_29) & 0xf ^ pcVar14->flags;
                          break;
                        }
                        cVar11 = cVar11 + '\x01';
                      }
                    }
                    else {
                      tuple_remove_dst(t,dst_opnd);
                      if ((!bVar6) && (!bVar7)) {
                        bVar4 = false;
                      }
                      for (pcVar14 = t->src; pcVar14 != (c2_operand *)0x0; pcVar14 = pcVar14->next)
                      {
                        if ((pcVar14->kind == '\x01') && ((pcVar14->u18).reg == other_reg)) {
                          pcVar14->flags11 = pcVar14->flags11 & 0xef;
                          break;
                        }
                      }
                    }
                  }
                  local_29 = local_29 + 1;
                  dst_opnd = pcVar13;
                } while (pcVar13 != (c2_operand *)0x0);
              } while( true );
            }
          }
          else if (bVar6) {
            iVar8 = pcVar14->sym->offset;
            if ((iVar8 < 4) && (iVar8 != 0)) goto LAB_107237ec;
          }
          else {
            iVar8 = pcVar13->sym->offset;
            if ((iVar8 < 4) && (iVar8 != 0)) {
              walk = find_next_use_of_symbol_2(copy,pcVar13->sym);
              goto LAB_1072361f;
            }
          }
        }
        else {
          if (bVar6) {
            iVar10 = pcVar14->sym->offset;
          }
          else {
            iVar10 = pcVar13->sym->offset;
          }
          if (iVar10 < 4) {
            iVar8 = iVar10 + -8;
LAB_107235ca:
            if (iVar8 == 0) goto LAB_107235d0;
          }
        }
      }
      else {
        uVar9 = bitset_test(g_ra_offset_byte_ranges,temp_reg->id);
        if (uVar9 == 0) goto LAB_107237ec;
      }
    }
  }
  goto LAB_10723748;
joined_r0x107239c7:
  if (pcVar2 == copy) goto LAB_1072387b;
  if ((pcVar2->flags & 1) != 0) {
    pcVar13 = pcVar2->src;
    last_match = (c2_operand *)0x0;
    if (pcVar13 != (c2_operand *)0x0) {
      do {
        if ((pcVar13->kind == '\x01') && ((pcVar13->u18).reg == other_reg)) {
          last_match = pcVar13;
        }
        pcVar13 = pcVar13->next;
      } while (pcVar13 != (c2_operand *)0x0);
      if (last_match != (c2_operand *)0x0) {
        bVar1 = last_match->flags11;
        if ((bVar1 & 0x10) != 0) {
          pcVar3 = copies->next;
          goto joined_r0x10723a13;
        }
        goto LAB_1072387b;
      }
    }
  }
  pcVar2 = pcVar2->prev;
  goto joined_r0x107239c7;
joined_r0x10723a13:
  if (pcVar3 == (c2_list_cell *)0x0) goto LAB_10723a21;
  if ((((pcVar3->u04).tuple == pcVar2) && ((1 << (pcVar2->dst->kind & 0x1f) & 6U) != 0)) &&
     (pcVar2->dst->sym->def != (c2_tuple *)0x0)) {
    if (((uint)((pcVar2->dst->u18).reg)->uses[2].next & 0x1000) == 0) {
      (pcVar3->u04).tuple = (c2_tuple *)0x0;
    }
    goto LAB_10723a21;
  }
  pcVar3 = pcVar3->next;
  goto joined_r0x10723a13;
LAB_10723a21:
  last_match->flags11 = bVar1 & 0xef;
  src_opnd->flags11 = bVar15 | 0x10;
LAB_1072387b:
  scan_opnd = (c2_operand *)0x0;
  for (pcVar13 = t->src; dst_opnd = (c2_operand *)0x0, pcVar13 != (c2_operand *)0x0;
      pcVar13 = pcVar13->next) {
    pcVar14 = scan_opnd;
    if (((pcVar13->kind == '\x01') && ((pcVar13->u18).reg == other_reg)) &&
       ((pcVar14 = pcVar13, scan_opnd != (c2_operand *)0x0 && ((scan_opnd->flags11 & 0x10) != 0))))
    {
      scan_opnd->flags11 = scan_opnd->flags11 & 0xef;
      pcVar13->flags11 = pcVar13->flags11 | 0x10;
    }
    scan_opnd = pcVar14;
  }
LAB_1072373f:
  tuple_unlink_free(copy);
LAB_10723748:
  copies = copies->next;
  goto joined_r0x10723565;
}

