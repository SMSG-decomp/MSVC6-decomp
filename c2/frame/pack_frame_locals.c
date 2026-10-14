void __fastcall pack_frame_locals(c2_function *fn)

{
  uint32_t nsyms;
  int iVar1;
  c2_bitset *pcVar2;
  int32_t fpo_or_aligned;
  int iVar3;
  
  init_frame_layout_state();
  count_stack_object_references(fn);
  g_stack_object_table = arena_alloc(4,g_stack_object_count * 4);
  nsyms = index_stack_objects();
  if ((g_opt_eh_enabled == 0) && (g_eh_guard_local != (c2_symbol *)0x0)) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  choose_fpo_for_size(fn,((uint)(g_frame_eh_record != (c2_fe_symbol *)0x0) -
                         g_stack_param_slot_count) + iVar1 + g_stack_object_count);
  if (g_stack_object_count != g_stack_param_slot_count) {
    build_stack_object_liveness(fn);
    g_stack_interference = arena_alloc(4,g_stack_object_count << 2);
    iVar1 = 0;
    if (0 < g_stack_object_count) {
      do {
        pcVar2 = bitset_new(6);
        iVar3 = iVar1 + 1;
        g_stack_interference[iVar1] = pcVar2;
        iVar1 = iVar3;
      } while (iVar3 < g_stack_object_count);
    }
    build_stack_object_interference(fn);
    if (((fn->flags & 0x10) == 0) && ((fn->flags & 0x600000) == 0)) {
      fpo_or_aligned = 0;
    }
    else {
      fpo_or_aligned = 1;
    }
    pack_stack_slots(fn,fpo_or_aligned,nsyms);
    iVar1 = 0;
    if (0 < g_stack_slot_count) {
      iVar3 = 0;
      do {
        bitset_free(*(c2_bitset **)((int)&g_stack_slots->interference + iVar3));
        bitset_free(*(c2_bitset **)((int)&g_stack_slots->members + iVar3));
        iVar1 = iVar1 + 1;
        iVar3 = iVar3 + 0x14;
      } while (iVar1 < g_stack_slot_count);
    }
    iVar1 = 0;
    if (0 < g_stack_object_count) {
      do {
        bitset_free(g_stack_interference[iVar1]);
        iVar1 = iVar1 + 1;
      } while (iVar1 < g_stack_object_count);
    }
    arena_reset(4);
    g_frame_offsets_assigned = 1;
  }
  return;
}

