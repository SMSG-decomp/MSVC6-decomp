void __fastcall insert_fdiv_bug_check(c2_tuple *fdiv,c2_function *fn)

{
  c2_tuple *anchor;
  uint32_t uVar1;
  c2_register_descriptor *pcVar2;
  bool bVar3;
  c2_fe_symbol *pcVar4;
  c2_tuple *pcVar5;
  c2_tuple *t;
  c2_tuple *pcVar6;
  c2_const_operand *pcVar7;
  c2_symbol *pcVar8;
  c2_operand *pcVar9;
  c2_operand *pcVar10;
  int iVar11;
  c2_operand *src;
  uint lo;
  char *name;
  ushort uVar12;
  bool bVar13;
  code *pcVar14;
  c2_insert_fn *insert_fn;
  
  bVar3 = false;
  uVar12 = fdiv->line;
  if (uVar12 != 0) {
    g_current_line_abs = fn->line_base + (uint)uVar12;
    g_cur_line = uVar12;
  }
  anchor = fdiv->next;
  pcVar4 = label_symbol_new();
  pcVar5 = tuple_new_label(pcVar4);
  pcVar4 = label_symbol_new();
  t = tuple_new_label(pcVar4);
  pcVar6 = find_next_reg_writer(fdiv);
  bVar13 = pcVar6 != (c2_tuple *)0x0;
  if (bVar13) {
    tuple_new_nooperands(0xad,0x1004,tuple_insert_before,fdiv);
  }
  insert_fn = tuple_insert_before;
  pcVar6 = fdiv;
  pcVar7 = operand_new_intconst(0x1004,0,0);
  pcVar4 = extern_symbol_lookup_or_create((uint8_t *)"__adjust_fdiv");
  pcVar8 = fe_symbol_get_storage(pcVar4);
  pcVar9 = operand_new_sym(0x14b,0x1004,pcVar8);
  pcVar10 = operand_new_reg(0x149,0x8000,g_reg_symbols + 0x42,g_reg_symbols + 0x42);
  tuple_new_binary(0x2f,0x1004,pcVar10,pcVar9,pcVar7,insert_fn,pcVar6);
  tuple_new_branch(0xf,'\x05',(c2_node *)pcVar5,(c2_operand *)0x0,(c2_tuple *)0x0,
                   tuple_insert_before,fdiv);
  tuple_new_branch(0x10,'\0',(c2_node *)t,(c2_operand *)0x0,(c2_tuple *)0x0,tuple_insert_before,
                   anchor);
  tuple_insert_before(anchor,pcVar5);
  uVar1 = fdiv->op;
  switch(*(undefined1 *)(uVar1 + 0x1077c297)) {
  case 0:
    pcVar9 = fdiv->src;
    pcVar10 = pcVar9->next;
    if (pcVar10->kind == '\x01') {
      insert_fn = tuple_insert_before;
      name = "__adj_fdiv_r";
      bVar3 = true;
      pcVar5 = anchor;
      src = operand_new_reg(0x149,0x1004,g_reg_symbols + 1,g_reg_symbols + 1);
      tuple_new_src_only(0xd,0x1004,src,insert_fn,pcVar5);
      pcVar2 = (pcVar9->u18).reg;
      if (pcVar2 == g_reg_symbols + 0x1f) {
        lo = ((pcVar10->u18).reg)->id * 8 - 0xf8;
      }
      else {
        lo = pcVar2->id * 8 - 0xf8 | 4;
      }
      if ((uVar1 == 0x4f) || (uVar1 == 0x50)) {
        lo = lo | 1;
      }
      if ((uVar1 == 0x4a) || (uVar1 == 0x50)) {
        lo = lo | 2;
      }
      insert_fn = tuple_insert_before;
      pcVar5 = anchor;
      pcVar7 = operand_new_intconst(0x1001,lo,(int)lo >> 0x1f);
      pcVar9 = operand_new_reg(0x149,0x1001,g_reg_symbols + 0x11,g_reg_symbols + 0x11);
      tuple_new(1,0x1001,pcVar9,pcVar7,insert_fn,pcVar5);
    }
    else {
      if (bVar13) {
        iVar11 = operand_needs_esp_adjust(pcVar10);
        if (iVar11 != 0) {
          pcVar10->rank = pcVar10->rank - 4;
        }
      }
      switch((&insert_fdiv_bug_check_memop_index_base)[uVar1]) {
      case 0:
        uVar12 = fdiv->type;
        if ((uVar12 & 0xfff) == 4) {
          name = "__adj_fdiv_m32";
        }
        else {
          name = "__adj_fdiv_m64";
        }
        break;
      case 1:
        uVar12 = fdiv->type;
        if ((uVar12 & 0xfff) == 4) {
          name = "__adj_fdivr_m32";
        }
        else {
          name = "__adj_fdivr_m64";
        }
        break;
      case 2:
        uVar12 = fdiv->type;
        if ((uVar12 & 0xfff) == 2) {
          name = "__adj_fdiv_m16i";
        }
        else {
          name = "__adj_fdiv_m32i";
        }
        break;
      case 3:
        uVar12 = fdiv->type;
        name = "__adj_fdivr_m16i";
        if ((uVar12 & 0xfff) != 2) {
          name = "__adj_fdivr_m32i";
        }
      }
      if ((uVar12 & 0xfff) == 2) {
        pcVar14 = tuple_insert_before;
        bVar3 = true;
        pcVar5 = anchor;
        pcVar9 = operand_new_reg(0x149,0x1004,g_reg_symbols + 1,g_reg_symbols + 1);
        tuple_new_src_only(0xd,0x1004,pcVar9,pcVar14,pcVar5);
        pcVar9 = (c2_operand *)node_clone((c2_node *)pcVar10);
        iVar11 = operand_needs_esp_adjust(pcVar10);
        if (iVar11 != 0) {
          pcVar9->rank = pcVar9->rank - 4;
        }
        pcVar14 = tuple_insert_before;
        pcVar5 = anchor;
        pcVar10 = operand_new_reg(0x149,0x1002,g_reg_symbols + 9,g_reg_symbols + 9);
        tuple_new(1,0x1002,pcVar10,pcVar9,pcVar14,pcVar5);
        pcVar14 = tuple_insert_before;
        pcVar5 = anchor;
        pcVar9 = operand_new_reg(0x149,0x1004,g_reg_symbols + 1,g_reg_symbols + 1);
        tuple_new_src_only(0xd,0x1004,pcVar9,pcVar14,pcVar5);
      }
      else if ((uVar12 & 0xfff) == 4) {
        tuple_new_src_only(0xd,0x1004,pcVar10,tuple_insert_before,anchor);
      }
      else {
        if (pcVar10->kind == '\x02') {
          pcVar8 = symbol_get_part(pcVar10->sym,0x1004,4,4);
          pcVar9 = operand_new_sym(pcVar10->op,0x1004,pcVar8);
        }
        else {
          pcVar9 = operand_new_mem(pcVar10->op,0x1004,pcVar10->base_sym,pcVar10->disp + 4,
                                   pcVar10->base,pcVar10->index,pcVar10->tag);
          pcVar9->flags = (pcVar10->flags ^ pcVar9->flags) & 0xf ^ pcVar9->flags;
        }
        pcVar9->rank = pcVar10->rank;
        tuple_new_src_only(0xd,0x1004,pcVar9,tuple_insert_before,anchor);
        if (pcVar10->kind == '\x02') {
          pcVar8 = symbol_get_part(pcVar10->sym,0x1004,4,0);
          pcVar9 = operand_new_sym(pcVar10->op,0x1004,pcVar8);
        }
        else {
          pcVar9 = operand_new_mem(pcVar10->op,0x1004,pcVar10->base_sym,pcVar10->disp,pcVar10->base,
                                   pcVar10->index,pcVar10->tag);
          pcVar9->flags = (pcVar10->flags ^ pcVar9->flags) & 0xf ^ pcVar9->flags;
        }
        iVar11 = operand_needs_esp_adjust(pcVar10);
        if (iVar11 != 0) {
          pcVar9->rank = pcVar10->rank - 4;
        }
        tuple_new_src_only(0xd,0x1004,pcVar9,tuple_insert_before,anchor);
      }
    }
    break;
  case 1:
    name = "__adj_fpatan";
    break;
  case 2:
    name = "__adj_fprem";
    break;
  case 3:
    name = "__adj_fptan";
    break;
  case 4:
    name = "__adj_fprem1";
  }
  pcVar4 = fe_symbol_lookup_name(name);
  pcVar9 = operand_for_symbol_ref(pcVar4);
  tuple_new_call(0xe,0x1004,(c2_operand *)0x0,pcVar9,'\x04',tuple_insert_before,anchor);
  if (bVar3) {
    insert_fn = tuple_insert_before;
    pcVar5 = anchor;
    pcVar9 = operand_new_reg(0x149,0x1004,g_reg_symbols + 5,g_reg_symbols + 5);
    pcVar10 = operand_new_reg(0x149,0x1004,g_reg_symbols + 1,g_reg_symbols + 1);
    tuple_new(0xc,0x1004,pcVar10,pcVar9,insert_fn,pcVar5);
  }
  tuple_insert_before(anchor,t);
  if (bVar13) {
    tuple_new_nooperands(0xab,0x1004,tuple_insert_before,anchor);
  }
  return;
}

