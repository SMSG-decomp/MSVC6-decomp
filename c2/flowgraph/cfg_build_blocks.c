void __fastcall cfg_build_blocks(c2_function *fn)

{
  c2_tuple *resume;
  c2_block *block;
  int iVar1;
  int eh_depth;
  int start_new_block;
  c2_tuple *t;
  c2_tuple *next_tuple;
  c2_tuple *walk_end;
  
  block = fn->cfg->first;
  start_new_block = 0;
  walk_end = fn->cfg->last->end;
  eh_depth = 0;
  t = block->head->next;
  if (t != walk_end) {
    do {
      next_tuple = t->next;
      if ((t->kind != '\x16') || (resume = cleanup_marker_tuple(t), resume == (c2_tuple *)0x0)) {
        if ((start_new_block != 0) || ((t->kind == '\x1a' || (t->kind == '\x18')))) {
          start_new_block = 0;
          block = block_split_before(fn,block,t);
          block->eh_state = (int16_t)eh_depth;
        }
        resume = next_tuple;
        switch(t->kind) {
        case '\x11':
        case '\x13':
        case '\x17':
          start_new_block = 1;
          if (t->op == 0x187) {
            block->flags = block->flags | 0x1000000;
          }
          break;
        case '\x14':
          switch(t->op) {
          case 0x192:
          case 0x1a4:
            eh_depth = eh_depth + 1;
            block->eh_state = (int16_t)eh_depth;
            break;
          case 0x194:
          case 0x196:
            eh_depth = eh_depth + -1;
            break;
          case 0x1a5:
            iVar1 = block_ends_at_next_head(t);
            resume = next_tuple;
            if (iVar1 != 0) {
              cfg_build_blocks_case_194(eh_depth,t,block,start_new_block,next_tuple,fn,walk_end);
              return;
            }
          }
          break;
        case '\x1a':
          (t->u14).block = block;
        }
      }
      t = resume;
    } while (t != walk_end);
  }
  return;
}

