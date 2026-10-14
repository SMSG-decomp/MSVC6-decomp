int __fastcall sched_can_pair_uv(c2_sched_node *first,c2_sched_node *n)

{
  c2_tuple *pcVar1;
  uint uVar2;
  uint32_t uVar3;
  bool bVar4;
  bool bVar5;
  
  pcVar1 = n->tuple;
  if (pcVar1 != (c2_tuple *)0x0) {
    uVar2 = first->tuple->op;
    if ((first->tuple->type & 0xf000) == 0x4000) {
      if (uVar2 < 0x144) {
        uVar3 = g_sched_latency_table[uVar2].unit_pairing;
      }
      else {
        uVar3 = 0x300;
      }
      bVar4 = uVar3 == 0x102;
      bVar5 = pcVar1->op == 0x5f;
    }
    else {
      if (((uVar2 < 0x144) && (g_sched_latency_table[uVar2].unit_pairing == 0)) ||
         ((uVar2 < 0x144 && (g_sched_latency_table[uVar2].unit_pairing == 0x100)))) {
        bVar4 = true;
      }
      else {
        bVar4 = false;
      }
      uVar2 = pcVar1->op;
      if ((uVar2 < 0x144) &&
         ((g_sched_latency_table[uVar2].unit_pairing == 0 ||
          ((uVar2 < 0x144 && (g_sched_latency_table[uVar2].unit_pairing == 0x200)))))) {
        bVar5 = true;
      }
      else {
        bVar5 = false;
      }
    }
    if ((bVar4) && (bVar5)) {
      return 1;
    }
  }
  return 0;
}

