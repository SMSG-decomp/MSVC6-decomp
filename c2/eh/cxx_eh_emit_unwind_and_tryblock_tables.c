void __fastcall cxx_eh_emit_unwind_and_tryblock_tables(c2_function *fn)

{
  char cVar1;
  c2_fe_symbol *pcVar2;
  char *pcVar3;
  int32_t iVar4;
  uint32_t uVar5;
  int iVar6;
  c2_fe_symbol *table_sym;
  c2_init *header;
  c2_init *rec;
  c2_init *item;
  c2_init *pcVar7;
  c2_eh_state *pcVar8;
  c2_init *ntry_item;
  int32_t iVar9;
  c2_cxx_try_block *try_block;
  char *pcVar10;
  int nstates;
  uint uVar11;
  c2_fe_symbol *tryblock_sym;
  int32_t state_index;
  c2_init **next_slot;
  int ntryblocks;
  c2_cxx_catch *catch_rec;
  
  iVar4 = g_eh_state_counter;
  table_sym = fe_symbol_new_local_cur(6,g_eh_state_counter * 8,7,1,'\x04',0x80);
  if (g_opt_edit_and_continue != 0) {
    uVar11 = 0xffffffff;
    pcVar3 = fn->fsym->name;
    pcVar10 = pcVar3;
    do {
      if (uVar11 == 0) break;
      uVar11 = uVar11 - 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    pcVar10 = arena_alloc(0,~uVar11 + 0xe);
    sprintf(pcVar10,"__unwindtable$%s",pcVar3);
    table_sym->name = pcVar10;
  }
  if ((g_cur_function->flags & 0x10000) == 0) {
    ntryblocks = 0;
  }
  else {
    ntryblocks = g_eh_try_block_count;
    tryblock_sym = fe_symbol_new_local_cur(6,g_eh_try_block_count * 0x14,7,1,'\x04',0x80);
    if (g_opt_edit_and_continue != 0) {
      uVar11 = 0xffffffff;
      pcVar3 = fn->fsym->name;
      pcVar10 = pcVar3;
      do {
        if (uVar11 == 0) break;
        uVar11 = uVar11 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      pcVar10 = arena_alloc(0,~uVar11 + 0x10);
      sprintf(pcVar10,"__tryblocktable$%s",pcVar3);
      tryblock_sym->name = pcVar10;
    }
  }
  header = alloc_init_record(0);
  (header->u08).header.sym_id = g_ehfuncinfo_symbol->id;
  rec = alloc_init_record(1);
  header->next = rec;
  (rec->u18).repeat = 1;
  (rec->u08).data.size = 4;
  (rec->u08).data.value_kind = 2;
  (rec->u08).header.offset = 0x19930520;
  item = alloc_init_record(1);
  rec->next = item;
  (item->u18).repeat = 1;
  (item->u08).data.size = 4;
  (item->u08).data.value_kind = 2;
  (item->u08).header.offset = iVar4;
  pcVar7 = alloc_init_record(2);
  item->next = pcVar7;
  rec = (c2_init *)table_sym->id;
  (pcVar7->u08).header.offset = 0;
  (pcVar7->u08).address.size = '\x04';
  (pcVar7->u08).header.list_next = rec;
  if (ntryblocks == 0) {
    item = alloc_init_record(1);
    pcVar7->next = item;
    (item->u18).repeat = 2;
    (item->u08).data.size = 4;
    (item->u08).data.value_kind = 2;
    (item->u08).header.offset = 0;
  }
  else {
    ntry_item = alloc_init_record(1);
    pcVar7->next = ntry_item;
    (ntry_item->u18).repeat = 1;
    (ntry_item->u08).data.size = 4;
    (ntry_item->u08).data.value_kind = 2;
    (ntry_item->u08).header.offset = ntryblocks;
    item = alloc_init_record(2);
    (item->u08).header.offset = 0;
    (item->u08).address.size = '\x04';
    ntry_item->next = item;
    (item->u08).header.list_next = (c2_init *)tryblock_sym->id;
  }
  cxx_eh_new_int2_init_record(fn,&item->next);
  init_record_insert_sorted(header);
  header = alloc_init_record(0);
  (header->u08).header.sym_id = (uint32_t)rec;
  state_index = 0;
  rec = header;
  if (0 < iVar4) {
    do {
      pcVar8 = eh_state_lookup(state_index);
      item = alloc_init_record(1);
      rec->next = item;
      (item->u18).repeat = 1;
      (item->u08).data.size = 4;
      (item->u08).data.value_kind = 1;
      if (pcVar8 == (c2_eh_state *)0x0) {
        iVar9 = -1;
      }
      else {
        iVar9 = pcVar8->to_state;
      }
      (item->u08).header.offset = iVar9;
      if ((((pcVar8 == (c2_eh_state *)0x0) || ((char)pcVar8->flags == '\x06')) ||
          (pcVar2 = pcVar8->funclet_label, pcVar2 == (c2_fe_symbol *)0x0)) ||
         ((pcVar8->flags & 0x400) != 0)) {
        rec = alloc_init_record(1);
        (rec->u18).repeat = 1;
        (rec->u08).data.size = 4;
        (rec->u08).data.value_kind = 1;
        item->next = rec;
        (rec->u08).header.offset = 0;
      }
      else {
        rec = alloc_init_record(2);
        pcVar7 = (c2_init *)pcVar2->id;
        (rec->u08).header.offset = 0;
        (rec->u08).address.size = '\x04';
        item->next = rec;
        (rec->u08).header.list_next = pcVar7;
      }
      state_index = state_index + 1;
    } while (state_index < iVar4);
  }
  init_record_insert_sorted(header);
  note_symbol_referenced(table_sym);
  if (ntryblocks != 0) {
    header = alloc_init_record(0);
    (header->u08).header.sym_id = tryblock_sym->id;
    try_block = eh_next_unhandled_object((c2_cxx_try_block *)0x0);
    rec = header;
    for (; try_block != (c2_cxx_try_block *)0x0; try_block = eh_next_unhandled_object(try_block)) {
      next_slot = &rec->next;
      table_sym = fe_symbol_new_local_cur(6,try_block->ncatches << 4,7,1,'\x04',0x80);
      try_block->handler_array = table_sym;
      if (g_opt_edit_and_continue != 0) {
        uVar11 = 0xffffffff;
        pcVar3 = fn->fsym->name;
        pcVar10 = pcVar3;
        do {
          if (uVar11 == 0) break;
          uVar11 = uVar11 - 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        pcVar10 = arena_alloc(0,~uVar11 + 0x17);
        iVar6 = g_eh_name_counter;
        g_eh_name_counter = g_eh_name_counter + 1;
        sprintf(pcVar10,"__catchsym$%s$%d",pcVar3,iVar6);
        table_sym->name = pcVar10;
      }
      rec = alloc_init_record(1);
      nstates = try_block->try_low;
      (rec->u18).repeat = 1;
      (rec->u08).data.size = 4;
      (rec->u08).data.value_kind = 1;
      *next_slot = rec;
      (rec->u08).header.offset = nstates;
      item = alloc_init_record(1);
      nstates = try_block->try_high;
      rec->next = item;
      (item->u18).repeat = 1;
      (item->u08).data.size = 4;
      (item->u08).data.value_kind = 1;
      (item->u08).header.offset = nstates;
      rec = alloc_init_record(1);
      nstates = try_block->catch_high;
      item->next = rec;
      (rec->u18).repeat = 1;
      (rec->u08).data.size = 4;
      (rec->u08).data.value_kind = 1;
      (rec->u08).header.offset = nstates;
      item = alloc_init_record(1);
      iVar4 = try_block->ncatches;
      rec->next = item;
      (item->u18).repeat = 1;
      (item->u08).data.size = 4;
      (item->u08).data.value_kind = 2;
      (item->u08).header.offset = iVar4;
      rec = alloc_init_record(2);
      (rec->u08).header.offset = 0;
      (rec->u08).address.size = '\x04';
      item->next = rec;
      (rec->u08).header.list_next = (c2_init *)table_sym->id;
    }
    init_record_insert_sorted(header);
    for (try_block = eh_next_unhandled_object((c2_cxx_try_block *)0x0);
        try_block != (c2_cxx_try_block *)0x0; try_block = eh_next_unhandled_object(try_block)) {
      header = alloc_init_record(0);
      catch_rec = try_block->catches;
      (header->u08).header.sym_id = try_block->handler_array->id;
      rec = header;
      while (catch_rec != (c2_cxx_catch *)0x0) {
        item = alloc_init_record(1);
        uVar5 = catch_rec->adjectives;
        rec->next = item;
        table_sym = catch_rec->type;
        (item->u18).repeat = 1;
        (item->u08).data.size = 4;
        (item->u08).data.value_kind = 2;
        (item->u08).header.offset = uVar5;
        if (table_sym == (c2_fe_symbol *)0x0) {
          pcVar7 = alloc_init_record(1);
          (pcVar7->u18).repeat = 1;
          (pcVar7->u08).data.size = 4;
          (pcVar7->u08).data.value_kind = 1;
          item->next = pcVar7;
          (pcVar7->u08).header.offset = 0;
        }
        else {
          pcVar7 = alloc_init_record(2);
          rec = (c2_init *)table_sym->id;
          (pcVar7->u08).header.offset = 0;
          (pcVar7->u08).address.size = '\x04';
          item->next = pcVar7;
          (pcVar7->u08).header.list_next = rec;
        }
        if (catch_rec->object == (c2_fe_symbol *)0x0) {
          item = alloc_init_record(1);
          (item->u18).repeat = 1;
          (item->u08).data.size = 4;
          (item->u08).data.value_kind = 1;
          pcVar7->next = item;
          (item->u08).header.offset = 0;
        }
        else {
          item = alloc_init_record(1);
          table_sym = catch_rec->object;
          pcVar7->next = item;
          (item->u18).repeat = 1;
          (item->u08).data.size = 4;
          (item->u08).data.value_kind = 1;
          nstates = field_0c_of_edx(fn,table_sym);
          (item->u08).header.offset = nstates;
        }
        rec = alloc_init_record(2);
        table_sym = catch_rec->label;
        catch_rec = catch_rec->next;
        (rec->u08).header.offset = 0;
        (rec->u08).address.size = '\x04';
        pcVar7 = (c2_init *)table_sym->id;
        item->next = rec;
        (rec->u08).header.list_next = pcVar7;
      }
      init_record_insert_sorted(header);
      note_symbol_referenced(try_block->handler_array);
    }
    note_symbol_referenced(tryblock_sym);
  }
  note_symbol_referenced(g_ehfuncinfo_symbol);
  return;
}

