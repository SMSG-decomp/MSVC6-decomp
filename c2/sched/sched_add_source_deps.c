void __fastcall sched_add_source_deps(c2_sched_node *n,c2_tuple *t)

{
  uint8_t uVar1;
  c2_operand *opnd;
  c2_symbol *sym;
  c2_symbol_cell *pcVar2;
  int iVar3;
  
  opnd = t->src;
  do {
    if (opnd == (c2_operand *)0x0) {
      return;
    }
    switch(opnd->kind) {
    case '\x01':
      if (((opnd->u18).reg)->cls == '\x02') goto override_jmp_1073adb7_case_1;
      sched_deps_on_prior_defs((opnd->u18).reg,n,1);
      break;
    case '\x02':
override_jmp_1073adb7_case_1:
      sym = opnd->sym;
      uVar1 = sym->cls;
      if ((((uVar1 == '\x04') || (uVar1 == '\x05')) || (uVar1 == '\x03')) &&
         (((sym->flags5 & 2) == 0 &&
          ((g_frame_offsets_assigned == 0 ||
           (pcVar2 = stack_slot_aliased_symbols(sym), pcVar2 == (c2_symbol_cell *)0x0)))))) {
        sched_deps_on_prior_defs(sym,n,0x20);
        sched_add_source_deps_part(opnd);
        return;
      }
sched_add_source_deps_case_mem:
      sched_memory_deps_on_stores(opnd,n,0x20);
      sched_add_source_deps_part(opnd);
      return;
    case '\x06':
      goto sched_add_source_deps_case_mem;
    case '\n':
      iVar3 = bitset_iter_next((c2_bitset *)opnd->sym);
      while (iVar3 != -1) {
        sched_deps_on_prior_defs(g_reg_symbols + iVar3,n,1);
        iVar3 = bitset_iter_next((c2_bitset *)0x0);
      }
    }
    opnd = opnd->next;
  } while( true );
}

