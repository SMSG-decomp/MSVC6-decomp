uint32_t __fastcall lower_switch_to_jump_table(c2_tuple *anchor,c2_function *fn)

{
  c2_tuple **ppcVar1;
  uint8_t uVar2;
  byte bVar3;
  ushort uVar4;
  short sVar5;
  c2_tuple *pos;
  uint uVar6;
  int iVar7;
  c2_fe_symbol *pcVar8;
  c2_tuple *pcVar9;
  c2_operand *pcVar10;
  c2_symbol *pcVar11;
  c2_tuple *pcVar12;
  c2_tuple *pcVar13;
  c2_switch_case *pcVar14;
  c2_const_operand *pcVar15;
  uint16_t type;
  ushort uVar16;
  int iVar17;
  c2_switch_case *pcVar18;
  int iVar19;
  bool bVar20;
  c2_operand *pcVar21;
  int32_t iVar22;
  c2_operand *pcVar23;
  uint32_t uVar24;
  c2_tuple *cond_def;
  code *pcVar25;
  c2_insert_fn *insert_fn;
  
  pcVar14 = (anchor->u24).cases;
  while (pcVar14 != (c2_switch_case *)0x0) {
    ppcVar1 = &pcVar14->label;
    pcVar14 = pcVar14->next;
    pcVar10 = (*ppcVar1)->src;
    *(uint *)((int)&pcVar10[1].rank + 2) = *(uint *)((int)&pcVar10[1].rank + 2) | 1;
  }
  pos = fn->cfg->last->end;
  uVar2 = pos->kind;
  while (uVar2 != '\x18') {
    pos = pos->prev;
    uVar2 = pos->kind;
  }
  iVar7 = switch_use_byte_index_table((c2_node *)anchor);
  if (iVar7 == 0) {
    pcVar8 = label_symbol_new();
    pcVar9 = tuple_new_label(pcVar8);
    pcVar10 = anchor->src;
    pcVar25 = tuple_insert_before;
    pcVar8 = (c2_fe_symbol *)pcVar9->src;
    pcVar12 = (c2_tuple *)0x0;
    pcVar23 = (c2_operand *)0x0;
    uVar24 = 2;
    pcVar21 = (c2_operand *)0x0;
    iVar22 = 0;
    pcVar8->role = '\x02';
    pcVar13 = anchor;
    pcVar11 = fe_symbol_get_storage(pcVar8);
    pcVar10 = operand_new_mem(0x14f,0x1004,pcVar11,iVar22,pcVar21,pcVar10,uVar24);
    pcVar13 = tuple_new_branch(0x10,'\0',(c2_node *)pcVar10,pcVar23,pcVar12,pcVar25,pcVar13);
    iVar7 = log2_floor(4);
    bVar3 = pcVar13->src->flags;
    pcVar13->src->flags = (bVar3 ^ (byte)iVar7) & 0xf ^ bVar3;
    tuple_insert_before(pos,pcVar9);
    uVar16 = pos->line;
    if (uVar16 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar16;
      g_cur_line = uVar16;
    }
    iVar7 = 0;
    for (pcVar14 = (anchor->u24).cases; pcVar14 != (c2_switch_case *)0x0; pcVar14 = pcVar14->next) {
      if (iVar7 < pcVar14->lo) {
        uVar6 = anchor->switch_flags;
        iVar17 = pcVar14->lo - iVar7;
        iVar7 = iVar7 + iVar17;
        do {
          if ((uVar6 & 2) == 0) {
            pcVar10 = operand_new_labelref((anchor->u20).default_label,1);
          }
          else {
            pcVar10 = operand_new_intconst(0x1004,0,0);
          }
          tuple_new_src_only(0xbb,0x1004,pcVar10,tuple_insert_before,pos);
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      iVar17 = pcVar14->hi;
      if (iVar7 <= iVar17) {
        pcVar13 = pcVar14->label;
        iVar19 = iVar7;
        do {
          pcVar10 = operand_new_labelref(pcVar13,1);
          tuple_new_src_only(0xbb,0x1004,pcVar10,tuple_insert_before,pos);
          iVar7 = iVar19 + 1;
          if (iVar19 == iVar17) break;
          iVar19 = iVar7;
        } while (iVar7 <= iVar17);
      }
    }
  }
  else {
    pcVar13 = anchor->prev;
    if (((((pcVar13->op == 1) && (pcVar13->dst->kind == '\x01')) &&
         (pcVar10 = anchor->src, (pcVar13->dst->u18).reg == (pcVar10->u18).reg)) &&
        (pcVar21 = pcVar13->src, pcVar21->kind == '\x01')) &&
       ((g_opt_favor_speed == 0 ||
        (((pcVar21->u18).reg)->storage != ((pcVar10->next->u18).reg)->storage)))) {
      pcVar21 = (c2_operand *)node_clone((c2_node *)pcVar21);
      tuple_unlink_free(anchor->prev);
    }
    else {
      pcVar21 = anchor->src;
      pcVar10 = pcVar21;
    }
    pcVar8 = label_symbol_new();
    pcVar9 = tuple_new_label(pcVar8);
    pcVar8 = (c2_fe_symbol *)pcVar9->src;
    bVar20 = g_opt_favor_speed == 0;
    pcVar8->role = '\x02';
    pcVar13 = anchor;
    if (bVar20) {
      pcVar25 = tuple_insert_before;
      uVar24 = 2;
      pcVar23 = (c2_operand *)0x0;
      iVar22 = 0;
      pcVar11 = fe_symbol_get_storage(pcVar8);
      pcVar23 = operand_new_mem(0x14c,0x1001,pcVar11,iVar22,pcVar21,pcVar23,uVar24);
      type = 0x1004;
      uVar24 = 0xc2;
      pcVar21 = pcVar10;
      insert_fn = pcVar25;
    }
    else {
      pcVar11 = ((pcVar10->next->u18).reg)->storage;
      pcVar10 = operand_new_reg(0x149,0x1004,pcVar11,pcVar11);
      tuple_new_binary(0x34,0x1004,pcVar10,pcVar10,pcVar10,tuple_insert_before,anchor);
      insert_fn = tuple_insert_before;
      uVar24 = 2;
      pcVar23 = (c2_operand *)0x0;
      iVar22 = 0;
      pcVar11 = fe_symbol_get_storage((c2_fe_symbol *)pcVar9->src);
      pcVar23 = operand_new_mem(0x14c,0x1001,pcVar11,iVar22,pcVar21,pcVar23,uVar24);
      type = 0x1001;
      uVar24 = 1;
      pcVar21 = anchor->src->next;
    }
    tuple_new(uVar24,type,pcVar21,pcVar23,insert_fn,pcVar13);
    pcVar8 = label_symbol_new();
    pcVar12 = tuple_new_label(pcVar8);
    insert_fn = tuple_insert_before;
    pcVar8 = (c2_fe_symbol *)pcVar12->src;
    cond_def = (c2_tuple *)0x0;
    pcVar23 = (c2_operand *)0x0;
    uVar24 = 2;
    pcVar21 = (c2_operand *)0x0;
    iVar22 = 0;
    pcVar8->role = '\x02';
    pcVar13 = anchor;
    pcVar11 = fe_symbol_get_storage(pcVar8);
    pcVar10 = operand_new_mem(0x14f,0x1004,pcVar11,iVar22,pcVar21,pcVar10,uVar24);
    pcVar13 = tuple_new_branch(0x10,'\0',(c2_node *)pcVar10,pcVar23,cond_def,insert_fn,pcVar13);
    iVar7 = log2_floor(4);
    bVar3 = pcVar13->src->flags;
    pcVar13->src->flags = (bVar3 ^ (byte)iVar7) & 0xf ^ bVar3;
    tuple_insert_before(pos,pcVar12);
    pcVar14 = (anchor->u24).cases;
    pcVar18 = pcVar14;
    while (pcVar18 != (c2_switch_case *)0x0) {
      pcVar13 = pcVar18->label;
      pcVar18 = pcVar18->next;
      pcVar13->flags12 = '\0';
      pcVar13->flags13 = '\0';
    }
    uVar16 = 0;
    for (pcVar18 = pcVar14; pcVar18 != (c2_switch_case *)0x0; pcVar18 = pcVar18->next) {
      pcVar13 = pcVar18->label;
      sVar5._0_1_ = pcVar13->flags12;
      sVar5._1_1_ = pcVar13->flags13;
      if (sVar5 == 0) {
        uVar16 = uVar16 + 1;
        *(ushort *)&pcVar13->flags12 = -uVar16;
      }
    }
    uVar4 = pos->line;
    if (uVar4 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar4;
      g_cur_line = uVar4;
    }
    bVar20 = true;
    pcVar18 = pcVar14;
    if (pcVar14 != (c2_switch_case *)0x0) {
      do {
        pcVar13 = pcVar18->label;
        if (*(short *)&pcVar13->flags12 < 0) {
          *(short *)&pcVar13->flags12 = -1 - *(short *)&pcVar13->flags12;
          pcVar10 = operand_new_labelref(pcVar13,1);
          tuple_new_src_only(0xbb,0x1004,pcVar10,tuple_insert_before,pos);
        }
        if (((bVar20) && (pcVar18->next != (c2_switch_case *)0x0)) &&
           (pcVar18->hi != pcVar18->next->lo + -1)) {
          bVar20 = false;
        }
        pcVar18 = pcVar18->next;
      } while (pcVar18 != (c2_switch_case *)0x0);
      if (!bVar20) {
        if ((anchor->switch_flags & 2) == 0) {
          pcVar10 = operand_new_labelref((anchor->u20).default_label,1);
        }
        else {
          pcVar10 = operand_new_intconst(0x1004,0,0);
        }
        tuple_new_src_only(0xbb,0x1004,pcVar10,tuple_insert_before,pos);
      }
    }
    tuple_insert_before(pos,pcVar9);
    iVar7 = 0;
    if (pcVar14 != (c2_switch_case *)0x0) {
      do {
        if (iVar7 < pcVar14->lo) {
          iVar17 = pcVar14->lo - iVar7;
          iVar7 = iVar7 + iVar17;
          do {
            insert_fn = tuple_insert_before;
            pcVar13 = pos;
            pcVar15 = operand_new_intconst(0x1001,(uint)uVar16,0);
            tuple_new_src_only(0xbb,0x1001,pcVar15,insert_fn,pcVar13);
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
        }
        iVar17 = pcVar14->hi;
        if (iVar7 <= iVar17) {
          uVar4._0_1_ = pcVar14->label->flags12;
          uVar4._1_1_ = pcVar14->label->flags13;
          iVar19 = iVar7;
          do {
            insert_fn = tuple_insert_before;
            pcVar13 = pos;
            pcVar15 = operand_new_intconst(0x1001,(uint)uVar4,0);
            tuple_new_src_only(0xbb,0x1001,pcVar15,insert_fn,pcVar13);
            iVar7 = iVar19 + 1;
            if (iVar19 == iVar17) break;
            iVar19 = iVar7;
          } while (iVar7 <= iVar17);
        }
        pcVar14 = pcVar14->next;
        if (pcVar14 == (c2_switch_case *)0x0) {
          uVar24 = switch_free(anchor);
          return uVar24;
        }
      } while( true );
    }
  }
  uVar24 = switch_free(anchor);
  return uVar24;
}

