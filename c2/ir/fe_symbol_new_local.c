c2_fe_symbol * __fastcall
fe_symbol_new_local(void *scope,uint16_t cls,int a,int16_t kind,int arena,uint8_t f,uint32_t attrs)

{
  c2_fe_symbol *s;
  uint32_t uVar1;
  c2_list_cell *pcVar2;
  
  s = fe_symbol_alloc('\x01',arena);
  s->size = a;
  uVar1 = g_fe_forced_local_id;
  s->storage = ((f & 0xf) << 3 | (byte)kind & 7) << 4 | cls & 0xf | s->storage & 0xffff7800;
  s->name = (char *)0x0;
  s->role = '&';
  s->attrs = attrs;
  if (uVar1 == 0) {
    uVar1 = fe_symbol_next_id();
  }
  s->id = uVar1;
  scope_hash_insert(scope,s);
  if (kind != 3) {
    fe_symbol_choose_section(s);
    if ((s->attrs & 0x480) == 0) {
      fe_symbol_assign_frame(s);
    }
  }
  if ((scope != &g_global_scope) && (kind != 3)) {
    pcVar2 = arena_alloc(1,8);
    (pcVar2->u04).fe = s;
    pcVar2->next = g_reader_new_locals;
    g_reader_new_locals = pcVar2;
  }
  return s;
}

