void __fastcall assign_parameter_homes(c2_function *fn)

{
  uint16_t type;
  c2_operand *pcVar1;
  c2_symbol *pcVar2;
  c2_fe_symbol *pcVar3;
  c2_symbol *sym;
  c2_tuple *entry;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  c2_tuple *pcVar6;
  c2_tuple *t;
  uint uVar7;
  uint conv;
  int local_8;
  uint32_t local_4;
  c2_insert_fn *insert_fn;
  
  local_4 = 0;
  entry = find_tuple_of_kind(fn->cfg->first->head,'\x17');
  prepend_entry_frame_operand(fn,entry);
  local_8 = 0;
  g_param_cursor = first_param_offset();
  conv = g_cur_func_sym->attrs & 0x1c;
  if (((conv == 4) || (conv == 0x14)) || (conv == 0x18)) {
    for (pcVar1 = entry->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
      assign_register_argument(fn,&local_4,pcVar1,conv,1);
    }
  }
  mark_parameters_used_in_body(fn,entry);
  pcVar3 = g_cur_func_sym;
  for (pcVar1 = entry->src; g_cur_func_sym = pcVar3, pcVar1 != (c2_operand *)0x0;
      pcVar1 = pcVar1->next) {
    pcVar2 = pcVar1->sym->storage;
    pcVar3 = pcVar2->fe;
    if ((pcVar1->kind == '\x01') && (((pcVar1->u18).reg)->cls == '\x01')) {
      if (g_opt_global != 0) {
        *(uint16_t *)&pcVar3->refcount = (((pcVar1->u18).reg)->u28).hw_reg;
        pcVar3->storage = pcVar3->storage | 0x8000;
      }
      if (((pcVar3->attrs & 0x100) != 0) || (g_opt_global == 0)) {
        pcVar3->attrs = pcVar3->attrs | 0x100;
        pcVar3->storage = pcVar3->storage & 0xffffff9f | 0x10;
        for (pcVar2 = pcVar2->storage; pcVar2 != (c2_symbol *)0x0; pcVar2 = pcVar2->part_next) {
          pcVar2->cls = '\x04';
        }
        fe_symbol_assign_frame(pcVar3);
      }
    }
    else {
      uVar7 = fe_symbol_assign_frame(pcVar3);
      local_8 = local_8 + uVar7;
    }
    pcVar3 = g_cur_func_sym;
  }
  pcVar3->level = (char)local_8;
  pcVar3->combine = (char)((uint)local_8 >> 8);
  pcVar3->u44 = (c2_fe_symbol_u44)(short)((uint)local_8 >> 0x10);
  if (((conv == 4) || (conv == 0x14)) && ((pcVar3->attrs & 0x400) == 0)) {
    for (pcVar1 = entry->src; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
      if (((pcVar1->kind == '\x01') && (pcVar2 = (pcVar1->u18).reg, pcVar2->cls == '\x01')) &&
         (sym = pcVar1->sym->storage, (sym->fe->attrs & 0x100) != 0)) {
        type = pcVar2->type;
        insert_fn = tuple_insert_after;
        pcVar6 = entry;
        pcVar4 = operand_new_temp_in_reg(pcVar2->id,type);
        pcVar5 = operand_new_sym(0x14a,type,sym);
        pcVar6 = tuple_new(1,type,pcVar5,pcVar4,insert_fn,pcVar6);
        pcVar6->line = entry->line;
        t = tuple_new_pseudo(0x19e,type);
        pcVar4 = pcVar6->src;
        pcVar5 = (c2_operand *)node_clone((c2_node *)pcVar4);
        tuple_append_dst(t,pcVar5);
        tuple_insert_after(entry,t);
        pcVar4->sym->def = t;
      }
    }
  }
  return;
}

