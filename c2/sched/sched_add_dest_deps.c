void __fastcall sched_add_dest_deps(c2_sched_node *snode,c2_tuple **from,c2_tuple **end)

{
  uint8_t uVar1;
  c2_operand *opnd;
  c2_symbol *sym;
  c2_symbol_cell *pcVar2;
  int iVar3;
  
  opnd = (c2_operand *)from[7];
  do {
    if (opnd == (c2_operand *)0x0) {
      return;
    }
    switch(opnd->kind) {
    case '\x01':
      if (((opnd->u18).reg)->cls == '\x02') goto switchD_1073ae39_caseD_2;
      iVar3 = sched_flags_def_unused(opnd,from,end);
      if (iVar3 == 0) {
        sched_deps_on_prior_defs((opnd->u18).reg,snode,4);
      }
      sched_add_reg_dep_edges((opnd->u18).reg,snode,2);
      break;
    case '\x02':
switchD_1073ae39_caseD_2:
      sym = opnd->sym;
      uVar1 = sym->cls;
      if ((((uVar1 != '\x04') && (uVar1 != '\x05')) && (uVar1 != '\x03')) ||
         (((sym->flags5 & 2) != 0 ||
          ((g_frame_offsets_assigned != 0 &&
           (pcVar2 = stack_slot_aliased_symbols(sym), pcVar2 != (c2_symbol_cell *)0x0))))))
      goto switchD_1073ae39_caseD_6;
      sched_deps_on_prior_defs(sym,snode,0x80);
      sched_add_reg_dep_edges(opnd->sym,snode,0x40);
      break;
    case '\x06':
switchD_1073ae39_caseD_6:
      sched_memory_deps_on_stores(opnd,snode,0x80);
      sched_add_store_load_edges(opnd,snode);
      break;
    case '\n':
      iVar3 = bitset_iter_next((c2_bitset *)opnd->sym);
      while (iVar3 != -1) {
        sched_deps_on_prior_defs(g_reg_symbols + iVar3,snode,4);
        sched_add_reg_dep_edges(g_reg_symbols + iVar3,snode,2);
        iVar3 = bitset_iter_next((c2_bitset *)0x0);
      }
    }
    opnd = opnd->next;
  } while( true );
}

