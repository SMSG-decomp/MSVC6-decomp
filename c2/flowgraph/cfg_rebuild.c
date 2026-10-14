void __fastcall cfg_rebuild(c2_function *fn)

{
  c2_block *block;
  c2_tuple *pcVar1;
  
  cfg_reset_single_block(fn);
  g_fg_keep_markers = 0;
  coalesce_label_runs(fn);
  remove_dead_labels(fn);
  cfg_build_blocks(fn);
  cfg_build_edges(fn);
  for (block = fn->cfg->first; block != (c2_block *)0x0; block = block->next) {
    pcVar1 = block->end->prev;
    if ((pcVar1->kind == '\x13') && ((pcVar1->switch_flags & 1) != 0)) {
      flow_edge_delete_to(block,(((pcVar1->u20).default_label)->u14).block,fn);
      cfg_add_edge(fn,block,(((pcVar1->u20).default_label)->u14).block);
      add_switch_table_edges(fn,block,(pcVar1->u24).cases);
    }
  }
  return;
}

