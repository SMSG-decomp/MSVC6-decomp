void __fastcall split_solve_region_bits(c2_ra_split_block *head,c2_ra_split_block *tail,int mode)

{
  c2_block *pcVar1;
  c2_edge *pcVar2;
  c2_ra_split_block *pcVar3;
  c2_block_slot cVar4;
  c2_bitset *pcVar5;
  uint uVar6;
  c2_ra_split_block *pcVar7;
  c2_bitset *pcVar8;
  uint uVar9;
  
  do {
    uVar6 = 0;
    pcVar7 = tail;
    pcVar3 = head;
    if (tail == (c2_ra_split_block *)0x0) break;
    do {
      pcVar1 = pcVar7->block;
      pcVar8 = (c2_bitset *)0x0;
      for (pcVar2 = pcVar1->succs; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_succ) {
        pcVar8 = (c2_bitset *)((uint)pcVar8 | (uint)(pcVar2->to->avail_in).set);
      }
      if (pcVar8 != (pcVar1->avail_out).set) {
        pcVar5 = (pcVar1->avail_in).set;
        (pcVar1->avail_out).set = pcVar8;
        pcVar8 = (c2_bitset *)(~(uint)pcVar1->kill & (uint)pcVar8 | (uint)pcVar1->ue);
        (pcVar1->avail_in).set = pcVar8;
        uVar6 = uVar6 | (uint)pcVar8 ^ (uint)pcVar5;
      }
      pcVar7 = pcVar7->prev;
    } while (pcVar7 != (c2_ra_split_block *)0x0);
  } while (uVar6 != 0);
  while (pcVar3 != (c2_ra_split_block *)0x0) {
    pcVar1 = pcVar3->block;
    pcVar3 = pcVar3->next;
    pcVar1->set24 = (c2_bitset *)pcVar1->avail_in;
    (pcVar1->avail_in).set = (c2_bitset *)0x0;
    pcVar1->set28 = (pcVar1->avail_out).set;
    (pcVar1->avail_out).set = (c2_bitset *)((uint)pcVar1->de & (uint)(pcVar1->avail_out).set);
  }
  do {
    uVar6 = 0;
    pcVar7 = head;
    if (head == (c2_ra_split_block *)0x0) break;
    do {
      pcVar1 = pcVar7->block;
      uVar9 = 0;
      for (pcVar2 = pcVar1->preds; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_pred) {
        uVar9 = uVar9 | (uint)(pcVar2->from->avail_out).set;
      }
      pcVar8 = (c2_bitset *)(uVar9 & (uint)pcVar1->set24);
      if (pcVar8 != (pcVar1->avail_in).set) {
        pcVar5 = (pcVar1->avail_out).set;
        (pcVar1->avail_in).set = pcVar8;
        pcVar8 = (c2_bitset *)
                 ((~(uint)pcVar1->kill & (uint)pcVar8 | (uint)pcVar1->de) & (uint)pcVar1->set28);
        (pcVar1->avail_out).set = pcVar8;
        uVar6 = uVar6 | (uint)pcVar8 ^ (uint)pcVar5;
      }
      pcVar7 = pcVar7->next;
    } while (pcVar7 != (c2_ra_split_block *)0x0);
  } while (uVar6 != 0);
  pcVar7 = head;
  if (mode == 0) {
    while (head != (c2_ra_split_block *)0x0) {
      pcVar1 = head->block;
      head = head->next;
      cVar4 = pcVar1->avail_in;
      (pcVar1->avail_in).set = (c2_bitset *)0x0;
      pcVar1->set24 = (c2_bitset *)cVar4;
      pcVar1->set28 = (c2_bitset *)pcVar1->avail_out;
      (pcVar1->avail_out).set = (c2_bitset *)0x0;
      pcVar1->set50 = (c2_bitset *)0x0;
    }
  }
  else {
    while (pcVar7 != (c2_ra_split_block *)0x0) {
      pcVar1 = pcVar7->block;
      pcVar7 = pcVar7->next;
      pcVar1->set24 = (c2_bitset *)pcVar1->avail_in;
      pcVar1->avail_in = (c2_block_slot)pcVar1->set50;
      pcVar1->set28 = (c2_bitset *)pcVar1->avail_out;
      (pcVar1->avail_out).set = (c2_bitset *)0x0;
    }
    do {
      uVar6 = 0;
      pcVar7 = tail;
      if (tail == (c2_ra_split_block *)0x0) break;
      do {
        pcVar1 = pcVar7->block;
        pcVar8 = (c2_bitset *)0x0;
        for (pcVar2 = pcVar1->succs; pcVar2 != (c2_edge *)0x0; pcVar2 = pcVar2->next_succ) {
          pcVar8 = (c2_bitset *)((uint)pcVar8 | (uint)(pcVar2->to->avail_in).set);
        }
        if (pcVar8 != (pcVar1->avail_out).set) {
          pcVar5 = (pcVar1->avail_in).set;
          (pcVar1->avail_out).set = pcVar8;
          pcVar8 = (c2_bitset *)(~(uint)pcVar1->set54 & (uint)pcVar8 | (uint)pcVar1->set50);
          (pcVar1->avail_in).set = pcVar8;
          uVar6 = uVar6 | (uint)pcVar8 ^ (uint)pcVar5;
        }
        pcVar7 = pcVar7->prev;
      } while (pcVar7 != (c2_ra_split_block *)0x0);
    } while (uVar6 != 0);
    if (head != (c2_ra_split_block *)0x0) {
      do {
        pcVar1 = head->block;
        head = head->next;
        (pcVar1->avail_in).set = (c2_bitset *)0x0;
        pcVar1->set50 = (c2_bitset *)pcVar1->avail_out;
        (pcVar1->avail_out).set = (c2_bitset *)0x0;
      } while (head != (c2_ra_split_block *)0x0);
      return;
    }
  }
  return;
}

