c1_declarator * __thiscall
decl_declarator_init(c1_declarator *d,fe_name *name,c1_u32 kind,c1_overload_set *qualifier)

{
  c1_u8 *rec;
  c1_decl_record *pcVar1;
  
  d->name = name;
  d->qualifier = qualifier;
  d->op_token = '\x01';
  d->kind = kind;
  rec = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x4c;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (rec != (c1_u8 *)0x0) {
    pcVar1 = decl_record_init_default((c1_decl_record *)rec,d->name,d->qualifier);
    d->decl = pcVar1;
    d->position = g_token_position;
    return d;
  }
  d->decl = (c1_decl_record *)0x0;
  d->position = g_token_position;
  return d;
}

