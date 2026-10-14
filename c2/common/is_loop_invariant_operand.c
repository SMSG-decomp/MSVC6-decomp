uint32_t __fastcall is_loop_invariant_operand(c2_operand *opnd)

{
  c2_symbol *pcVar1;
  uint uVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  
  uVar2 = 1 << (opnd->kind & 0x1f);
  if ((uVar2 & 0x380) != 0) {
    return 1;
  }
  if ((uVar2 & 0x18) == 0) {
    if (opnd->kind == 2) {
      pcVar1 = opnd->sym;
      if (((pcVar1->u30).sizeopt.width_facts & 2) != 0) {
        return 1;
      }
      if (pcVar1->def == (c2_tuple *)0x0) {
        uVar4 = pcVar1->id;
        uVar3 = bitset_test(g_loop_kill_set,uVar4);
        if ((uVar3 == 0) &&
           ((pcVar1->cls != '\x03' ||
            (uVar4 = bitset_test(g_preheader_avail_exprs,uVar4), uVar4 != 0)))) {
          return 1;
        }
      }
    }
    return 0;
  }
  return 1;
}

