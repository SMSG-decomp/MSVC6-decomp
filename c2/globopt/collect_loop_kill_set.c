void __fastcall collect_loop_kill_set(c2_loop *loop)

{
  c2_block *pcVar1;
  
  bitset_clear_all(g_loop_kill_set);
  pcVar1 = loop->first;
  if (pcVar1 != loop->last->next) {
    do {
      bitset_or(g_loop_kill_set,pcVar1->set4c);
      pcVar1 = pcVar1->next;
    } while (pcVar1 != loop->last->next);
  }
  return;
}

