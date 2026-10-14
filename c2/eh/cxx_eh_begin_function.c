void __fastcall cxx_eh_begin_function(c2_function *fn,int mode)

{
  char cVar1;
  ushort uVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  c2_eh_op_try *pcVar5;
  c2_cxx_try_block **ppcVar6;
  c2_tuple *t;
  int iVar7;
  c2_cxx_try_block *pcVar8;
  c2_cxx_try_block *pcVar9;
  c2_symbol *pcVar10;
  c2_tuple *pcVar11;
  c2_cxx_catch *catch_rec;
  c2_cxx_try_block *pcVar12;
  int32_t iVar13;
  c2_cxx_try_block *pcVar14;
  uint uVar15;
  char *pcVar16;
  c2_eh_op *begin_op;
  
  if (mode != 0) {
    uVar15 = g_cur_function->fsym->fn_flags;
    g_cur_function->fsym->fn_flags = fn->fsym->fn_flags & 0x700 | uVar15;
    if ((uVar15 & 0x700) == 0) {
      cxx_eh_reset_function_state();
      cxx_eh_build_try_nesting(g_cur_function,0);
    }
    reset_eh_state_numbering();
    cxx_eh_build_try_nesting(fn,1);
    return;
  }
  g_eh_guard_local = (c2_symbol *)0x0;
  cxx_eh_reset_function_state();
  g_cxx_try_records = (c2_cxx_try_block *)0x0;
  pcVar14 = (c2_cxx_try_block *)0x0;
  t = fn->cfg->first->head;
  do {
    if (t == (c2_tuple *)0x0) {
      return;
    }
    uVar2 = t->line;
    pcVar11 = t->next;
    if (uVar2 != 0) {
      g_current_line_abs = fn->line_base + (uint)uVar2;
      g_cur_line = uVar2;
    }
    pcVar12 = pcVar14;
    pcVar8 = g_eh_trymap_tail;
    pcVar9 = g_eh_trymap_list;
    switch(t->kind) {
    case '\x11':
      if (((t->op == 0x186) && ((t->src->sym->u30).globopt.live == 'G')) &&
         ((fn->fsym->attrs & 0x1000) == 0)) {
        pcVar11 = seh_move_finally_block(t,(c2_tuple **)&stack0xfffffff8);
        pcVar12 = g_cxx_try_records;
        pcVar8 = g_eh_trymap_tail;
        pcVar9 = g_eh_trymap_list;
      }
      break;
    case '\x14':
      uVar4 = t->op;
      if (uVar4 == 0x1a4) {
        if ((pcVar14 != (c2_cxx_try_block *)0x0) &&
           ((pcVar14->u24).catch_tail != (c2_cxx_catch *)0x0)) {
          ((pcVar14->u24).catch_tail)->needs_saved_esp = 1;
        }
        pcVar12 = cxx_eh_new_try_record();
        begin_op = (t->u20).eh_op;
        pcVar12->begin_tuple = t;
        pcVar12->outer = g_cxx_try_records;
        (begin_op->try_op).try_block = pcVar12;
        pcVar8 = g_eh_trymap_tail;
        g_cxx_try_records = pcVar12;
        pcVar9 = g_eh_trymap_list;
      }
      else if (uVar4 == 0x1a5) {
        pcVar5 = (t->u20).eh_try;
        catch_rec = cxx_eh_new_catch_record
                              (pcVar14,pcVar5->adjectives,(c2_fe_symbol *)pcVar5->state,
                               (c2_fe_symbol *)pcVar5->catch_rec);
        pcVar5->catch_rec = catch_rec;
        pcVar12 = g_cxx_try_records;
        pcVar5->try_block = pcVar14;
        pcVar8 = g_eh_trymap_tail;
        pcVar9 = g_eh_trymap_list;
      }
      else if (uVar4 == 0x1a6) {
        pcVar12 = pcVar14->outer;
        ((t->u20).eh_try)->try_block = pcVar14;
        pcVar8 = pcVar14;
        g_cxx_try_records = pcVar12;
        pcVar9 = pcVar14;
        if (g_eh_trymap_list != (c2_cxx_try_block *)0x0) {
          ppcVar6 = &g_eh_trymap_tail->trymap_next;
          g_eh_trymap_tail = pcVar14;
          *ppcVar6 = pcVar14;
          pcVar8 = g_eh_trymap_tail;
          pcVar9 = g_eh_trymap_list;
        }
      }
      break;
    case '\x17':
      g_cxx_eh_init_insert_point = t;
      break;
    case '\x1a':
      if (pcVar14 == (c2_cxx_try_block *)0x0) {
LAB_107542b7:
        iVar13 = -1;
      }
      else {
        if ((pcVar14->u24).catch_tail != (c2_cxx_catch *)0x0) {
          pcVar14 = pcVar14->outer;
        }
        if (pcVar14 == (c2_cxx_try_block *)0x0) goto LAB_107542b7;
        iVar13 = pcVar14->index;
      }
      pcVar3 = t->src;
      *(int32_t *)((int)&pcVar3[1].op + 2) = iVar13;
      pcVar8 = g_eh_trymap_tail;
      pcVar9 = g_eh_trymap_list;
      if (g_opt_edit_and_continue != 0) {
        if (*(char *)&pcVar3[1].next == 'G') {
          uVar15 = 0xffffffff;
          pcVar16 = g_cur_function->fsym->name;
          do {
            if (uVar15 == 0) break;
            uVar15 = uVar15 - 1;
            cVar1 = *pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (cVar1 != '\0');
          pcVar10 = arena_alloc(0,~uVar15 + 0x15);
          iVar7 = g_eh_name_counter;
          g_eh_name_counter = g_eh_name_counter + 1;
          sprintf((char *)pcVar10,"__unwind$%s$%d",g_cur_function->fsym->name,iVar7);
          pcVar12 = g_cxx_try_records;
          (pcVar3->u18).reg = pcVar10;
          pcVar8 = g_eh_trymap_tail;
          pcVar9 = g_eh_trymap_list;
        }
        else if (*(char *)&pcVar3[1].next == 'H') {
          uVar15 = 0xffffffff;
          pcVar16 = g_cur_function->fsym->name;
          do {
            if (uVar15 == 0) break;
            uVar15 = uVar15 - 1;
            cVar1 = *pcVar16;
            pcVar16 = pcVar16 + 1;
          } while (cVar1 != '\0');
          pcVar10 = arena_alloc(0,~uVar15 + 0x15);
          iVar7 = g_eh_name_counter;
          g_eh_name_counter = g_eh_name_counter + 1;
          sprintf((char *)pcVar10,"__tryend$%s$%d",g_cur_function->fsym->name,iVar7);
          pcVar12 = g_cxx_try_records;
          (pcVar3->u18).reg = pcVar10;
          pcVar8 = g_eh_trymap_tail;
          pcVar9 = g_eh_trymap_list;
        }
      }
    }
    g_eh_trymap_list = pcVar9;
    g_eh_trymap_tail = pcVar8;
    pcVar14 = pcVar12;
    t = pcVar11;
  } while( true );
}

