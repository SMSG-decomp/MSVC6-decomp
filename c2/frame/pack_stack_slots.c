void __fastcall pack_stack_slots(c2_function *fn,int32_t fpo_or_aligned,int32_t nsyms)

{
  c2_symbol *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_symbol_cell *pcVar3;
  c2_bitset **ppcVar4;
  c2_stack_slot *pcVar5;
  c2_bitset *pcVar6;
  uint32_t uVar7;
  int iVar8;
  c2_stack_slot_range *pcVar9;
  c2_stack_slot_range *pcVar10;
  int iVar11;
  uint32_t uVar12;
  int32_t iVar13;
  c2_symbol_cell *pcVar14;
  int iVar15;
  int iVar16;
  int local_14;
  int local_10;
  int local_c;
  c2_symbol *obj;
  
  iVar15 = 0;
  local_14 = 0;
  local_c = 0;
  g_stack_slots = arena_alloc(4,g_stack_object_count * 0x14);
  for (pcVar1 = g_stack_object_order_head; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->order_next)
  {
    if (pcVar1->cls == '\x05') {
      uVar12 = (pcVar1->u38).index;
      if ((pcVar1->flags6 & 4) != 0) {
        bitset_set_range(g_stack_interference[uVar12],nsyms);
      }
      pcVar6 = bitset_new(6);
      pcVar5 = g_stack_slots;
      iVar16 = g_stack_slot_count;
      g_stack_slots[g_stack_slot_count].interference = pcVar6;
      pcVar6 = bitset_new(6);
      ppcVar4 = g_stack_interference;
      pcVar5[iVar16].members = pcVar6;
      bitset_copy(pcVar5[iVar16].interference,ppcVar4[uVar12]);
      bitset_set(g_stack_slots[g_stack_slot_count].members,uVar12);
      pcVar5 = g_stack_slots;
      iVar13 = pcVar1->fe->offset;
      g_stack_slots[g_stack_slot_count].size = pcVar1->fe->size + 3 & 0xfffffffc;
      pcVar5[g_stack_slot_count].offset = iVar13;
      iVar15 = iVar15 + 1;
      g_stack_slot_count = g_stack_slot_count + 1;
    }
  }
  if (iVar15 != g_stack_param_slot_count) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\stack.c",0x522);
  }
  pcVar1 = g_stack_object_order_head;
  if (((fn->flags & 0x40) != 0) || ((fn->flags & 0x600000) != 0)) {
    iVar15 = 0;
  }
  do {
    if (pcVar1 == (c2_symbol *)0x0) {
      if (((fpo_or_aligned != 0) && (0 < local_c)) && (0x6f < local_14)) {
        iVar15 = 0;
        if (0 < g_stack_slot_count) {
          iVar16 = 0;
          do {
            bitset_free(*(c2_bitset **)((int)&g_stack_slots->interference + iVar16));
            bitset_free(*(c2_bitset **)((int)&g_stack_slots->members + iVar16));
            iVar15 = iVar15 + 1;
            iVar16 = iVar16 + 0x14;
          } while (iVar15 < g_stack_slot_count);
        }
        g_stack_slot_count = 0;
        local_14 = 0;
        g_stack_param_slot_count = 0;
        for (pcVar1 = g_stack_object_order_head; pcVar1 != (c2_symbol *)0x0;
            pcVar1 = pcVar1->order_next) {
          if (pcVar1->cls != '\x05') {
            local_14 = join_or_create_stack_slot(pcVar1,local_14);
          }
        }
      }
      g_stack_local_bytes = local_14;
      if (0x80 < local_14) {
        sort_stack_slots_by_density(g_stack_param_slot_count,g_stack_slot_count + -1);
      }
      iVar15 = 0;
      g_stack_slot_ranges = (c2_stack_slot_range *)0x0;
      if (fpo_or_aligned == 0) {
        nsyms = 0;
        if (0 < g_stack_slot_count) {
          do {
            if (nsyms < g_stack_param_slot_count) {
              local_10 = *(int *)((int)&g_stack_slots->offset + iVar15);
            }
            else {
              local_10 = frame_alloc_local(*(uint32_t *)((int)&g_stack_slots->size + iVar15),0);
              local_10 = local_10 + g_stack_slot_bias;
            }
            pcVar9 = arena_alloc(1,0x10);
            pcVar5 = g_stack_slots;
            pcVar9->offset = local_10;
            iVar13 = *(int32_t *)((int)&pcVar5->size + iVar15);
            pcVar9->next = g_stack_slot_ranges;
            pcVar6 = *(c2_bitset **)((int)&pcVar5->members + iVar15);
            pcVar9->size = iVar13;
            g_stack_slot_ranges = pcVar9;
            iVar16 = bitset_iter_next(pcVar6);
            while (iVar16 != -1) {
              pcVar1 = g_stack_object_table[iVar16];
              if (pcVar1->cls == '\x04') {
                pcVar2 = pcVar1->fe;
                uVar12 = align_frame_offset(-((*(int *)((int)&g_stack_slots->size + iVar15) -
                                              pcVar1->size) + local_10),pcVar1->size,
                                            g_default_stack_align);
                pcVar2->offset = -uVar12;
                pcVar2->attrs = pcVar2->attrs | 0x800;
              }
              else {
                uVar12 = align_frame_offset(-((*(int *)((int)&g_stack_slots->size + iVar15) -
                                              pcVar1->size) + local_10),pcVar1->size,
                                            g_default_stack_align);
                (pcVar1->u28).frame_home = -uVar12;
                pcVar1->flags5 = pcVar1->flags5 | 0x20;
              }
              if ((pcVar1->flags5 & 2) != 0) {
                pcVar14 = arena_alloc(1,8);
                pcVar3 = pcVar9->aliased;
                pcVar14->sym = pcVar1;
                pcVar14->next = pcVar3;
                pcVar9->aliased = pcVar14;
              }
              iVar16 = bitset_iter_next((c2_bitset *)0x0);
            }
            nsyms = nsyms + 1;
            iVar15 = iVar15 + 0x14;
          } while (nsyms < g_stack_slot_count);
          return;
        }
      }
      else {
        iVar15 = g_stack_slot_count + -1;
        if (-1 < iVar15) {
          iVar16 = iVar15 * 0x14;
          do {
            if (iVar15 < g_stack_param_slot_count) {
              iVar13 = *(int32_t *)((int)&g_stack_slots->offset + iVar16);
            }
            else {
              uVar12 = stack_slot_alignment
                                 (*(c2_bitset **)((int)&g_stack_slots->members + iVar16),fn);
              iVar13 = frame_alloc_local(*(uint32_t *)((int)&g_stack_slots->size + iVar16),uVar12);
            }
            pcVar10 = arena_alloc(1,0x10);
            pcVar9 = g_stack_slot_ranges;
            pcVar5 = g_stack_slots;
            g_stack_slot_ranges = pcVar10;
            pcVar10->offset = iVar13;
            pcVar10->next = pcVar9;
            pcVar10->size = *(int32_t *)((int)&pcVar5->size + iVar16);
            iVar11 = bitset_iter_next(*(c2_bitset **)((int)&pcVar5->members + iVar16));
            while (iVar11 != -1) {
              obj = g_stack_object_table[iVar11];
              if (obj->cls == '\x04') {
                pcVar2 = obj->fe;
                pcVar2->offset = iVar13;
                pcVar2->attrs = pcVar2->attrs | 0x800;
              }
              else {
                (obj->u28).frame_home = iVar13;
                obj->flags5 = obj->flags5 | 0x20;
              }
              if ((obj->flags5 & 2) != 0) {
                pcVar14 = arena_alloc(1,8);
                pcVar3 = pcVar10->aliased;
                pcVar14->sym = obj;
                pcVar14->next = pcVar3;
                pcVar10->aliased = pcVar14;
              }
              iVar11 = bitset_iter_next((c2_bitset *)0x0);
            }
            iVar15 = iVar15 + -1;
            iVar16 = iVar16 + -0x14;
          } while (-1 < iVar15);
        }
      }
      return;
    }
    if (pcVar1->cls != '\x05') {
      uVar12 = (pcVar1->u38).index;
      if ((pcVar1->flags6 & 4) != 0) {
        bitset_set_range(g_stack_interference[uVar12],nsyms);
      }
      iVar16 = 0;
      if (0 < iVar15) {
        iVar11 = 0;
        do {
          if (((pcVar1->size <= *(int *)((int)&g_stack_slots->size + iVar11)) &&
              (uVar7 = bitset_test(*(c2_bitset **)((int)&g_stack_slots->interference + iVar11),
                                   uVar12), uVar7 == 0)) &&
             (iVar8 = bitset_intersects(*(c2_bitset **)((int)&g_stack_slots->members + iVar11),
                                        g_stack_interference[uVar12]), iVar8 == 0)) {
            bitset_set(g_stack_slots[iVar16].members,uVar12);
            bitset_or(g_stack_slots[iVar16].interference,g_stack_interference[uVar12]);
            local_c = local_c + 1;
            if (iVar16 < iVar15) goto LAB_10726b09;
            break;
          }
          iVar16 = iVar16 + 1;
          iVar11 = iVar11 + 0x14;
        } while (iVar16 < iVar15);
      }
      local_14 = join_or_create_stack_slot(pcVar1,local_14);
    }
LAB_10726b09:
    pcVar1 = pcVar1->order_next;
  } while( true );
}

