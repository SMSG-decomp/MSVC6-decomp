void __fastcall limit_loop_exit_availability(c2_loop *loop)

{
  c2_loop_exit *pcVar1;
  c2_block *pcVar2;
  
  collect_loop_kill_set(loop);
  for (pcVar1 = loop->exits; pcVar1 != (c2_loop_exit *)0x0; pcVar1 = pcVar1->next) {
    pcVar2 = pcVar1->block;
    bitset_and(pcVar2->set54,loop->first->set50);
    bitset_andnot(pcVar2->set54,g_loop_kill_set);
  }
  return;
}

