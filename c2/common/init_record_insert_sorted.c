c2_init * __fastcall init_record_insert_sorted(c2_init *rec)

{
  uint32_t id;
  c2_fe_symbol *pcVar1;
  c2_init *cur;
  c2_init **link;
  int32_t first_offset;
  int32_t rec_offset;
  c2_init *next_header;
  c2_init *part;
  c2_init *rec_last;
  
  id = (rec->u08).header.sym_id;
  pcVar1 = fe_symbol_lookup_id(id);
  if ((pcVar1 == (c2_fe_symbol *)0x0) || ((pcVar1->u32).label_tuple == (c2_tuple *)0x0)) {
    link = (c2_init **)((int)g_init_records_tail + 8);
    if (g_init_records_tail == (void *)0x0) {
      link = &g_init_record_list;
    }
  }
  else {
    link = &g_init_record_list;
    for (cur = g_init_record_list; (cur != (c2_init *)0x0 && ((cur->u08).header.sym_id != id));
        cur = (cur->u08).header.list_next) {
      link = (c2_init **)&cur->u08;
    }
  }
  cur = ((c2_init_header *)link)->list_next;
  if (cur != (c2_init *)0x0) {
    rec_offset = (rec->u08).header.offset;
    first_offset = (cur->u08).header.offset;
    next_header = (cur->u08).header.list_next;
    do {
      if (rec_offset < (cur->u08).header.offset) break;
      rec_last = cur->next;
      while ((part = rec_last, link = &cur->next, part != (c2_init *)0x0 && (part->kind != 0))) {
        cur = part;
        rec_last = part->next;
      }
      cur = *link;
    } while (cur != (c2_init *)0x0);
    cur = ((c2_init_header *)link)->list_next;
    if (cur != (c2_init *)0x0) {
      rec_last = rec->next;
      for (part = rec->next->next; part != (c2_init *)0x0; part = part->next) {
        rec_last = part;
      }
      rec_last->next = cur;
    }
    if (rec_offset < first_offset) {
      (rec->u08).header.list_next = next_header;
      (cur->u08).header.list_next = (c2_init *)0x0;
    }
  }
  ((c2_init_header *)link)->list_next = rec;
  if ((pcVar1 == (c2_fe_symbol *)0x0) || ((pcVar1->u32).label_tuple == (c2_tuple *)0x0)) {
    cur = (rec->u08).header.list_next;
    g_init_records_tail = rec;
    while (next_header = cur, next_header != (c2_init *)0x0) {
      g_init_records_tail = next_header;
      cur = (next_header->u08).header.list_next;
    }
  }
  if (pcVar1 != (c2_fe_symbol *)0x0) {
    (pcVar1->u32).inits = rec;
  }
  return rec;
}

