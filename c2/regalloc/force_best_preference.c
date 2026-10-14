int __fastcall force_best_preference(c2_live_range *lr)

{
  c2_bitset *bs;
  c2_register_descriptor *pcVar1;
  c2_tuple *pcVar2;
  uint uVar3;
  int iVar4;
  uint32_t uVar5;
  c2_register_descriptor *pcVar6;
  int32_t iVar7;
  c2_register_preference *pcVar8;
  
  iVar4 = load_saving(lr->sym);
  if (0 < iVar4 + lr->weight) {
    pcVar8 = lr->prefs;
    pcVar6 = (c2_register_descriptor *)0x0;
    iVar7 = 0;
    if (pcVar8 != (c2_register_preference *)0x0) {
      bs = lr->allowed;
      do {
        pcVar1 = pcVar8->reg;
        uVar5 = bitset_test(bs,pcVar1->id);
        if ((uVar5 != 0) && ((pcVar6 == (c2_register_descriptor *)0x0 || (iVar7 < pcVar8->count))))
        {
          iVar7 = pcVar8->count;
          pcVar6 = pcVar1;
        }
        pcVar8 = pcVar8->next;
      } while (pcVar8 != (c2_register_preference *)0x0);
      if ((pcVar6 != (c2_register_descriptor *)0x0) &&
         ((((lr->refcount != 3 || (pcVar2 = (lr->u38).def, pcVar2 == (c2_tuple *)0x0)) ||
           (uVar3 = pcVar2->op, uVar3 == 0)) ||
          (((0x143 < uVar3 || ((g_x86_op_flags[uVar3] & 0x40) == 0)) || (pcVar2->dst->rank != 0)))))
         ) {
        bitset_clear_all(bs);
        bitset_set(bs,pcVar6->id);
        lr->weight = 1;
        return 1;
      }
    }
  }
  return 0;
}

