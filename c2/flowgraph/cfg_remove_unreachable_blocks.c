void __fastcall cfg_remove_unreachable_blocks(c2_function *fn)

{
  c2_block *pcVar1;
  c2_tuple *pcVar2;
  c2_block *block;
  
  cfg_dfs_rpo(fn);
  block = fn->cfg->first;
  if (block != fn->cfg->last) {
    do {
      pcVar1 = block->next;
      if ((block->flags & 1) == 0) {
        for (pcVar2 = block->head->next; pcVar2 != block->end; pcVar2 = pcVar2->next) {
          if ((((pcVar2->flags & 1) != 0) && (pcVar2->kind != '\x11')) && (pcVar2->kind != '\x14'))
          {
            g_current_line_abs = (uint)pcVar2->line + fn->line_base;
            warning(4,0x2be);
            break;
          }
        }
        delete_unreachable_block(fn,block);
      }
      block = pcVar1;
    } while (pcVar1 != fn->cfg->last);
  }
  return;
}

