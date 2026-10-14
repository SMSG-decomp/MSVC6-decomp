uint32_t __fastcall split_resolve_markers_in_blocks(void *blocks,c2_bitset *ranges)

{
  int iVar1;
  c2_tuple *t;
  c2_tuple *pcVar2;
  c2_bitset *dst;
  c2_operand *pcVar3;
  c2_register_descriptor *pcVar4;
  uint32_t id;
  c2_operand *pcVar5;
  c2_live_range *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  c2_tuple *pcVar10;
  uint local_2c;
  uint local_28;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  uVar9 = 0;
  local_14 = 0;
  if (blocks == (void *)0x0) {
    return 0;
  }
  do {
    iVar1 = *(int *)((int)blocks + 8);
    blocks = *(void **)blocks;
    uVar8 = 0;
    t = *(c2_tuple **)(iVar1 + 0x20);
    pcVar2 = *(c2_tuple **)(iVar1 + 0x1c);
    uVar7 = 0;
    local_20 = 0;
    local_28 = 0;
    local_2c = 0;
    local_18 = 0;
    local_1c = 0;
    while (t != pcVar2) {
      pcVar10 = t;
      if ((t->flags & 1) == 0) {
        if (t->kind == '\x1b') {
          if (t->flags12 == '\0') {
            dst = (t->u14).regs;
            bitset_and(dst,ranges);
            bitset_and(dst,*(c2_bitset **)(iVar1 + 0x48));
            uVar8 = local_28;
            uVar9 = local_14;
            if (dst->chunks == (c2_bitset_chunk *)0x0) {
              pcVar10 = t->next;
              (t->u14).arg = (void *)0x0;
              tuple_unlink_free(t);
              bitset_free(dst);
              goto LAB_10723f8c;
            }
            t->flags12 = '\x01';
            id = bitset_iter_next(dst);
            pcVar3 = (c2_operand *)0x0;
            while (id != 0xffffffff) {
              pcVar5 = alloc_rename_cell();
              pcVar6 = live_range_from_id(id);
              pcVar5->next = pcVar3;
              pcVar5->op = (uint32_t)pcVar6;
              id = bitset_iter_next((c2_bitset *)0x0);
              pcVar3 = pcVar5;
            }
            t->src = pcVar3;
            (t->u14).arg = (void *)0x0;
            bitset_free(dst);
            uVar7 = local_18;
          }
          pcVar5 = (c2_operand *)0x0;
          for (pcVar3 = t->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            pcVar5 = (c2_operand *)((uint)pcVar5 | *(uint *)(pcVar3->op + 0x10));
          }
          t->dst = pcVar5;
          local_2c = local_2c | (uint)pcVar5;
          local_28 = uVar8 & ~(uint)pcVar5;
          uVar7 = uVar7 | (uint)pcVar5;
          uVar8 = local_28;
          local_18 = uVar7;
        }
      }
      else {
        for (pcVar3 = t->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
          if (((pcVar3->kind == '\x01') && (pcVar6 = (pcVar3->u18).range, pcVar6->kind == '\x02'))
             && ((pcVar6->flags5 & 2) != 0)) {
            pcVar4 = pcVar6->colour;
            if ((((uint)pcVar4 & local_2c) == 0) && ((pcVar3->flags & 0xf) == 0)) {
              local_20 = local_20 | (uint)pcVar4;
              local_2c = local_2c | (uint)pcVar4;
            }
            uVar8 = uVar8 & ~(uint)pcVar4;
            uVar7 = uVar7 & ~(uint)pcVar4;
            local_1c = local_1c | (uint)pcVar4;
            uVar9 = uVar9 | pcVar3->rank;
          }
          local_28 = uVar8;
          local_18 = uVar7;
          local_14 = uVar9;
        }
        for (pcVar3 = t->src; uVar9 = local_14, pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next)
        {
          if ((pcVar3->kind == '\x01') && (pcVar6 = (pcVar3->u18).range, pcVar6->kind == '\x02')) {
            if ((pcVar6->flags5 & 2) != 0) {
              pcVar4 = pcVar6->colour;
              if ((local_2c & (uint)pcVar4) == 0) {
                local_20 = local_20 | (uint)pcVar4;
              }
              uVar8 = uVar8 | (uint)pcVar4;
              if ((pcVar3->flags11 & 0x10) != 0) {
                local_1c = local_1c | (uint)pcVar4;
                uVar7 = uVar7 & ~(uint)pcVar4;
              }
            }
          }
          else if ((pcVar3->kind == '\x02') && (pcVar3->rank != 0)) {
            pcVar6 = live_range_from_id(pcVar3->rank);
            uVar7 = uVar7 | (uint)pcVar6->colour;
          }
          local_28 = uVar8;
          local_18 = uVar7;
        }
      }
LAB_10723f8c:
      t = pcVar10->prev;
    }
    *(uint *)(iVar1 + 0x30) = uVar8;
    *(uint *)(iVar1 + 0x2c) = local_20;
    *(uint *)(iVar1 + 0x34) = local_2c;
    *(uint *)(iVar1 + 0x50) = uVar7;
    *(uint *)(iVar1 + 0x54) = local_1c;
    *(uint *)(iVar1 + 0x38) = uVar8;
    if (blocks == (void *)0x0) {
      return uVar9;
    }
  } while( true );
}

