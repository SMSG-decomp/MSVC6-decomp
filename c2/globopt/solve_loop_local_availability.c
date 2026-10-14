void __fastcall solve_loop_local_availability(c2_loop *loop)

{
  c2_block *pcVar1;
  c2_block *pcVar2;
  c2_block *pcVar3;
  c2_block *b;
  c2_loop *local_4;
  
  pcVar1 = loop->last;
  pcVar2 = loop->first;
  local_4 = loop;
  bitset_copy(pcVar1->set5c,pcVar1->set54);
  do {
    local_4 = (c2_loop *)0x0;
    bitset_copy((pcVar2->u58).set,pcVar1->set5c);
    pcVar3 = pcVar1->next;
    for (b = pcVar2; b != pcVar3; b = b->next) {
      propagate_loop_local_availability(b,(uint)(b == pcVar2),(uint32_t *)&local_4);
    }
  } while (local_4 != (c2_loop *)0x0);
  return;
}

