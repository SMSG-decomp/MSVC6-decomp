void cfg_build_blocks_case_194
               (int eh_depth,c2_tuple *t,c2_block *block,int start_new_block,c2_tuple *next_tuple,
               c2_function *fn,c2_tuple *walk_end)

{
  c2_tuple *resume;
  int iVar1;
  c2_tuple *following;
  
  following = next_tuple;
code_r0x107046ef:
  next_tuple = following;
  eh_depth = eh_depth + -1;
  resume = next_tuple;
  goto switchD_107046a9_caseD_12;
switchD_107046a9_caseD_14:
  switch(next_tuple->op) {
  case 0x192:
  case 0x1a4:
    eh_depth = eh_depth + 1;
    block->eh_state = (int16_t)eh_depth;
  default:
switchD_107046a9_caseD_12:
    do {
      next_tuple = resume;
      if (next_tuple == walk_end) {
        return;
      }
      following = next_tuple->next;
    } while ((next_tuple->kind == '\x16') &&
            (resume = cleanup_marker_tuple(next_tuple), resume != (c2_tuple *)0x0));
    if ((start_new_block != 0) || ((next_tuple->kind == '\x1a' || (next_tuple->kind == '\x18')))) {
      start_new_block = 0;
      block = block_split_before(fn,block,next_tuple);
      block->eh_state = (int16_t)eh_depth;
    }
    resume = following;
    switch(next_tuple->kind) {
    case '\x11':
    case '\x13':
    case '\x17':
      start_new_block = 1;
      if (next_tuple->op == 0x187) {
        block->flags = block->flags | 0x1000000;
      }
    default:
      goto switchD_107046a9_caseD_12;
    case '\x14':
      goto switchD_107046a9_caseD_14;
    case '\x1a':
      (next_tuple->u14).block = block;
      goto switchD_107046a9_caseD_12;
    }
  case 0x194:
  case 0x196:
    goto code_r0x107046ef;
  case 0x1a5:
    iVar1 = block_ends_at_next_head(next_tuple);
    if (iVar1 != 0) {
      cfg_build_blocks_case_194(eh_depth,next_tuple,block,start_new_block,following,fn,walk_end);
      return;
    }
    goto switchD_107046a9_caseD_12;
  }
}

