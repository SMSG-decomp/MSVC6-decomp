c2_bitset * __fastcall
propagate_colour_to_neighbours
          (c2_function *fn,int reg_class,c2_live_range *lr,c2_bitset *neighbours,
          c2_bitset *split_set)

{
  byte bVar1;
  uint32_t id;
  c2_live_range *pcVar2;
  c2_bitset *pcVar3;
  uint32_t uVar4;
  int iVar5;
  c2_bitset *local_10;
  c2_bitset *local_c;
  
  local_c = (c2_bitset *)0x0;
  local_10 = (c2_bitset *)0x0;
  if (neighbours->chunks != (c2_bitset_chunk *)0x0) {
    uVar4 = lr->colour->id;
    id = bitset_iter_next(neighbours);
    while (id != 0xffffffff) {
      pcVar2 = live_range_from_id(id);
      pcVar3 = pcVar2->allowed;
      bitset_clear(pcVar3,uVar4);
      if (pcVar3->chunks == (c2_bitset_chunk *)0x0) {
        if (((pcVar2->flags5 & 4) == 0) &&
           (iVar5 = try_rematerialize_live_range(pcVar2), iVar5 != 0)) {
          if (split_set != (c2_bitset *)0x0) {
            bitset_clear(split_set,id);
          }
        }
        else {
          if (local_c == (c2_bitset *)0x0) {
            local_c = bitset_new(6);
          }
          bitset_set(local_c,id);
          if ((pcVar2->flags5 & 0x80) != 0) {
            if (pcVar2->sym->cls == '\r') {
              materialize_byte_constant_uses(pcVar2);
            }
            else {
              if (local_10 == (c2_bitset *)0x0) {
                local_10 = bitset_new(6);
              }
              bitset_set(local_10,id);
            }
          }
        }
      }
      id = bitset_iter_next((c2_bitset *)0x0);
    }
  }
  bitset_free(neighbours);
  if (split_set != (c2_bitset *)0x0) {
    pcVar3 = (c2_bitset *)0x0;
    uVar4 = bitset_iter_next(split_set);
    if (uVar4 != 0xffffffff) {
      do {
        pcVar2 = live_range_from_id(uVar4);
        bVar1 = pcVar2->flags5;
        pcVar2->flags5 = bVar1;
        if (((bVar1 & 4) == 0) && (iVar5 = try_rematerialize_live_range(pcVar2), iVar5 != 0)) {
          if (pcVar3 == (c2_bitset *)0x0) {
            pcVar3 = bitset_new(6);
          }
          bitset_set(pcVar3,uVar4);
        }
        else if (((pcVar2->flags5 & 8) == 0) &&
                ((iVar5 = is_rematerializable_def((pcVar2->u38).def), iVar5 != 0 &&
                 (pcVar2->allowed->chunks != (c2_bitset_chunk *)0x0)))) {
          split_live_range_regions(pcVar2);
        }
        uVar4 = bitset_iter_next((c2_bitset *)0x0);
      } while (uVar4 != 0xffffffff);
      if (pcVar3 != (c2_bitset *)0x0) {
        bitset_andnot(split_set,pcVar3);
        bitset_free(pcVar3);
      }
    }
  }
  if (local_c == (c2_bitset *)0x0) goto LAB_10716a53;
  if (local_10 == (c2_bitset *)0x0) {
LAB_10716b87:
    pcVar3 = bitset_clone(g_class_allowed_sets[reg_class]);
    if (g_ebp_allocatable == 0) {
      bitset_clear(pcVar3,6);
    }
    place_split_points_for_ranges(fn,local_c,pcVar3);
    bitset_free(pcVar3);
    uVar4 = bitset_iter_next(local_c);
    while (uVar4 != 0xffffffff) {
      pcVar2 = live_range_from_id(uVar4);
      bVar1 = pcVar2->flags5;
      pcVar2->flags5 = bVar1 | 2;
      if (((bVar1 & 8) == 0) && (iVar5 = is_rematerializable_def((pcVar2->u38).def), iVar5 != 0)) {
        split_live_range_regions(pcVar2);
      }
      if (split_set == (c2_bitset *)0x0) {
        split_set = bitset_new(6);
      }
      bitset_set(split_set,uVar4);
      uVar4 = bitset_iter_next((c2_bitset *)0x0);
    }
  }
  else {
    place_split_points_for_ranges(fn,local_10,g_byte_register_set);
    uVar4 = bitset_iter_next(local_10);
    while (uVar4 != 0xffffffff) {
      pcVar2 = live_range_from_id(uVar4);
      bVar1 = pcVar2->flags5;
      pcVar2->flags5 = bVar1 | 2;
      if (((bVar1 & 8) == 0) && (iVar5 = is_rematerializable_def((pcVar2->u38).def), iVar5 != 0)) {
        split_live_range_regions(pcVar2);
      }
      if (split_set == (c2_bitset *)0x0) {
        split_set = bitset_new(6);
      }
      bitset_set(split_set,uVar4);
      uVar4 = bitset_iter_next((c2_bitset *)0x0);
    }
    bitset_andnot(local_c,local_10);
    bitset_free(local_10);
    if (local_c->chunks != (c2_bitset_chunk *)0x0) goto LAB_10716b87;
  }
  bitset_free(local_c);
LAB_10716a53:
  if ((split_set != (c2_bitset *)0x0) && (split_set->chunks == (c2_bitset_chunk *)0x0)) {
    bitset_free(split_set);
    return (c2_bitset *)0x0;
  }
  return split_set;
}

