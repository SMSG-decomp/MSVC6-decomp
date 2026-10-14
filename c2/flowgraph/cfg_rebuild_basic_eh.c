void __fastcall cfg_rebuild_basic_eh(c2_function *fn)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_block *to;
  bool bVar3;
  int *piVar4;
  
  seh_mark_try_region_memory_ops(fn);
  cfg_reset_single_block(fn);
  g_fg_keep_markers = 1;
  cfg_build_blocks(fn);
  bVar3 = false;
  to = fn->cfg->first;
  do {
    if (to == (c2_block *)0x0) {
      return;
    }
    if (bVar3) {
      cfg_add_edge(fn,to->prev,to);
    }
    pcVar2 = to->head->next;
    if (pcVar2->kind == '\x1a') {
      for (pcVar1 = pcVar2->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
        piVar4 = (int *)pcVar1->rank;
        if ((char)piVar4[2] == '\x1d') {
          piVar4 = (int *)piVar4[6];
        }
        cfg_add_edge(fn,*(c2_block **)(*(int *)(*piVar4 + 0x14) + 4),to);
      }
    }
    pcVar2 = to->end->prev;
    if (pcVar2->kind == '\x11') {
      if (((pcVar2->u20).cond_cells == (c2_cond_cell *)0x0) && (pcVar2->op != 0x18b)) {
        bVar3 = false;
      }
      else {
LAB_1070487e:
        bVar3 = true;
      }
    }
    else {
      if (pcVar2->kind != '\x13') goto LAB_1070487e;
      bVar3 = false;
    }
    to = to->next;
  } while( true );
}

