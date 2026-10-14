void __fastcall sort_stack_slots_by_density(int32_t lo,int32_t hi)

{
  c2_stack_slot *pcVar1;
  int b;
  int iVar2;
  int local_c;
  
  while (lo < hi) {
    swap_stack_slots(lo,(lo + hi) / 2);
    b = lo + 1;
    local_c = lo;
    if (b <= hi) {
      iVar2 = b * 0x14;
      pcVar1 = g_stack_slots;
      do {
        if ((pcVar1[lo].refs * 1000) / pcVar1[lo].size <
            (*(int *)((int)&pcVar1->refs + iVar2) * 1000) / *(int *)((int)&pcVar1->size + iVar2)) {
          local_c = local_c + 1;
          swap_stack_slots(local_c,b);
          pcVar1 = g_stack_slots;
        }
        b = b + 1;
        iVar2 = iVar2 + 0x14;
      } while (b <= hi);
    }
    swap_stack_slots(lo,local_c);
    sort_stack_slots_by_density(lo,local_c + -1);
    lo = local_c + 1;
  }
  return;
}

