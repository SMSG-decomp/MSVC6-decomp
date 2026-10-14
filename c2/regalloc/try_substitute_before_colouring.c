int __fastcall try_substitute_before_colouring(c2_live_range *lr)

{
  c2_tuple *def;
  c2_bitset *bs;
  int iVar1;
  uint32_t uVar2;
  c2_live_range *pcVar3;
  int iVar4;
  c2_live_range *local_4;
  
  def = (lr->u38).def;
  local_4 = lr;
  bs = collect_remat_dependencies(def,(c2_live_range *)0x0,(int *)&local_4);
  if (bs == (c2_bitset *)0x0) {
    return 0;
  }
  if ((local_4 == (c2_live_range *)0x1) && ((lr->flags5 & 0x20) == 0)) {
    bitset_free(bs);
    return 0;
  }
  iVar1 = can_rematerialize_address(def,lr,bs,0);
  if (iVar1 != 0) {
    if (local_4 != (c2_live_range *)0x0) {
      substitute_definition_into_uses(def,lr,(c2_operand *)0x0);
      free_live_range(lr,1);
      bitset_free(bs);
      return iVar1;
    }
    uVar2 = bitset_iter_next(bs);
    pcVar3 = live_range_from_id(uVar2);
    iVar4 = pcVar3->priority;
    uVar2 = bitset_iter_next((c2_bitset *)0x0);
    while (uVar2 != 0xffffffff) {
      pcVar3 = live_range_from_id(uVar2);
      if (pcVar3->weight < 1) {
        bitset_free(bs);
        return 0;
      }
      if (pcVar3->priority < iVar4) {
        iVar4 = pcVar3->priority;
      }
      uVar2 = bitset_iter_next((c2_bitset *)0x0);
    }
    lr->priority = iVar4 + -1;
    (lr->u14).queue_next = (c2_live_range *)0x0;
    lr->queue_prev = (c2_live_range *)0x0;
  }
  bitset_free(bs);
  return iVar1;
}

