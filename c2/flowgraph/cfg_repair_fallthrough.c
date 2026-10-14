int __fastcall
cfg_repair_fallthrough(c2_block *block,c2_block *old_succ,c2_tuple *at,c2_function *fn)

{
  uint16_t uVar1;
  c2_tuple *pcVar2;
  c2_block *to;
  c2_fe_symbol *label_sym;
  int iVar3;
  
  if (old_succ == (c2_block *)0x0) {
    return 0;
  }
  switch(at->kind) {
  case '\x11':
    if (((at->u20).cond_cells == (c2_cond_cell *)0x0) && (at->op != 0x18b)) {
      return 0;
    }
    break;
  case '\x12':
    if ((at->u20).intrinsic.id == 0x17e) {
      iVar3 = cfg_repair_fallthrough_case_13();
      return iVar3;
    }
    break;
  case '\x13':
    return 0;
  case '\x14':
    if (at->op == 0x16c) {
      return 0;
    }
  }
  pcVar2 = old_succ->head->next;
  if (pcVar2->op != 0x1ae) {
    label_sym = label_symbol_new();
    pcVar2 = label_insert_in_block(label_sym,old_succ);
  }
  uVar1 = block->end->prev->line;
  if (uVar1 != 0) {
    g_current_line_abs = (uint)block->end->prev->line + fn->line_base;
    g_cur_line = uVar1;
  }
  pcVar2 = tuple_new_jmp_before(pcVar2,block->end);
  to = block_split_before(fn,block,pcVar2);
  to->loop = old_succ->loop;
  flow_edge_delete_to(block,old_succ,fn);
  cfg_add_edge(fn,block,to);
  cfg_add_edge(fn,to,old_succ);
  return 1;
}

