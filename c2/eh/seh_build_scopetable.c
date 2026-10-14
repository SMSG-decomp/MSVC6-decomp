void seh_build_scopetable(void)

{
  int32_t iVar1;
  c2_fe_symbol *pcVar2;
  c2_function *pcVar3;
  c2_init *header;
  c2_init *level_item;
  c2_init *filter_item;
  c2_init *tail;
  c2_seh_try_scope *scope;
  
  header = alloc_init_record(0);
  pcVar3 = g_cur_function;
  (header->u08).header.sym_id = g_seh_scopetable->id;
  tail = header;
  for (scope = pcVar3->seh_try_scopes; scope != (c2_seh_try_scope *)0x0; scope = scope->next) {
    level_item = alloc_init_record(1);
    iVar1 = scope->enclosing_level;
    tail->next = level_item;
    pcVar2 = scope->filter_label;
    (level_item->u18).repeat = 1;
    (level_item->u08).data.size = 4;
    (level_item->u08).data.value_kind = 1;
    (level_item->u08).header.offset = iVar1;
    if (pcVar2 == (c2_fe_symbol *)0x0) {
      filter_item = alloc_init_record(1);
      level_item->next = filter_item;
      (filter_item->u18).repeat = 1;
      (filter_item->u08).data.size = 4;
      (filter_item->u08).data.value_kind = 1;
      (filter_item->u08).header.offset = 0;
    }
    else {
      filter_item = alloc_init_record(2);
      tail = (c2_init *)pcVar2->id;
      (filter_item->u08).header.offset = 0;
      (filter_item->u08).address.size = '\x04';
      level_item->next = filter_item;
      (filter_item->u08).header.list_next = tail;
    }
    pcVar2 = scope->handler_label;
    if (pcVar2 == (c2_fe_symbol *)0x0) {
      tail = alloc_init_record(1);
      filter_item->next = tail;
      (tail->u18).repeat = 1;
      (tail->u08).data.size = 4;
      (tail->u08).data.value_kind = 1;
      (tail->u08).header.offset = 0;
    }
    else {
      tail = alloc_init_record(2);
      level_item = (c2_init *)pcVar2->id;
      (tail->u08).header.offset = 0;
      (tail->u08).address.size = '\x04';
      filter_item->next = tail;
      (tail->u08).header.list_next = level_item;
    }
  }
  init_record_insert_sorted(header);
  return;
}

